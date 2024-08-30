import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

    static class Point {
        int y;
        int x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int[] min;
    static int[][] board;
    static List<Point> coreList;
    static int N;

    static void play(int start, int coreCnt, int sum) {
//    	for(int i = 0; i < N; i++) {
//    		for(int j = 0; j < N; j++) System.out.print(board[i][j] + "");
//    		System.out.println();
//    	}
//    	System.out.println();

        if (start == coreList.size()) { // 끝까지 왔을 때 등록
            if(min[coreCnt] > sum) {
                min[coreCnt] = sum;
            }
            return;
        }


        Point core = coreList.get(start);

        if (core.x == N - 1 || core.x == 0 || core.y == N - 1 || core.y == 0) {
            play(start + 1, coreCnt + 1, sum);
            return;
        }


        // 위를 채운다
        boolean canGo = true;
        for (int y = core.y - 1; y >= 0; y--) {
            if (board[y][core.x] != 0) {
                canGo = false;
                break;
            }
        }
        if (canGo) {
            for (int y = core.y - 1; y >= 0; y--) {
                board[y][core.x] = 2;
            }
            play(start + 1, coreCnt + 1, sum + core.y);
            for (int y = core.y - 1; y >= 0; y--) {
                board[y][core.x] = 0;
            }
        }

        // 아래를 채운다
        canGo = true;
        for (int y = core.y + 1; y < N; y++) {
            if (board[y][core.x] != 0) {
                canGo = false;
                break;
            }
        }
        if (canGo) {
            for (int y = core.y + 1; y < N; y++) {
                board[y][core.x] = 2;
            }
            play(start + 1, coreCnt + 1, sum + N - core.y - 1);
            for (int y = core.y + 1; y < N; y++) {
                board[y][core.x] = 0;
            }
        }

        // 왼쪽을 채운다
        canGo = true;
        for (int x = core.x - 1; x >= 0; x--) {
            if (board[core.y][x] != 0) {
                canGo = false;
                break;
            }
        }
        if (canGo) {
            for (int x = core.x - 1; x >= 0; x--) {
                board[core.y][x] = 2;
            }
            play(start + 1, coreCnt + 1, sum + core.x);
            for (int x = core.x - 1; x >= 0; x--) {
                board[core.y][x] = 0;
            }
        }

        // 오른쪽을 채운다
        canGo = true;
        for (int x = core.x + 1; x < N; x++) {
            if (board[core.y][x] != 0) {
                canGo = false;
                break;
            }
        }
        if (canGo) {
            for (int x = core.x + 1; x < N; x++) {
                board[core.y][x] = 2;
            }
            play(start + 1, coreCnt + 1, sum + N - core.x - 1);
            for (int x = core.x + 1; x < N; x++) {
                board[core.y][x] = 0;
            }
        }

        // 안채운다.
        play(start + 1, coreCnt, sum);


    }

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int testCase = 1; testCase <= T; testCase++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            board = new int[N][N];
            coreList = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                    if (board[i][j] == 1) {
                    	if(i == 0 || i == N-1 || j == 0 || j == N-1) continue;
                        coreList.add(new Point(i, j));
                    }
                }
            }
            min = new int[coreList.size() + 1];

            Arrays.fill(min, Integer.MAX_VALUE);
            play(0, 0, 0);

            int ret = 0;
            for (int i = min.length - 1; i >= 0; i--) {
                if (min[i] != Integer.MAX_VALUE) {
                    ret = min[i];
                    break;
                }   
            }

            sb.append('#').append(testCase).append(' ').append(ret).append('\n');
        }
        System.out.print(sb);
    }
}
