//Dynamic Programming
import java.util.Scanner;

class Main{
	static int[] memo;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		sc.close();

		memo = new int[n+1];
		memo[1] = 0;
		solve(n);
		
		System.out.println(memo[n]);
	}

	public static void solve(int cnt){
		if(cnt == 1)
			return;
		if(cnt == 2){
			memo[2] = 1;
			return;
		}
		if(cnt == 3){
			memo[3] = 1;
			return;
		}

		if(memo[cnt]!=0)
			return;
		if(cnt%3==0){
			solve(cnt/3);
			solve(cnt-1);
			memo[cnt] = Math.min(memo[cnt/3], memo[cnt-1])+1;
		}
		else if(cnt%2==0){
			solve(cnt/2);
			solve(cnt-1);
			memo[cnt] = Math.min(memo[cnt/2], memo[cnt-1])+1;
		}
		else {
			solve(cnt-1);
			memo[cnt] = memo[cnt-1]+1;
		}
		return;
	}
}
