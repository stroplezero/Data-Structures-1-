#define _CRT_SECURE_NO_WARNINGS

#include "calculator.h"

int main() {
	char sample[100];
	char postfix[100];

	printf("입력: ");
	scanf("%[^\n]s", sample);

	int i = 0;
	int j = 0;
	char temp[100] = { 0 };

	while (sample[i] != '\0') {
		if (!(sample[i] == ' ')) {
			temp[j] = sample[i];
			i++;
			j++;
		}
		else {
			i++;
		}
	}

	infixtoPostfix(temp, postfix);
	evalPostfix(postfix);
}
