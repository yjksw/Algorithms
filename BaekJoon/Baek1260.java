//DFS BFS

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Arrays;

class Baek1260 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int start = sc.nextInt();
        int[][] graph = new int[n][n];
        int[] visited = new int[n];
        int flag = 0;

        for (int i = 0; i < m; i++) {
            graph[sc.nextInt() - 1][sc.nextInt() - 1] = 1;
        }
        Stack<Integer> st = new Stack<>();
        LinkedList<Integer> qu = new LinkedList<>();
        st.push(start);
        visited[start - 1] = 1;
        System.out.print(start);

        //DFS w/ Stack
        while (!st.empty()) {
            int num = st.peek();
            search:
            for (int i = 0; i < n; i++) {
                if (graph[num - 1][i] == 1 && visited[i] != 1) {
                    st.push(i + 1);
                    visited[i] = 1;
                    System.out.printf(" %d", (i + 1));
                    break search;
                }
                if (graph[i][num - 1] == 1 && visited[i] != 1) {
                    st.push(i + 1);
                    visited[i] = 1;
                    System.out.printf(" %d", i + 1);
                    break search;
                }
            }
            if (num == st.peek()) {
                st.pop();
            }
        }

        Arrays.fill(visited, 0);
        System.out.print("\n" + start);
        qu.add(start);
        visited[start - 1] = 1;
        //BFS w/ Queue
        while (!qu.isEmpty()) {
            int num = qu.peek();
            search2:
            for (int i = 0; i < n; i++) {
                if (graph[num - 1][i] == 1 && visited[i] != 1) {
                    qu.add(i + 1);
                    visited[i] = 1;
                    System.out.printf(" %d", i + 1);
                    break search2;//search;
                }
                if (graph[i][num - 1] == 1 && visited[i] != 1) {
                    qu.add(i + 1);
                    visited[i] = 1;
                    System.out.printf(" %d", i + 1);
                    break search2;//search;
                }
                if (i == (n - 1)) {
                    flag = 1;
                }
            }
            if (flag == 1) {
                qu.poll();
                flag = 0;
            }
        }
    }
}
