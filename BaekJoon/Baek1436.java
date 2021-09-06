import java.util.Scanner;

class Baek1436 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int check = 0;
        int num = 666;
        int result = 0;
        while (true) {
            if (String.valueOf(num).contains("666")) {
                check++;
            }
            if (check == n) {
                break;
            }
            num++;
        }

        System.out.println(num);
    }
}

