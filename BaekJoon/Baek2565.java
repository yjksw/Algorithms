//Dynamic Programming

import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Baek2565 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] input = new int[n][2];
        int[] inc = new int[n];

        for (int i = 0; i < n; i++) {
            input[i][0] = sc.nextInt();
            input[i][1] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(input, new Comparator<int[]>() {
            public int compare(int[] t1, int[] t2) {
                if (t1[0] == t2[0]) {
                    return t1[1] - t2[1];
                } else {
                    return t1[0] - t2[0];
                }
            }
        });

        inc[0] = 1;
        for (int i = 1; i < n; i++) {
            inc[i] = 1;
            for (int j = 0; j < i; j++) {
                if (input[i][0] > input[j][0] && input[i][1] > input[j][1] && inc[i] < inc[j] + 1) {
                    inc[i] = inc[j] + 1;
                }
            }
        }

        Arrays.sort(inc);
        System.out.println(n - inc[n - 1]);
    }
}
