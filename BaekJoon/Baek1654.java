import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int k, n;
		k = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		int[] input = new int[k];
		for(int i=0;i<k;i++){
			input[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(input);
		long left = 1;
		long right = input[k-1];
		long middle = 0;

		System.out.println(right);
		while(left <= right){ 
			long mid = (left+right)/2;
			int count = 0;
			for(int i=0;i<k;i++){
				count += input[i]/mid;
			}
			if(count < n){
				right = mid-1;
			} else {
				left = mid+1; 
			}
		}

		
		System.out.println(right);

	
	}
}
