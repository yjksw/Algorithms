/*Dynamic Programming
행렬 곱셈 순서*/
#include<cstdio>
#include<vector>
#include<cstdlib>

using namespace std;

int main() {
    int n = 0;
    scanf("%d", &n);

    vector<int> sizes(n+1, 0);
    vector<vector<int> > dp(n, vector<int>(n, 0));

    int sizeA = 0;
    int sizeB = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &sizeA, &sizeB);
        sizes[i] = sizeA;
        if(i == n-1) {
            sizes[i+1] = sizeB;
        }
    }

    for (int gap = 1; gap < n; gap++) {
        for (int start = 0; start + gap < n; start++) {
            int end = start + gap;
            int minNum = -1;
            for (int breakPoint = start; breakPoint < end; breakPoint++) {
                if (minNum < 0) {
                    minNum = dp[start][breakPoint] + dp[breakPoint+1][end] + sizes[start]*sizes[breakPoint+1]*sizes[end+1];
                } else {
                    minNum = min(minNum, dp[start][breakPoint] + dp[breakPoint+1][end] + sizes[start]*sizes[breakPoint+1]*sizes[end+1]);
                }
            }
            dp[start][end] = minNum;
        }
    }

    printf("%d", dp[0][n-1]);
    return 0;
}