import java.util.*;
import java.io.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N, M, K, A, B, sum;
	static int[] rTime, fTime;
	static Queue<Person> rWaitQ = new ArrayDeque<>();
	static Queue<Person> fWaitQ = new ArrayDeque<>();
	static Person[] receiptDo;
	static Person[] fixDo;
	
	static class Person{
		int id;
		int time;
		int receipt;
		int fix;
		public Person(int id, int time) {
			this.id = id;
			this.time = time;
		}
		@Override
		public String toString() {
			return String.format("{%d, %d}", id, time);
		}
	}
	
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			init();
			int time = -1, rCnt = 0, wCnt = 0;
			while(!rWaitQ.isEmpty() || !fWaitQ.isEmpty() || rCnt > 0 || wCnt > 0) {
				time++;
//				System.out.println(time);
//				System.out.println("rw "+rWaitQ);
//				System.out.println("fw "+fWaitQ);
//				System.out.println(Arrays.toString(receiptDo));
//				System.out.println(Arrays.toString(fixDo));
				for(int i = 0; i < M; i++) {
					if(fixDo[i] == null) continue;
					else if(fixDo[i].time == time) {
						if(fixDo[i].fix == B && fixDo[i].receipt == A) sum += fixDo[i].id;
						fixDo[i] = null;
						wCnt--;
					}
				}
				for(int i = 0; i < N; i++) {
					if(receiptDo[i] == null) continue;
					else if(receiptDo[i].time == time) {
						fWaitQ.add(receiptDo[i]);
						receiptDo[i] = null;
						rCnt--;
					}
				}
				while(rCnt < N && !rWaitQ.isEmpty() && rWaitQ.peek().time <= time) {
					for(int i = 0; i < N; i++) {
						if(receiptDo[i] == null) {
							rCnt++;
							receiptDo[i] = rWaitQ.poll();
							receiptDo[i].time = time + rTime[i];
							receiptDo[i].receipt = i + 1;
						}
						if(rWaitQ.isEmpty() || rWaitQ.peek().time > time) break;
					}
				}
				while(wCnt < M && !fWaitQ.isEmpty() && fWaitQ.peek().time <= time) {
					for(int i = 0; i < M; i++) {
						if(fixDo[i] == null) {
							wCnt++;
							fixDo[i] = fWaitQ.poll();
							fixDo[i].time = time + fTime[i];
							fixDo[i].fix = i + 1;
						}
						if(fWaitQ.isEmpty() || fWaitQ.peek().time > time) break;
					}
				}
				
			}
			
			System.out.printf("#%d %d\n",t, sum == 0 ? -1 : sum);
		}
	}
	static void init() throws Exception {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		sum = 0;
		st = new StringTokenizer(br.readLine());
		rTime = new int[N];
		receiptDo = new Person[N];
		fixDo = new Person[M];
		for(int i = 0; i < N; i++) rTime[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		fTime = new int[N];
		for(int i = 0; i < M; i++) fTime[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int id = 1;
		for(int i = 0; i < K; i++) rWaitQ.add(new Person(id++, Integer.parseInt(st.nextToken())));
	}
}
