//Dynamic Programming
import java.util.Scanner;

class Main {

  static int n;
  static long[] count;
  static int[] input;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    input = new int[n];
    for(int i=0;i<n;i++){
      input[i] = sc.nextInt();
    }

    count = new long[101];
    count[0] = 0;
    count[1] = 1;
    count[2] = 1;

    sc.close();

    for(int i=0;i<n;i++){
      solu(input[i]);
      System.out.println(count[input[i]]);
    }


  }

  public static void solu(int num){
    if(num<3){
      return;
    }

    solu(num-1);
    count[num] = count[num-3] + count[num-2];
    return;
  }
}
