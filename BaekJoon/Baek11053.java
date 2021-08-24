//Dynamic Programming

import java.util.Scanner;
import java.util.Arrays;

class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] input = new int[n];

        for (int i = 0; i < n; i++) {
            input[i] = sc.nextInt();
        }
        sc.close();

        int[] count = new int[n];
        count[0] = 1;
        for (int i = 1; i < n; i++) {
            count[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (input[i] > input[j]) {
                    count[i] = Math.max(count[j] + 1, count[i]);
                }
            }
            //other solution
			/*for(int j=0;j<i;j++){
			  if(input[i]>input[j] && count[i]<=count[j])
				count[i] = count[j]+1;
			}*/
        }
        Arrays.sort(count);
        System.out.println(count[n - 1]);
    }
}
