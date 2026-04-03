# 피보나치의 시간 복잡도 분석 보고서

## 1. 피보나치 코드 링크
- main.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/main.c]
- my_math.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/my_math.c]
- my_math.h: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-4-2/my_math.h]

## 2. 피보나치의 시간 복잡도 분석
- 사용 알고리즘: 재귀적 방법(피보나치 수열) 
- 설명: 입력값 n에 대해 n번째 피보나치 수를 구하는 프로그램 F(n)을 재귀적 방법으로 구현하면, 가장 중요한 코드는 F(n)을 구하기 위해 반복해서 연산하는 코드이다.  
이 코드는 n이 1 증가할 때마다 자기 자신의 코드를 2번씩 추가로 더 호출하므로 2^n번 실행된다고 할 수 있다.  

 따라서 피보나치의 시간 복잡도는 O(2^n)의 시간 복잡도를 가진다고 할 수 있다.  

## 3. 프로파일링 분석
 GCD와 피보나치 수열의 시간 복잡도를 분석하기 위해 코드의 반복 횟수를 30번부터 2번씩 늘려 최종 50번까지 프로파일링을 각 횟수마다 3번씩 돌려 평균 시간을 계산하였다.  
(평균 시간은 몫이 알맞게 떨어지지 않는 경우, 소수점 아래 4번째 자리에서 반올림하여 소수점 아래 3자리까지 표현함.)

- 30번 돌린 결과
![30번 결과1](https://github.com/user-attachments/assets/c37bdbaf-1cc1-44af-883b-594025fae161)
![30번 결과2](https://github.com/user-attachments/assets/c3bb9bd7-235a-4cd3-88a5-b2611b039c92)
![30번 결과3](https://github.com/user-attachments/assets/b40eff9f-443f-4f4b-9c40-0d81855b3e74)

평균: 4.085초

- 32번 돌린 결과
![32번 결과1](https://github.com/user-attachments/assets/8756eb70-23c5-452f-988b-fd03bd20d566)
![32번 결과1](https://github.com/user-attachments/assets/2d828fc0-3bd6-4e0c-aa70-8fa7e7273895)
![32번 결과1](https://github.com/user-attachments/assets/cc913208-73c3-44ee-b1c7-c6c6b18211b6)

평균: 3.86초 

- 34번 돌린 결과
![34번 결과1](https://github.com/user-attachments/assets/307dd020-3679-4d57-a86e-0e7284924b97)
![34번 결과1](https://github.com/user-attachments/assets/c47fb1f4-c2f4-42ff-869b-3884248b9f1e)
![34번 결과1](https://github.com/user-attachments/assets/f5bf9cfa-7b16-43dd-97d3-87d217d8cada)

평균: 4.608초 

- 36번 돌린 결과
![36번 결과1](https://github.com/user-attachments/assets/0aa2e1f7-fa3a-4750-8520-2ab32273a810)
![36번 결과2](https://github.com/user-attachments/assets/3ca03c3f-00db-4a1e-8a17-1d2de409eebf)
![36번 결과3](https://github.com/user-attachments/assets/e61e87df-8666-496f-801d-5ccfd1dfb4b8)

평균: 6.146초

- 38번 돌린 결과
![38번 결과1](https://github.com/user-attachments/assets/35396867-4ca7-4b43-87dc-c6c139be2a10)
![38번 결과2](https://github.com/user-attachments/assets/9d5f7f6c-ad5b-4309-8b0d-e5c45ada308d)
![38번 결과3](https://github.com/user-attachments/assets/c735b7dd-6610-4d66-b4a9-6e9d8f0afdb8)

평균: 10.005초 

- 40번 돌린 결과
![40번 결과1](https://github.com/user-attachments/assets/77c04d20-c4f2-4566-82fe-5234c1dc3293)
![40번 결과2](https://github.com/user-attachments/assets/ae1a762b-2312-40d5-a93a-044572e130a8)
![40번 결과3](https://github.com/user-attachments/assets/7e4dab40-7987-4b8c-86f9-7ecef8f76b62)

평균: 21.81초 

- 42번 돌린 결과
![42번 결과1](https://github.com/user-attachments/assets/92f73d07-8d39-4d61-b7e4-959ebbdee39c)
![42번 결과2](https://github.com/user-attachments/assets/db805c46-030b-4b5a-bbc9-fbf11e3a7886)
![42번 결과3](https://github.com/user-attachments/assets/899bb4b9-3919-47ca-9c4f-ecaa3c601efb)

평균: 52.255초

- 44번 돌린 결과
![44번 결과1](https://github.com/user-attachments/assets/e0d48bcc-82d3-49c2-85c3-bb9de61d0d76)
![44번 결과2](https://github.com/user-attachments/assets/97b0d2d8-a901-4ac4-a463-f6f0d84e4654)
![44번 결과3](https://github.com/user-attachments/assets/c92eed51-04a2-4fdb-b2f1-363a5d8642da)

평균: 128.667초 (2분 8.887초)

- 46번 돌린 결과
![46번 결과1](https://github.com/user-attachments/assets/efe6d3cc-c0b9-469d-b6e5-dd50e3f13c13)
![46번 결과2](https://github.com/user-attachments/assets/8778f443-cac0-4513-8621-f94fa048d592)
![46번 결과3](https://github.com/user-attachments/assets/0d26f045-ea0f-455b-9b42-2308090f66aa)

평균: 319초 (5분 19초)

- 48번 돌린 결과
![48번 결과1](https://github.com/user-attachments/assets/5d8efbdd-2744-44a6-a6dc-c9d4b2b586e6)
![48번 결과2](https://github.com/user-attachments/assets/16dd78af-91a3-48dc-87ad-da0f471dc29a)
![48번 결과3](https://github.com/user-attachments/assets/13076bc2-08bf-4a17-917d-fb1b79712b60)

평균: 799초 (13분 19초)

- 50번 돌린 결과
![50번 결과1](https://github.com/user-attachments/assets/637a15d8-436c-4493-8666-ae9bd44564f5)
![50번 결과2](https://github.com/user-attachments/assets/1ace1da5-31eb-42b3-918f-feb9a6a4fa6a)
![50번 결과3](https://github.com/user-attachments/assets/52121b9d-23eb-4dd0-9a1a-281325622184)

평균: 2,110.667초 (35분 10.667초)

## 4. 피보나치의 시간 복잡도 검증
 분석 시간이 크게 차이나지 않는 30번부터 34번까지의 결과는 고려하지 않고, 34번부터 50번까지의 결과를 살펴보았다. 
 반복 횟수가 늘어날 때마다 각 시간이 얼마나 차이나는지 계산하여 정리해보면 다음 표와 같다. 

| 반복 횟수 | 시간 | 증가랑 | 증가 배수 |
| ------ | ---- | ------ | ------|
| 34 -> 36 | 4.608 -> 6.146 | +1.538 | 약 1.33배 |
| 36 -> 38 | 6.146 -> 10.005 | +3.859 | 약 1.63배 |
| 38 -> 40 | 10.006 -> 21.81 | +11.805 | 약 2.18배 |
| 40 -> 42 | 21.81 -> 52.255 | +30.445 | 약 2.40배 |
| 42 -> 44 | 52.255 -> 128.667 | +76.412 | 약 2.46배 |
| 44 -> 46 | 128.667 -> 319 | +190.333 | 약 2.48배 |
| 46 -> 48 | 319 -> 799 | +480 | 약 2.50배 |
| 48-> 50 | 799 -> 2110.667 | +1311.667 : 약 2.64배 |

 위의 표를 보면 초반 반복 횟수에서는 반복 횟수에 따른 시간 증가 배수가 점차 증가하고 있으나, 40회부터 일정한 비율로 매우 빠르게 시간이 증가함을 알 수 있다. 이에 대한 이유를 생각해보면 다음과 같다.  
 현재 알고리즘에서는 일정 수 이상으로 n이 커지면 피보나치 수를 구하는 알고리즘의 값이 지수적으로 커져 변수로 작용할 수 있는 다른 요소들(ex. 시스템 기본 세팅 시간 등)이 시간이 피보나치 수를 구하는 시간보다 매우 작아져 총 걸리는 시간에 영향을 미치지 않지만, n의 값이 작을 때에는 피보나치 수를 구하는 연산 시간이 매우 크지 않아 다른 요소들이 시간에 영향을 미쳤을 수 있다.  
 따라서 40회 이후의 시간 증가량을 계산하면 보다 정확한 피보나치의 시간 복잡도를 증명할 수 있다.

- 40회 이후의 시간 증가량 계산
 40회부터 이후의 시간 증가량의 평균을 계산해보면 약 2.496배로 1회가 늘어날 때마다 약 1.248배 늘어남을 알 수 있다.  
 따라서 피보나치 수열의 시간 복잡도를 구하면 O(2^n)임을 알 수 있다. 
