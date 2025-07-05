---
title: Layer7 컴퓨터 구조 1차시
categories:
    - Layer7
tags:
    - Layer7
date: 2025-05-11
---

## 컴퓨터 구조 배우는 이유

앞으로의 리버스 엔지니어링, 시스템 해킹을 학습하기 위해서는 컴퓨터가 어떤 구조로 이루어져 있는지, 어느 부분에서 취약점이 발생할 수 있는지 명확히 이해하고 있어야 한다.

---
## ISA (명령어 집합 구조)

명령어 집합 구조는 간단히 말하면 CPU가 이해할 수 있는 기계어 명령어의 집합이다.

소프트웨어의 명령어 집합을 ISA에 맞게 CPU가 이해해서 하드웨어단에서 실행되는 것이다.

명령어 집합 구조는 명령어 길이가 일정한지에 따라 가변길이CISC(Complex Instuction Set Computer))와 고정길이(RISC(Reduced Instruction Set Computer))로 분류할 수 있다.

---
### ISA 종류

대표적인 두 가지만 알아보도록 하겠다.
#### x86, x86-64
고성능 프로세서를 설계하기 위해 사용한다. 많은 전력이 필요하고 발열이 심하기 때문에 냉각장치의 공간을 확보할 수 있는 데스크탑이나 랩탑에 사용된다. (가변길이)
#### ARM
저전력, 고효율 프로세서를 설계하기 위해 사용한다. 발열 문제에 민감한 스마트폰이나 임베디드 기기에 사
용된다. (고정길이)

---

### CPU (중앙 처리 장치)

프로그램의 연산과 제어를 담당하는 하드웨어이다. ALU, Register 등으로 구성된다.

---

#### ALU (산술 논리 장치)

- **산술 연산:** 덧셈, 뺄셈, 곱셈, 나눗셈 등을 수행한다

- **논리 연산:** AND, OR, NOT, XOR 등의 논리 연산을 수행한다. 

- **비교 연산:** 두 값의 크기를 비교하여 어느 것이 더 큰지, 같은지, 작은지 등을 판단한다. 

- **데이터 처리:** 레지스터에서 데이터를 가져와 연산을 수행하고 결과를 레지스터에 저장한다.

---

#### Register

CPU의 빠른 데이터 처리를 돕기 위해 사용되는 임시저장공간

**대표적인 레지스터의 종류 :**

- PC (Program Counter) : 다음 명령어의 주소를 가지고 있는 레지스터

- AC (Accumulator) : 연산 결과 데이터를 일시적으로 저장하는 레지스터

- IR (Instruction Register) : 현재 실행 중인 명령어가 저장되어 있는 레지스터

- MAR (Memory Address Register) : PC 에 저장된 명령어 주소가 사용되기 전에 일시적으로 저장되는 주소 레지스터

- MBR (Memory Buffer Register) : 기억장치에 저장될 데이터 혹은 읽혀진 데이터가 일시적으로 저장되는 버퍼 레지스터

---

### Memory (기억장치)

컴퓨터에 필요한 데이터를 저장하는 장치

용도에 따라 주기억장치와 보조기억장치로 분류한다.

#### 주기억장치 (RAM)

필요한 데이터를 **보조기억장치**에서 불러와 임시로 저장한다.
> 예 ) 컴퓨터의 전원을 켜면 SSD에서 RAM으로 운영체제를 불러온다.

컴퓨터의 전원이 꺼지면 주기억장치의 데이터가 사라지는 휘발성 메모리다.

---

#### 보조기억장치 (HDD, SSD)

주기억장치가 불러올 데이터를 장기적으로 저장한다.

컴퓨터의 전원이 꺼져도 보조기억장치의 데이터가 사라지지 않는 비휘발성 메모리다.

---

## Byte Ordering

메모리의 연속적으로 저장되는 데이터의 경우에는 정렬되는 방식이 각각 다른데, 빅 엔디안과 리틀 엔디안으로 나뉜다.

---

### 빅 엔디안

큰 바이트부터 메모리의 낮은 주소부터 저장한다.

일반적인 컴퓨터의 CPU에서는 사용되지 않는다.

> 예 ) `0x72831923` -> | `0x72` | `0x83` | `0x19` | `0x23` |

---

### 리틀 엔디안

작은 바이트부터 메모리의 낮은 주소부터 저장한다.

일반적인 컴퓨터의 CPU에서 사용된다.

> 예 ) `0x72831923` -> | `0x23` | `0x19` | `0x83` | `0x72` |

---
## 인코딩

데이터를 특정한 형식으로 변환(암호화)한다.

## 디코딩

인코딩(암호화)된 데이터를 원래 값으로 변환(복호화)한다.

---

## 운영체제 (OS)

Operating System의 약자로, 하드웨어의 자원을 효율적으로 관리하도록 하는 시스템이다.

> 예 ) 메모리 공간을 효율적으로 사용하도록 분배

운영체제는 크게 쉘과 커널로 구성된다.

사용자가 애플리케이션에 명령어를 입력하면 그 명령을 쉘이 해석하여 커널에 전달하고 커널에 하드웨어를 관리하도록 한다.

---

### 쉘 (Shell)

운영체제와 상호작용할 수 있도록 하는 명령 줄 인터페이스다. 명령어를 입력받으면 명령어를 해석하여 커널에 전달한다.

#### 쉘 종류
- `sh` : 최초의 유닉스 쉘로 스크립트를 지원한다. 기능이 별로 없다.
- `bash` : `sh`의 확장 버전으로 `mv`, `cp`, `rm`, `touch`, `ls`, `mkdir`, `cd`, `rmdir` 등의 명령어 들이 추가되었다.
- `zsh` :  맞춤법 검사, 로그인 감시, 자동 생성, 플러그인 및 테마가 지원된다.
- `fish` : `Friendly Interatice SHell`, 친근하고 인터랙티브한 기능들이 지원된다.

---

### 커널 (Kernel)

운영체제의 핵심적인 역할을 하는 소프트웨어다. 하드웨어의 자원을 프로세스에 분배하고, 프로세스 제어, 메모리 제어, 시스템 콜 등 하드웨어에 직접적인 작업을 커널이 수행한다.

---

### 운영체제 종류

크게 분류해보자면 `UNIX` 기반의 운영체제와 아닌 것으로 나눌 수 있다.

`Windows`를 제외하면 현대 대부분의 운영체제는 `UNIX` 운영체제를 기반으로 하고 있다.

그 중 `Linux`의 경우에는 `UNIX`를 계승한 오픈소스 운영체제로 `Ubuntu`, `Arch Linux` 등 다양한 배포판이 있고, 커스터마이징이 자유로워 다양한 환경에 사용된다는 장점이 있다.

외에는 `macOS`, `iOS`, `AndroidOS` 등이 있다.

---

### CLI (Command Line Interface)

명령 줄로 컴퓨터와 상호작용하여 동작하는 인터페이스다.

`Linux`나 서버 용도로 사용하는 운영체제의 경우에 자주 사용된다.

---

### GUI (Graphic User Interface)

그래픽으로 상호작용하여 동작하는 인터페이스다.

`Windows`나 `macOS`와 같은 운영체제에서 대부분의 작업에서 사용한다.

---

## 리눅스 명령어

`cd` : 디렉토리 변경

`cat` : 파일 읽기

`ls` : 디렉토리 내 리스트 출력

`pwd` : 현재 디렉토리 출력

이 외에도 다양한 명령어가 있다.

---

## 과제

리눅스에서 자기 이름 폴더 만들고 C언어 소스코드 파일 만들기 및 과정 정리

### 과정

`mkdir` 명령어로 디렉토리를 생성한 뒤, 해당 디렉토리로 이동하였다.

```
~
❯ mkdir t43w00

~
❯ cd t43w00
```

<br>

`vi` 명령어로 `vim` 에디터를 사용하여 c 코드 파일을 생성 및 편집하였다.

```
~/t43w00 via C v13.3.0-gcc took 8s
❯ vi test.c
```

<br>

```c
#include <stdio.h>

int main() {  

 printf("                                                    `                                                \n");
 printf("                                                   /h:                                               \n");
 printf("                                                  +ddd:                                              \n");
 printf("                                                `oddddd:                                             \n");
 printf("                                               .yddddddd/                                            \n");
 printf("                                              -hddddddddd/                                           \n");
 printf("                                             :hddddddddddy`                                          \n");
 printf("                                            /ddddddddddds`                                           \n");
 printf("                                          `oddddddddddd+`                                            \n");
 printf("                                         `sddddddddddh:                                              \n");
 printf("                                        .yddddddddddh-        -                                      \n");
 printf("                                       -hdddddddddds.       `omy`                                    \n");
 printf("                                      /dddddddddddo`       `sdmMd-                                   \n");
 printf("                                     +ddddddddddd/        -hddmMMN/                                  \n");
 printf("                                   `oddddddddddh:        :hdddmMMMMo`                                \n");
 printf("                                  .yddddddddddy.        +dddddmMMMMMh.                               \n");
 printf("                                 .hdddddddddds`       `oddddddmMMMMMMm-                              \n");
 printf("                                :ddddddddddd+        .ydddddddmMMMMMMMN/                             \n");
 printf("                               /ddddddddddd:        -hddddddddhNMMMMMMMMs`                           \n");
 printf("                              oddddddddddh-        /dddddddddo`-mMMMMMMMMd.                          \n");
 printf("                            `sddddddddddy`        oddddddddd/   `hMMMMMMMMN:                         \n");
 printf("                           .yddddddddddo        `yddddddddh.      oMMMMMMMMM+                        \n");
 printf("                          -hdddddddddd/        `hddddddddo`        :NMMMMMMMMy`                      \n");
 printf("                         /ddddddddddd-         `dddddddd/           .dMMMMMMMMm.                     \n");
 printf("                        +ddddddddddy.          `ddddddh.              sMMMMMMMMN/                    \n");
 printf("                      `sdddddddddds`           `ddddds`                /NMMMMMMMMs                   \n");
 printf("                     `ydddddddddd+             `dddd/                   .dMMMMMMMMh.                 \n");
 printf("                    -hdddddddddd:              `ddh-                     `sMMMMMMMMm-                \n");
 printf("                   :hdddddddddh-               `ds`                        +NMMMMMMMN+               \n");
 printf("                  /ddddddddddy.              `.-/                           -mMMMMMMMMy`             \n");
 printf("                `oddddddddddo`     `.-:/+sydmmd-                             `yMMMMMMMMd.            \n");
 printf("               `sdddddddddds:/+sydmmNNMMMMMMMm-                               `oNMMMMMMMm:           \n");
 printf("              .ydddddddddmNNMMMMMMMMMMMMMNNmy.                                  :mMMMMMMMNo          \n");
 printf("             -hdddddddddmNMMMMMMNNNNmmdhys+.                                     .hMMMMMMMMy`        \n");
 printf("            /ddddddddddmNNNmmmmdhyso/-.``                                         `sMMMMMMMMd-       \n");
 printf("           +ddddddddddddddhyo+:-.`                                                  /NMMMMMMMN/      \n");
 printf("          :ssssssssssso/-.`                                                          -dMMMMMMMMs`    \n");
 printf("                                                                                      `sMMMMMMMMh.   \n");
 printf("                                                                                        +NMMMMMMMm:  \n");
 printf("                                                                                         -mMMMMMMMN+ \n");
 printf("                                                                                          `yMMMMMMMMs\n");
 printf("                                                                                            oNMMMMMMN\n");
 printf("                                                                                             :mMMMMMN\n");
 printf("                                                                                              .hMMMMM\n");
 printf("                                                                                                sMMMM\n");
 printf("                                                                                                 /NMM\n");
 printf("                                                                                                  .dM\n");
 printf("                                                                                                   `y\n");
  
  return 0;
}
```

`vi` 에디터 내의 `:wq` 명령을 통해 저장 및 종료하였다.

<br>

`gcc`로 컴파일한 뒤 실행하였다.

```
~/t43w00 via C v13.3.0-gcc
❯ gcc -o test test.c

~/t43w00 via C v13.3.0-gcc
❯ ./test
                                                    `
                                                   /h:
                                                  +ddd:
                                                `oddddd:
                                               .yddddddd/
                                              -hddddddddd/
                                             :hddddddddddy`
                                            /ddddddddddds`
                                          `oddddddddddd+`
                                         `sddddddddddh:
                                        .yddddddddddh-        -
                                       -hdddddddddds.       `omy`
                                      /dddddddddddo`       `sdmMd-
                                     +ddddddddddd/        -hddmMMN/
                                   `oddddddddddh:        :hdddmMMMMo`
                                  .yddddddddddy.        +dddddmMMMMMh.
                                 .hdddddddddds`       `oddddddmMMMMMMm-
                                :ddddddddddd+        .ydddddddmMMMMMMMN/
                               /ddddddddddd:        -hddddddddhNMMMMMMMMs`
                              oddddddddddh-        /dddddddddo`-mMMMMMMMMd.
                            `sddddddddddy`        oddddddddd/   `hMMMMMMMMN:
                           .yddddddddddo        `yddddddddh.      oMMMMMMMMM+
                          -hdddddddddd/        `hddddddddo`        :NMMMMMMMMy`
                         /ddddddddddd-         `dddddddd/           .dMMMMMMMMm.
                        +ddddddddddy.          `ddddddh.              sMMMMMMMMN/
                      `sdddddddddds`           `ddddds`                /NMMMMMMMMs
                     `ydddddddddd+             `dddd/                   .dMMMMMMMMh.
                    -hdddddddddd:              `ddh-                     `sMMMMMMMMm-
                   :hdddddddddh-               `ds`                        +NMMMMMMMN+
                  /ddddddddddy.              `.-/                           -mMMMMMMMMy`
                `oddddddddddo`     `.-:/+sydmmd-                             `yMMMMMMMMd.
               `sdddddddddds:/+sydmmNNMMMMMMMm-                               `oNMMMMMMMm:
              .ydddddddddmNNMMMMMMMMMMMMMNNmy.                                  :mMMMMMMMNo
             -hdddddddddmNMMMMMMNNNNmmdhys+.                                     .hMMMMMMMMy`
            /ddddddddddmNNNmmmmdhyso/-.``                                         `sMMMMMMMMd-
           +ddddddddddddddhyo+:-.`                                                  /NMMMMMMMN/
          :ssssssssssso/-.`                                                          -dMMMMMMMMs`
                                                                                      `sMMMMMMMMh.
                                                                                        +NMMMMMMMm:
                                                                                         -mMMMMMMMN+
                                                                                          `yMMMMMMMMs
                                                                                            oNMMMMMMN
                                                                                             :mMMMMMN
                                                                                              .hMMMMM
                                                                                                sMMMM
                                                                                                 /NMM
                                                                                                  .dM
                                                                                                   `y

```