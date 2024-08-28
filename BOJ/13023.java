import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		s = new HashSet[N];
		for(int i = 0; i < N; i++) s[i] = new HashSet<>();
		for(int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			s[a].add(b);
			s[b].add(a);
		}
		
		
		for(int i = 0; i < N; i++) {
			vis = new HashSet<>();
			vis.add(i);
			dfs(i,0);
            if(flag) break;
		}
		if(flag) System.out.println(1);
		else System.out.println(0);
	}
	static Set<Integer> vis;
	static Set<Integer>[] s;
	static boolean flag;
	static void dfs(int i, int j) {
		if(j == 4) {
			flag = true;
            return;
		}
		for(int tmp: s[i]) {
			if(vis.contains(tmp)) continue;
			vis.add(tmp);
			dfs(tmp, j + 1);
			vis.remove(tmp);
		}
	}
}
