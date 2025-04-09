---
title: Layer7 3차시
description: Layer7 3차시 과제 정리
categories:
    - Layer7
tags:
    - Layer7
date: 2025-04-07
---

# 백준 문제 정리

1차원 배열 : 10807, 10818*, 10810*
2차원 배열 : 2738, 10798*, 2563*

---

## 10807

[문제 링크](https://www.acmicpc.net/problem/10807)

### 문제

총 N개의 정수가 주어졌을 때, 정수 v가 몇 개인지 구하는 프로그램을 작성하시오.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N, v, cnt = 0;
    scanf("%d", &N);
    int arr[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &v);
    
    for (int i = 0; i < N; i++) {
        if (arr[i] == v) {
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
```

---

## 10818 | 최소, 최대

[문제 링크](https://www.acmicpc.net/problem/10818)

### 문제

N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

### 풀이

반복문을 통해 `arr` 배열에 각 원소들을 입력받은 뒤, 각각의 원소들을 비교하여 가장 작은 값을 `tmp` 변수에 저장하여 출력하였다. 가장 큰 값도 같은 방법으로 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N, tmp;
    
    scanf("%d", &N);
    
    int arr[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    tmp = arr[0];
    
    for (int i = 0; i < N; i++) {
        if (arr[i] < tmp) {
            tmp = arr[i];
        }
    }
    
    printf("%d ", tmp);
    
    tmp = -1000001;
        
    for (int i = 0; i < N; i++) {
        if (arr[i] > tmp) {
            tmp = arr[i];
        }
    }
    
    printf("%d", tmp);
    
    return 0;
}
```

---

## 10810 | 공 넣기

[문제 링크](https://www.acmicpc.net/problem/10810)


### 문제

도현이는 바구니를 총 N개 가지고 있고, 각각의 바구니에는 1번부터 N번까지 번호가 매겨져 있다. 또, 1번부터 N번까지 번호가 적혀있는 공을 매우 많이 가지고 있다. 가장 처음 바구니에는 공이 들어있지 않으며, 바구니에는 공을 1개만 넣을 수 있다.

도현이는 앞으로 M번 공을 넣으려고 한다. 도현이는 한 번 공을 넣을 때, 공을 넣을 바구니 범위를 정하고, 정한 바구니에 모두 같은 번호가 적혀있는 공을 넣는다. 만약, 바구니에 공이 이미 있는 경우에는 들어있는 공을 빼고, 새로 공을 넣는다. 공을 넣을 바구니는 연속되어 있어야 한다.

공을 어떻게 넣을지가 주어졌을 때, M번 공을 넣은 이후에 각 바구니에 어떤 공이 들어 있는지 구하는 프로그램을 작성하시오.

### 풀이

`baskets` 배열을 0으로 초기화 한 뒤에, 반복문을 통해 배열에 입력받았다. 이후 `M`번 만큼 `I`, `J`, `K`를 입력받아 `I`부터 `J`번째 인덱스에 `K` 값을 저장해주었다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int N, M, I, J, K;
    
    scanf("%d %d", &N, &M);
    
    int baskets[N];
    
    for (int i = 0; i < N; i++) {
        baskets[i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &I, &J, &K);
        
        for (int j = I - 1; j <= J - 1; j++) {
            baskets[j] = K;
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", baskets[i]);
    }
    
    return 0;
}
```

--- 

## 2738 | 행렬 덧셈 

[문제 링크](https://www.acmicpc.net/problem/2738)

### 문제

N\*M크기의 두 행렬 A와 B가 주어졌을 때, 두 행렬을 더하는 프로그램을 작성하시오.

### 코드 

```c
#include <stdio.h>

int main() {
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int arr1[N][M];
    int arr2[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr2[i][j]);
            arr2[i][j] += arr1[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

---

## 10798 | 세로읽기

[문제 링크](https://www.acmicpc.net/problem/10798)

### 문제 

아직 글을 모르는 영석이가 벽에 걸린 칠판에 자석이 붙어있는 글자들을 붙이는 장난감을 가지고 놀고 있다. 

이 장난감에 있는 글자들은 영어 대문자 ‘A’부터 ‘Z’, 영어 소문자 ‘a’부터 ‘z’, 숫자 ‘0’부터 ‘9’이다. 영석이는 칠판에 글자들을 수평으로 일렬로 붙여서 단어를 만든다. 다시 그 아래쪽에 글자들을 붙여서 또 다른 단어를 만든다. 이런 식으로 다섯 개의 단어를 만든다. 아래 그림 1은 영석이가 칠판에 붙여 만든 단어들의 예이다. 

A A B C D D
a f z z 
0 9 1 2 1
a 8 E W g 6
P 5 h 3 k x
<그림 1>

한 줄의 단어는 글자들을 빈칸 없이 연속으로 나열해서 최대 15개의 글자들로 이루어진다. 또한 만들어진 다섯 개의 단어들의 글자 개수는 서로 다를 수 있다. 

심심해진 영석이는 칠판에 만들어진 다섯 개의 단어를 세로로 읽으려 한다. 세로로 읽을 때, 각 단어의 첫 번째 글자들을 위에서 아래로 세로로 읽는다. 다음에 두 번째 글자들을 세로로 읽는다. 이런 식으로 왼쪽에서 오른쪽으로 한 자리씩 이동 하면서 동일한 자리의 글자들을 세로로 읽어 나간다. 위의 그림 1의 다섯 번째 자리를 보면 두 번째 줄의 다섯 번째 자리의 글자는 없다. 이런 경우처럼 세로로 읽을 때 해당 자리의 글자가 없으면, 읽지 않고 그 다음 글자를 계속 읽는다. 그림 1의 다섯 번째 자리를 세로로 읽으면 D1gk로 읽는다. 

그림 1에서 영석이가 세로로 읽은 순서대로 글자들을 공백 없이 출력하면 다음과 같다:

Aa0aPAf985Bz1EhCz2W3D1gkD6x

칠판에 붙여진 단어들이 주어질 때, 영석이가 세로로 읽은 순서대로 글자들을 출력하는 프로그램을 작성하시오.

### 풀이

5 * 15 크기의 배열을 만들고 각 줄에 문자열을 입력받았다. 빈 공간의 경우에는 `#` 문자를 저장해주었다. 반복문을 통해 세로로 출력하도록 하였는데, `#` 문자나 널 문자가 아닌 경우에만 출력하도록 하였다.

### 코드 

```c
#include <stdio.h>

int main() {
    
    char strings[5][15];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            strings[i][j] = '#';
        }
    }
    
    for (int i = 0; i < 5; i++) {
        scanf("%s", strings[i]);
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (strings[j][i] != '#' && strings[j][i] != '\0') {
                printf("%c", strings[j][i]);
            }
        }
    }
    
    return 0;       
}
```

---

## 2563 | 색종이

[문제 링크](https://www.acmicpc.net/problem/2563)

### 문제

가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다. 이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다. 이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 넓이를 구하는 프로그램을 작성하시오.

### 풀이

100 * 100 크기의 배열을 만들고 0으로 초기화하였다. `n`번 만큼 `x`와 `y`를 입력받아 반복문을 통해 10 * 10 크기의 정사각형에 1을 더해주었다. 이후 반복문을 통해 배열에 0 이상인 값이 있는 경우에는 `cnt`를 세어 출력하였다.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n, x, y, cnt =0;
    int area[100][100] = {0};
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                area[k][j] += 1;
            }
        }
    }
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (area[i][j] > 0) {
                cnt++;
            }
        }
    } 
    
    printf("%d", cnt);
    
    return 0;
}
```

---

# Codeup 문제 정리

1차원 배열 : 1093, 1094, 1095
2차원 배열 : 1460*, 1466, 1470
함수 : 1532, 1535*, 1538, 1548, 1580
재귀함수 : 1852, 1859*, 1860, 1912, 1915, 1920*, 1954

---

## 1093 | 이상한 출석 번호 부르기1

[문제 링크](https://codeup.kr/problem.php?id=1093)

### 문제

정보 선생님은 수업을 시작하기 전에 이상한 출석을 부른다.

선생님은 출석부를 보고 번호를 부르는데,
학생들의 얼굴과 이름을 빨리 익히기 위해 번호를 무작위(랜덤)으로 부른다.

그리고 얼굴과 이름이 잘 기억되지 않는 학생들은 번호를 여러 번 불러
이름과 얼굴을 빨리 익히려고 하는 것이다.

출석 번호를 n번 무작위로 불렀을 때, 각 번호(1 ~ 23)가 불린 횟수를 각각 출력해보자.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d", &n);
    
    int input[n];
    int num[23];
    
    for (int i = 0; i < 23; i++) {
        num[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    
    for (int i = 0; i < n; i++) {
        num[input[i]-1]++;
    }
    
    for (int i = 0; i < 23; i++) {
        printf("%d ", num[i]);
    }
    
    return 0;
}
```

---

## 1094 | 이상한 출석 번호 부르기2

[문제 링크](https://codeup.kr/problem.php?id=1094)

### 문제

정보 선생님은 수업을 시작하기 전에 이상한 출석을 부른다.

학생들의 얼굴과 이름을 빨리 익히기 위해 번호를 무작위(랜덤)으로 부르는데,
영일이는 선생님이 부른 번호들을 기억하고 있다가 거꾸로 불러보는 것을 해보고 싶어졌다.

출석 번호를 n번 무작위로 불렀을 때, 부른 번호를 거꾸로 출력해 보자.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d", &n);
    
    int input[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", input[i]);
    }
        
    return 0;
}
```

---

## 1095 | 이상한 출석 번호 부르기3

[문제 링크](https://codeup.kr/problem.php?id=1095)

### 문제

정보 선생님은 오늘도 이상한 출석을 부른다.

영일이는 오늘도 다른 생각을 해보았다.
출석 번호를 다 부르지는 않은 것 같은데... 가장 빠른 번호가 뭐였지?

출석 번호를 n번 무작위로 불렀을 때, 가장 빠른 번호를 출력해 보자.

### 코드

```c
#include <stdio.h>

int main() {
    
    int n, min = 23;
    
    scanf("%d", &n);
    
    int input[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        if (input[i] < min) {
            min = input[i];
        }
    }

    printf("%d", min);
            
    return 0;
}
```

---

## 1460 | 2차원 배열 순서대로 채우기 1-1

[문제 링크](https://codeup.kr/problem.php?id=1460)

### 문제 

다음과 같은 n\*n 배열 구조를 출력해보자.

입력이 3인 경우 다음과 같이 출력한다.
1 2 3
4 5 6
7 8 9

입력이 5인 경우는 다음과 같이 출력한다.
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

입력이 n인 경우의 2차원 배열을 출력해보자.

### 풀이

`n * n` 크기의 배열을 선언한 뒤, 이중 반복문을 통해 배열의 각각의 공간에 `num`을 저장한 뒤 출력하고 `num`을 증가시키는 것을 반복하였다. 한 행이 끝나면 줄바꿈이 되도록 하였다.

### 코드

```c
#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);

    int arr[n][n];
    int num = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = num;
            printf("%d ", arr[i][j]);
            num++;
        }
        printf("\n");
    }

    return 0;
}
```

---

## 1466 | 2차원 배열 순서대로 채우기 1-7

[문제 링크](https://codeup.kr/problem.php?id=1466)

### 문제 

다음과 같은 n\*m 배열 구조를 출력해보자.

입력이 3 4인 경우 다음과 같이 출력한다.
12 9 6 3
11 8 5 2
10 7 4 1

입력이 4 5인 경우는 다음과 같이 출력한다.
20 16 12 8 4
19 15 11 7 3
18 14 10 6 2
17 13 9 5 1

입력이 n m인 경우의 2차원 배열을 출력해보자.

### 코드

```c
#include <stdio.h>

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = (n * (m - j)) - i;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 1470 | 2차원 배열 지그재그 채우기 2-3

[문제 링크](https://codeup.kr/problem.php?id=1470)

### 문제

다음과 같은 n\*n 배열 구조를 출력해보자.

입력이 3인 경우 다음과 같이 출력한다.
1 6 7
2 5 8
3 4 9

입력이 5인 경우는 다음과 같이 출력한다.
1 10 11 20 21
2 9 12 19 22
3 8 13 18 23
4 7 14 17 24
5 6 15 16 25

입력이 n인 경우의 2차원 배열을 출력해보자.

### 코드

```c
#include <stdio.h>

int main() {

    int n, num = 1;

    scanf("%d", &n);

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        if (!(i % 2)) {
            for (int j = 0; j < n; j++) {
                arr[j][i] = num++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                arr[j][i] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 1532 | 함수로 정수(long long int) -2147483649 리턴하기

[문제 링크](https://codeup.kr/problem.php?id=1532)

### 문제 

–2147483649 을 출력하시오.

단, 함수형 문제이므로 함수 f()만 작성하시오.

### 코드 

```c
long long int f() {
    return -2147483649LL;
}
```

---

## 1535 | 함수로 가장 큰 값 위치 리턴하기

[문제 링크](https://codeup.kr/problem.php?id=1535)

### 문제

배열에서 가장 큰 값이 처음 나타나는 위치를 출력하시오.

단, 함수형 문제이므로 함수 f()만 작성하시오.

### 풀이

반복문을 통해 각각의 원소를 비교하여 가장 큰 값을 찾았다. 다시 반복문으로 인덱스를 구해 출력하였다.

### 코드

```c
int f() {
    int tmp = d[0];

    for (int i = 0; i < n; i++) {
        if (d[i] > tmp) {
            tmp = d[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == tmp) {
            tmp = i;
            break;
        }
    }

    return tmp + 1;
}
```

---

## 1538 | 함수로 odd 또는 even 출력하기

[문제 링크](https://codeup.kr/problem.php?id=1538)

### 문제

odd 또는 even 을 출력하시오.

단, 함수형 문제이므로 함수 f()만 작성하시오.

### 코드

```c
void f(int n) {
    if (!(n % 2)) {
        printf("even");
    }
    else {
        printf("odd");
    }
}
```

---

## 1548 | 함수로 학점 리턴하기

[문제 링크](https://codeup.kr/problem.php?id=1548)

### 문제

다음과 같이, 점수를 입력 받아 학점을 출력하시오.

90 점 이상 ~ 100점 이하 : A
80 점 이상 ~ 90점 미만 : B
70 점 이상 ~ 80점 미만 : C
60 점 이상 ~ 70점 미만 : D
60 점 미만 : F 

단, 함수형 문제이므로 함수 grade()만 작성하여 제출하시오.

### 코드

```c
char grade(int n) {
    if (n >= 90) return 'A';
    else if (n >= 80) return 'B';
    else if (n >= 70) return 'C';
    else if (n >= 60) return 'D';
    else return 'F';
}
```

---

## 1580 | 원의 넓이

[문제 링크](https://codeup.kr/problem.php?id=1580)

### 문제

이 문제는 원의 넓이를 구하는 함수를 구현하는 문제입니다.

다음 조건을 참고해서 함수 본체만 작성해서 제출하시기 바랍니다.

함수명 : circle

매개 변수(parameter) : 반지름(r)을 나타내는 정수형(int) 변수 1개

반환 형(return type) : 실수형(float)

함수 내용 : 원의 넓이를 구하는 함수 구현 (원의 넓이 = 3.14×r×r)

### 코드

```c
float circle(int r) {
    return 3.14 * r * r;
}
```

---

## 1852 | 재귀로 1부터 n까지 한 줄로 출력하기

[문제 링크](https://codeup.kr/problem.php?id=1852)

### 문제 

한 정수 n을 입력받아 1부터 n까지 한 줄로 출력하시오.
(단, 반복문은 사용할 수 없다.)

### 코드

```c
#include <stdio.h>

void func(int n) {

    if (n == 1) {
        printf("1 ");
    } else {
        func(n - 1);
        printf("%d ", n);
    }
}

int main() {

    int n;

    scanf("%d", &n);

    func(n);

    return 0;
}
```

---

## 1859 | 별 삼각형 출력하기

[문제 링크](https://codeup.kr/problem.php?id=1859)

### 문제

한 정수 n을 입력받아 n층의 별 삼각형을 출력하시오.
(단, 반복문은 사용할 수 없다.)

### 풀이

`n`을 입력받아 `n`이 0이 될 때까지 `f(n-1)`을 실행하였다. `n`이 0이 되면 `star(n)`을 호출하는데, `star(n)` 또한 `n`이 0이 될 때까지 다시 호출된다. 반환되지 않은 `star` 함수는 `*`을 출력하게 되고, 하나의 `f(n)` 함수가 끝나게 되면 `\n`을 출력한다. 따라서 줄마다 별의 개수가 `n-1`, `n-2` ... 와 같은 식으로 출력된다.

### 코드

```c
#include <stdio.h>

void star(int n) {
    if(n <= 0) {
        return;
    }
  
    star(n-1);
    printf("*");
}

void f(int n) {
    if(n <= 0) {
        return;
    }

    f(n-1);
    star(n);
    printf("\n");
}

int main() {
    
    int n;

    scanf("%d", &n);
    f(n);

    return 0;
}
```

---

## 1860 | 수 삼각형 출력하기

한 정수 n을 입력받아 n층의 수 삼각형을 출력하시오.
(단, 반복문은 사용할 수 없다.)

### 문제

### 코드

## 1912 | 팩토리얼 계산

팩토리얼(!)은 다음과 같이 정의된다.

n!=n×(n−1)×(n−2)×⋯×2×1

즉, 5!=5×4×3×2×1=120이다.

n이 입력되면 n!의 값을 출력하시오.

### 문제

### 코드

## 1915 | 피보나치 수열

### 문제

피보나치 수열이란 앞의 두 수를 더하여 나오는 수열이다.

첫 번째 수와 두 번째 수는 모두 1이고, 세 번째 수부터는 이전의 두 수를 더하여 나타낸다. 피보나치 수열을 나열해 보면 다음과 같다.

1, 1, 2, 3, 5, 8, 13 …

자연수 N을 입력받아 N번째 피보나치 수를 출력하는 프로그램을 작성하시오.

### 코드

## 1920 | 2진수 변환

### 문제

어떤 10진수 n이 주어지면 2진수로 변환해서 출력하시오.

### 코드

## 1954 |

### 문제

길이 n이 입력되면 역삼각형을 출력한다.

예)

n이 5이면
```
*****
****
***
**
*
```

### 코드
