//시멘트 계산

import java.util.Scanner;
import java.util.Vector;

class Main {

    private static void solution(int day, int width, int[][] blocks) {
        int[] stack = new int[width];
        int left = -1;
        int right = -1;
        int ans = 0;

        for (int i = 0; i < day; i++) {
            Vector<Integer> areaL = new Vector<>();
            Vector<Integer> areaR = new Vector<>();

            for (int j = 0; j < width; j++) {
                stack[j] += blocks[i][j];
            }

            int j = 0;
            while (j < width - 1) {
                if (stack[j + 1] < stack[j]) {
                    left = j;
                    for (int k = left + 1; k < width; k++) {
                        if (k == width - 1) {
                            if (stack[k - 1] < stack[k]) {
                                right = k;
                                areaR.add(right);
                                break;
                            }
                        } else if (stack[k - 1] < stack[k] && stack[k + 1] < stack[k]) {
                            right = k;
                            areaR.add(right);
                            break;
                        }
                    }
                    if (right != -1) {
                        areaL.add(left);
                        j = right;
                        left = -1;
                        right = -1;
                    } else {
                        j = width - 1;
                    }
                } else {
                    j++;
                }
            }

            for (int fill = 0; fill < areaL.size(); fill++) {
                int min = Math.min(stack[areaL.elementAt(fill)], stack[areaR.elementAt(fill)]);
                for (int a = areaL.elementAt(fill) + 1; a < areaR.elementAt(fill); a++) {
                    ans += min - stack[a];
                    stack[a] = min;
                }
            }
        }
        System.out.println(ans);
    }

    private static class InputData {

        int day;
        int width;
        int[][] blocks;
    }

    private static InputData processStdin() {
        InputData inputData = new InputData();

        try (Scanner scanner = new Scanner(System.in)) {
            inputData.day = Integer.parseInt(scanner.nextLine().replaceAll("\\s+", ""));
            inputData.width = Integer.parseInt(scanner.nextLine().replaceAll("\\s+", ""));

            inputData.blocks = new int[inputData.day][inputData.width];
            for (int i = 0; i < inputData.day; i++) {
                String[] buf = scanner.nextLine().trim().replaceAll("\\s+", " ").split(" ");
                for (int j = 0; j < inputData.width; j++) {
                    inputData.blocks[i][j] = Integer.parseInt(buf[j]);
                }
            }
        } catch (Exception e) {
            throw e;
        }

        return inputData;
    }

    public static void main(String[] args) throws Exception {
        InputData inputData = processStdin();

        solution(inputData.day, inputData.width, inputData.blocks);
    }
}
