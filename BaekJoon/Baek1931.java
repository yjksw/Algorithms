//Greedy Algorithm

import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] value = new int[n][2];

        for (int i = 0; i < n; i++) {
            value[i][0] = sc.nextInt();
            value[i][1] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(value, new Comparator<int[]>() {
            public int compare(int[] t1, int[] t2) {
                if (t1[1] == t2[1]) {
                    return t1[0] - t2[0];
                } else {
                    return t1[1] - t2[1];
                }
            }
        });

        int result = 1;
        int end = value[0][1];
        for (int i = 1; i < n; i++) {
            if (value[i][0] >= end) {
                result++;
                end = value[i][1];
            }
        }
        System.out.println(result);
    }
}
