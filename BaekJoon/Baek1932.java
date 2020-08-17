//Dynamic Programming
import java.util.Scanner;
import java.util.Arrays;

class Main{
	static int[][] value;
	static int[][] result;
	static int n;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		value = new int[n][n];
		result = new int[n][n];

		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++){
				value[i][j] = sc.nextInt();
			}
		}
			
		result[0][0] = value[0][0];
		solve(n-1);
		
		int[] temp = new int[n];
		temp = result[n-1];
		Arrays.sort(temp);
		System.out.println(temp[n-1]);
	}

	public static void solve(int cnt){
		if(cnt==0){
			return;
		}

		solve(cnt-1);

		for(int i=0;i<=cnt;i++){
			if(i==0)
				result[cnt][i] = result[cnt-1][i]+value[cnt][i];
			else if(i==cnt)
				result[cnt][i] = result[cnt-1][i-1]+value[cnt][i];
			else
				result[cnt][i] = value[cnt][i]+Math.max(result[cnt-1][i-1],result[cnt-1][i]);
		}
		return;
	}
}
