//Queue

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Deque;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Deque<Integer> dq = new LinkedList<>();

        int num = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            String command = sc.next();
            if (command.equalsIgnoreCase("push")) {
                num = sc.nextInt();
                last = num;
                dq.add(num);
            } else if (command.equalsIgnoreCase("pop")) {
                if (dq.isEmpty()) {
                    num = -1;
                } else {
                    num = dq.pop();
                }
                System.out.println(num);
            } else if (command.equalsIgnoreCase("size")) {
                num = dq.size();
                System.out.println(num);
            } else if (command.equalsIgnoreCase("empty")) {
                boolean empty = dq.isEmpty();
                if (empty) {
                    num = 1;
                } else {
                    num = 0;
                }
                System.out.println(num);
            } else if (command.equalsIgnoreCase("front")) {
                if (dq.isEmpty()) {
                    num = -1;
                } else {
                    num = dq.getFirst();
                }
                System.out.println(num);
            } else if (command.equalsIgnoreCase("back")) {
                if (dq.isEmpty()) {
                    num = -1;
                } else {
                    System.out.println(last);
                }
            }
        }
    }
}

