typedef unsigned int my_fraction;

//1개의 문자열 str를 A/B 꼴로 받아서 2개의 정수 num, den에 저장함 
extern void change_from_f(const char *str, int *num, int *den);

//2개의 정수를 분수 자료형에서 A/B 꼴로 변환하여 1개의 문자열 str에 저장함 
extern void change_from_ab(const int* temp, char* out);

//4개의 정수 num1, den1, num2, den2를 받아 사칙연산을 수행함
extern void add(int num1, int den1, int num2, int den2, int* temp1, int* temp2);
extern void minus(int num1, int den1, int num2, int den2, int* temp1, int* temp2);
extern void mult(int num1, int den1, int num2, int den2, int* temp1, int* temp2);
extern void divid(int num1, int den1, int num2, int den2, int* temp1, int* temp2);

//2개의 정수를 받아 최대공약수로 나누어 기약분수로 변환함
extern void simplify(int* temp1, int* temp2);
