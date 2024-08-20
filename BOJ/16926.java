import java.util.*;
import java.io.*;

public class Main {
	static int[][] m = new int[305][305];
	static int flow, N, M, R;
	
	static void rotate() {
		for(int i = 0; i < flow; i++) {
			int[] tmp = {m[N-i-1][i], m[N-i-1][M-i-1], m[i][M-i-1], m[i][i]};
			for(int j = N-i-1; j > i; j--) {
				m[j][i] = m[j-1][i];
			}
			for(int j = M-i-1; j > i; j--) {
				m[N-i-1][j] = m[N-i-1][j-1];
			}
			for(int j = i; j < N - i - 1; j++) {
				m[j][M-i-1] = m[j+1][M-i-1];
			}
			for(int j = i; j < M - i - 1; j++) {
				m[i][j] = m[i][j+1];
			}
			m[N-i-1][i+1] = tmp[0];
			m[N-i-2][M-1-i] = tmp[1];
			m[i][M-2-i] = tmp[2];
		}
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i < N; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j = 0; j < M; j++) {
        		m[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        
        flow = Math.min(N, M)/2;
        
        for(int i = 0; i < R; i++) rotate();
        
        for(int i = 0; i < N; i++) {
        	for(int j = 0; j < M; j++) {
        		bw.write(m[i][j] +" ");
        	}
        	bw.write("\n");
        }
        
        bw.flush();
        bw.close();
    }
}
