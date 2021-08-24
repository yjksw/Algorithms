import java.util.Scanner;
import java.util.Arrays;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] num = new int[n];
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        sc.close();

        arr[0] = num[0];
        for (int i = 1; i < n; i++) {
            arr[i] = Math.max(num[i], arr[i - 1] + num[i]);
        }

        Arrays.sort(arr);
        System.out.println(arr[n - 1]);
    }
}
