import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Collections;

class Baek2261 {

    static Point[] value;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        value = new Point[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            value[i] = new Point(x, y);
        }

        Arrays.sort(value, new xComparator());

        int answer = minDistance(0, n - 1);
        System.out.println(answer);
        br.close();

        return;
    }

    public static int minDistance(int begin, int end) {
        int size = end - begin + 1;
        if (size <= 3) {
            return searchMin(begin, end);
        }

        int mid = (begin + end) / 2;
        int d1 = minDistance(begin, mid);
        int d2 = minDistance(mid + 1, end);

        int result = Math.min(d1, d2);

        ArrayList<Point> mid_list = new ArrayList<>();

        for (int i = mid - 1; i >= begin; i--) {
            int xDist = value[mid].x - value[i].x;
            if ((xDist * xDist) < result) {
                mid_list.add(value[i]);
            } else {
                break;
            }
        }

        for (int i = mid + 1; i <= end; i++) {
            int xDist = value[mid].x - value[i].x;
            if ((xDist * xDist) < result) {
                mid_list.add(value[i]);
            } else {
                break;
            }
        }

        Collections.sort(mid_list, new yComparator());
        int mlist_size = mid_list.size();

        for (int i = 0; i < mlist_size - 1; i++) {
            for (int j = i + 1; j < mlist_size; j++) {
                int yDist = mid_list.get(i).y - mid_list.get(j).y;
                if (yDist * yDist < result) {
                    int dist = distance(mid_list.get(i), mid_list.get(j));
                    if (dist < result) {
                        result = dist;
                    }
                } else {
                    break;
                }
            }
        }
        return result;
    }

    public static int searchMin(int left, int right) {
        int answer = Integer.MAX_VALUE;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j <= right; j++) {
                int temp = distance(value[i], value[j]);
                if (temp < answer) {
                    answer = temp;
                }
            }
        }
        return answer;
    }

    public static int distance(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
}

class xComparator implements Comparator<Point> {

    public int compare(Point p1, Point p2) {
        return p1.x - p2.x;
    }
}

class yComparator implements Comparator<Point> {

    public int compare(Point p1, Point p2) {
        return p1.y - p2.y;
    }
}

class Point {

    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

