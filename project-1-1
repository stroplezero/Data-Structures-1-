#include <stdio.h>

int main() {

	char a = -5;							// 임의로 음수 저장. char를 사용하는 이유는 8비트로 제한하기 위함.
	unsigned char ua = (unsigned char)a;	// unsiged로 형변환을 사용하여, -5의 비트를 부호 없이 읽은 값을 ua에 저장함.

	if (ua == 250) {						// 컴퓨터가 -5를 1의 보수로 저장했다면, 비트를 부호 없이 읽은 값이 250이 되므로 이를 비교함. 
		printf("1의 보수입니다.");
	}

	else if (ua == 251) {					// 컴퓨터가 2의 보수로 저장했다면, 비트를 부호 없이 읽은 값이 251이 되므로 이를 비교함. 
		printf("2의 보수입니다.");
	}

	return 0;
}
