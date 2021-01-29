//DFS BFS
//이분 그래프
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int testcase = 0 ;
    scanf("%d", &testcase);

    while (testcase > 0) {
        int v = 0;
        int e = 0;

        scanf("%d %d", &v, &e);
        vector<vector<int> > graph(v+1);
        vector<int> visit(v+1, -1);
        
        for (int i = 0; i < e; i++) {
            int a = 0;
            int b = 0;
            scanf("%d %d", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> pq;
        int start = 1;
        int fail = 0;
        int done = 0; 
        
        while (done == 0) {
            pq.push(start);
            visit[start] = 0;

            while(!pq.empty()) {
                int current = pq.front();
                pq.pop();

                int group = (visit[current] + 1) % 2;
                for (int i = 0; i < graph[current].size(); i++) {
                    if (visit[graph[current][i]] == -1) {
                        visit[graph[current][i]] = group;
                        pq.push(graph[current][i]);
                    } else if (visit[graph[current][i]] != group) {
                        fail = 1;
                        break;
                    }
                }
                
                if(fail == 1) {
                    break;
                }
            }

            if(fail == 1) {
                break;
            }

            done = 1;
            for (int i = 1; i <= v; i++) {
                if (visit[i] == -1) {
                    start = i;
                    done = 0;
                }
            }
        }

        if(fail == 1) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }

        testcase--;
    }

    return 0;
}