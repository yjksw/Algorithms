//Back-tracking 

import java.util.Scanner;

class Main {

    static int[] num;
    static int[] oper = new int[4];
    static int[] mm = new int[2];
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            oper[i] = sc.nextInt();
        }

        sc.close();
        mm[0] = Integer.MIN_VALUE;
        mm[1] = Integer.MAX_VALUE;
        solu(0, num[0]);

        for (int i = 0; i < 2; i++) {
            System.out.println(mm[i]);
        }
    }

    public static void solu(int cnt, int cal) {
        if (cnt == n - 1) {
            mm[0] = Math.max(mm[0], cal);
            mm[1] = Math.min(mm[1], cal);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (oper[i] == 0) {
                continue;
            }
            oper[i]--;

            int result = 0;
            if (i == 0) {
                result = cal + num[cnt + 1];
            } else if (i == 1) {
                result = cal - num[cnt + 1];
            } else if (i == 2) {
                result = cal * num[cnt + 1];
            } else if (i == 3) {
                result = cal / num[cnt + 1];
            }

            solu(cnt + 1, result);
            oper[i]++;
        }
    }
}
