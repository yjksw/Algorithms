#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	fscanf(stdin, "%d", &n);

	int count[8];
	int value[8];
	count[0] = 1;

	int digit = 0;
	int num = 0;
	int temp = n;
	int result = 0;

	while(temp!=0){
		num = temp % 10;
		temp /= 10;
		value[digit] = num;
		digit++;
	}

	for(int i=1;i<digit-1;i++){
		count[i] = count[i-1]*9 + pow(10, i);
	}


	for(int i=digit-1;i>0;i--){
		if(value[i] > 4){
			result += (value[i]-1) * count[i-1] + pow(10, i);
		}
		else {
			result += value[i] * count[i-1];
		}
	}

	if(value[0] > 4) {
		result++;
	}
	
	fprintf(stdout, "%d", n-result);
	exit(0);
}
