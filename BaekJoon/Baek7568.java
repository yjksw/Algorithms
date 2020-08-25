//Brute-force
import java.util.Scanner;

public class Baek7568{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] input = new int[n][2];

		for(int i=0;i<n;i++){
			input[i][0]=sc.nextInt();
			input[i][1]=sc.nextInt();
		}
		
		sc.close();
		find_rank(input, n);
		return;
	}

	public static void find_rank(int[][] in, int num){
		int count=0;
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(i==j)
					continue;
				if(in[i][0]<in[j][0] && in[i][1]<in[j][1])
					count++;
			}
			System.out.printf("%d ", count+1);
			count=0;
		}
		return;
	}
}

