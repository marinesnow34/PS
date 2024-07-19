import java.io.*;
import java.util.*;

public class Main {
    public static int gcd(int a, int b){
        if (a==0) return b;
        if (b==0) return a;
        if(a%b == 0) return b;
        return gcd(b, a%b);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        double m = 100000000;

        StringTokenizer st = new StringTokenizer(br.readLine());
        int xs = Integer.parseInt(st.nextToken());
        int ys = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int xe = Integer.parseInt(st.nextToken());
        int ye = Integer.parseInt(st.nextToken());
        int dx = Integer.parseInt(st.nextToken());
        int dy = Integer.parseInt(st.nextToken());

        int di = gcd(dx > dy ? dx : dy, dx > dy ? dy : dx);
        
        dx /= di;
        dy /= di;

        int x=0, y=0;

        for(int i = 0; i < 300; i++){
            int nx = xe + dx * i;
            int ny = ye + dy * i;

            double dis = Math.sqrt((xs - nx) * (xs - nx) + (ys - ny) * (ys - ny));
            if(dis > m) break;
            m = dis;
            x = nx;
            y = ny;
        }
        bw.write(x + " " + y);
        bw.flush();
        bw.close();
    }
}
