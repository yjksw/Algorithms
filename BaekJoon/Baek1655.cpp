#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {

	int n = 0;
	scanf("%d", &n);

	priority_queue<int, vector<int>, less<int> > leftQ;
	priority_queue<int, vector<int>, greater<int> > rightQ;

	for (int i = 0; i < n; i++) {
		int input = 0;
		scanf("%d", &input);

		if (leftQ.size() == rightQ.size()) {
			leftQ.push(input);
		} else if(rightQ.size() < leftQ.size()) {
			rightQ.push(input);
		}

		if (!rightQ.empty() && leftQ.top() > rightQ.top()) {
			int temp = leftQ.top();
			leftQ.pop();
			leftQ.push(rightQ.top());
			rightQ.pop();
			rightQ.push(temp);
		}

		printf("%d\n", leftQ.top());
	}
}
