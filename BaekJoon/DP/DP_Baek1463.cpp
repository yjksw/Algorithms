#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dp;

int memo(int index) {
    if (dp[index] != -1) {
        return dp[index];
    }

    vector<int> candidate;

    if (index % 3 == 0) {
        candidate.push_back(memo(index / 3) + 1);
    }

    if (index % 2 == 0) {
        candidate.push_back(memo(index / 2) + 1);
    }
    
    candidate.push_back(memo(index -1) + 1);

    dp[index] = *min_element(candidate.begin(), candidate.end());
    return dp[index];
}

int main() {

    int n;
    cin >> n;

    dp.resize(n + 1, -1);
    dp[1] = 0;

    memo(n);
    
    cout << dp[n];
    return 0;
}