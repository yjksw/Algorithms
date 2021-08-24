//Recursion

import java.util.Scanner;
import java.util.Arrays;

public class Baek2447 {

    public static char fig[][];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        fig = new char[n][n];

        for (char[] row : fig) {
            Arrays.fill(row, ' ');
        }

        drawFig(0, 0, n);

        for (char[] row : fig) {
            System.out.println(row);
        }

        return;
    }

    public static void drawFig(int a, int b, int num) {
        if (num == 1) {
            fig[a][b] = '*';
            return;
        }
        int n = num / 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                drawFig((a * 3) + i, (b * 3) + j, n);
            }
        }
        return;
    }
}
