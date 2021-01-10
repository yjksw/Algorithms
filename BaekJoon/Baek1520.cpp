ㅕ#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

void dfs() {
    
}

int main() {
    int m = 0;
    int n = 0;

    scanf("%d %d", &m, &n);

    vector<vector<int> > route (m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &route[i][j]);
        }
    }

    return 0;
}