#include <cstdio>
#include <vector>

using namespace std;

int main() {

    int n = 0;
    int m = 0;

    scanf("%d", &n);

    vector<int> num(n, 0);
    vector<vector<int> > dp (n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start + len - 1 < n; start++) {
            int end = start + len -1;
            if (len == 1) {
                dp[start][end] = 1;
                continue;
            }
            if (len == 2) {
                if (num[start] == num[end]) {
                    dp[start][end] = 1;
                }
                continue;
            }
            if (dp[start+1][end-1] == 1 && num[start] == num[end]) {
                dp[start][end] = 1;
            }
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a-1][b-1]);
    }
    
    return 0;
}