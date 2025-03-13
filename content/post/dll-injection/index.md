---
title: DLL Injection
description: DLL Injection 기법 학습 내용 정리
categories:
    - Reversing
tags:
    - Reversing
date: 2025-03-07
---

## 목표

`notepad.exe`에 `MessageBox` 함수를 호출하는 `DLL Injection` 하기

---

## DLL Injection이란?

실행 중인 프로세스의 공간에 강제로 `DLL`을 주입하여 악의적인 코드를 실행하는 기법을 말한다.

---

## DLL Injection 구현

프로세스의 메모리에 `DLL` 파일의 경로를 쓰고, 원격 스레드를 통해 `DLL`을 로드한다.

`DLL`이 로드되면 `DllMain` 함수가 실행되는데, 이 함수에 원하는 코드를 작성하여 실행할 수 있다.

---

### 프로세스 핸들 구하기

먼저 프로세스의 메모리에 접근하기 위해 프로세스의 핸들을 구해야 한다.

프로세스 핸들은 `OpenProcess` 함수를 통해 구해야 하는데, 인자로 `PID`가 필요하다.

---

#### PID 구하기

`PID`는 작업 관리자에서 확인할 수 있지만, 매번 확인할 수는 없으니 동적으로 구해야 한다.

`tlhelp32.h`의 `CreateToolhelp32Snapshot` 함수를 통해 스냅샷을 만들어 프로세스의 정보를 가져올 수 있는데, `PROCESSENTRY32` 구조체의 필드 중 `th32ProcessId`를 가져올 수 있다.

---

### 메모리 공간 할당하기

`VirtualAllocEx` 함수를 통해 프로세스의 메모리 공간을 할당할 수 있다.

---

### 메모리 공간에 DLL 경로 쓰기

`WriteProcessMemory` 함수를 통해 지정된 프로세스의 메모리 영역에 데이터를 쓸 수 있다.

이 함수를 통해 타겟 프로세스의 메모리 영역에 DLL의 경로를 쓰면 된다.

---

### LoadLibrary 함수 주소 가져오기

`GetModuleHandle` 함수로 `kernel32.dll`의 핸들을 가져오고, `GetProcAddress` 함수를 통해 `LoadLibrary` 함수의 주소를 가져올 수 있다.

---

### 원격 스레드 생성하기

타겟 프로세스에 원격 스레드를 생성하여 DLL을 LoadLibrary 함수를 통해 불러온다.

---

## 코드 구현

---

### DLL Injection 코드

```c
// compile -o DLL_Injection.exe DLL_Injection.c

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  HANDLE hSnapshot;
  HANDLE hProcess;
  PROCESSENTRY32 PE32;
  unsigned long targetPID;
  char* dllPath = "C:/Users/t43w00/MessageBox.dll";

  // PID 구하기

  PE32.dwSize = sizeof(PROCESSENTRY32);

  hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

  if (Process32First(hSnapshot, &PE32)) {
    while (Process32Next(hSnapshot, &PE32)) {
      if (!strcmp(PE32.szExeFile, "Notepad.exe")) {
        targetPID = PE32.th32ProcessID;
        break;
      }
    }
  }

  // 프로세스 핸들 구하기
  hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetPID);

  printf("Process Name : %s\n", PE32.szExeFile);
  printf("Process ID : %lu\n", targetPID);
  printf("Process Handle : %p\n", hProcess);

  // 메모리 공간 할당하기
  LPVOID pRemoteDllPath = VirtualAllocEx(
    hProcess,
    NULL,
    strlen(dllPath) + 1,
    MEM_COMMIT | MEM_RESERVE,
    PAGE_READWRITE
  );

  // 메모리 공간에 DLL 경로 쓰기
  WriteProcessMemory(
    hProcess,
    pRemoteDllPath,
    dllPath,
    strlen(dllPath) + 1,
    NULL
  );

  // LoadLibrary 함수 주소 가져오기
  HMODULE hKernel32 = GetModuleHandle("kernel32.dll");
  FARPROC pLoadLibrary = GetProcAddress(hKernel32, "LoadLibraryA");

  // 원격 스레드 생성하기
  HANDLE hRemoteThread = CreateRemoteThread(
    hProcess,
    NULL,
    0,
    (LPTHREAD_START_ROUTINE)pLoadLibrary,
    pRemoteDllPath,
    0,
    NULL
  );

  WaitForSingleObject(hRemoteThread, INFINITE);

  // 정리
  VirtualFreeEx(
    hProcess,
    pRemoteDllPath,
    0,
    MEM_RELEASE
  );

  CloseHandle(hSnapshot);
  CloseHandle(hProcess);
  
  return 0;
}
```

---

### DLL 코드

`DLL`이 프로세스에 로드되었을 때 `DllMain` 함수에서 `MessageBoxA` 함수가 실행되도록 작성하였다.

```c
#include <windows.h>

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  if (fdwReason == DLL_PROCESS_ATTACH) {
    MessageBoxA(NULL, "Injected!", "MessageBox", MB_OK);
  }
  return TRUE;
}
```

---

## 코드 실행

`notepad.exe`를 실행한 뒤에, `DLL_Injection.exe`를 실행하면 `MessageBox`가 호출되는 것을 확인할 수 있다.







