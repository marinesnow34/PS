import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    public static void main(String args[]) throws Exception{
    Scanner sc = new Scanner(System.in);
      int T;
      T=sc.nextInt();
 
      for(int test_case = 1; test_case <= T; test_case++) {
        int N = sc.nextInt();
        int M = sc.nextInt();
         
        int[] A = new int[N];
        int[] B = new int[M];
        for(int i = 0; i < N; i++)
          A[i] = sc.nextInt();
        for(int i = 0; i < M; i++)
          B[i] = sc.nextInt();
 
        if(M > N) {
          int tmp = N;
          N = M;
          M = tmp;
          int[] tmpArr = A;
          A = B;
          B = tmpArr;
        }
 
        int m = 0;
        for(int i = 0; i <= N - M; i++){
          int tmp = 0;
          for(int j = i; j < i + M; j++){
            tmp += A[j] * B[j - i];
          }
          m = Math.max(tmp, m);
        }
        System.out.print("#"+test_case+" "+m + "\n");
      }
  }
}
