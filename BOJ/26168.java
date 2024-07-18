import java.io.*;
import java.util.*;

public class Main {
    static List<Long> num = new ArrayList<>();

    public static int lowerBound(long target){
        int st = 0;
        int en = num.size();
        while(st < en){
            int mid = (st + en)/2;
            if(num.get(mid) >= target){
                en = mid;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
    public static int upperBound(long target){
        int st = 0;
        int en = num.size();
        while(st < en){
            int mid = (st + en)/2;
            if(num.get(mid) <= target){
                st = mid+1;
            }
            else{
                en = mid;
            }
        }
        return en;
    }

    public static void main(String[] args) throws Exception {
        // 1 lower bound
        // 2 upper bound
        // 3 upper - lower

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++)
            num.add(Long.parseLong(st.nextToken()));

        Collections.sort(num);
        
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            if(c == 1){
                bw.write((n-lowerBound(Long.parseLong(st.nextToken())))+"\n");
            }
            if(c == 2){
                bw.write((n-upperBound(Long.parseLong(st.nextToken())))+"\n");
            }
            if(c == 3){
                bw.write(Math.abs(lowerBound(Long.parseLong(st.nextToken())) - upperBound(Long.parseLong(st.nextToken()))) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
