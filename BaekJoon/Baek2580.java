//Back-tracking

import java.util.Scanner;
import java.util.ArrayList;

class Main {

    static int[][] board = new int[9][9];
    static boolean fin = false;
    static ArrayList<int[]> list = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = sc.nextInt();
                if (board[i][j] == 0) {
                    list.add(new int[]{i, j});
                }
            }
        }

        solve(0, 0);
        sc.close();
    }

    public static void solve(int index, int cnt) {
        if (cnt == list.size()) {
            fin = true;
            print();
            return;
        }
        if (fin) {
            return;
        }

        int i = list.get(index)[0];
        int j = list.get(index)[1];
        check:
        for (int ans = 1; ans <= 9; ans++) {
            for (int count = 0; count < 9; count++) {
                if (board[i][count] == ans) {
                    continue check;
                }
                if (board[count][j] == ans) {
                    continue check;
                }
                if (board[(i / 3) * 3 + count / 3][(j / 3) * 3 + count % 3] == ans) {
                    continue check;
                }
            }
            board[i][j] = ans;
            solve(index + 1, cnt + 1);
            board[i][j] = 0;
        }
    }

    public static void print() {
        System.out.println("");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}


