//DAC

import java.util.Scanner;

class Main {

    static long n;
    static long[] arr;

    public static void main(String[] args) {
        //cycle is 15000000
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        arr = new long[15000000];
        arr[0] = 0;
        arr[1] = 1;

        if (n < 15000000) {
            for (int i = 2; i <= n; i++) {
                arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
            }
        } else {
            for (int i = 2; i < 15000000; i++) {
                arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
            }
        }

        if (n >= 15000000) {
            n = n % 15000000;
        }
        System.out.println(arr[(int) n]);
        sc.close();
    }
}
