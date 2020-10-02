import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main{
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n, c;
		n = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
	
		int[] pos = new int[n];
		for(int i=0;i<n;i++){
			pos[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(pos);
		long left = 1;
		long right = pos[n-1]-pos[0];
		long mid = 0; 

		while(left<=right) {
			mid = (left+right)/2; 
			int count = 1;
			int wifi = pos[0];
			for(int i=1;i<n;i++){
				if(pos[i]-wifi>=mid){
					count++;
					wifi = pos[i];
				}
			} 
			if(count<c) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}

		System.out.println(right);
		br.close();
	}
}
