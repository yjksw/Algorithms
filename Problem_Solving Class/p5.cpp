#include <stdio.h>
#include <iostream>

using namespace std;

int binSearch(int func[][2], int size, int num) {
	int left = 1;
	int right = size+1;
	int mid = 0;

	while(left<right){
		mid = (left+right)/2;
		
		if(func[mid][0] <= num) {
			left = mid+1;
		} else {
			right = mid;
		}
	}

	return left;
}

int main() {
	int initial = -2000000001;
	int last = 2000000001;
	int mod = 10007;


	int numPointF = 0;
	cin >> numPointF; 
	int f[numPointF+2][2];
	f[0][0] = initial;
	f[0][1] = 0;
	f[numPointF+1][0] = last;
	f[numPointF+1][1] = 0;
	for(int i=1;i<=numPointF;i++){
		cin >> f[i][0] >> f[i][1];
	}

	int numPointG = 0;
	cin >> numPointG;
	int g[numPointG+2][2];
	g[0][0] = initial;
	g[0][1] = 0;
	g[numPointG+1][0] = last;
	g[numPointG+1][1] = 0;
	for(int i=1;i<=numPointG;i++){
		cin >> g[i][0] >> g[i][1];
	}

	int pq[2];
	cin >> pq[0] >> pq[1];

	int posF = binSearch(f, numPointF, pq[0]) - 1;
	int posG = binSearch(g, numPointG, pq[0]) - 1;
	int posPQ = pq[0];
	int next = 0;
	int sum = 0;

	while(posPQ <= pq[1]){
		
		next = (f[posF+1][0] < g[posG+1][0]) ? f[posF+1][0] : g[posG+1][0];
		if(next > pq[1])
			next = pq[1]+1;

		if(f[posF][1]>g[posG][1]){
			sum += ((f[posF][1] % mod) * (next%mod-posPQ%mod)) % mod;
		} else 
			sum += ((g[posG][1] % mod) * (next%mod-posPQ%mod)) % mod;

		posPQ = next;
		
		if(f[posF+1][0] <= next)
			posF++;
		if(g[posG+1][0] <= next)
			posG++; 
	}

	sum = sum % mod;
	cout << sum;
	exit(0);
}
