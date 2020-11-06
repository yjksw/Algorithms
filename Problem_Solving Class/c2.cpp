#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 500

int n;
int maxAltitude = -1;
int minAltitude = -1;
int maxOfAll = 0;
int region[MAX][MAX];
int difficulty[MAX][MAX];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
bool possibleMax = false;

int dfs(int cellX, int cellY){
	bool end = true; 

	if(difficulty[cellX][cellY] != -1)
		return difficulty[cellX][cellY];


	for(int i=0;i<4;i++){
		int nextX = cellX+moveX[i];
		int nextY = cellY+moveY[i];
		if(nextX<0 || nextX>=n || nextY<0 || nextY>=n)
			continue;
		if(region[nextX][nextY] < region[cellX][cellY]){
			end = false;
			int curDiff = region[cellX][cellY] - region[nextX][nextY] + dfs(nextX, nextY);
			difficulty[cellX][cellY] = difficulty[cellX][cellY] > curDiff ? difficulty[cellX][cellY]:curDiff;
			if(possibleMax == true)
				break;
		}
	}
	
	if(end==true){
		difficulty[cellX][cellY] = 0;
		return 0;
	}
	if(difficulty[cellX][cellY] == (maxAltitude-minAltitude))
		possibleMax = true;
	return difficulty[cellX][cellY];
}

int main(){
	cin >> n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> region[i][j];
			if(region[i][j]>maxAltitude || maxAltitude<0){
				maxAltitude = region[i][j];
			}
			if(region[i][j]<minAltitude || minAltitude<0){
				minAltitude = region[i][j];
			}
		}
	}

	std::fill_n(difficulty[0], MAX*MAX, -1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(possibleMax == true)
				break;
			if(region[i][j]-minAltitude <= maxOfAll)
				continue;
			int answer = dfs(i, j);
			if(answer > maxOfAll)
				maxOfAll = answer;
		}
		if(possibleMax == true)
			break;
	}

	cout << maxOfAll;
	exit(0);
}
