//최단경로
//특정한 최단 경로
#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {

    int v = 0;
    int e = 0;

    scanf("%d %d", &v, &e);

    vector<vector<pair<int, int> > > graph(v+1);

    for (int i = 0; i < e; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        scanf("%d %d %d", &a, &b, &c);

        pair<int, int> p;
        p.first = b;
        p.second = c;
        graph[a].push_back(p);

        p.first = a;
        graph[b].push_back(p);
    }

    int v1 = 0; 
    int v2 = 0;
    scanf("%d %d", &v1, &v2);

    vector<int> distance(v + 1, INT_MAX);

    distance[1] = 0;
    int start = 1;

    int route1 = 0;
    int route2 = 0;
    int flag1 = 1;
    int flag2 = 1;

    for (int i = 0; i < 3; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

        fill_n(distance.begin(), v + 1, INT_MAX);

        if (i == 1) {
            distance[v1] = 0;
            start = v1;
        }

        if (i == 2) {
            distance[v2] = 0;
            start = v2;
        }

        pair<int, int> p;
        p.first = start;
        p.second = 0;
        pq.push(p);

        while(!pq.empty()) {
            int v = pq.top().first;
            int w = pq.top().second;
            pq.pop();
        
            if (distance[v] < w) {
                continue;
            }

            distance[v] = w;

            for (int j = 0; j < graph[v].size(); j++) {
                int ver = graph[v][j].first;
                int wei = graph[v][j].second;
                if (distance[ver] > distance[v] + wei) {
                    distance[ver] = distance[v] + wei;
                    pair<int, int> p;
                    p.first = ver;
                    p.second = distance[ver];
                    pq.push(p);
                }
            }
        }

        if (i == 0) {
            if (distance[v1] == INT_MAX) {
                flag1 = 0;
            }
            if (distance[v2] == INT_MAX) {
                flag2 = 0;
            }
            route1 += distance[v1];
            route2 += distance[v2];
        }

        if (i == 1) {
            if (distance[v2] == INT_MAX) {
                flag1 = 0;
            }
            if (distance[v] == INT_MAX) {
                flag2 = 0;
            }
            route1 += distance[v2];
            route2 += distance[v];
        }

        if (i == 2) {
            if (distance[v] == INT_MAX) {
                flag1 = 0;
            }
            if (distance[v1] == INT_MAX) {
                flag2 = 0;
            }
            route1 += distance[v];
            route2 += distance[v1];
        }
    }

    if (flag1 == 0 && flag2 == 0) {
        printf("-1");
        return 0;
    }
    
    int ans = min(route1, route2);
    printf("%d", ans);

    return 0;
}