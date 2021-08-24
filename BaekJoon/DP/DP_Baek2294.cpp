#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    int n = 0;
    int k = 0;
    vector<int> coin;
    vector<int> dp;

    cin >> n >> k;

    dp.resize(k + 1, 10001);

    for (int i = 0; i < n; i ++) {
        int temp;
        cin >> temp;
        coin.push_back(temp);
    }

    dp[0] = 0;
    for (int i = 0; i < coin.size(); i++) {
        for (int j = coin[i]; j <= k; j++) {
            int candidate = dp[j-coin[i]] + 1;
            if (dp[j] > candidate) {
                dp[j] = candidate;
            }
        }
    }
    
    if (dp[k] == 10001) {
        dp[k] = -1;
    }

    cout << dp[k];
    return 0; 
}