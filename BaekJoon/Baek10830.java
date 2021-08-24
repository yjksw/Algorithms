//DAC

import java.util.Scanner;
import java.util.Arrays;

class Main {

    static long[][] a;
    static long[][] ans;
    static int n;
    static long b;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        b = sc.nextLong();

        a = new long[n][n];
        ans = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
                ans[i][j] = a[i][j];
            }
        }

        solve(b);

        for (long[] arr : ans) {
            for (long temp : arr) {
                System.out.print(temp + " ");
            }
            System.out.println();
        }

        sc.close();
    }

    public static void solve(long cnt) {
        if (cnt == 1 || cnt == 0) {
            return;
        }

        solve(cnt / 2);
        multiply(true);
        if (cnt % 2 == 1) {
            multiply(false);
        }

        return;
    }

    public static void multiply(boolean pow) {
        long num = 0;

        long[][] temp = new long[n][n];

        int row = 0;
        int col = 0;
        for (long[] arr : ans) {
            col = 0;
            for (long element : arr) {
                temp[row][col] = element;
                col++;
            }
            row++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num = 0;
                for (int r = 0; r < n; r++) {
                    if (pow == true) {
                        num += (temp[i][r] * temp[r][j]) % 1000;
                    } else {
                        num += (temp[i][r] * a[r][j]) % 1000;
                    }
                }
                ans[i][j] = num % 1000;
            }
        }
        return;
    }
}
