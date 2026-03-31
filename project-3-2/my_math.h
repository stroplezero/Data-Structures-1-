typedef unsigned int my_math;

//두 정수(i, j)를 입력받으면 유클리드 호제법(Euclidean Algorithm)으로 최대공약수(GCD)를 구함
extern my_math get_gcd(my_math i, my_math j);

//두 정수(i, j)를 입력받으면 두 수를 곱한 후 최대공약수로 나누어 최소공배수(LCM)을 구함
extern my_math get_lcm(my_math i, my_math j);
