//Stack

import java.util.Scanner;
import java.util.Stack;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Character> st = new Stack<>();
        boolean check = true;

        String input = sc.nextLine();
        while (!input.equals(".")) {
            st.clear();
            for (int j = 0; j < input.length(); j++) {
                if (input.charAt(j) == '(' || input.charAt(j) == '[') {
                    st.push(input.charAt(j));
                } else if (input.charAt(j) == ')' || input.charAt(j) == ']') {
                    if (st.isEmpty() || (st.peek() == '(' && input.charAt(j) == ']') || (
                        st.peek() == '[' && input.charAt(j) == ')')) {
                        check = false;
                        break;
                    } else {
                        st.pop();
                    }
                }
            }

            if (!st.isEmpty()) {
                check = false;
            }
            if (check) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            input = sc.nextLine();
            check = true;
        }

        sc.close();
    }
}
