//DFS BFS
//유기농 배추
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<vector<int> > visited;
int posX[] = {0, 1, 0, -1};
int posY[] = {-1, 0, 1, 0};

void dfs(int x, int y, int sizeX, int sizeY) {

    for (int i = 0; i < 4; i++) {
        int nextX = x + posX[i];
        int nextY = y + posY[i];

        if(nextX < 0 || nextX >= sizeY || nextY < 0 || nextY >= sizeX) {
            continue;
        }

        if(graph[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY, sizeX, sizeY);
        }
    }
}

int main() {

    int testCase = 0;
    scanf("%d", &testCase);

    while (testCase > 0) {
        int m = 0;
        int n = 0;
        scanf("%d %d", &m, &n);
        
        graph.resize(n, vector<int> (m, 0));
        visited.resize(n, vector<int> (m, 0));

        int num = 0;
        scanf("%d", &num);

        for (int i = 0; i < num; i++) {
            int a = 0;
            int b = 0; 
            scanf("%d %d", &a, &b);
            graph[b][a] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1 && visited[i][j] == 0) {
                    ans++;
                    visited[i][j] = 1;
                    dfs(i, j, m, n);
                }
            }
        }

        printf("%d\n", ans);

        for(int i = 0; i < n; i++) {
            graph[i].clear();
            visited[i].clear();
        }
        graph.clear();
        visited.clear();

        testCase--;
    }

    return 0;
}