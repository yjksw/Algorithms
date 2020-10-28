#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int numOfCard = 0;
	scanf("%d", &numOfCard);

	int cards[numOfCard];
	vector<int> v;

	for(int i=0;i<numOfCard;i++) {
		scanf("%d", &cards[i]);
	}


	for(int pick=0;pick<numOfCard;pick++) {

		if(v.empty() || v.back() < cards[pick])
			v.push_back(cards[pick]);
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

			v[left] = cards[pick];
		}
	}


	int ans = v.size();

	printf("%d", ans);
	return 0;
}
