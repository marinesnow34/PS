import java.util.Scanner;
import java.io.FileInputStream;

public class Main {
  public static void main(String args[]) throws Exception {
    Scanner sc = new Scanner(System.in);
    int T;
    T=sc.nextInt();

    for(int test_case = 1; test_case <= T; test_case++) {
      int N = sc.nextInt();
      int[][] arr = new int[N][N];
      String[][] sol = new String[N][3];
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
          arr[i][j] = sc.nextInt();
      }
      int[][] one = rotate(arr);
      int[][] two = rotate(one);
      int[][] three = rotate(two);

      System.out.print("#"+test_case+"\n");

      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          System.out.print(one[i][j]);
        }
        System.out.print(" ");
        for(int j = 0; j < N; j++){
          System.out.print(two[i][j]);
        }
        System.out.print(" ");
        for(int j = 0; j < N; j++){
          System.out.print(three[i][j]);
        }
        System.out.print("\n");
      }
    }
  }
  public static int[][] rotate(int arr[][]){
    int[][] tmp = new int[arr.length][arr.length];
    for(int i = 0; i < arr.length; i++){
      for(int j = 0; j < arr.length; j++){
        tmp[i][j] = arr[arr.length - j - 1][i];
      }
    }
    return tmp;
  }
}
