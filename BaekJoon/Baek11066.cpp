/*Dynamic Programming
파일 합치기 */
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int trials = 0;
    scanf("%d", &trials);

    for (int i = 0; i < trials; i++) {
        int num = 0;
        scanf("%d", &num);

        vector<int> values(num, 0);
        for (int j = 0; j < num; j++) {
            scanf("%d", &values[j]);
        }

        vector<int> sum(num, 0);
        sum[0] = values[0];
        for (int j = 1; j < num; j++) {
            sum[j] = sum[j-1] + values[j];
        }

        vector<vector<int> > dp(num,vector<int>(num, 0));
        for (int a = 1; a < num; a++) {
            for (int b = 0; b + a < num; b++) {
                int end = b + a;
                int minNum = -1;
                for (int c = b; c < end; c++) {
                    if (minNum < 0) {
                        minNum = dp[b][c] + dp[c+1][end] + sum[end] - sum[b-1];
                    } else {
                        minNum = min(minNum, dp[b][c] + dp[c+1][end] + sum[end] - sum[b-1]);
                    }
                }
                dp[b][end] = minNum;
            }
        }
        printf("%d", dp[0][num-1]);

    }

    return 0;
}