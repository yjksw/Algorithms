//DFS BFS
//단지 번호 붙이기
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int> > visited; 
vector<vector<int> > house;
vector<int> ans;
int posX[] = {-1, 0, 1, 0};
int posY[] = {0, 1, 0 , -1};
int n = 0; 
int numHouse = 0;

void dfs(int x, int y) {
    
    for (int i = 0; i < 4; i++) {
        int nextX = x + posX[i];
        int nextY = y + posY[i];
        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
            continue;
        }

        if(house[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
            numHouse++;
            visited[nextX][nextY] = 1; 
            dfs(nextX, nextY); 
        }
    }   
}
int main() {
    
    scanf("%d", &n);

    house.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0 ; i < n; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < n; j++) {
            house[i][j] = str.front() - '0';
            str.erase(str.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(house[i][j] == 1 && visited[i][j] == 0) {
                numHouse = 1;
                visited[i][j] = 1;
                dfs(i, j);
                ans.push_back(numHouse);
            } 
        }
    }

    printf("%lu\n", ans.size());
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}