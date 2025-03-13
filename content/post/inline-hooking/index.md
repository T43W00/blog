---
title: Inline Hooking
description: Inline Hooking 기법 학습 내용 정리
categories:
    - Reversing
tags:
    - Reversing
date: 2025-03-10
---

## 목표

`Inline Hooking`을 통해 `rand` 함수의 반환값 조작하기

---

## Inline Hooking이란?

먼저 `Hooking`이란, 프로그램의 실행 흐름을 변경하는 기법인데, 그 중 `Inline Hooking`은 특정 함수의 시작 부분에 코드를 삽입하여 흐름을 변경하는 기법이다.

---

## DLL 코드 작성

`rand` 값을 조작하는 DLL 코드를 작성한 뒤, 랜덤한 값을 출력하는 프로그램에서 로드하여 실행할 것이다.

---

### 함수 주소 가져오기

`GetModuleHandle` 함수로 `rand` 함수를 저장하는 `ucrtbase.dll`의 핸들을 가져온 뒤, `GetProcAddress` 함수로 `rand` 함수의 주소를 가져올 수 있다.

---

### 삽입할 코드 배열 생성하기

삽입할 코드는 `jmp` 명령어의 옵코드인 `0xE9`를 저장하고, 다음으로 `Hooking` 할 함수의 주소까지의 길이를 원래 `rand` 함수의 주소를 빼서 구하여 저장한다. 

---

### 메모리에 복사하기

`memcpy` 함수를 통해 기존 `rand` 함수를 저장해둔 뒤에, 후킹한 함수를 덮어씌운다.

---

## 전체 코드

```c
#include <windows.h>
#include <stdio.h>
#include <stdint.h>

typedef int (*rand_Func)(void);

rand_Func Original_rand = NULL;

BYTE Original_bytes[5];

// 후킹할 함수
int __stdcall Hooked_rand() {
    return 7;
}
    
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {

    Original_rand = (rand_Func)GetProcAddress(GetModuleHandle("ucrtbase.dll"), "rand");

    BYTE Patch[5] = { 0xE9 };

    *(DWORD*)(Patch + 1) = (uintptr_t)Hooked_rand - (uintptr_t)Original_rand - 5;

    DWORD oldProtect;

    // 메모리 복사하기
    VirtualProtect(Original_rand, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(Original_bytes, Original_rand, 5);
    memcpy(Original_rand, Patch, 5);
    VirtualProtect(Original_rand, 5, oldProtect, &oldProtect);

    return TRUE;
}
```

---

## 테스트 프로그램

후킹을 테스트 할 프로그램으로 1부터 6까지 수 중에 랜덤한 값을 출력하는 C 코드를 작성한 뒤 실행하였다.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    
    HINSTANCE hDll = LoadLibrary("hook.dll");
    srand((unsigned int)time(NULL));
    int random_value;

    for (int i = 0; i < 10; i++) {
        random_value = rand();
        printf("%d\n", random_value);
    }

    FreeLibrary(hDll);
    return 0;
}
```

---

## 코드 실행

코드 실행 결과 랜덤 값이 7로 고정되어 출력되는 걸 확인할 수 있다.