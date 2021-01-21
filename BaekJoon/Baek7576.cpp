//DFS BFS
//토마토
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    vector<vector<int> > box(m, vector<int>(n, 0));
    vector<vector<int> > memo(m, vector<int>(n, -1));
    queue<pair<int, int> > pq;
    int done = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &box[i][j]);

            if(box[i][j] == 0) {
                done = 0;
            }

            if(box[i][j] == -1) {
                memo[i][j] = -2;
            }

            if(box[i][j] == 1) {
                pair<int, int> p;
                memo[i][j] = 0;
                p.first = i;
                p.second = j;
                pq.push(p);
            }
        }
    }

    if (done == 1) {
        printf("%d", 0);
        return 0;
    }

    int time = 0;
    int posX[] = {0, 1, 0, -1};
    int posY[] = {-1, 0, 1, 0};

    while(!pq.empty()) {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop(); 

        time = memo[x][y] + 1;
        for (int i = 0; i < 4; i++) {
            int nextX = x + posX[i];
            int nextY = y + posY[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
                continue; 
            }

            if (box[nextX][nextY] == 0 && memo[nextX][nextY] == -1) {
                pair<int, int> p;
                memo[nextX][nextY] = time;
                p.first = nextX;
                p.second = nextY;
                pq.push(p);
            }
        }
    }

    int ans = 0; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[i][j] == -1) {
                printf("%d", -1);
                return 0;
            }
        }
    }

    printf("%d", time-1);
    return 0;
}