//Dynamic Programming 
//동전 1
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    int k = 0;
    vector<int> coin;
    vector<int> dp;

    scanf("%d", &n);
    scanf("%d", &k);

    coin.resize(n, 0);
    dp.resize(k+1, 0);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k+1; j++) {
            if (coin[i] > j) {
                continue;
            } else {
                dp[j] = dp[j] + dp[j - coin[i]];
            }
        }
    }

    printf("%d", dp[k]);
}