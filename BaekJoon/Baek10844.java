//Dynamic Programming

import java.util.Scanner;

class Baek10844 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();

        long[][] memo = new long[2][10];

        for (int i = 1; i < 10; i++) {
            memo[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            memo[i % 2][0] = memo[(i - 1) % 2][1] % 1000000000;
            for (int j = 1; j < 9; j++) {
                memo[i % 2][j] = (memo[(i - 1) % 2][j - 1] + memo[(i - 1) % 2][j + 1]) % 1000000000;
            }
            memo[i % 2][9] = memo[(i - 1) % 2][8] % 1000000000;
        }

        long result = 0;
        for (long num : memo[(n - 1) % 2]) {
            result += num;
        }
        System.out.println(result % 1000000000);

    }
}
