//Dynamic Programming
import java.util.Scanner;

class Main{
	static int n;	
	static int[] value;
	static int[] input;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		input = new int[n];
		value = new int[n];

		for(int i=0;i<n;i++){
			input[i] = sc.nextInt();
		}

		sc.close();

		solve(n-1);
		System.out.println(value[n-1]);

	}

	public static void solve(int cnt){
		if(cnt==0){
			value[0] = input[0];
			return; 
		} 
		if(cnt==1){
			solve(cnt-1);
			value[1] = input[0]+input[1];
			return;
		}
		if(cnt==2){
			solve(cnt-1);
			value[2] = Math.max(input[2]+input[1], input[2]+input[0]);
			return; 
		}

		solve(cnt-1);
		int case1 = input[cnt]+input[cnt-1]+value[cnt-3];
		int case2 = input[cnt]+value[cnt-2];
		value[cnt] = Math.max(case1, case2);
		return;		
	}
}
