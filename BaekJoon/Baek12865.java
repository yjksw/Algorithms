//Dynamic Programming

import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();

        int[][] wv = new int[n][2];
        int[][] arr = new int[n + 1][w + 1];

        for (int i = 0; i < n; i++) {
            wv[i][0] = sc.nextInt();
            wv[i][1] = sc.nextInt();
        }
        sc.close();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (j < wv[i - 1][0]) {
                    arr[i][j] = arr[i - 1][j];
                } else {
                    arr[i][j] = Math
                        .max(arr[i - 1][j], arr[i - 1][j - wv[i - 1][0]] + wv[i - 1][1]);
                }
            }
        }

        System.out.println(arr[n][w]);
    }
}
