#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

struct compare {
	bool operator() (int a, int b) 
	{
		if(abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}
		return a > b;
	}
};

int main() {
	int n = 0;
	scanf("%d", &n);

	priority_queue<int, vector<int>, compare > pq; 
	int num;

	for (int i = 0 ; i < n; i++) {
		scanf("%d", &num);
		if (num == 0) {
			if(pq.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		} else { 
			pq.push(num);
		}
	}

	return 0;
}
