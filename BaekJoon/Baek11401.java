//DAC

import java.util.Scanner;

class Baek11401 {

    static int n;
    static int k;
    static long[] fac;
    static long x;
    static long y;
    static long temp;
    static long p = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();
        fac = new long[n + 1];

        factorial(n);

        long b = (fac[k] * fac[n - k]) % p;
        long a = fac[n] % p;

        euc(p, b);
        //ax % p
        //px + By = 1

        long ans = (a * y % p) % p;
        if (ans < 0) {
            ans += p;
        }

        System.out.println(ans);
        sc.close();

    }

    public static void factorial(long num) {
        fac[0] = 1;
        fac[1] = 1;
        for (int i = 2; i <= num; i++) {
            fac[i] = (i * fac[i - 1]) % p;
        }
    }

    public static void euc(long p, long B) {
        if (p % B > 0) {
            euc(B, p % B);
            temp = y;
            y = x - (p / B) * y;
            x = temp;
        } else {
            x = 0;
            y = 1;
        }
    }
}
