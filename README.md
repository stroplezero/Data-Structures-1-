분수 추상 자료형(ADT)

- 자료: 정수 분모와 정수 분자로 구성된 (분자, 분모)의 쌍
- 연산:
  change_from_f: 1개의 문자열 str를 A/B 꼴로 받아서 2개의 정수 num, den에 저장함.
  change_from_ab: 2개의 정수를 배열(temp)로 받아 A/B 꼴로 변환하여 1개의 문자열 out에 저장함.
  add: 2개의 분수(f1, f2)를 4개의 정수(num1, den1, num2, den2)로 분리하고 통분한 분모의 값과 통분한 분자끼리 합한 값을 각각 temp1, temp2에 저장함.
  minus: 2개의 분수(f1, f2)를 4개의 정수(num1, den1, num2, den2)로 분리하고 통분한 분모의 값와 통분한 분자끼리 뺀 값을 각각 temp1, temp2에 저장함.
  mult: 2개의 분수(f1, f2)를 4개의 정수(num1, den1, num2, den2)로 분리하고 분자끼리 분모끼리 각각 곱함.
  divid: 2개의 분수(f1, f2)를 4개의 정수(num1, den1, num2, den2)로 분리하고 f2의 역수를 f1에 분자끼리 분모끼리 각각 곱함.
  simplify: 2개의 정수(temp1, temp2)를 받아 두 수의 최대공약수로 각각 나눈 값을 다시 temp1, temp2에 저장함. 기약분수로 치완하기 위함.
