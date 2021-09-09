import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

class Baek2805 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n, m;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[] input = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(input);
        long left = 0;
        long right = input[n - 1];
        long mid = 0;
        long answer = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            long total = 0;
            for (int i = 0; i < n; i++) {
                if (input[i] > mid) {
                    total += input[i] - mid;
                }
            }
            System.out.println(mid);
            if (total < m) {
                right = mid - 1;
            } else if (total > m) {
                left = mid + 1;
            } else {
                right = mid;
                break;
            }
        }

        System.out.println(right);
        br.close();

    }
}
