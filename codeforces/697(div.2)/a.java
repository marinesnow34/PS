import java.util.*;
import java.io.*;
 
public class a {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            HashMap<Integer, Integer> arr = new HashMap<>();
            for(int i = 0; i < N; i++){
                arr.merge(Integer.parseInt(st.nextToken()), 1, (ov,nv)->ov+nv);
            }
            int max = 0;
            for(Integer i : arr.values()){
                max = Math.max(max, i);
            }
            pw.println(N-max);
        }
        pw.close();
    }
}