//Shortest path
//최단경로
#include <cstdio>
#include <vector>
#include <limits.h>
#include <queue>
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
    
    int start = 0;
    scanf("%d", &start);

    vector<vector<pair<int, int> > > graph(v+1);

    for (int i = 0; i < e; i++) {
        int u = 0;
        int v = 0; 
        int w = 0;
        scanf ("%d %d %d", &u, &v, &w);

        pair<int, int> p;
        p.first = v;
        p.second = w;
        graph[u].push_back(p);
    }

    vector<int> distance(v+1, INT_MAX);

    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare > pq;

    pair<int, int> p;
    p.first = start;
    p.second = 0;
    pq.push(p);

    while (!pq.empty()) {
        int vertex = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (distance[vertex] < weight) {
            continue;
        }

        distance[vertex] = weight;

        for (int i = 0; i < graph[vertex].size(); i++) {
            int v = graph[vertex][i].first;
            int w = graph[vertex][i].second;

            if (distance[v] > distance[vertex] + w) {
                distance[v] = distance[vertex] + w;
                pair<int, int> p;
                p.first = v;
                p.second = distance[v];
                pq.push(p);
            } 
        }
    }

    for (int i = 1; i <= v; i++) {
        if (distance[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", distance[i]);
        }
    }

    return 0;
}