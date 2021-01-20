//DFS BFS
//숨박꼭질
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int start = 0;
    int dest = 0;

    scanf("%d %d", &start, &dest);

    vector<int> visit(100001, 0);
    queue<int> pq;
    pq.push(start);
    visit[start] = 1;

    int time = 0;
    int ans = 0; 

    while(!pq.empty()) {
        time = visit[pq.front()] + 1;
        int current = pq.front();
        pq.pop();

        if (current == dest) {
            ans = visit[current] - 1;
            break;
        }

        if(current + 1 <= 100000 && visit[current+1] == 0) {
            pq.push(current+1);
            visit[current + 1] = time;
        }

        if(current - 1 >= 0 && visit[current - 1] == 0) {
            pq.push(current-1);
            visit[current - 1] = time;
        }

        if(current * 2 <= 100000 && visit[current * 2] == 0) {
            pq.push(current*2);
            visit[current * 2] = time;  
        }
    }

    printf("%d", ans);
    return 0;
}