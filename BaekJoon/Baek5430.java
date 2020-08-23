//Queue Deque
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.LinkedList;

class Main{
	static boolean r = false;
	static boolean error = false;
	static Deque<Integer> dq = new LinkedList<>();
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try{
			int num = Integer.parseInt(br.readLine());
			for(int i=0;i<num;i++){
				error = false;
				r = false;
				String[] input = br.readLine().split("");
				int cnt = Integer.parseInt(br.readLine());
				String value = br.readLine();
				value = value.substring(1,value.length()-1);
				String[] numbers = value.split(",");
				for(int j=0;j<cnt;j++){
					dq.add(Integer.parseInt(numbers[j]));
				}

				for(int j=0;j<input.length;j++){
					compute(input[j]);
				}

				if(error == true)
					System.out.println("error");
				else {
					if(dq.isEmpty()){
						System.out.println("[]");
						continue;
					}
					StringBuilder sb = new StringBuilder("");
					sb.append("[");
					if(r == true){
						while(!dq.isEmpty()){
							sb.append(dq.pollLast()+",");
						}
					} else {
						while(!dq.isEmpty()){
							sb.append(dq.poll()+",");
						}
					}

					sb.delete(sb.length()-1, sb.length());
					sb.append("]");
					System.out.println(sb);
				}

			}

		} catch (IOException e){}
	}

	public static void compute(String in){
		if(in.equals("R")){
			if(r==true){
				r = false;
			} else
				r = true;
		} else if(in.equals("D")){
			if(dq.isEmpty()){
				error = true;
				return;
			}
			if(r == true){
				dq.pollLast();
			} else
				dq.poll();
		}
	}
}

