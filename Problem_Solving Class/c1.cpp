  #include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int n, k, f;
	int result = 0;
	cin >> n >> k >> f;

	int graph[n+1][n+1];
	int count[n+1];

	std::fill_n(count, n+1, 0);
	std::fill_n(graph[0], (n+1)*(n+1), 0);

	for(int i=1;i<=f;i++){
		int input[2];
		cin >> input[0] >> input[1];
		graph[input[0]][input[1]] = 1;
		graph[input[1]][input[0]] = 1;
		count[input[0]]++;
		count[input[1]]++;
	}

	while(true){
		bool check = false;
		for(int j=1;j<=n;j++){ 
			if(count[j] < k && count[j]>0){
				check = true;
				for(int i=1;i<=n;i++){
					if(graph[j][i] == 1){
						graph[j][i] = 0;
						graph[i][j] = 0;
						count[j]--;
						count[i]--;
					}
				}
			}
		}
		if(check == false){
			break;
		}
	}

	for(int i=1;i<=n;i++){
		if(count[i] >= k)
			result++;
	}

	cout << result;
	exit(0);
}
