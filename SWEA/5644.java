import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st;
     
    static int[][][] map = new int[13][13][4]; //1번 2번 2명 ap번호
     
    static int M, A;
    static int[] a = new int[105];
    static int[] b = new int[105];
     
    static int[] dx = {0,-1,0,1,0};
    static int[] dy = {0,0,1,0,-1};
     
    static int move() {
        int sum = map[1][1][0] + map[10][10][0];
        int x1 = 1, y1 = 1, idx1 = 0;
        int x2 = 10, y2 = 10, idx2 = 0;
         
        for(int i = 0; i < M; i++) {
            x1 += dx[a[i]];
            y1 += dy[a[i]];
            x2 += dx[b[i]];
            y2 += dy[b[i]];
             
            idx1 = map[x1][y1][3];
            idx2 = map[x2][y2][3];
            if(idx1 == idx2) {
                sum += Math.max(map[x1][y1][0] + map[x2][y2][1], map[x2][y2][0] + map[x1][y1][1]);
            }
            else {
                sum += map[x1][y1][0];
                sum += map[x2][y2][0];
            }
        }
        return sum;
    }
    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            init();
            System.out.printf("#%d %d\n",t,move()); 
        }
    }
    static void init() throws Exception{
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        for(int i = 1; i < 11; i++) {
            for(int j = 1; j < 11; j++) {
                for(int k = 0; k < 4; k++) map[i][j][k] = 0;
            }
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++) a[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++) b[i] = Integer.parseInt(st.nextToken());
         
        for(int i = 0; i < A; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            setAp(x,y,r,c,i);
        }
    }
    static void setAp(int x, int y, int r, int c, int idx) {
        for(int i = 0 ; i <= r; i++) {
            for(int j = y - i; j <= y + i; j++) {
                setCell(x - r + i,j,c, idx);
            }
        }
        for(int i = 1; i <= r; i++) {
            for(int j = y -r + i; j <= y + r - i; j++) {
                setCell(x + i,j,c,idx);
            }
        }
    }
    static void setCell(int y, int x, int c, int idx) {
        if(x < 1 || x > 10 || y < 1 || y > 10) return;
        if(map[x][y][0] < c) {
            map[x][y][1] = map[x][y][0];
            map[x][y][0] = c;
            map[x][y][3] = idx+1;
        }
        else if(map[x][y][0] == c) {
            map[x][y][1] = c;
            map[x][y][3] = Math.min(idx+1,map[x][y][3]);
        }
        else if(map[x][y][1] < c) {
            map[x][y][1] = c;
        }
    }
}
