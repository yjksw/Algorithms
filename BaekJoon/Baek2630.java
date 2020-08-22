//DAC
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
	static int[][] arr;
	static int b = 0;
	static int w = 0;
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			int n = Integer.parseInt(br.readLine());
			arr = new int[n][n];
			for(int i=0; i<n; i++){
				String[] temp = br.readLine().split(" ");
				for(int j=0;j<n;j++){
					arr[i][j] = Integer.parseInt(temp[j]);
				}
			}

			solve(0, 0, n);


		} catch (IOException e) {}

		System.out.println(w);
		System.out.println(b);
	}

	public static void solve(int x, int y, int size){
		int num = arr[x][y];
		for(int i=x;i<x+size;i++){
			for(int j=y;j<y+size;j++){
				if(num != arr[i][j]){
					solve(x, y, size/2);
					solve(x+size/2, y, size/2);
					solve(x, y+size/2, size/2);
					solve(x+size/2, y+size/2, size/2);
					return;
				}
			}
		}
		if(num == 1) 
			b++;
		else 
			w++;
		return;
	}
}
