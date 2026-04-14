# 피보나치 수열 순환적 방법과 재귀적 방법 분석 및 비교
## 1. 개요
본 md는 피보나치 수열을 **재귀적 방법**과 **순환적 방법**으로 구현하고, 정수 N이 1부터 차례대로 증가함에 따른 수행 시간을 비교 분석한 결과이다.

## 2. 코드 구현
### 2-1. 재귀적 방법
시간 복잡도: O(2^n)
링크: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-8-1/main.c]

### 2-2. 순환적 방법
시간 복잡도: O(n)
링크: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-8-2/main.c]

## 3. 수행 시간 프로파일링 결과
각 방법을 최대로 반복하기 위해 재귀적 방법은 N을 100으로 잡아 최대치까지 수행해보았고, 순환적 방법은 N을 각각 100과 1000으로 잡아 수행 시간을 프로파일링해보았다.

### 3-1. 재귀적 방법 프로파일링 결과
[!재귀 50번째 중단]https://github.com/user-attachments/assets/8fab3b19-60a9-4fec-8788-f953b23e63ad
