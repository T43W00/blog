---
title: Layer7 2차시
description: Layer7 2차시 과제 정리
categories:
    - Layer7
tags:
    - Layer7
date: 2025-04-02
---

# 백준 문제 풀이

[반복문](https://www.acmicpc.net/step/3)
[조건문](https://www.acmicpc.net/step/4)
[문자열](https://www.acmicpc.net/step/7)

2440, 2441 (별찍기 3~4)

---

## 2739 | 구구단

[문제 링크](https://www.acmicpc.net/problem/2739)

### 문제 설명

N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오. 출력 형식에 맞춰서 출력하면 된다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = 1; i <= 9; i++) {
        printf("%d * %d = %d\n", N, i, N * i);
    }
    
    return 0;
}
```

---

## 10950 | A + B - 3

[문제 링크](https://www.acmicpc.net/problem/10950)

### 문제 설명

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int T, A, B;
    
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}
```

---

## 8393 | 합

[문제 링크](https://www.acmicpc.net/problem/8393)

### 문제 설명

n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {

    int n, sum = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("%d", sum);

    return 0;
}
```

---

## 25304 | 영수증

[문제 링크](https://www.acmicpc.net/problem/25304)

### 문제 설명

준원이는 저번 주에 살면서 처음으로 코스트코를 가 봤다. 정말 멋졌다. 그런데, 몇 개 담지도 않았는데 수상하게 높은 금액이 나오는 것이다! 준원이는 영수증을 보면서 정확하게 계산된 것이 맞는지 확인해보려 한다.

영수증에 적힌,

- 구매한 각 물건의 가격과 개수
- 구매한 물건들의 총 금액

을 보고, 구매한 물건의 가격과 개수로 계산한 총 금액이 영수증에 적힌 총 금액과 일치하는지 검사해보자.

### 코드

```c
#include <stdio.h>

int main() {

    int X, N, a, b;

    scanf("%d", &X);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &a, &b);
        X -= a * b;
    }

    if (X == 0) printf("Yes");
    else printf("No");
    
    return 0;
}
```

---

## 25314 | 코딩은 체육과목 입니다

[문제 링크](https://www.acmicpc.net/problem/25314)

### 문제 설명 

오늘은 혜아의 면접 날이다. 면접 준비를 열심히 해서 앞선 질문들을 잘 대답한 혜아는 이제 마지막으로 칠판에 직접 코딩하는 문제를 받았다. 혜아가 받은 문제는 두 수를 더하는 문제였다. C++ 책을 열심히 읽었던 혜아는 간단히 두 수를 더하는 코드를 칠판에 적었다. 코드를 본 면접관은 다음 질문을 했다. “만약, 입출력이

$N$바이트 크기의 정수라면 프로그램을 어떻게 구현해야 할까요?”

혜아는 책에 있는 정수 자료형과 관련된 내용을 기억해 냈다. 책에는 long int는
$4$바이트 정수까지 저장할 수 있는 정수 자료형이고 long long int는 $8$바이트 정수까지 저장할 수 있는 정수 자료형이라고 적혀 있었다. 혜아는 이런 생각이 들었다. “int 앞에 long을 하나씩 더 붙일 때마다 $4$바이트씩 저장할 수 있는 공간이 늘어나는 걸까? 분명 long long long int는 $12$바이트, long long long long int는

$16$바이트까지 저장할 수 있는 정수 자료형일 거야!” 그렇게 혜아는 당황하는 면접관의 얼굴을 뒤로한 채 칠판에 정수 자료형을 써 내려가기 시작했다.

혜아가
$N$바이트 정수까지 저장할 수 있다고 생각해서 칠판에 쓴 정수 자료형의 이름은 무엇일까?

### 코드

```c
#include <stdio.h>

int main() {

  int N;

  scanf("%d", &N);

  for (int i = 0; i < N / 4; i++) {
    printf("long ");
  }
  
  printf("int");

  return 0;
}
```

---

## 11022 | A + B - 8

[문제 링크](https://www.acmicpc.net/problem/11022)

### 문제 설명

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int T, A, B;
    
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i, A, B, A + B);
    }
    
    return 0;
}
```

---

## 2438 | 별 찍기 - 1

[문제 링크](https://www.acmicpc.net/problem/11022)

### 문제 설명

첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

### 풀이

이중 반복문을 통해 `i` 만큼 별을 출력하고 줄바꿈을 하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```

---

## 2439 | 별 찍기 - 2

[문제 링크](https://www.acmicpc.net/problem/11022)

### 문제 설명

첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.

### 풀이

이중 반복문을 통해 `N - 1` 만큼 공백을 출력하고 `i` 만큼 별을 출력한 뒤 줄바꿈하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```

---

## 10952 | A+B - 5

[문제 링크](https://www.acmicpc.net/problem/10952)

### 문제 설명

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

### 풀이

`do-while` 문을 이용하여 `A`와 `B`가 0이 아닌 경우에는 계속 출력하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int A, B;
    
    do {
        scanf("%d %d", &A, &B);
        if (A && B) {
            printf("%d\n", A + B);
        }
    } while (A && B);
    
    return 0;
}
```

---

## 10951 | A+B - 4

[문제 링크](https://www.acmicpc.net/problem/10951)

### 문제 설명

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

### 풀이

`scanf()` 함수의 경우에는 입력 파일의 끝에 도달했을 때 `-1` 을 반환하게 되는데, 이를 이용하여 `scanf()` 반환값이 `-1` 일 때까지 반복하여 입출력 하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int A, B;
    
    while (scanf("%d %d", &A, &B) != -1) {
        printf("%d\n", A + B);
    }
    
    return 0;
}
```

---

## 1330 | 두 수 비교하기

[문제 링크](https://www.acmicpc.net/problem/1330)

### 문제 설명

두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    if (A > B) printf(">");
    else if (A < B) printf("<");
    else printf("==");
    
    return 0;
}
```

---

## 9498 | 시험 성적

[문제 링크](https://www.acmicpc.net/problem/1330)

### 문제 설명

시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d", &n);
    
    if (n <= 100 && n >= 90) printf("A");
    else if (n < 90 && n >= 80) printf("B");
    else if (n < 80 && n >= 70) printf("C");
    else if (n < 70 && n >= 60) printf("D");
    else printf("F");
    
    return 0;
}
```

---

## 2753 | 윤년

[문제 링크](https://www.acmicpc.net/problem/1330)

### 문제 설명

연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성하시오.

윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.

예를 들어, 2012년은 4의 배수이면서 100의 배수가 아니라서 윤년이다. 1900년은 100의 배수이고 400의 배수는 아니기 때문에 윤년이 아니다. 하지만, 2000년은 400의 배수이기 때문에 윤년이다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int y;
    
    scanf("%d", &y);
    
    if (!(y % 4) && (y % 100)) printf("1");
    else if (!(y % 400)) printf("1");
    else printf("0");

    return 0;
}
```

---

## 14681 | 사분면 고르기

[문제 링크](https://www.acmicpc.net/problem/1330)

### 문제 설명

흔한 수학 문제 중 하나는 주어진 점이 어느 사분면에 속하는지 알아내는 것이다. 사분면은 아래 그림처럼 1부터 4까지 번호를 갖는다. "Quadrant n"은 "제n사분면"이라는 뜻이다.

예를 들어, 좌표가 (12, 5)인 점 A는 x좌표와 y좌표가 모두 양수이므로 제1사분면에 속한다. 점 B는 x좌표가 음수이고 y좌표가 양수이므로 제2사분면에 속한다.

점의 좌표를 입력받아 그 점이 어느 사분면에 속하는지 알아내는 프로그램을 작성하시오. 단, x좌표와 y좌표는 모두 양수나 음수라고 가정한다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    if (x > 0 && y > 0) printf("1");
    else if (x < 0 && y > 0) printf("2");
    else if (x < 0 && y < 0) printf("3");
    else printf("4");
    
    return 0;
}
```

---

## 2884 | 알람 시계

[문제 링크](https://www.acmicpc.net/problem/2884)

### 문제 설명

상근이는 매일 아침 알람을 듣고 일어난다. 알람을 듣고 바로 일어나면 다행이겠지만, 항상 조금만 더 자려는 마음 때문에 매일 학교를 지각하고 있다.

상근이는 모든 방법을 동원해보았지만, 조금만 더 자려는 마음은 그 어떤 것도 없앨 수가 없었다.

이런 상근이를 불쌍하게 보던 창영이는 자신이 사용하는 방법을 추천해 주었다.

바로 "45분 일찍 알람 설정하기"이다.

이 방법은 단순하다. 원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾸는 것이다. 어차피 알람 소리를 들으면, 알람을 끄고 조금 더 잘 것이기 때문이다. 이 방법을 사용하면, 매일 아침 더 잤다는 기분을 느낄 수 있고, 학교도 지각하지 않게 된다.

현재 상근이가 설정한 알람 시각이 주어졌을 때, 창영이의 방법을 사용한다면, 이를 언제로 고쳐야 하는지 구하는 프로그램을 작성하시오.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int H, M;
    
    scanf("%d %d", &H, &M);
    
    if (M < 45) {
        if (H == 0) H = 23;
        else H--;
        M += 60;
    }
    
    M -= 45;
    
    printf("%d %d", H, M);
}
```

---

## 2525 | 오븐 시계

[문제 링크](https://www.acmicpc.net/problem/2525)

### 문제 설명

KOI 전자에서는 건강에 좋고 맛있는 훈제오리구이 요리를 간편하게 만드는 인공지능 오븐을 개발하려고 한다. 인공지능 오븐을 사용하는 방법은 적당한 양의 오리 훈제 재료를 인공지능 오븐에 넣으면 된다. 그러면 인공지능 오븐은 오븐구이가 끝나는 시간을 분 단위로 자동적으로 계산한다.

또한, KOI 전자의 인공지능 오븐 앞면에는 사용자에게 훈제오리구이 요리가 끝나는 시각을 알려 주는 디지털 시계가 있다.

훈제오리구이를 시작하는 시각과 오븐구이를 하는 데 필요한 시간이 분단위로 주어졌을 때, 오븐구이가 끝나는 시각을 계산하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int A, B, m;
    
    scanf("%d %d", &A, &B);
    scanf("%d", &m);
    
    B += m;
    
    if (B >= 60) {
        A += B / 60;
        B %= 60;
    }
    
    if (A >= 24) {
        A -= 24;
    }
    
    printf("%d %d", A, B);
    
    return 0;
}
```

---

## 2480 | 주사위 세개

[문제 링크](https://www.acmicpc.net/problem/2480)

### 문제 설명 

1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.

1. 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
2. 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
3. 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.

예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3×100으로 계산되어 1,300원을 받게 된다. 또 3개의 눈이 2, 2, 2로 주어지면 10,000+2×1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그중 가장 큰 값이 6이므로 6×100으로 계산되어 600원을 상금으로 받게 된다.

3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성 하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n1, n2, n3, max, same;
    
    scanf("%d %d %d", &n1, &n2, &n3);
    
    max = (n1 >= n2 && n1 >= n3) ? n1 : ((n2 >= n1 && n2 >= n3) ? n2 : n3);
    same = n1 == n2 ? n1 : (n2 == n3 ? n2 : n3);
    
    if (n1 == n2 && n2 == n3) {
        printf("%d", 10000 + n1 * 1000);
    }
    
    else if (n1 == n2 || n2 == n3 || n3 == n1) {
        printf("%d", 1000 + same * 100);
    }
    
    else { 
        printf("%d", max * 100);
    }
    
    return 0;
}
```

---

## 27866 | 문자와 문자열

[문제 링크](https://www.acmicpc.net/problem/2480)

### 문제 설명

단어 $S$와 정수 $i$가 주어졌을 때, $S$의 $i$번째 글자를 출력하는 프로그램을 작성하시오.

### 풀이

문자열과 정수를 입력받고, `str`의 `i-1`번째의 값을 `char`형으로 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    char str[1000];
    int i;
    
    scanf("%s %d", str, &i);
    
    printf("%c", str[i-1]);
}
```

---

## 2743 | 단어 길이 재기

[문제 링크](https://www.acmicpc.net/problem/2743)

### 문제 설명

알파벳으로만 이루어진 단어를 입력받아, 그 길이를 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    
    char str[100];
    
    scanf("%s", str);
    
    printf("%lu", strlen(str));
    
    return 0;
}
```

---

## 9086 | 문자열

[문제 링크](https://www.acmicpc.net/problem/9086)

### 문제 설명

문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    
    int T;
    char str[1000];
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%s", str);
        printf("%c%c\n", str[0], str[strlen(str) - 1]);
    }
    
    return 0;
}
```

---

## 11654 | 아스키 코드

[문제 링크](https://www.acmicpc.net/problem/11654)

### 문제 설명

알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때, 주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    char c;
    
    scanf("%c", &c);
    printf("%d", c);
    
    return 0;
}
```

---

## 11720 | 숫자의 합

[문제 링크](https://www.acmicpc.net/problem/11720)

### 문제 설명 

N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int N, sum = 0;
    char n;

    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &n);
        sum += n - 48;
    }
    
    printf("%d", sum);
    
    return 0;
}
```

---

## 10809 | 알파벳 찾기

[문제 링크](https://www.acmicpc.net/problem/10809)

### 문제 설명

알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    char alph[26] = "abcdefghijklmnopqrstuvwxyz";
    int res[26]; 
    
    scanf("%s", S);

    for (int i = 0; i < 26; i++) {
        res[i] = -1;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < strlen(S); j++) {
            if (S[j] == alph[i]) {
                res[i] = j;
                break;
            }
        }
    }
    
    for (int i = 0; i < 26; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
```

---

## 2675 | 문자열 반복

[문제 링크](https://www.acmicpc.net/problem/10809)

### 문제 설명

문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%\*+-./: 이다.

### 풀이

반복문을 통해 문자열 `S`를 순회하여 각 문자를 `R` 만큼 출력하도록 하였다.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    
    char S[20];
    int T, R;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d %s", &R, S);
        
        for (int j = 0; j < strlen(S); j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
```

---

## 1152 | 단어의 개수

[문제 링크](https://www.acmicpc.net/problem/1152)

### 문제 설명

영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    char S[1000001];
    int cnt = 0;
    
    scanf("%[^\n]s", S);
    
    for (int i = 0; i < strlen(S); i++) {
        if (i != 0 && i != strlen(S) - 1 && S[i] == ' ') {
            cnt++;
        }
    }
    
    if (strlen(S) <= 1 && S[0] <= 0x20) {
        cnt = 0;
    }
    else {
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}
```

---

## 2908 | 상수

[문제 링크](https://www.acmicpc.net/problem/2908)

### 문제 설명

상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다. 이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다. 상근이는 세 자리 수 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.

상수는 수를 다른 사람과 다르게 거꾸로 읽는다. 예를 들어, 734와 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다. 따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.

두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    A = ((A % 10) * 100) + ((A % 100) / 10) * 10 + (A / 100);
    B = ((B % 10) * 100) + ((B % 100) / 10) * 10 + (B / 100);
    
    if (A > B) {
        printf("%d", A);
    }
    else {
        printf("%d", B);
    }
               
    return 0;
}
```

---

## 5622 | 다이얼

[문제 링크](https://www.acmicpc.net/problem/5622)

### 문제 설명

전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다. 숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.

숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다. 예를 들어, UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 최소 시간을 구하는 프로그램을 작성하시오.

### 풀이

알파벳과 해당 알파벳마다의 걸리는 시간을 배열로 저장한 뒤, 반복문을 통해 입력받은 문자열의 문자와 알파벳 배열의 문자가 같을 경우, 해당 알파벳이 걸리는 시간을 `dial` 배열의 인덱스에서 구해 더해주었다.

### 코드

```c
#include <stdio.h>
#include <string.h>

int main() {
    
    char input[15];
    char alph[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int dial[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    int res = 0;
    
    scanf("%s", input);
    
    unsigned int len = strlen(input);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (alph[j] == input[i]) {
                res += dial[j];
            }
        }
    }
    
    printf("%d", res);
    
    return 0;
}
```

---

## 11718 | 그대로 출력하기

[문제 링크](https://www.acmicpc.net/problem/11718)

### 문제 설명

입력 받은 대로 출력하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    char S[100];
    while (scanf("%[^\n]", S) != -1) {
        printf("%s\n", S);
        getchar();
    }
    
    return 0;
}
```

---

## 2440 | 별 찍기 - 3

[문제 링크](https://www.acmicpc.net/problem/2440)

### 문제 설명

첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

### 설명

이중 반복문을 통해, `i` 가 `N` 부터 0이 될 때까지 별을 출력하고 줄바꿈하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = N; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```

## 2441 | 별 찍기 - 4

[문제 링크](https://www.acmicpc.net/problem/2441)

### 문제 설명 

첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.

### 풀이

`N`이 `0`이 될 때까지 `N-1` 만큼 공백을 출력하고 `i` 만큼 별을 출력한 뒤 줄바꿈하도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = N; i > 0; i--) {
        for (int j = 0; j < N - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```

---

# Codeup 문제 풀이

---

## 1173 | 30분전

### 문제 설명

수호는 30분 전으로 돌아가고 싶은 1人 이다.

공백을 기준으로 시간과 분이 주어진다.

그러면 이 시간을 기준으로 30분전의 시간을 출력하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int h, m;
    
    scanf("%d %d", &h, &m);
    
    if (m < 30) {
        
        if (h == 0) {
            h = 24;
        }
        
        h--;
        m += 60;
    }
    
    m -= 30;
    
    printf("%d %d", h, m);
    
    return 0;
}
```

---

## 1180 | 만능 휴지통

### 문제 설명

민호는 발명을 되게 좋아하고, 컴퓨터 프로그램도 되게 좋아한다.

어느 날 민호는 컴퓨터를 사용하던 중 휴지통이 꽉 차서 불편을 느꼈다.

그래서 휴지통이 n만큼 차면 알아서 쓰레기를 압축해주는 휴지통을 만들려고 한다.

이 때 압축하는 알고리즘은 다음과 같다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d", &n);
    n = (((n % 10) * 10 + (n / 10)) * 2) % 100;
    
    printf("%d\n", n);
    
    if (n <= 50) {
        printf("GOOD");
    }
    
    else {
        printf("OH MY GOD");
    }
    
    return 0;
}
```

---

## 1284 | 암호 해독

### 문제 설명

두 소수의 곱을 암호로 사용하는 알고리즘은 큰 수의 소인수분해가 어렵기 때문에 안전하다고 알려져있다.

그렇지만, 만약 두 소수를 잊어버리면 어떻게 될까? 굉장히 난감할 것이다.

이에 대비해 어떤 수(n)가 입력되면 두 소수의 곱으로 나타낼 수 있으면 두 소수를 오름차순으로 출력하고,

그렇지 않으면 "wrong number"를 출력하는 프로그램을 작성하시오.

### 문제 

```c
#include <stdio.h>

int main() {
    
    int n, cnt;
    int res[2] = {0, 0};
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            
            cnt = 0;
            
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    cnt++;
                }
            }
            
            if (cnt == 2) {
                if (res[0] != 0) {
                    res[1] = i;
                }
                else {
                    res[0] = i;
                }
            }
        }
    }
    
    if (res[0] * res[1] == n) {
        printf("%d %d", res[0], res[1]);
    }
    else {
        printf("wrong number");
    }
    
    return 0;
}
```