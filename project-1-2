#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

    int main() {
        float input;
        int bits[16] = { 0 }; 

        printf("입력값: ");
        scanf("%f", &input);

        float temp = (input < 0) ? -input : input;
        int i_part = (int)temp;
        float f_part = temp - i_part;

        for (int i = 7; i >= 0; i--) {
            bits[i] = i_part % 2;
            i_part /= 2;
        }

        for (int i = 8; i < 16; i++) {
            f_part *= 2;

            if (f_part >= 1) {
                bits[i] = 1;
                f_part -= 1;
            }
            else {
                bits[i] = 0;
            }
        }

        if (input < 0) {
           
            for (int i = 0; i < 16; i++) {
                bits[i] = (bits[i] == 0) ? 1 : 0;
            }

            for (int i = 15; i >= 0; i--) {
                if (bits[i] == 0) {
                    bits[i] = 1; 
                    break;
                }
                else {
                    bits[i] = 0;
                }
            }
        }

        for (int i = 0; i < 16; i++) {
            printf("%d", bits[i]);
            if (i == 7) printf("."); 
        }

        return 0;
    }
