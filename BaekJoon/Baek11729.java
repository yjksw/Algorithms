//Recursion
import java.util.Scanner;

public class Baek11729{

	public static StringBuilder str = new StringBuilder();
	public static int count = 0;

	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		hanoi(1, 3, 2, n);
		System.out.println(count);
		System.out.println(str.toString());
		return;

	}

	public static void move(int src, int dest){
		count++;
		str.append(src+" "+dest);
		str.append(System.lineSeparator());
		//str = str+"\n"+temp;
		//System.out.println(src+" "+dest);
		return;
	}

	public static void hanoi(int src, int dest, int temp, int num){
		if(num == 1){
			move(src, dest);
			return;
		}
		hanoi(src, temp, dest, num-1);
		hanoi(src, dest, temp, 1);
		hanoi(temp, dest, src, num-1);
	}
}
