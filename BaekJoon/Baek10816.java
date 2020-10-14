import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main{
	static int[] num_list;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder("");

		int n = Integer.parseInt(br.readLine());
		num_list = new int[n];
		st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<n;i++){
			num_list[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(num_list);

		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<m;i++){
			int find = Integer.parseInt(st.nextToken());
			int result = searchUpper(0, n, find) - searchLower(0, n, find);
			sb.append(result);
			sb.append(" ");
		}

		System.out.println(sb);
		br.close();
	}

	static int searchUpper(int start, int end, int num){
		if(start>=end)
			return start;
		
		int mid = (start+end)/2;
		
		if(num_list[mid] <= num){
			return searchUpper(mid+1, end, num);
		} else {
			return searchUpper(start, mid, num);
		}
	}

	static int searchLower(int start, int end, int num) {
		if(start>=end)
			return start;
		
		int mid = (start+end)/2;
		
		if(num_list[mid] >= num){
			return searchLower(start, mid, num);
		} else {
			return searchLower(mid+1, end, num);
		}
	}
}
