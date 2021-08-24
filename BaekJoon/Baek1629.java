//DAC

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {

    static int[] num = new int[3];

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long result = 0;
        try {
            String[] temp = br.readLine().split(" ");
            for (int i = 0; i < 3; i++) {
                num[i] = Integer.parseInt(temp[i]);
            }
            result = solve(num[0], num[1]) % num[2];
        } catch (IOException e) {
        }

        System.out.println(result);
    }

    public static long solve(long a, long b) {
        if (b == 0) {
            return 1;
        }

        long n = solve(a, b / 2);
        long temp = n * n % num[2];

        if (b % 2 == 0) {
            return temp;
        } else {
            return temp * a % num[2];
        }
    }
}

