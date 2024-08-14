import java.util.*;
import java.io.*;

public class Main {
	// 방 N * M
	// 청소기 방향 동,서,남,북
	// 좌상단 0,0
	
	// 처음에 빈 칸은 전부 청소 되지 않은 상태
	
	//1.현재칸이 청소 X 현재칸 청소
	//2.주변 4칸 모두 청소 불가
	///1칸 후진
	///불가능하면 stop
	//3.주변 4칸 중 청소 가능 존재
	///반시계 90도 회전
	///앞칸 청소 안됐으면 전진
	
	static int[][] map = new int[55][55];
	static int sol = 0, N, M;
	
	static class Robot{
		//                    동 북 서 남
		static int[] moveX = {0,-1,0,1};
		static int[] moveY = {1,0,-1,0};
		int x;
		int y;
		int direction;
		boolean status;
		Robot(int x, int y, int direction){
			this.x = x;
			this.y = y;
			if(direction == 0) {
				this.direction = 1;				
			}
			else if(direction == 1) {
				this.direction = 0;				
			}
			else if(direction == 2) {
				this.direction = 3;				
			}
			else if(direction == 3) {
				this.direction = 2;				
			}
			this.status = true;
		}
		void go() {
			cleanNow();
			if(canClean()) {
				for(int i = 0; i < 4; i++) {
					direction = (direction + 1) % 4; 
					int nx = x + moveX[direction], ny = y + moveY[direction];
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(map[nx][ny] == 0) {
						this.x = nx;
						this.y = ny;
						break;
					}
				}
			}
			else {
				goBack();
			}
		}
		void goBack() {
			int backDirection = (direction+2)%4;
			int nx = x + moveX[backDirection], ny = y + moveY[backDirection];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 1) {
				status = false;
				return;
			}
			this.x = nx;
			this.y = ny;
		}
		void cleanNow() {
			if(map[x][y] == 0) {
				map[x][y] = 2;
				sol++;
			}
		}
		boolean canClean() {
			for(int i = 0; i < 4; i++) {
				int nx = x + moveX[i], ny = y + moveY[i];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if(map[nx][ny] == 0) return true;
			}
			
			return false;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		Robot robot = new Robot(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		while(robot.status) {
			robot.go();
		}
		System.out.println(sol);
	}
}
