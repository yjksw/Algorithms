//Brute force

import java.util.Scanner;

class Baek1018 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] board = new char[n][m];

        for (int i = 0; i < n; i++) {
            String temp = sc.next();
            for (int j = 0; j < m; j++) {
                board[i][j] = temp.charAt(j);
            }
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n - 7; i++) {
            for (int j = 0; j < m - 7; j++) {
                char compare = 'B';
                for (int nu = 0; nu < 2; nu++) {
                    //char start = board[i][j];
                    if (nu == 1) {
                        compare = 'W';
                    }
                    int count = 0;
                    for (int k = i; k < i + 8; k++) {
                        for (int l = j; l < j + 8; l++) {
                            if (board[k][l] != compare) {
                                count++;
                            }
                            if (compare == 'B') {
                                compare = 'W';
                            } else {
                                compare = 'B';
                            }
                        }
                        if (compare == 'B') {
                            compare = 'W';
                        } else {
                            compare = 'B';
                        }
                    }
                    min = Math.min(min, count);
                }
            }
        }
        sc.close();
        System.out.println(min);
    }
}
