//back-tracking

import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;
import java.io.*;
import java.util.StringTokenizer;

class Baek15651 {

    public static Stack<Integer> st = new Stack<>();
    public static int cnt = 0;
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        try {
            input = br.readLine();
        } catch (IOException e) {
        }
        StringTokenizer st = new StringTokenizer(input);

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        DFS(n, m);

        System.out.println(sb);
    }

    public static void DFS(int num, int count) {
        if (cnt == count) {
            print();
            return;
        }
        for (int i = 1; i <= num; i++) {
            //if(st.search(i) != -1)
            //	continue;
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
            sb.append(value.next() + " ");
        }

        sb.append("\n");
    }
}
