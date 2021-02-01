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
        for (int i = 0; i < t; i++) {
            int x = 0;
            scanf("%d", &x);
            candidate.push_back(x);
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
        pair<int, int> p;
        p.first = s;
        p.second = 0;
        pq.push(p);

        vector<int> distance(n+1);
        distance[s] = 0;

        int route1 = 0;
        int route2 = 0;

        for (int i = 0; i < 3; i++) {
            while (!pq.empty()) {
                int v = pq.top().first;
                int w = p

            }
        }


        //목적지 목록 출력
        testcase--;
    }



    return 0;
}