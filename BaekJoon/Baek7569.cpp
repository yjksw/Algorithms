//DFS BFS
//토마토 3차원
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int n = 0;
    int m = 0;
    int h = 0;

    scanf("%d %d %d", &n, &m, &h);

    vector<vector<vector<int> > > box(h, vector<vector<int> >(m, vector<int>(n, 0)));
    vector<vector<vector<int> > > memo(h, vector<vector<int> >(m, vector<int>(n, -1)));
    queue<vector<int> > pq;
    int done = 1;

    for (int l = 0; l < h; l++) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &box[l][i][j]);

            if(box[l][i][j] == 0) {
                done = 0;
            }

            if(box[l][i][j] == -1) {
                memo[l][i][j] = -2;
            }

            if(box[l][i][j] == 1) {
                vector<int> in(3);
                memo[l][i][j] = 0;
                in[0] = l;
                in[1] = i;
                in[2] = j;
                pq.push(in);
            }
        }
    }
    }

    if (done == 1) {
        printf("%d", 0);
        return 0;
    }

    int time = 0;
    int posL[] = {0, 0, 0, 0, 1, -1};
    int posX[] = {0, 1, 0, -1, 0, 0};
    int posY[] = {-1, 0, 1, 0, 0, 0};

    while(!pq.empty()) {
        int l = pq.front().at(0);
        int x = pq.front().at(1);
        int y = pq.front().at(2);
        pq.pop(); 

        time = memo[l][x][y] + 1;
        for (int i = 0; i < 6; i++) {
            int nextL = l + posL[i];
            int nextX = x + posX[i];
            int nextY = y + posY[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || nextL < 0 || nextL >= h) {
                continue; 
            }

            if (box[nextL][nextX][nextY] == 0 && memo[nextL][nextX][nextY] == -1) {
                vector<int> in(3);
                memo[nextL][nextX][nextY] = time;
                in[0] = nextL;
                in[1] = nextX;
                in[2] = nextY;
                pq.push(in);
            }
        }
    }

    int ans = 0; 
    for (int l = 0; l < h; l++) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[l][i][j] == -1) {
                printf("%d", -1);
                return 0;
            }
        }
    }
    }

    printf("%d", time-1);
    return 0;
}