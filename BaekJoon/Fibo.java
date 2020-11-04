//Recursion
import java.util.Scanner;

class Fibo{
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int result = fibo(n);
		System.out.println(result);
	}

	public static int fibo(int num){
		if(num==0)
			return 0;
		else if(num==1)
			return 1;
		else {
			return fibo(num-1)+fibo(num-2);
		}
	}
}

