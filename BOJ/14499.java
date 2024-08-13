import java.util.*;
import java.io.*;

public class Main {
	//지도 크기 N*M
	//좌상단 0,0
	// 가로배열
	// 세로배열
	// 위아래만 갱신
	
	// 동일 방향이면 밀고
	// 다른 방향이면 위 아래 만 변경
	static int[][] map = new int[25][25];
	static int[] row = new int[4];
	static int[] column = new int[4];
	static int N;
	static int M;
	static int x;
	static int y;
	
	static int R() {
		if(y+1 >= M) return -1;
		y++;
		int tmp = row[0];
		for(int i = 0; i < 3; i++) row[i] = row[i+1];
		row[3] = tmp;
		if(map[x][y] == 0) {
			map[x][y] = row[0];
//			row[0] = 0;
		}
		else {
			row[0] = map[x][y];
			map[x][y] = 0;
		}
		column[0] = row[0];
		column[2] = row[2];
		return row[2];
	}
	static int L() {
		if(y-1 < 0) return -1;
		y--;
		int tmp = row[3];
		for(int i = 3; i > 0; i--) row[i] = row[i-1];
		row[0] = tmp;
		if(map[x][y] == 0) {
			map[x][y] = row[0];
//			row[0] = 0;
		}
		else {
			row[0] = map[x][y];
			map[x][y] = 0;
		}
		column[0] = row[0];
		column[2] = row[2];
		return row[2];
	}
	static int D() {
		if(x+1 >= N) return -1;
		x++;
		int tmp = column[0];
		for(int i = 0; i < 3; i++) column[i] = column[i+1];
		column[3] = tmp;
		if(map[x][y] == 0) {
			map[x][y] = column[0];
//			column[0] = 0;
		}
		else {
			column[0] = map[x][y];
			map[x][y] = 0;
		}
		row[0] = column[0];
		row[2] = column[2];
		return column[2];
	}
	static int U() {
		if(x-1 < 0) return -1;
		x--;
		int tmp = column[3];
		for(int i = 3; i > 0; i--) column[i] = column[i-1];
		column[0] = tmp;
		if(map[x][y] == 0) {
			map[x][y] = column[0];
//			column[0] = 0;
		}
		else {
			column[0] = map[x][y];
			map[x][y] = 0;
		}
		row[0] = column[0];
		row[2] = column[2];
		return column[2];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < k ; i++) {
			int cmd = Integer.parseInt(st.nextToken());
			int res = -1;
			if(cmd == 1) {
				res = R();
			}
			else if(cmd == 2) {
				res = L();
			}
			else if(cmd == 3) {
				res = U();
			}
			else if(cmd == 4) {
				res = D();
			}
			if(res != -1) bw.write(res+"\n");
		}
		
		bw.flush();
		bw.close();
	}
}
