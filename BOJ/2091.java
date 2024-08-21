import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int[] coin = new int[4];
		int target = sc.nextInt();
		for(int i = 0; i < 4; i++) {
			coin[i] = sc.nextInt();
		}
//		Arrays.sort(coin);
		
		int[][] dp = new int[target+5][5];
		for(int i = 0; i <= target; i++) {
//			System.out.printf("%d: %d %d %d %d %d\n",i,dp[i][0],dp[i][1],dp[i][2],dp[i][3],dp[i][4]);
			if(i + 1 <= target) {
				if(dp[i+1][4] < dp[i][4] + 1 && dp[i][0] + 1 <= coin[0]) {
					if(dp[i][0] + dp[i][1]*5 + dp[i][2] * 10 + dp[i][3] * 25 + 1 == i+1) {
						for(int j = 0; j < 5; j++) dp[i+1][j] = dp[i][j];
						dp[i+1][0]++;
						dp[i+1][4]++;
					}
				}
			}
			if(i + 5 <= target) {
				if(dp[i+5][4] < dp[i][4] + 1 && dp[i][1] + 1 <= coin[1]) {
					if(dp[i][0] + dp[i][1]*5 + dp[i][2] * 10 + dp[i][3] * 25 + 5 == i+5) {
						for(int j = 0; j < 5; j++) dp[i+5][j] = dp[i][j];
						dp[i+5][1]++;
						dp[i+5][4]++;
					}
				}
			
			}
			if(i + 10 <= target) {
				if(dp[i+10][4] < dp[i][4] + 1 && dp[i][2] + 1 <= coin[2]) {
					if(dp[i][0] + dp[i][1]*5 + dp[i][2] * 10 + dp[i][3] * 25 + 10 == i+10) {
						for(int j = 0; j < 5; j++) dp[i+10][j] = dp[i][j];
						dp[i+10][2]++;
						dp[i+10][4]++;
					}
				}
			}
			if(i + 25 <= target) {
				if(dp[i+25][4] < dp[i][4] + 1 && dp[i][3] + 1 <= coin[3]) {
					if(dp[i][0] + dp[i][1]*5 + dp[i][2] * 10 + dp[i][3] * 25 + 25 == i+25) {
						for(int j = 0; j < 5; j++) dp[i+25][j] = dp[i][j];
						dp[i+25][3]++;
						dp[i+25][4]++;
					}
				}
			}
		}
		for(int i = 0; i < 4; i ++) pw.printf("%d ", dp[target][i]);
		pw.close();
	}

}
