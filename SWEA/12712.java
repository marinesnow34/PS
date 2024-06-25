import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
	public static void main(String args[]) throws Exception {
    Scanner sc = new Scanner(System.in);
    int T;
    T = sc.nextInt();

    int[] dx1 = { 1, -1, 0, 0 };
    int[] dy1 = { 0, 0, 1, -1 };
    int[] dx2 = { 1, 1, -1, -1 };
    int[] dy2 = { 1, -1, 1, -1 };

    for (int test_case = 1; test_case <= T; test_case++) {
      int m = 0;
      int N = sc.nextInt();
      int M = sc.nextInt();
      int[][] fly = new int[N][N];
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          fly[i][j] = sc.nextInt();

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          int cnt1 = fly[i][j], cnt2 = fly[i][j];
          for (int k = 0; k < 4; k++) {
            for (int l = 1; l <= M - 1; l++) {
              int new_x1 = i + dx1[k] * l;
              int new_y1 = j + dy1[k] * l;
              int new_x2 = i + dx2[k] * l;
              int new_y2 = j + dy2[k] * l;
              if (0 <= new_x1 && new_x1 < N && 0 <= new_y1 && new_y1 < N) {
                cnt1 += fly[new_x1][new_y1];
              }
              if (0 <= new_x2 && new_x2 < N && 0 <= new_y2 && new_y2 < N) {
                cnt2 += fly[new_x2][new_y2];
              }
            }
          }
          m = Math.max(m, Math.max(cnt1, cnt2));
        }
      }
      System.out.print("#" + test_case + " " + m + "\n");
    }
  }
}
