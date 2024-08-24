import java.util.*;
import java.io.*;
 
public class b {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int t = Integer.parseInt(br.readLine().trim());
        List<String> results = new ArrayList<>();
        
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine().trim());
            
            if (n == 1) {
                results.add("1");
            } else if (n % 2 == 0) {
                results.add("-1");
            } else {
                StringBuilder leftHalf = new StringBuilder();
                StringBuilder rightHalf = new StringBuilder();
                
                for (int j = 1; j <= n / 2; j++) {
                    leftHalf.append(j).append(" ");
                }
                for (int j = n; j > n / 2; j--) {
                    rightHalf.append(j).append(" ");
                }
                
                results.add(leftHalf.toString() + rightHalf.toString().trim());
            }
        }
        
        for (String result : results) {
            pw.println(result);
        }
        
        pw.flush();
        pw.close();
        br.close();
    }
}