//Dynamic Programming
import java.util.Scanner;

class Main {

  static int n;
  static long[][] count;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    int[] list = new int[n];
    for(int i=0;i<n;i++){
      list[i] = sc.nextInt();
    }
    count = new long[41][2];
    count[0][0] = 1;
    count[0][1] = 0;

    count[1][0] = 0;
    count[1][1] = 1;
    sc.close();
    //fibo = new long[n+1];

    for(int i=0;i<n;i++){
      solu(list[i]);
      System.out.println(count[list[i]][0]+" "+count[list[i]][1]);
    }
  }

  public static void solu(int num){
    if(num==0 || num==1){
      return;
    }

    solu(num-1);
    //for(int i=2;i<=num;i++){
      count[num][0] = count[num-1][0] + count[num-2][0];
      count[num][1] = count[num-1][1] + count[num-2][1];
    //}
    return;
  }
}
