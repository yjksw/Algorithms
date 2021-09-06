import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


class Baek1300 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n, k;
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        long left = 1;
        long right = k;
        long mid = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            long index = findIndex(mid, n);

            if (index >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        System.out.println(left);
        br.close();
        return;
    }

    public static long findIndex(long num, int n) {

        long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += Math.min(n, num / i);
        }

        return cnt;
    }
}

