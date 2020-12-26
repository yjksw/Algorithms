#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int totalDay = 0;
	int day = 0;
	int numTask = 0;
	int max = 0;

	scanf("%d %d %d", &totalDay, &day, &numTask);

	int tasks[totalDay+1];
	fill_n(tasks, totalDay + 1, 0);


	for(int i = 0 ; i < numTask ; i++) {

		int s = 0;
		scanf("%d", &s);

		tasks[s]++;

		if(tasks[s] > max) {
			max = tasks[s];
		}
	}

	int left = max / (day + 1);
	int right = max;
	int mid = 0;

	if(max % (day + 1) != 0) {
		left ++;
	}
	
	while(left < right) {
		
		int fail = 0;
		vector<int> remain;

		mid = (left + right) / 2;

		for(int d = 1; d <= totalDay ; d++) {
		
			int bulldozer = mid;
			remain.push_back(tasks[d]);
			
			while(bulldozer != 0 && !remain.empty()) {
			
				if(remain.front() > bulldozer) {
					remain[0] = remain.front() - bulldozer;
					bulldozer = 0;
				} else {
					bulldozer = bulldozer - remain.front();
					remain.erase(remain.begin());
				}
			}
			
			if(remain.size() > day) {
				fail = 1;
				break;
			}
		}

		if(fail == 1) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	printf("%d", left); 
	return 0;

}

