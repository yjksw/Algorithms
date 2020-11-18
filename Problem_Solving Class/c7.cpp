#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int bfs(int curr, int grouped[], vector<int> graph[], int group) {

	queue<int> q;

	grouped[curr] = group;
	group = (group + 1) % 2;	
	q.push(curr);

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		group = (grouped[node] + 1) % 2;

		for(int i = 0 ; i < graph[node].size() ; i++) {
			int edge = graph[node][i];
	
			if(grouped[edge] == -1) {
				grouped[edge] = group;
				q.push(edge);
			} else if (grouped[edge] != group)
				return -1;
		}
	}	

	return 1;
}

int main() {

	int numMedicines = 0;
	int numPair = 0;

	scanf("%d", &numMedicines);
	scanf("%d", &numPair);

	int grouped[numMedicines+1];
	fill_n(grouped, numMedicines+1, -1);

	vector<int> graph[numMedicines+1];

	int medA = 0;
	int medB = 0;
	int ans = 0;

	for(int i = 0 ; i < numPair ; i++) {

		scanf("%d %d", &medA, &medB);

		if(i == 0) {
			grouped[medA] = 0;
			grouped[medB] = 1;
			continue;
		}

		if(grouped[medA] == -1 && grouped[medB] == -1) {
			graph[medA].push_back(medB);
			graph[medB].push_back(medA);
		}

		if(grouped[medA] != -1 && grouped[medB] != -1) {
			if(grouped[medA] == grouped[medB]) {
				ans = i + 1;
				break;
			}
		}

		if(grouped[medA] != -1) {
			int groupN = (grouped[medA] + 1) % 2;
			if(bfs(medB, grouped, graph, groupN) == -1) {
				ans = i + 1;
				break;
			}
		} else if (grouped[medB] != -1) {
			int groupN = (grouped[medB] + 1) % 2;
			if(bfs(medA, grouped, graph, groupN) == -1) {
				ans = i + 1;
				break;
			}
		}
	}

	printf("%d", ans);
	return 0;
}
