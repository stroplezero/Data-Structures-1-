#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdlib.h>

#include "linkedStack.h"

int main() {
	printf("[스택 메뉴]\n"
		"-----------------------------------------------------------------------\n"
		"1. URL 추가 : URL을 입력받아 스택에 URL을 추가\n"
		"2. URL 제거 : 스택에서 URL을 제거 및 출력\n"
	    "3. 스택 확인 : 현재 스택에 저장된 URL의 마지막 값을 출력\n"
		"-----------------------------------------------------------------------\n");

	int menuNum = 0;
	LinkedStack* mylinkedStack = createLinkedStack();

	int check = 1;

	while (check) {
		printf("[스택 메뉴] 번호 입력: ");
		scanf("%d", &menuNum);
		while (getchar() != '\n');

		char newURL[50] = { 0 };

		stackElement* temp;

		if (menuNum < 1 || menuNum > 3) {
			printf("1~3의 정수를 입력해주세요.\n");
		}
		else {
			switch (menuNum) {
			case(1):
				printf("1. [URL 추가] URL 입력: ");
				scanf("%s", newURL);
				while (getchar() != '\n');
				pushLinkedStack(mylinkedStack, newURL);
				printf("현재 창: ");
				temp = peekLinkedStack(mylinkedStack);
				printf("%s\n", *temp);

				break;

			case(2):
				printf("2. [URL 제거]\n이탈: ");
				temp = popLinkedStack(mylinkedStack);
				printf("%s\n", *temp);
				free(temp);

				if (peekLinkedStack(mylinkedStack) == NULL) {
					printf("브라우저가 종료되었습니다.");
					destroyLinkedStack(mylinkedStack);
					check = 0;
				}
				else {
					printf("현재 창: ");
					printf("%s\n", *peekLinkedStack(mylinkedStack));
				}

				break;

			case(3):
				printf("3. [스택 확인]\n현재 창: ");
				printf("%s\n", *peekLinkedStack(mylinkedStack));

				break;
			}
		}
	}
}
