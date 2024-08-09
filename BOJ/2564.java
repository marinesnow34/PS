import java.util.*;
import java.io.*;

public class Main {
	static int map_x, map_y;
	static Store[] stores = new Store[105];
	static class Store{
		int x;
		int y;
		int direction;
		
		Store(int direction, int distance){
			this.direction = direction;
			if(direction==1) {
				this.x = map_x;
				this.y = distance;
			}
			else if(direction==2) {
				this.x = 0;
				this.y = distance;
			}
			else if(direction==3) {
				this.x = map_x-distance;
				this.y = 0;
			}
			else if(direction==4) {
				this.x = map_x-distance;
				this.y = map_y;
			}
		}
		
		int calcMinDistance(Store another) {
			int x = another.x;
			int y = another.y;
			int diff_x = Math.abs(x - this.x);
			int diff_y = Math.abs(y - this.y);
			
			//동일 선상
			if(this.direction == another.direction) return Math.max(diff_x, diff_y);
			
			int tmp_x = Math.min(Math.min(x, this.x), map_x - Math.max(x,this.x))*2;
			int tmp_y = Math.min(Math.min(y, this.y), map_y - Math.max(y,this.y))*2;
			return tmp_x + diff_x + tmp_y + diff_y;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		map_y = Integer.parseInt(st.nextToken());
		map_x = Integer.parseInt(st.nextToken());
		
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			stores[i] = new Store(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		}
		
		st = new StringTokenizer(br.readLine());
		Store dong = new Store(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		
		int res = 0;
		for(int i = 0; i < N; i++) {
			res += stores[i].calcMinDistance(dong);
//			System.out.println(stores[i].calcMinDistance(dong));
		}
		System.out.println(res);
	}
}
