---
title: DLL Injection 기법
description: Windows 환경에서의 DLL Injection 기법 학습 내용 정리
categories:
    - Reversing
tags:
    - Reversing
date: 2025-03-06
---

## 목표

- **DLL Injection** 기법의 개념 이해와 공격 코드 작성

---

## DLL Injection이란?

다른 프로세스에 `DLL` 파일을 삽입하여 프로세스의 동작을 제어하거나 변조하는 기법이다.

`DLL` 파일이 프로세스에 로드되면 `DllMain` 함수가 실행되는데, 이를 이용하여 해당 함수에 악의적인 코드를 작성하여 동작을 제어하는 원리이다.

## DLL 파일 




