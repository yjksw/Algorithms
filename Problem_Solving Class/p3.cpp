#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int m, n;
	cin >> m;

	int carriers = 0;
	int count[m];
	std::fill_n(count, m, 0);

	while(cin >> n){
		if(n==m)
			carriers++;
		else
			count[n]++;
	}

	for(int i=1;i<=m/2;i++){
		if(i == (m-i)){
			carriers += count[i]/2;
			carriers += count[i]%2;
		}
		else if(count[i]>=count[m-i]){
			carriers += count[m-i];
			count[i] -= count[m-i];
			if(i!=m/2)
				count[i+1] += count[i];
			else
				carriers = carriers + count[i]/2 + count[i]%2;
		}
		else if(count[i]<count[m-i]){
			carriers += count[i];
			count[m-i] -= count[i];
			carriers += count[m-i];
		}
	}

	cout << carriers;
	exit(0);
}
