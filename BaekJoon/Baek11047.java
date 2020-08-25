//Greedy Algorithm
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int[] value = new int[n];

    for(int i=0;i<n;i++){
      value[i] = sc.nextInt();
    }
    sc.close();

    int sum = 0;
    int result = 0;
    for(int i=n-1;i>=0;i--){
      while(true){
        if(sum+value[i]>k)
          break;
        else {
          result++;
          sum += value[i];
        }
      }
    }

    System.out.println(result);
  }
}
