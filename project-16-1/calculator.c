#include "calculator.h"
#include "arrayStack.h"

int infixtoPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	printf("\n출력:\n");
	printf("Transform:\n");

	for (int i = 0; infix[i] != '\0'; i++) {

		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];

			j++;
		}

		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j] = popArrayStack(opStack).operator;
					j++;
				}
				else {
					break;
				}
			}

			pushArrayStack(opStack, (stackElement) { .operator = infix[i] });
		}
		else if (infix[i] == '(') {
			pushArrayStack(opStack, (stackElement) { .operator = infix[i] });
		}
		else if (infix[i] == ')') {
			do {
				stackElement prevOp = popArrayStack(opStack);

				if (prevOp.operator != '(') {
					postfix[j] = prevOp.operator;
					j++;
				}
				if (prevOp.operator == '(') {
					break;
				}
			} while (!emptyArrayStack(opStack));
		}

		printf("- Postfix: ");
		for (int k = 0; k < j; k++) {
			printf("%c ", postfix[k]);
		}

		printf("|Stack: ");
		for (int k = 0; k <= opStack->top; k++) {
			printf("%c ", opStack->data[k].operator);
		}

		printf("\n");
	}

	while (!emptyArrayStack(opStack)) {
		postfix[j] = popArrayStack(opStack).operator;
		j++;
	}

	postfix[j] = '\0';

	printf("- Postfix: ");
	for (int i = 0; postfix[i] != '\0'; i++) {
		printf("%c ", postfix[i]);
	}
	printf("|Stack: ");
	for (int k = 0; k <= opStack->top; k++) {
		printf("%c ", opStack->data[k].operator);
	}
	printf("\n\n");

	printf("- Result: ");
	for (int i = 0; postfix[i] != '\0'; i++) {
		printf("%c ", postfix[i]);
	}
	printf("\n\n");

	return 1;
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	printf("Eval:\n");
	printf("- Postfix: ");
	for (int i = 0; postfix[i] != '\0'; i++) {
		printf("%c ", postfix[i]);
	}
	printf("\n");

	while (postfix[i] != '\0') {
		printf("- Current: %c ", postfix[i]);
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			pushArrayStack(valueStack, (stackElement) { .value = postfix[i] - '0' });
		}
		else if (postfix[i] == '*') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;

			pushArrayStack(valueStack, (stackElement) { .value = i1 * i2 });
		}
		else if (postfix[i] == '/') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;

			pushArrayStack(valueStack, (stackElement) { .value = i2 / i1 });
		}
		else if (postfix[i] == '+') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;

			pushArrayStack(valueStack, (stackElement) { .value = i1 + i2 });
		}
		else if (postfix[i] == '-') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;

			pushArrayStack(valueStack, (stackElement) { .value = i2 - i1 });
		}

		printf("|Stack: ");
		for (int k = 0; k <= valueStack->top; k++) {
			printf("%d ", valueStack->data[k].value);
		}
		printf("\n");

		i++;
	}

	printf("\n- Result: ");
	for (int i = 0; i <= valueStack->top; i++) {
		printf("%d ", valueStack->data[i].value);
	}
	printf("\n\n");

	return popArrayStack(valueStack).value;
}

int precedence(char op) {

	switch (op) 
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	}
}
