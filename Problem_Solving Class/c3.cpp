#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


void findPath(vector<int> roadInfo[], int distanceInfo[], int from, int numCity){
	int visit[numCity+1];
	queue<int> bfsQ;
	vector<int>::iterator it;
	
	std::fill_n(visit, numCity+1, 0);
	bfsQ.push(from);
	visit[from] = 1;

	while(!bfsQ.empty()){
		int currCity = bfsQ.front();
		bfsQ.pop();
		for(it = roadInfo[currCity].begin(); it!=roadInfo[currCity].end(); ++it){
			if(visit[*it] == 1)
				continue;
			visit[*it] = 1;
			distanceInfo[*it] = distanceInfo[currCity] + 1;
			bfsQ.push(*it);
		}
	}
}

void calFuel(int distanceInfo[], int fuel, int numCity){
	for(int i=1;i<=numCity;i++){
		distanceInfo[i] *= fuel;
	}
}

int main() {
	
	int p, q, r;
	int n, m;

	cin >> p >> q >> r;
	cin >> n >> m;
	
	vector<int> road[n+1];

	for(int i=1;i<=m;i++){
		int input[2];
		cin >> input[0] >> input[1];
		
		road[input[0]].push_back(input[1]);
		road[input[1]].push_back(input[0]);
	}

	int fromAlpha[n+1];
	int fromBeta[n+1];
	int toDest[n+1];

	int min = -1; 

	std::fill_n(fromAlpha, n+1, 0);
	std::fill_n(fromBeta, n+1, 0);
	std::fill_n(toDest, n+1, 0);

	findPath(road, fromAlpha, 1, n);
	findPath(road, fromBeta, 2, n);
	findPath(road, toDest, n, n);

	calFuel(fromAlpha, p, n);
	calFuel(fromBeta, q, n);
	calFuel(toDest, r, n);

	for(int i=1;i<=n;i++){
		int totalFuel = fromAlpha[i] + fromBeta[i] + toDest[i];
		if(totalFuel<min || min<0){
			min = totalFuel;
		}
	}

	cout << min;
	exit(0);
}
