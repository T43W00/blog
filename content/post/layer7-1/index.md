---
title: Layer7 C언어 1차시
categories:
    - Layer7
tags:
    - Layer7
date: 2025-03-31
---

# codeup 문제 풀이

아래 문제 풀이와 정답 코드 정리

1014, 1015, 1017, 1018, 1026, 1027, 1028
1029, 1030, 1031, 1032, 1033, 1034, 1035

---

## 1014

[문제 링크](https://codeup.kr/problem.php?id=1014)

### 문제 설명

2개의 문자(ASCII CODE)를 입력받아서 순서를 바꿔 출력해보자.

### 풀이

입력받은 변수의 순서를 바꾸어 출력해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    
    char a, b;
    
    scanf("%c %c", &a, &b);
    printf("%c %c", b, a);
    
    return 0;
}
```

---

## 1015

[문제 링크](https://codeup.kr/problem.php?id=1015)

### 문제 설명

실수(float) 1개를 입력받아 저장한 후,
저장되어 있는 값을 소수점 셋 째 자리에서 반올림하여
소수점 이하 둘 째 자리까지 출력하시오.

### 풀이 

실수 값을 입력받은 뒤, `%.2f` 서식 지정자를 사용하여 소수점 이하 둘 째 자리까지만 출력하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {

    float f;

    scanf("%f", &f);
    printf("%.2f", f);
    
    return 0;
}
```

---

## 1017

[문제 링크](https://codeup.kr/problem.php?id=1017)

### 문제 설명

int형 정수 1개를 입력받아 공백을 사이에 두고 3번 출력해보자.

### 풀이

입력받은 정수를 공백을 사이에 두고 3번 출력해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    int a;
    
    scanf("%d", &a);
    printf("%d %d %d", a, a, a);
    
    return 0;
}
```

---

## 1018

[문제 링크](https://codeup.kr/problem.php?id=1018)

### 문제 설명

어떤 형식에 맞추어 시간이 입력될 때, 그대로 출력하는 연습을 해보자.

### 풀이

`:` 문자를 기준으로 앞 뒤로 정수를 입력받아 형식에 맞게 출력해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int h, m;
    
    scanf("%d:%d", &h, &m);
    printf("%d:%d", h, m);
    
    return 0;
}
```

---

## 1026

[문제 링크](https://codeup.kr/problem.php?id=1026)

### 문제 설명

입력되는 시:분:초 에서 분만 출력해보자.

### 풀이

`:` 문자를 기준으로 시, 분, 초를 각각 `h`, `m`, `s`에 입력받아 `m`만 출력해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int h, m, s;
    
    scanf("%d:%d:%d", &h, &m, &s);
    printf("%d", m);
    
    return 0;
}
```

---

## 1027

[문제 링크](https://codeup.kr/problem.php?id=1027)

### 문제 설명

년월일을 출력하는 방법은 나라마다, 형식마다 조금씩 다르다.

년월일(yyyy.mm.dd)를 입력받아,

일월년(dd-mm-yyyy)로 출력해보자.

(단, 한 자리 일/월은 0을 붙여 두자리로, 년도도 0을 붙여 네자리로 출력한다.) 

### 풀이

`.` 기준으로 년, 월, 일을 각각 `y`, `m`, `d` 변수에 입력받은 뒤, `dd-mm-yyyy` 형식으로 출력해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int y, m, d;
    
    scanf("%d.%d.%d", &y, &m, &d);
    printf("%02d-%02d-%04d", d, m, y);
    
    return 0;
}
```

---

## 1028

[문제 링크](https://codeup.kr/problem.php?id=1028)

### 문제 설명

정수 1개를 입력받아 그대로 출력해보자.
(단, 입력되는 정수의 범위는 0 ~ 4,294,967,295 이다.)

### 풀이

`unsigned int` 자료형으로 입력받아 `0 ~ 4294967295` 범위의 정수를 입력받아 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    unsigned int a;
    
    scanf("%u", &a);
    printf("%u", a);
    
    return 0;
}
```

---

## 1029

[문제 링크](https://codeup.kr/problem.php?id=1029)

### 문제 설명

실수 1개를 입력받아 그대로 출력해보자.
(단, 입력되는 실수의 범위는 +- 1.7*10-308 ~ +- 1.7*10308 이다.)

### 풀이

`double` 자료형을 입력받아 `+- 3.4*10-38 ~ +- 3.4*1038` 범위의 실수 값을 출력할 수 있도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    double f;
    
    scanf("%lf", &f);
    printf("%.11lf", f);
    
    return 0;
}
```

---

## 1030

[문제 링크](https://codeup.kr/problem.php?id=1030)

### 문제 설명

정수 1개를 입력받아 그대로 출력해보자.
단, 입력되는 정수의 범위는
`-9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807` 이다.

### 풀이

`long long int` 자료형을 사용하여 범위에 맞는 값을 입출력 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    long long int a;
    
    scanf("%lld", &a);
    printf("%lld", a);
    
    return 0;
}
```

---

## 1031

[문제 링크](https://codeup.kr/problem.php?id=1031)

### 문제 설명

10진수를 입력받아 8진수(octal)로 출력해보자.

### 풀이

`%d` 서식 지정자로 입력을 받은 뒤, 8진수를 나타내는 `%o` 서식 지정자로 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int a;
    
    scanf("%d", &a);
    printf("%o", a);
    
    return 0;
}
```

---

## 1032

[문제 링크](https://codeup.kr/problem.php?id=1031)

### 문제 설명

10진수를 입력받아 16진수(hexadecimal)로 출력해보자.

### 풀이

`%d` 서식 지정자로 입력을 받은 뒤, 16진수를 나타내는 `%x` 서식 지정자로 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int a;
    
    scanf("%d", &a);
    printf("%x", a);
    
    return 0;
}
```

---

## 1033

[문제 링크](https://codeup.kr/problem.php?id=1031)

### 문제 설명 

10진수를 입력받아 16진수(hexadecimal)로 출력해보자.

### 풀이 

`%d` 서식 지정자로 입력을 받은 뒤, 16진수(대문자)를 나타내는 `%X` 서식 지정자로 출력하였다.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int a;
    
    scanf("%d", &a);
    printf("%X", a);
    
    return 0;
}
```

---

## 1034

[문제 링크](https://codeup.kr/problem.php?id=1031)

### 문제 설명 

8진수로 입력된 정수 1개를 10진수로 바꾸어 출력해보자.

### 풀이

8진수를 나타내는 `%o` 서식 지정자로 입력을 받은 뒤, 10진수를 나타내는 `%d` 서식 지정자로 출력하였다.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int a;
    
    scanf("%o", &a);
    printf("%d", a);
    
    return 0;
}
```

---

## 1035

[문제 링크](https://codeup.kr/problem.php?id=1031)

### 문제 설명

16진수로 입력된 정수 1개를 8진수로 바꾸어 출력해보자.

### 풀이

16진수를 나타내는 `%x` 서식 지정자로 입력을 받은 뒤, 8진수를 나타내는 `%o` 서식 지정자로 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int a;
    
    scanf("%x", &a);
    printf("%o", a);
    
    return 0;
}
```

---

# C언어 환경 세팅 인증

```
❯ gcc -v
Using built-in specs.
COLLECT_GCC=C:\TDM-GCC-64\bin\gcc.exe
COLLECT_LTO_WRAPPER=C:/TDM-GCC-64/bin/../libexec/gcc/x86_64-w64-mingw32/10.3.0/lto-wrapper.exe
Target: x86_64-w64-mingw32
Configured with: ../../../src/gcc-git-10.3.0/configure --build=x86_64-w64-mingw32 --enable-targets=all --enable-languages=ada,c,c++,fortran,jit,lto,objc,obj-c++ --enable-libgomp --enable-lto --enable-graphite --enable-cxx-flags=-DWINPTHREAD_STATIC --disable-build-with-cxx --disable-build-poststage1-with-cxx --enable-libstdcxx-debug --enable-threads=posix --enable-version-specific-runtime-libs --enable-fully-dynamic-string --enable-libstdcxx-filesystem-ts=yes --disable-libstdcxx-pch --enable-libstdcxx-threads --enable-libstdcxx-time=yes --enable-mingw-wildcard --with-gnu-ld --disable-werror --enable-nls --disable-win32-registry --enable-large-address-aware --disable-rpath --disable-symvers --prefix=/mingw64tdm --with-local-prefix=/mingw64tdm --with-pkgversion=tdm64-1 --with-bugurl=https://github.com/jmeubank/tdm-gcc/issues
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 10.3.0 (tdm64-1)
```
