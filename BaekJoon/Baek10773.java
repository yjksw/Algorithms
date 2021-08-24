//Stack

import java.util.Scanner;
import java.util.Stack;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Stack<Integer> st = new Stack<>();

        int num = 0;
        for (int i = 0; i < n; i++) {
            num = sc.nextInt();
            if (num == 0) {
                st.pop();
            } else {
                st.push(num);
            }
        }

        sc.close();
        int result = 0;

        if (st.isEmpty()) {
            System.out.println(0);
            return;
        }

        int size = st.size();
        for (int i = 0; i < size; i++) {
            result += st.pop();
        }

        System.out.println(result);
    }
}
