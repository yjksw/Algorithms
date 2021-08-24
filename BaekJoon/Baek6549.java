import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int n;
    static long[] value;
    static int[] binTree;
    static long max;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        try {
            while (true) {
                input = br.readLine();
                StringTokenizer st = new StringTokenizer(input);
                n = Integer.parseInt(st.nextToken());

                if (n == 0) {
                    br.close();
                    break;
                }

                value = new long[n];
                for (int i = 0; i < n; i++) {
                    value[i] = Long.parseLong(st.nextToken());
                }

                int height = (int) Math.ceil(Math.log10(n) / Math.log10(2));
                int size = (int) Math.pow(2, height + 1);

                binTree = new int[size];
                init(0, n - 1, 1);
                solve(0, n - 1);
                System.out.println(max);
                max = 0;
            }
        } catch (IOException e) {
        }
    }

    static void init(int start, int end, int index) {
        if (start == end) {
            binTree[index] = start;
            return;
        }
        init(start, (start + end) / 2, index * 2);
        init((start + end) / 2 + 1, end, index * 2 + 1);
        if (value[binTree[index * 2]] <= value[binTree[index * 2 + 1]]) {
            binTree[index] = binTree[index * 2];
        } else {
            binTree[index] = binTree[index * 2 + 1];
        }
        return;
    }

    static int findMin(int start, int last, int left, int right, int index) {
        if (left > last || right < start) {
            return -1;
        }
        if (left <= start && right >= last) {
            return binTree[index];
        } else {
            int temp1 = findMin(start, (start + last) / 2, left, right, index * 2);
            int temp2 = findMin((start + last) / 2 + 1, last, left, right, index * 2 + 1);
            if (temp1 == -1) {
                return temp2;
            } else if (temp2 == -1) {
                return temp1;
            } else {
                if (value[temp1] <= value[temp2]) {
                    return temp1;
                }
                return temp2;
            }
        }
    }

    static void solve(int startIndex, int lastIndex) {
        long area = 0;

        if (startIndex == lastIndex) {
            area = value[startIndex];
            if (area > max) {
                max = area;
            }
            return;
        }

        int minIndex = findMin(0, n - 1, startIndex, lastIndex, 1);
        long min = value[minIndex];
        area = min * (lastIndex - startIndex + 1);

        if (area > max) {
            max = area;
        }

        if (minIndex == startIndex) {
            solve(minIndex + 1, lastIndex);
        } else if (minIndex >= lastIndex) {
            solve(startIndex, minIndex - 1);
        } else {
            solve(startIndex, minIndex - 1);
            solve(minIndex + 1, lastIndex);
        }
    }
}
