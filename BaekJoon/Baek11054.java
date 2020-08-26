//Dynamic Programming
import java.util.Scanner;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] input = new int[n];
    int[] inc = new int[n];
    int[] dec = new int[n];

    for(int i=0;i<n;i++){
      input[i] = sc.nextInt();
    }
    sc.close();

    inc[0] = 1;
    dec[n-1] = 1;
    for(int i=1;i<n;i++){
      inc[i] = 1;
      dec[n-1-i] = 1;
      for(int j=0;j<i;j++){
        if(input[i]>input[j] && inc[i]<inc[j]+1){
          inc[i] = inc[j]+1;
        }
        if(input[n-1-i] > input[n-1-j] && dec[n-1-i]<dec[n-1-j]+1){
          dec[n-1-i] = dec[n-1-j]+1;
        }
      }
    }

    for(int i=0;i<n;i++){
      inc[i]+= dec[i]-1;
    }
    Arrays.sort(inc);
    System.out.println(inc[n-1]);
  }
}
