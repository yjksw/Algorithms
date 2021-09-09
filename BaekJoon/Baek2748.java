//Dynamic Programming

import java.util.Scanner;

class Baek2748 {

    static int n;
    static long[] fibo;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.close();

        fibo = new long[n + 1];
        long result = 0;
        result = solu(n);
        System.out.println(result);
    }

    public static long solu(int num) {
        if (fibo[num] > 0) {
            return fibo[num];
        }

        if (num == 0) {
            fibo[0] = 0;
            return fibo[0];
        } else if (num == 1) {
            fibo[1] = 1;
            return fibo[1];
        }

        fibo[num] = solu(num - 2) + solu(num - 1);

        return fibo[num];
    }
}
