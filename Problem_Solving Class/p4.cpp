#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

vector<int> hanoi[4];

int hanoiTower(int diskNum, int from, int to) {
	hanoi[from].erase(hanoi[from].begin());

	if(diskNum == 1) {
		if(from == to){
			return 0;
		}
		return 1;
	}

	int newFrom = 0;
	for (int rodN=1;rodN<=3;rodN++){
		if(hanoi[rodN].front() == diskNum-1) {
			newFrom = rodN;
			break;
		}
	}

	if(from == to) {
		return hanoiTower(diskNum-1, newFrom, to); 
	}

	int newTo = 6 - (from+to);
	return hanoiTower(diskNum-1, newFrom, newTo) + (pow(2, diskNum-1)-1) + 1;
}

int main() {
	
	int numDisk;
	int src, dest;

	cin >> numDisk >> dest;

	for(int rod=1;rod<=3;rod++) {
		int count = 0;
		cin >> count;
		for(int disk=0;disk<count;disk++){
			int diskNum = 0;
			cin >> diskNum;	
			hanoi[rod].push_back(diskNum);
			if(diskNum == numDisk) {
				src = rod;
			}
		}
	}

	int answer = hanoiTower(numDisk, src, dest);
	cout << answer;
	
	exit(0);
}
