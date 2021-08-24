#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<vector<int> > > dp;

int memo(int x, int y, int z) {
    int posX = x + 50;
    int posY = y + 50;
    int posZ = z + 50; 

    if (dp[posX][posY][posZ] != 0) {
        return dp[posX][posY][posZ];
    }

    if (x <= 0 || y <= 0 || z <= 0) {
        dp[posX][posY][posZ] = 1;
        return dp[posX][posY][posZ];
    }

    if (x > 20 || y > 20 || z > 20) {
        dp[posX][posY][posZ] = memo(20, 20, 20);
        return dp[posX][posY][posZ];
    }

    if (x < y && y < z) {
        dp[posX][posY][posZ] = memo(x, y, z - 1) + memo(x, y - 1, z - 1) - memo(x, y - 1, z);
    } else {
        dp[posX][posY][posZ] = memo(x - 1, y, z) + memo(x - 1, y - 1, z) + memo(x - 1, y, z - 1) - memo(x - 1, y - 1, z- 1);
    }

    return dp[posX][posY][posZ];
}

int main() {

    dp.resize(101, vector<vector<int> >(101, vector<int>(101, 0)));

    while (true) {

        int a = 0;
        int b = 0;
        int c = 0;

        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        int ans = memo(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << endl;
    }

    return 0;
}