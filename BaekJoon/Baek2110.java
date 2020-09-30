import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) throw IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n, c;
		int[] pos = new int[n];

		n = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<n;i++){
			pos[i] = Integer.parseInt(br.readLine());
		}




		br.close();
	}
}
