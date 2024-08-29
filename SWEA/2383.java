import java.io.*;
import java.util.*;
public class Solution {
	//브포
	static List<Stair> stairs;
	static List<Person> persons;
	static class Person{
		int x;
		int y;
		public Person(int x, int y) {
			this.x = x;
			this.y = y;
		}
		int calcDistance(Stair s) {
			return Math.abs(this.x -s.x) + Math.abs(this.y -s.y);
		}
	}
	
	static class Stair{
		int x;
		int y;
		int cost;
		Queue<Integer> pq;
		public Stair(int x, int y, int cost) {
			this.x = x;
			this.y = y;
			this.cost = cost;
		}
		int calcTime(Deque<Integer> dq) {
			pq = new PriorityQueue<>(dq);
			Queue<Integer> st = new ArrayDeque<>();
			int time = 0;
			while(!pq.isEmpty()) {
				int in = pq.poll() + 1;
				if(st.size() < 3) {
					st.add(in + cost);
				}
				else {
					int front = st.poll();
					time=front;
					if(front <= in) {
						st.add(in+cost);
					}
					else {
						st.add(front+cost);
					}
				}
			}
			while(!st.isEmpty()) time = st.poll(); 
			
			return time;
		}
	}
	
	static int size,sol;
	
	static Deque<Integer> dq1;
	static Deque<Integer> dq2;
	
	static void func(int n) {
		if(n == size) {
			sol = Math.min(sol, Math.max(stairs.get(0).calcTime(dq1), stairs.get(1).calcTime(dq2)));
			return;
		}
		dq1.addLast(persons.get(n).calcDistance(stairs.get(0)));
		func(n+1);
		dq1.pollLast();
		dq2.addLast(persons.get(n).calcDistance(stairs.get(1)));
		func(n+1);
		dq2.pollLast();
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++) {
			stairs = new ArrayList<>();
			persons = new ArrayList<>();
			int N = Integer.parseInt(br.readLine());
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					int tmp = Integer.parseInt(st.nextToken());
					if(tmp == 1) {
						persons.add(new Person(i, j));
					}
					if(tmp > 1) {
						stairs.add(new Stair(i, j, tmp));
					}
				}
			}
			dq1 = new ArrayDeque<>();
			dq2 = new ArrayDeque<>();
			size = persons.size();
			sol = Integer.MAX_VALUE;
			func(0);
			System.out.printf("#%d %d\n", t, sol);
		}
	}
}
