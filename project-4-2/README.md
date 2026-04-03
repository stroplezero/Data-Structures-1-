# GCD와 피보나치 수열의 시간 복잡도 분석 보고서

## 1. 피보나치 수열 코드 구현
- main.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/main.c]
- my_math.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/my_math.c]
- my_math.h: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/my_math.h]

## 2. 피보나치 수열의 시간 복잡도 분석
- 사용 알고리즘: 재귀적 방법(피보나치 수열) 
- 설명: 입력값 n에 대해 n번째 피보나치 수를 구하는 프로그램 F(n)을 재귀적 방법으로 구현하면, 가장 중요한 코드는 F(n)을 구하기 위해 반복해서 연산하는 코드이다.  
이 코드는 n이 1 증가할 때마다 자기 자신의 코드를 2번씩 추가로 더 호출하므로 2^n번 실행된다고 할 수 있다.  

따라서 피보나치 수열의 시간 복잡도는 O(2^n)의 시간 복잡도를 가진다고 할 수 있다.  

## 2. 프로파일링 분석
 GCD와 피보나치 수열의 시간 복잡도를 분석하기 위해 코드의 반복 횟수를 30번부터 2번씩 늘려 프로파일링을 각 횟수마다 3번씩 돌려 평균 시간을 계산하였다. 

![30번 결과1](https://github.com/user-attachments/assets/c37bdbaf-1cc1-44af-883b-594025fae161)
