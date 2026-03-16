#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float input;
    int bits[32] = { 0 };

    printf("입력값: ");
    scanf("%f", &input);

    float value = (input < 0) ? -input : input;

    if (input < 0) {
        bits[0] = 1;
    }

    if (value == 0.0f) {
        printf("결과: ");
        for (int i = 0; i < 32; i++) {
            printf("%d", bits[i]);
            if (i == 0) printf("//");
            if (i == 8) printf("//");
        }
        printf("\n");
        return 0;
    }

    int num = 0;
    if (value >= 2.0) {
        while (value >= 2.0) { value /= 2; num++; }
    }
    else if (value< 1.0) {
        while (value < 1.0) { value *= 2; num--; }
    }

    num = num + 127;
    
    for (int i = 8; i >= 1; i--) {
        bits[i] = num % 2;
        num /= 2;
    }

    int temp = 0;

    value = value - 1.0;
    for (int i = 9; i <= 31; i++) {
        value = value * 2;
        bits[i] = (int)(value);
        if (value >= 1.0) value -= 1.0;
    }

    printf("결과: ");
    for (int i = 0; i < 32; i++) {
        printf("%d", bits[i]);
        if (i == 0) printf("/");
        else if (i == 8) printf("/");
        else if (i > 2 && i % 4 == 0) printf(" ");
    }
    printf("\n");

    return 0;
}
