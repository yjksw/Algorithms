//Bruteforce 

import java.util.Scanner;

public class Baek2231 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int count = 0;
        int len = n;
        while (len != 0) {
            len = len / 10;
            count++;
        }

        int i = count * 9;
        int start = n - i;
        while (i > 0) {
            int sum = start;
            int num = start;
            for (int j = 0; j < count - 1; j++) {
                sum = sum + num % 10;
                num = num / 10;
            }
            sum = sum + num;
            if (sum == n) {
                break;
            }
            i--;
            start++;
        }
        if (start == n) {
            System.out.println(0);
        } else {
            System.out.println(start);
        }

        return;
    }
}
			




