//back-tracking`

import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;

class Baek15649 {

    public static Stack<Integer> st = new Stack<>();
    public static int cnt = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        sc.close();

        DFS(n, m);
    }

    public static void DFS(int num, int count) {
        if (cnt == count) {
            print();
            return;
        }
        for (int i = 1; i <= num; i++) {
            if (st.search(i) != -1) {
                continue;
            }
            st.push(i);
            cnt++;
            DFS(num, count);
            st.pop();
            cnt--;
        }
    }

    public static void print() {
        Iterator value = st.iterator();
        while (value.hasNext()) {
            System.out.printf("%d ", value.next());
        }

        System.out.print("\n");
    }
}
