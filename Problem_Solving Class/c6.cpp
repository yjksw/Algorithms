#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int numOfCard = 0;
	scanf("%d", &numOfCard);

	int cards[numOfCard];
	int incFromLeft[numOfCard];
	int incFromRight[numOfCard];
	int max = 0;

	fill_n(incFromLeft, numOfCard, 1);
	fill_n(incFromRight, numOfCard, 1);

	for(int i=0;i<numOfCard;i++) {
		scanf("%d", &cards[i]);
	}

	vector<int> v;

	for(int pick=0;pick<numOfCard;pick++) {

		if(v.empty() || v.back() < cards[pick]){
			v.push_back(cards[pick]);
			incFromLeft[pick] = v.size();
		}
		else {
			int left = 0;
			int right = v.size();
			int mid = 0;

			while(left<right) {
				mid = (left+right)/2;
				if(v[mid] < cards[pick]) 
					left = mid+1;
				if(v[mid] >= cards[pick]) 
					right = mid;
			}

			int in = left;
			v[in] = cards[pick];
			incFromLeft[pick] = in + 1;
		}

	}

	v.clear();

	for(int pick=numOfCard-1;pick>=0;pick--) {

		if(v.empty() || v.back() < cards[pick]){
			v.push_back(cards[pick]);
			incFromRight[pick] = v.size();
		}
		else {
			int left = 0;
			int right =  v.size();
			int mid = 0;

			while(left<right) {
				mid = (left+right)/2;
				if(v[mid] < cards[pick]) 
					left = mid+1;
				if(v[mid] >= cards[pick]) 
					right = mid;
			}

			int in = left;
			v[in] = cards[pick];
			incFromRight[pick] = in + 1;

		}

		if(incFromRight[pick] + incFromLeft[pick] > max)
			max = incFromRight[pick] + incFromLeft[pick];
	}
	
	/*for(int i=0;i<numOfCard;i++){
		printf("%d ", incFromRight[i]);
	}*/

	int ans = max - 1;

	printf("%d", ans);
	return 0;
}
