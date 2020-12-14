#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	
	int num = 0;
	scanf("%d", &num);

	int cable[num];
	for(int i=0;i<num;i++) {
		scanf("%d", &cable[i]);
	}
	
	vector<vector<long long> > memo(num+1, vector<long long>(num+1, 0));
	vector<long long> addUp(num+1, 0);

	for(int i=1;i<=num;i++){
		addUp[i] = addUp[i-1] + cable[i-1]; 
	}
	
	int maxStep = num - 1;
	for(int step=1;step<=maxStep;step++) {
		for(int start=1;start+step<=num;start++) {
			int end = start + step;
			long long minValue = -1;
			for(int breakPoint=start;breakPoint<end;breakPoint++) {
				long long hours = memo[start][breakPoint] + memo[breakPoint+1][end] + addUp[end] - addUp[start-1];
				if(minValue < 0) {
					minValue = hours; 
				} else {
					minValue = min(minValue, hours);
				}
			}
			memo[start][end] = minValue;
		}
	}

	printf("%lld", memo[1][num]);
	return 0;
}
