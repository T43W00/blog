---
title: Layer7 5차시
description: Layer7 5차시 과제 정리
categories:
    - Layer7
tags:
    - Layer7
date: 2025-04-16
---

## 수업 내용 정리

### 구조체란?
서로 다른 자료형을 갖는 자료들의 집합이다. 배열과 달리 같은 자료형이 아닌 서로 다른 자료형을 사용할 수 있다는 것이 특징이다.


#### 선언 방법 

아래와 같이 선언할 수 있다.

```c
struct structure {
    int number;
    char string[10];
};
```

만약 선언한 구조체 변수를 사용하려면 아래와 같이 선언할 수 있다.

```c
struct structure {
    int number;
    char string[10];
};

struct structure s1, s2, s3;
```

혹은 구조체 선언과 같이 구조체 변수 또한 선언할 수 있다.

```c

struct structure {
    int number;
    char string[10];
} s1, s2, s3;
```

#### 구조체 멤버 초기화

구조체는 초기값이 주어지지 않은 경우 그 값이 0으로 초기화된다.

#### 구조체 멤버의 활용

구조체 멤버로는 배열이나 포인터와 같은 변수도 포함할 수 있다.

```c
struct student {
    char name[20];
    char *intro;
} sunrin;

int main() {

    sunrin.intro = (char *)malloc(80);

    strcpy(sunrin.name, "Sunrin Kim");
    gets(sunrin.intro);

    printf("%s\n%s", sunrin.name, sunrin.intro);

    free(sunrin.intro);
    
    return 0;
}
```

#### typedef를 이용한 형 재정의

`typedef`를 이용하여 형을 재정의하면 비교적 간단하게 자료형을 선언할 수 있다.

```c
struct student {
    char name[20];
    int age;
} sunrin;

typedef struct student stu;

int main() {
    stu s1 = {"sunrin", 17};
    printf("이름 : %s\n", s1.name);
    printf("나이 : %d", s1.age);

    return 0;
}
```

선언과 동시에 재정의 또한 가능하다.

```c
typedef struct student {
    char name[20];
    int age;
} stu;

typedef struct student stu;

int main() {
    stu s1 = {"sunrin", 17};
    printf("이름 : %s\n", s1.name);
    printf("나이 : %d", s1.age);

    return 0;
}

```

#### 구조체 배열

구조체 배열을 통해 하나의 연속된 구조체 변수를 선언할 수 있다.

```c
typedef struct student {
    int num;
    char name[20];
    int score;
} stu;

int main() {
    stu s1[3] = {
        {10100, "Kim", 100},
        {10200, "Lee", 74},
        {10300, "Pak", 86}
    };

    for (int i = 0; i < 3; i++) {
        printf("%d %s %d점\n", s1[i].num, s1[i].name, s1[i].score);
    }

    return 0;
}
```

#### 구조체 포인터와 -> 연산자

구조체 포인터에 -> 연산자를 사용하면 바로 해당 구조체의 멤버에 접근할 수 있다.

```c
typedef struct student {
    int num;
    char name[20];
} stu;

int main() {
    stu s1 = {10100, "Kim"};
    stu *ptr = &s1;

    printf("%d %s\n", ptr->num, ptr->name);

    return 0;
}
```

---

## Codeup 문제 정리

### 1805 | 입체기동장치 생산공장

[문제 링크](https://codeup.kr/problem.php?id=1805)

#### 문제

입체기동장치 생산공장에서는 거인들을 물리치기 위한 기계가 생산되고 있습니다.

이 공장을 운영하는 에렌은 입체기동장치(1~100)의 식별번호(1~100)와 가스 보유량(0~10000)을 같이 관리하려고 합니다.

하지만, 식별번호를 정렬할 때 가스 보유량이 뒤죽박죽 되어 버려 골머리를 앓고 있습니다.

에렌을 남몰래 좋아하고 있던 미카사는 에렌이 스트레스성 탈모로 잔머리가 모두 빠지기 전에 이 문제를 해결해주려 합니다.

미카사가 에렌의 스트레스성 탈모를 막을 수 있도록 프로그램을 작성하세요.

식별번호가 한번 정해지면 그 입체기동장치의 가스 보유량은 정렬되더라도 변하지 않아야 합니다.

#### 풀이

먼저 식별번호와 가스 보유량을 포함한 구조체 배열을 선언한 뒤, 입체기동장치의 개수만큼 반복문을 통해 입력받았다.

식별 번호 순으로 정렬한 뒤 출력하였다.

#### 코드

```c
#include <stdio.h>

struct VME {
    int num;
    int gas;
} a[100], tmp;

int main() {
    
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
      scanf("%d %d", &a[i].num, &a[i].gas);
  }

  for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
          if (a[i].num > a[j].num) {
              tmp = a[i];
              a[i] = a[j];
              a[j] = tmp;
          }
      }
  }

  for (int i = 0; i < n; i++) {
      printf("%d %d\n", a[i].num, a[i].gas);
  }

  return 0;
}
```

---

### 4012 | 석차 계산

[문제 링크](https://codeup.kr/problem.php?id=4012)

#### 문제

정렬되지 않은 학생들의 임의의 점수를 입력하여 석차를 계산하는 프로그램을 작성하시오. 점수는 동점이 있을 수 있으며, 이러한 경우 같은 석차로 처리한다. 예를 들어 5명의 점수 100, 90, 76, 60, 90이 입력되었다면 석차는 2등이 2명이고 3등은 없다. (단, 점수가 가장 높은 학생을 1등으로 한다.)

#### 풀이

먼저 `score`와 `rank`라는 멤버를 가진 구조체 배열 `stu`와 이를 정렬할 복사본 `sorted`를 선언하였다.

두 배열에 `n` 만큼 점수를 입력받고, `sorted` 배열에는 점수에 따라 정렬하였다.

이후 `sorted` 배열에 인덱스를 `rank`에 저장하고 `stu` 배열과 `sorted` 배열 중 같은 점수를 가진 구조체는 `sorted`의 `rank`를 `stu`의 `rank`에 복사해주었다.

#### 코드

```c
#include <stdio.h>

typedef struct {
  int score;
  int rank;
} student;


int main() {

  student stu[200], sorted[200];

  int n, tmp;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &stu[i].score);
    sorted[i].score = stu[i].score;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (sorted[j].score > sorted[i].score) {
        tmp = sorted[j].score;
        sorted[j].score = sorted[i].score;
        sorted[i].score = tmp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    sorted[i].rank = i + 1;
  }

  for (int i = 0; i < n; i++) {
    if (sorted[i].score == sorted[i+1].score) {
      sorted[i+1].rank = sorted[i].rank;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (stu[i].score == sorted[j].score) {
        stu[i].rank = sorted[j].rank;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", stu[i].score, stu[i].rank);
  }

  return 0;
}
```

---

## 창작 문제 | 회계 관리 시스템

### 문제

Layer7는 동아리 부원들의 지출 내역을 정리하고자 한다.  
부원마다 여러 건의 지출 내역이 있으며, 각 지출은 항목명, 금액, 날짜로 이루어져 있다.  
모든 부원은 정보를 입력받아 각 회원의 총 지출을 출력하고, 가장 지출이 많은 부원을 찾아 출력하는 프로그램을 작성하시오.

### 풀이

지출 내역을 저장할 구조체인 `details`와 지출 내역을 비롯한 회원들의 정보를 저장할 `info` 구조체를 선언하였다.

회원 수를 입력받아 동적으로 `user` 구조체의 메모리를 할당해주었고, 각각의 정보들을 입력받았다.

만약 지출 내역 수가 1 이상이면 지출 내역을 입력받고, 각각의 회원들의 총 지출 금액을 `sum`이라는 멤버에 저장하였다.

`sum` 멤버를 기준으로 내림차순으로 정렬한 뒤 최고 지출자를 출력하였다.

### 코드

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char item[100];
  int price;
  char date[10];
} details;

typedef struct {
  char name[100];
  int id;
  int num;
  int sum;
  details *detail;
} info;

void sort(info user[], int n) {
  info tmp;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (user[j].sum > user[i].sum) {
        tmp = user[j];
        user[j] = user[i];
        user[i] = tmp;
      }
    }
  }
}

int main() {

  int n;

  printf("회원 수를 입력하세요 : ");
  scanf("%d", &n);

  info *user = (info *)malloc(n * sizeof(info));

  for (int i = 0; i < n; i++) {
    printf("\n[%d번째 회원 정보 입력 ]\n", i + 1);
    
    printf("이름 : ");
    scanf("%s", (user + i) -> name);

    printf("학번 : ");
    scanf("%d", &((user + i) -> id));

    printf("지출 내역 수 : ");
    scanf("%d", &((user + i) -> num));
    
    if ((user + i) -> num > 0) {

      (user + i) -> detail = (details *)malloc(((user + i) -> num) * sizeof(details));

      for (int j = 0; j < (user + i) -> num; j++) {

        printf("\n\t[%d번째 지출 내역]\n", j + 1);

        printf("\t항목명 : ");
        scanf("%s", ((user + i) -> detail + j) -> item);

        printf("\t금액 : ");
        scanf("%d", &(((user + i) -> detail + j) -> price));

        printf("\t날짜 (YYYY-MM-DD): ");
        scanf("%s", (((user + i) -> detail + j) -> date));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (user + i) -> num; j++) {
       (user + i) -> sum += ((user + i) -> detail + j) -> price; 
    }
  }

  sort(user, n);

  for (int i = 0; i < n; i++) {
    printf("\n회원 : %s | 학번 : %d | 총 지출 : %d원\n", (user + i) -> name, (user + i) -> id, (user + i) -> sum);
  }

  printf("\n[최고 지출자]\n");
  printf("이름 : %s\n", user -> name);
  printf("학번 : %d\n", user -> id);
  printf("총 지출 : %d", user -> sum);
  
  return 0;
}
```
