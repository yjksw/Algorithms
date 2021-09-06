//Dynamic Programming

import java.util.Scanner;

class Baek1149 {

    static int n;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int[][] value = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                value[i][j] = sc.nextInt();
            }
        }
        sc.close();
        int[][] result = new int[n][3];
        result[0] = value[0];

        solve(result, value, 1);
        int answer = Math.min(Math.min(result[n - 1][0], result[n - 1][1]), result[n - 1][2]);

        System.out.println(answer);
    }

    public static void solve(int[][] r, int[][] v, int cnt) {
        if (cnt == n) {
            return;
        }
        for (int i = 0; i < 3; i++) {
            r[cnt][i] = v[cnt][i] + Math.min(r[cnt - 1][(i + 1) % 3], r[cnt - 1][(i + 2) % 3]);
        }
        solve(r, v, cnt + 1);
    }
}
