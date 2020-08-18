//Stack
import java.util.Scanner;
import java.util.Stack;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());

check: for(int i=0;i<n;i++){
			Stack<Integer> st = new Stack<>();
			String input = sc.nextLine();
			for(int j=0;j<input.length();j++){
				if(input.charAt(j) == '(')
					st.push(1);
				else if(input.charAt(j) == ')'){
					if(st.isEmpty()){
						System.out.println("NO");
						continue check;
					}
					st.pop();
				}
			}

			if(st.isEmpty())
				System.out.println("YES");
			else
				System.out.println("NO");
		}

		sc.close();
	}
}
