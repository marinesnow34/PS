import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String A = st.nextToken();
        String B = st.nextToken();

        int mi = 0, ma = 0;
        for(int i = 0; i < A.length(); i++){
            if(A.charAt(i) - '0' == 5 || A.charAt(i) - '0' == 6){
                mi += 5 * Math.pow(10, A.length() - 1 - i);
                ma += 6 * Math.pow(10, A.length() - 1 - i);
            }
            else{
                mi += ((int) (A.charAt(i) - '0')) * Math.pow(10, A.length() - 1 - i);
                ma += ((int) (A.charAt(i) - '0')) * Math.pow(10, A.length() - 1 - i);
            }
        }
        for(int i = 0; i < B.length(); i++){
            if(B.charAt(i) - '0' == 5 || B.charAt(i) - '0' == 6){
                mi += 5 * Math.pow(10, B.length() - 1 - i);
                ma += 6 * Math.pow(10, B.length() - 1 - i);
            }
            else{
                mi += ((int) (B.charAt(i) - '0')) * Math.pow(10, B.length() - 1 - i);
                ma += ((int) (B.charAt(i) - '0')) * Math.pow(10, B.length() - 1 - i);
            }
        }
        bw.write(mi + " " + ma);
        bw.flush();
        bw.close();
    }
}
