//DAC

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {

    static int[][] arr;
    static int nega = 0;
    static int posi = 0;
    static int zero = 0;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            int n = Integer.parseInt(br.readLine());
            arr = new int[n][n];
            for (int i = 0; i < n; i++) {
                String[] temp = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(temp[j]);
                }
            }
            solve(0, 0, n);

        } catch (IOException e) {
        }

        System.out.print(nega + "\n" + zero + "\n" + posi + "\n");
    }

    public static void solve(int x, int y, int size) {
        int num = arr[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (num != arr[i][j]) {
                    solve(x, y, size / 3);
                    solve(x, y + size / 3, size / 3);
                    solve(x, y + 2 * (size / 3), size / 3);
                    solve(x + size / 3, y, size / 3);
                    solve(x + size / 3, y + size / 3, size / 3);
                    solve(x + size / 3, y + 2 * (size / 3), size / 3);
                    solve(x + 2 * (size / 3), y, size / 3);
                    solve(x + 2 * (size / 3), y + size / 3, size / 3);
                    solve(x + 2 * (size / 3), y + 2 * (size / 3), size / 3);
                    return;
                }
            }
        }
        if (num == 1) {
            posi++;
        } else if (num == 0) {
            zero++;
        } else {
            nega++;
        }
        return;
    }
}

