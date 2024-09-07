import java.util.*;
import java.io.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(br.readLine());
		for(int t= 1; t <=T; t++) {
			int N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			
			int[] arr = new int[N];
			int e = 0, o = 0, max = Integer.MIN_VALUE;
			for(int i =0;i<N;i++) {
				arr[i] = Integer.parseInt(st.nextToken());
				max = Math.max(arr[i], max);
			}
			for(int i =0;i<N;i++) {
				if(arr[i] == max) continue;
				if((max-arr[i]) % 2 == 0) e += (max-arr[i])/2;
				else {
					o++;
					e+=(max-arr[i])/2;
				}
			}
			
			int time = 0, m = Math.min(o, e);
			o -= m;
			e -= m;
			time += m * 2;
			if(o != 0) {
				time += 1;
				o--;
				time += o * 2;
			}
			if(e != 0) {
				time += e / 3 * 4;
				if(e%3 == 1) time +=2;
				if(e%3 == 2) time +=3;
			}
			
			System.out.printf("#%d %d\n", t, time);
		}
	}
}
