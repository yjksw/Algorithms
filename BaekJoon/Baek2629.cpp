#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > dp;
vector<int> weights;
int n;

void createTable(int numOfWeights, int currWeight) {
    
    if (numOfWeights > n) {
        return;
    }

    if (dp[numOfWeights][currWeight] != -1) {
        return;
    }

    dp[numOfWeights][currWeight] = 1;

    createTable(numOfWeights+1, currWeight+(weights[numOfWeights]));
    createTable(numOfWeights+1, currWeight);
    createTable(numOfWeights+1, abs(currWeight - weights[numOfWeights]));
}

int main() {
    
    n = 0;
    scanf("%d", &n);

    weights.resize (n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int m = 0;
    scanf("%d", &m);

    vector<int> marbles(m, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d", &marbles[i]);
    }

    dp.resize(n+1, vector<int>(30 * 500 + 1, -1));
    
    createTable(0, 0);

    for(int i = 0; i < m; i++) {
        if(marbles[i] > 30*500) {
            printf("N ");
        } else if (dp[n][marbles[i]] == 1) {
            printf("Y ");
        } else if (dp[n][marbles[i]] == -1) {
            printf("N ");
        }
    }

    return 0;
}