//Dynamic Programming

import java.util.Scanner;

class Baek1904 {

    static int n;
    static int[] count;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        count = new int[n + 1];
        count[0] = 1;
        count[1] = 1;

        sc.close();
        solu(n);
        System.out.println(count[n]);

    }

    public static void solu(int num) {
        if (num == 1) {
            return;
        }

        solu(num - 1);
        count[num] = (count[num - 1] + count[num - 2]) % 15746;
        return;
    }
}
