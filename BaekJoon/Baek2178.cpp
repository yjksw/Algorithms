//DFS BFS 
//미로 탐색
#include <cstdio> 
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<int> > maze;
vector<vector<int> > memo;
queue<pair<int, int> > pq;
int posX[] = {0, 1, 0, -1};
int posY[] = {-1, 0, 1, 0};

int n = 0;
int m = 0;

int main() {

    scanf("%d %d", &n, &m);

    maze.resize(n, vector<int>(m, 0));
    memo.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++) {
            maze[i][j] = str.front() - '0';
            str.erase(str.begin());
        }
    }

    pair<int, int> p;
    p.first = 0;
    p.second = 0;

    pq.push(p);
    memo[0][0] = 1;

    int ans = 0;
    int flag = 0;
    int timeStamp = 0;
    while(!pq.empty()) {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();

        timeStamp = memo[x][y] + 1;
        for (int i = 0; i < 4; i++) {
            int nextX = x + posX[i];
            int nextY = y + posY[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                continue;
            }

            if (maze[nextX][nextY] == 1 && memo[nextX][nextY] == 0) {
                pair<int, int> p;
                p.first = nextX;
                p.second = nextY;
                pq.push(p);
                memo[nextX][nextY] = timeStamp;
                if(nextX == n-1 && nextY == m-1) {
                    ans = timeStamp;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) {
            break;
        }
    }

    printf("%d", ans);
    return 0;
}
