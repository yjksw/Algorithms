//최단 경로 단계
//미확인 도착지
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {

    int testcase = 0;
    scanf("%d", &testcase);

    while (testcase > 0) {
        
        int n = 0;
        int m = 0;
        int t = 0;
        scanf("%d %d %d", &n, &m, &t);

        int s = 0;
        int g = 0;
        int h = 0;
        scanf("%d %d %d", &s, &g, &h);

        vector<vector<pair<int, int> > > graph(n+1);

        for (int i = 0; i < m; i++) {
            int a = 0;
            int b = 0; 
            int d = 0;
            scanf("%d %d %d", &a, &b, &d);

            pair<int, int> p;
            p.first = b;
            p.second = d;
            graph[a].push_back(p);

            p.first = a;
            graph[b].push_back(p);
        }

        vector<int> candidate;
        vector<vector<int> > candidateShortestPath(t, vector<int>(2, 0));
        for (int i = 0; i < t; i++) {
            int x = 0;
            scanf("%d", &x);
            candidate.push_back(x);
        }

        vector<int> distance(n+1);
        fill_n(distance.begin(), n + 1, INT_MAX);
        distance[s] = 0;

        vector<int> candidatePath(t, 0);

        for (int i = 0; i < 3; i++) {
            if (i == 0) {
                priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
                pair<int, int> p;
                p.first = s;
                p.second = 0;
                pq.push(p);
            }

            if (i == 1) {
                fill_n(distance.begin(), n + 1, INT_MAX);
                priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
                pair<int, int> p;
                p.first = g;
                p.second = 0;
                pq.push(p);
                distance[g] = 0;
            }

            if (i == 2) {
                fill_n(distance.begin(), n + 1, INT_MAX);
                priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
                pair<int, int> p;
                p.first = h;
                p.second = 0;
                pq.push(p);
                distance[h] = 0;
            }

            while (!pq.empty()) {
                int v = pq.top().first;
                int w = pq.top().second;
                pq.pop();

                if (distance[v] < w) {
                    continue;
                }

                distance[v] = w;
                for (int i = 0; i < graph[v].size(); i++) {
                    int ver = graph[v][i].first;
                    int wei = graph[v][i].second;

                    if (distance[ver] > distance[v] + wei) {
                        distance[ver]= distance[v] + wei;
                        pair<int, int> p;
                        p.first = ver;
                        p.second = distance[ver];
                        pq.push(p);
                    }
                }
            }

            if (i == 0) {
                for (int i = 0; i < candidate.size(); i++) {
                    candidateShortestPath[i] = distance[candidate[i]];
                    candidatePath[i][0] += distance[g];
                    candidatePath[i][1] += distance[h];
                }
            }

            if (i == 1) {
                for (int i = 0; i < candidate.size(); i++) {
                    candidatePath[i][0] += distance[h];
                    candidatePath[i][1] += distance[g];
                }
            }

            if (i == 1) {
                for (int i = 0; i < candidate.size(); i++) {
                    candidatePath[i][0] += distance[candidate[i]];
                    candidatePath[i][1] += distance[candidate[i]];
                }
            }
        }

        //목적지 목록 출력
        
        testcase--;
    }



    return 0;
}