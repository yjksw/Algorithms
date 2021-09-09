//Dynamic Programming

import java.util.Scanner;
import java.util.Arrays;

class Baek2156 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] input = new int[n];
        int[] value = new int[n];

        for (int i = 0; i < n; i++) {
            input[i] = sc.nextInt();
        }
        sc.close();

        value[0] = input[0];
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                value[i] = input[1] + input[0];
                continue;
            } else if (i == 2) {
                value[i] = Math
                    .max(Math.max(input[i] + input[i - 1], input[i] + input[i - 2]), value[i - 1]);
                continue;
            }
            value[i] = Math
                .max(Math.max(input[i] + input[i - 1] + value[i - 3], input[i] + value[i - 2]),
                    value[i - 1]);
        }
		
	
		/*for(int temp: value)
			System.out.print(temp+" ");*/
        Arrays.sort(value);
        System.out.println(value[n - 1]);
    }
}

