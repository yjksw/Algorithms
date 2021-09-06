//Dynamic Programming

import java.util.Scanner;
import java.util.LinkedList;

class Baek1541 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> num = new LinkedList<>();
        LinkedList<Character> op = new LinkedList<>();
        LinkedList<Integer> n_num = new LinkedList<>();
        LinkedList<Character> n_op = new LinkedList<>();

        String m = sc.nextLine();
        sc.close();

        String n = "";
        for (int i = 0; i < m.length(); i++) {
            char ch = m.charAt(i);

            if (ch == '+' || ch == '-') {
                num.add(Integer.parseInt(n));
                op.add(ch);
                n = "";
                continue;
            }
            n += ch;
        }
        num.add(Integer.parseInt(n));

        int cnt = 0;
        int size = op.size();
        while (cnt < size) {
            int prevnum = num.poll();
            int nextnum = num.poll();
            char oper = op.poll();

            if (oper == '+') {
                num.addFirst(prevnum + nextnum);
            }
            if (oper == '-') {
                n_num.add(prevnum);
                n_op.add(oper);
                num.addFirst(nextnum);
            }
            cnt++;
        }
        n_num.add(num.poll());

        while (!n_op.isEmpty()) {
            int prevnum = n_num.poll();
            int nextnum = n_num.poll();
            char oper = n_op.poll();

            n_num.addFirst(prevnum - nextnum);
        }

        System.out.println(n_num.poll());
    }
}
