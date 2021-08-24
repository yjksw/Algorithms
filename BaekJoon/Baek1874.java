//Stack

import java.util.Scanner;
import java.util.Stack;
import java.util.ArrayList;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] num = new int[n];
        ArrayList<Character> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        sc.close();

        int count = 1;
        int index = 0;
        while (index < n) {
            if (!st.isEmpty() && st.peek() == num[index]) {
                st.pop();
                index++;
                ans.add('-'); //System.out.println("-");
            } else {
                st.push(count);
                count++;
                ans.add('+'); //System.out.println("+");
            }
            if (count > n + 1) {
                System.out.println("NO");
                return;
            }
        }

        for (char ch : ans) {
            System.out.println(ch);
        }
    }
}
