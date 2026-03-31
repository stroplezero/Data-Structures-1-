#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float input;
    int bits[16] = { 0 };

    printf("입력값: ");
    scanf("%f", &input);

    float scaled = input * 256;
    int value = (int)scaled;

    int temp = (value < 0) ? -value : value;

    for (int i = 15; i >= 0; i--) {
        bits[i] = temp % 2;
        temp /= 2;
    }

    if (value < 0) {
        for (int i = 0; i < 16; i++) {
            bits[i] = (bits[i] == 0) ? 1 : 0;
        }

        for (int i = 15; i >= 0; i--) {
            if (bits[i] == 0) {
                bits[i] = 1; 
                break;
            } else {
                bits[i] = 0; 
            }
        }
    }

    printf("결과: ");
    for (int i = 0; i < 16; i++) {
        printf("%d", bits[i]);
        if (i == 7) printf(".");
    }
    printf("\n");

    return 0;
}
