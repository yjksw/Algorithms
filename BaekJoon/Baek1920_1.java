//Binary Search
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main{
	static int n;
	static int m;
	static int[] n_list;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		n = Integer.parseInt(br.readLine());
		n_list = new int[n];

		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++){
			n_list[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(n_list);
		m = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++){
			search(0, n-1, Integer.parseInt(st.nextToken()));
		}
		
		br.close();
	
	}

	static void search(int start, int end, int num){
		int mid = (start+end)/2;
		if(n_list[mid] == num){
			System.out.println(1);
			return;
		}
		
		if(start > end){
			System.out.println(0);
			return;
		}

		if(n_list[mid] > num){
			search(start, mid-1, num);
		} else if(n_list[mid] < num){
			search(mid+1, end, num);
		}
	}
}	

