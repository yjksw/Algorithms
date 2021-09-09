//Dynamic Programming

import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Baek11399 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] value = new int[n];

        for (int i = 0; i < n; i++) {
            value[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(value);
        int result = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += value[i];
            result += sum;
        }
        System.out.println(result);
    }
}
