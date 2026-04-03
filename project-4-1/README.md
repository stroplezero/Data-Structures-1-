# GCD 알고리즘 복잡도 분석 보고서

## 1. 코드 링크
- main.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-3-2/main.c]
- my_math.c: [https://github.com/stroplezero/Data-Structures-1-/blob/main/project-3-2/my_math.c]
- my_math.h: []

## 2. 시간 복잡도 분석
- 사용 알고리즘: 유클리드 호제법
- 설명: 유클리드 호제법으로 GCD를 계산할 경우, 가장 핵심적인 코드 한줄은 i과 j의 GCD를 구하는 코드에서 i와 j를 나머지 연산을 하는 코드이다.  
  이 코드는 1회 실행될 때마다 결과값이 원래 코드의 값보다 절반 이하로 떨어지기 때문에 입력값이 커져도 실행횟수는 그의 절반으로 커지는 log n번으로 실행된다.

  따라서 GCD를 구하는 코드의 시간 복잡도는 O(log n)의 시간 복잡도를 가진다고 할 수 있다. 
