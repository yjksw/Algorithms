#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int ppl = 0;
	int time = 0;

	scanf("%d %d", &ppl, &time);
	int info[ppl][2];
	
	for(int i = 0 ; i < ppl ; i++) {
		scanf("%d %d", &info[i][0], &info[i][1]);		
	}

	int ans = ppl;
	for(int i = 0 ; i < ppl-1 ; i++) {
		if(info[i][1] == 1) 
			continue;
		int meet = 0;
		for(int j = i + 1 ; j < ppl ; j++) {
			if(info[i][1] > info[j][1]) {
				int groupWith = (info[j][0] - info[i][0]) / (info[i][1] - info[j][1]);
				if(groupWith <= time) {
					meet = 1;
					break;
				}
			}
		}
		if(meet == 1) {
			ans--;
		}
	}

	printf("%d", ans);
	return 0;
}
