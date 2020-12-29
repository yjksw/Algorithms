#include <iostream>
#include <stdio.h> 
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> v;
vector<int> visit;
vector<int> done;
int numVertex = 0;
int maxW = 0; 

void makeCluster(int node, vector<int> cluster, int w) {
	
	cluster.push_back(node);
	w += v[node];
	visit[node] = 1; 
	done[node] = 1;

	for(int i = 1 ; i <= numVertex ; i++) {
		if(g[node][i] == 1 && visit[i] == 0) {
			int flag = 1;
			for(int j = 0; j < cluster.size() ; j++) {
				if(g[i][cluster[j]] == 0) {
					flag = 0;
					break;
				}
			}

			if(flag == 1) {
				makeCluster(i, cluster, w);
			}
		}	
	}

	if(w > maxW)
		maxW = w;
	int back = cluster.back();
	cluster.pop_back();
	w -= v[back];

	return;
}

int main() {
	
	int numEdge = 0;
	scanf("%d %d", &numVertex, &numEdge);

	g.resize(numVertex+1, vector<int>(numVertex+1, 0));
	v.resize(numVertex+1, 0);
	visit.resize(numVertex+1, 0);
	done.resize(numVertex+1, 0);

	for(int i = 1 ; i <= numVertex ; i++) {
		scanf("%d", &v[i]);
	}

	for(int i = 1 ; i <= numEdge ; i++) {
		int x = 0; 
		int y = 0;
		scanf("%d %d", &x, &y);
		g[x][y] = 1;
		g[y][x] = 1;
	}

	for(int i = 1 ; i <= numVertex; i++) {
		if(done[i] == 1) {
			continue;
		}

		visit.clear();
		visit.resize(numVertex+1, 0);
		vector<int> cluster;
		makeCluster(i, cluster, 0);
	}

	printf("%d", maxW);
	return 0;
}
