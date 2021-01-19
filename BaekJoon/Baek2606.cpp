//DFS BFS
//Baek 2606 바이러스
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> visited; 
int ans = -1;

void dfs(int v) {
    
    ans++;

    for (int i = 0; i < graph[v].size(); i++) {
        if(visited[graph[v][i]] == 1) {
            continue;
        }
        visited[graph[v][i]] = 1;
        dfs(graph[v][i]);
    }
}

int main() {

    int num = 0;
    scanf("%d", &num);

    int con = 0;
    scanf("%d", &con);

    graph.resize(num+1);
    visited.resize(num+1, 0);

    for (int i = 0; i < con; i++) {
        int a = 0;
        int b = 0;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    
    visited[1] = 1;
    dfs(1);
    printf("%d", ans);

    return 0;
}