#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

int main() {

	int numBalloons;
	scanf("%d", &numBalloons);

	int pos[numBalloons];
	double radius[numBalloons];
	for(int i=0;i<numBalloons;i++){
		scanf("%d %lf", &pos[i], &radius[i]);
	}

	vector<double> storage;
	priority_queue<double> pq;
	pq.push(pos[0]+radius[0]);

	for(int index=1;index<numBalloons;index++){
		double curBalloon = pos[index] - radius[index];
		int check = index-1;
		while(pq.top() > curBalloon) {
			
			while(true) {
				if (pos[check]+radius[check] > curBalloon)
					break;
				check--;
			}

			double circum = ((pos[index]-pos[check])*(pos[index]-pos[check])) / (4.0 * radius[check]);
			radius[index] = circum < radius[index] ? circum:radius[index];

			check--;
			storage.push_back(pq.top());
			pq.pop();
			if(pq.empty())
				break;
		}

		while(!storage.empty()){
			pq.push(storage.back());
			storage.pop_back();
		}

		pq.push(pos[index]+radius[index]);
	}

	for(int i=0;i<numBalloons;i++){
		printf("%.3lf\n", radius[i]);
	}

	return 0;
}

