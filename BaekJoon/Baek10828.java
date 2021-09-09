//Stack

import java.util.Scanner;
import java.util.Stack;


class Baek10828 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Stack<Integer> st = new Stack<>();

        int num = 0;
        for (int i = 0; i < n; i++) {
            String command = sc.next();
            if (command.equalsIgnoreCase("push")) {
                num = sc.nextInt();
                st.push(num);
            } else if (command.equalsIgnoreCase("pop")) {
                if (st.empty()) {
                    num = -1;
                } else {
                    num = st.pop();
                }
                System.out.println(num);
                //System.out.println(st.isEmpty()?-1:st.pop());
            } else if (command.equalsIgnoreCase("size")) {
                num = st.size();
                System.out.println(num);
            } else if (command.equalsIgnoreCase("empty")) {
                boolean empty = st.empty();
                if (empty) {
                    num = 1;
                } else {
                    num = 0;
                }
                System.out.println(num);
                //System.out.println(st.isEmpty()?1:0);
            } else if (command.equalsIgnoreCase("top")) {
                if (st.empty()) {
                    num = -1;
                } else {
                    num = st.peek();
                }
                System.out.println(num);
                //System.out.println(st.isEmpty()?-1:st.peek());
            }
        }
    }
}
