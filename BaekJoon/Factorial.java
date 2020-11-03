//Recursion
import java.util.Scanner;

public class Factorial {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int result = factorial(n);
		System.out.println(result);
	}

	public static int factorial(int num){
		if(num == 1|| num == 0)
			return 1;
		else 
			return num*factorial(num-1);
	}
}
