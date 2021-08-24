//Binary Search

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main {

    static int n;
    static int m;
    static int[] n_list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        n = Integer.parseInt(br.readLine());
        n_list = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            n_list[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(n_list);
        m = Integer.parseInt(br.readLine());

        boolean found = false;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            found = false;
            int start = 0;
            int end = n - 1;
            int num = Integer.parseInt(st.nextToken());

            while (start <= end) {
                int mid = (start + end) / 2;

                if (n_list[mid] == num) {
                    System.out.println(1);
                    found = true;
                    break;
                }
                if (n_list[mid] < num) {
                    start = mid + 1;
                }
                if (n_list[mid] > num) {
                    end = mid - 1;
                }
            }
            if (found == false) {
                System.out.println(0);
            }
        }
        br.close();

    }
}
