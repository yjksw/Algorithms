#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int m = 0;
int n = 0;
int posX[] = {0, 1, 0, -1};
int posY[] = {-1, 0, 1, 0};
vector<vector<int> > dp;
vector<vector<int> > route;

void dfs(int x, int y)
{
    int flag = 0;

    if (x == m - 1 && y == n - 1)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (x + posX[i] < 0 || x + posX[i] > m - 1 || y + posY[i] < 0 || y + posY[i] > n - 1)
        {
            continue;
        }

        if (route[x + posX[i]][y + posY[i]] >= route[x][y])
        {
            continue;
        }

        flag = 1;
        if (dp[x + posX[i]][y + posY[i]] == -1)
        {
            dfs(x + posX[i], y + posY[i]);
        }
        if (dp[x][y] == -1)
        {
            dp[x][y] = dp[x + posX[i]][y + posY[i]];
        }
        else
        {
            dp[x][y] += dp[x + posX[i]][y + posY[i]];
        }
    }

    if (flag == 0) {
        dp[x][y] = 0;
    }

    return;
}

int main()
{

    scanf("%d %d", &m, &n);

    route.resize(m, vector<int>(n, -1));
    dp.resize(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &route[i][j]);
        }
    }

    dp[m - 1][n - 1] = 1;
    dfs(0, 0);

    printf("%d\n", dp[0][0]);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
