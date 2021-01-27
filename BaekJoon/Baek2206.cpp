//DFS BFS
//벽 부수고 이동하기 

#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);

    vector<vector<int> > graph(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            graph[i][j] = str.front() - '0';
            str.erase(str.begin());
        }
    }

    vector<vector<vector<int> > > visit(n, vector<vector<int> >(m, vector<int> (2, 0)));
    queue<vector<int> > pq;
    vector<int> v(3, 0);
    v[0] = 0; 
    v[1] = 0;
    v[2] = 0;
    pq.push(v); 

    int posX[] = {0, 1, 0, -1};
    int posY[] = {-1, 0, 1, 0};

    visit[0][0][0] = 1;
    visit[0][0][1] = 1;
    int ans = 0;
    int done = 0;
    while(!pq.empty()) {
        vector<int> current;
        current = pq.front();
        pq.pop();

        if (current[0] == n-1 && current[1] == m-1) {
            done = 1;
            ans = visit[n-1][m-1][current[2]];
            break;
        }

        int time = visit[current[0]][current[1]][current[2]] + 1;

        for (int i = 0; i < 4; i++) {
            int nextX = current[0] + posX[i];
            int nextY = current[1] + posY[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                continue;
            }

            if (graph[nextX][nextY] == 0 && visit[nextX][nextY][current[2]] == 0) {
                vector<int> cache(3, 0);
                cache[0] = nextX;
                cache[1] = nextY;
                cache[2] = current[2];
                pq.push(cache);
                visit[nextX][nextY][current[2]] = time;
            } else if (graph[nextX][nextY] == 1 && current[2] == 0) {
                vector<int> cache(3, 0);
                cache[0] = nextX;
                cache[1] = nextY;
                cache[2] = 1;
                pq.push(cache);
                visit[nextX][nextY][1] = time;
            }
        }
    }
 
    if (done == 0) {
        printf("-1");
        return 0;
    }
    
    printf("%d", ans);
    return 0;
}