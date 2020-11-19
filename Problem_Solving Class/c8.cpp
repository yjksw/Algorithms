#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
	return a.second < b.second;
}

int main() {

	int numVillage = 0;
	double distance = 0;

	scanf("%d %lf", &numVillage, &distance);

	vector<pair<double, double> > pos(numVillage);
	vector<pair<double, double> > range(numVillage);
	stack<double> check; 

	for(int i = 0 ; i < numVillage ; i++) {
		scanf("%lf %lf", &pos[i].first, &pos[i].second);

		double d = sqrt((distance * distance) - (pos[i].second * pos[i].second));
		range[i].first = pos[i].first - d;
		range[i].second = pos[i].first + d;
	}

	sort(range.begin(), range.end(), cmp); 

	for(int i = 0 ; i < numVillage ; i++) {
		if(check.empty() || (range[i].first > check.top())) {
			check.push(range[i].second);
		}
	}

	int wells = check.size();
	printf("%d", wells);
	return 0;
}
