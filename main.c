#include <stdio.h>
#include <math.h>

void convertbase10(int num) {
	//Converting Base 10 into Binary
	int originalNum = num; //Doing this for printf statements

	int binary[32];
	binary[0] = 0;
	bool isNegative = false;

	printf("%d in Base-2: ", originalNum);
	if (num < 0) {
		isNegative = true;
		binary[0] = 1;
		num *= -1;
		num--;
	}

	for (int i=31;i>=1;i--) {
		if (isNegative) {
			binary[i] = (num+1) % 2;
		}
		else {
			binary[i] = num % 2;
		}
		num = num / 2;
	}
	for (int i=0;i<32;i++) {
		printf("%d", binary[i]);
	}
	printf("\n");

	//Converting the binary into hexadecimal
	printf("%d in Hexadecimal: ", originalNum);

	char DIGITS[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char HEXADECIMAL[8];

	for (int i=0;i<32;i+=4) {
		int total = 0;
		int power = 0;
		for (int j=i+3;j>=i;j--) {
			if (binary[j] == 1) {
				total += pow(2,power);
			}
			power++;
		}
		HEXADECIMAL[i/4] = DIGITS[total];
	}
	for (int i=0;i<8;i++) {
		printf("%c", HEXADECIMAL[i]);
	}
	printf("\n");
}

int main() {
	int num = 0;
	printf("Enter a Base-10 number: ");
	scanf("%d", &num);
	convertbase10(num);
	return 0;
}

