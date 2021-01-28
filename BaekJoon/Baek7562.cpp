//DFS BFS
//나이트의 이동
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int testcase = 0;
    scanf("%d", &testcase);

    int posX[] = {-1, -1, -2, -2, 1, 1, 2, 2};
    int posY[] = {2, -2, 1, -1, 2, -2, 1, -1};

    while(testcase > 0) {
        int n = 0;
        scanf("%d", &n);

        int start[2];
        int dest[2];
        scanf("%d %d", &start[0], &start[1]);
        scanf("%d %d", &dest[0], &dest[1]);

        vector<vector<int> > visit(n, vector<int>(n, 0));
        queue<vector<int> > pq;
        vector<int> v(2, 0);
        v[0] = start[0];
        v[1] = start[1];
        pq.push(v);
        int ans = 0; 
        int time = 0;
        visit[start[0]][start[1]] = 1;
    
        while(!pq.empty()) {
            int x = pq.front().front();
            int y = pq.front().back();
            pq.pop();

            time = visit[x][y] + 1;

            if(x == dest[0] && y == dest[1]) {
                ans = visit[x][y];
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nextX = x + posX[i];
                int nextY = y + posY[i];

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
                    continue;
                }

                if (visit[nextX][nextY] == 0) {
                    vector<int> v(2, 0);
                    v[0] = nextX;
                    v[1] = nextY;
                    pq.push(v);
                    visit[nextX][nextY] = time;
                }
            }
        }

        printf("%d\n", ans - 1);
        testcase--;
    }

    return 0;
}