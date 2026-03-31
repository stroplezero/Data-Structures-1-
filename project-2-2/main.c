#include <stdio.h>

int main() {

	char str[30] = { 0 };
	int k = 0;

	printf("입력: ");
	fgets(str, sizeof(str), stdin);

	while (str[k] != 0) {
		if (str[k] >= 'A' && str[k] <= 'Z') {
			str[k] = str[k] + 32;
		}
		else if (str[k] >= 'a' && str[k] <= 'z') {
			str[k] = str[k] - 32;
		}
		k++;
	}
	printf("%s", str);

	return 0;
}
