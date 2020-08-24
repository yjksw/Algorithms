//Back-tracking N-queen
import java.io.*;
//import java.util.Iterator;
//import java.util.Stack;
//import java.util.StringTokenizer;

class Main{
	
	static int result;
	static int n;
	//static Stack<Integer> st = new Stack<>();
	static int[] position;
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = "";
		
		try{
			input = br.readLine();
			br.close();
		} catch (IOException e){}

		n = Integer.parseInt(input);
		position = new int[n];
		int count = 1;
		result = 0;
		for(int i=0;i<n;i++){
			//st.push(i);
			position[0]=i;
			nqueen(count);
			//st.pop();
		}
		System.out.println(result);
	}

	public static void nqueen(int cnt){
		if(cnt == n){
			result++;
			return;
		}
		repeat: for(int i=0;i<n;i++){
			//Iterator value = st.iterator();
			//int index=0;
			//while(value.hasNext()){
			for(int j=0;j<cnt;j++){
				//int temp=(int)value.next();
				if(Math.abs(j-cnt)==Math.abs(position[j]-i))
					continue repeat;
				if(position[j]==i)
					continue repeat;
				//index++;
			}
			//st.push(i);
			position[cnt]=i;
			nqueen(cnt+1);
			//st.pop();
		}
	}
}
