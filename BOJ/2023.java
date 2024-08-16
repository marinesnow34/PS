import java.io.*;
import java.util.*;

public class Main {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static boolean isPrime(int n, int i) {
		if(n == 2) return true;
		if(i * i > n) return true;
		if(n%i == 0) return false;
		return isPrime(n, i+1);
	}
	
	static void make(int i, int n, Integer N) throws IOException {
		if(n == N) {
			bw.write(i+ "\n");
			return;
		}
		i *= 10;
		for(int j = 1; j < 10; j+=2) {
			if(isPrime(i+j,2)) {				
				make(i+j, n+1,N);
			}
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		Integer N = sc.nextInt();
		
		for(int i = 2; i < 8; i++) {
			if(isPrime(i, 2)) {
				make(i, 1, N);
			}
		}
		bw.flush();
		bw.close();
	}
}
