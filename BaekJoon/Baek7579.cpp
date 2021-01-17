#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n = 0;
    int wantMem = 0;

    scanf("%d %d", &n, &wantMem);

    vector<int> memApp(n, 0);
    vector<int> costApp(n, 0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &memApp[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &costApp[i]);
        sum += costApp[i];
    }

    vector<int> dp(10000 + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= costApp[i]; j--) {
            dp[j] = max(dp[j-costApp[i]] + memApp[i], dp[j]);
        }
    }
    
    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= wantMem) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}