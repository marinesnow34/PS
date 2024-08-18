import java.util.*;

//상담 인원
class Solution {
    // 멘토 n명
    // 1~k번 상담 유형
    // 각 멘토는 k유형 중 하나만 담당
    // 멘토는 동시에 한 명 , 요청시간 할당
    
    // 상담중이 아닌 상담 유형 담당 멘토가 시작
    // 모두 상당중 자시 차례가 올 때 까지 대기
    int N, k, answer = Integer.MAX_VALUE;
    
    int[] person = new int[6];
    int[][] reqs;
    
    //N멘토 수, K 종류
    void calcTime(){
        PriorityQueue<Integer>[] counsel = new PriorityQueue[k+1];
        for(int i = 0; i <= k; i++) counsel[i] = new PriorityQueue<>();
        
        int totalWaitTime = 0;
        
        for(int i = 0; i < reqs.length; i++){
            int startTime = reqs[i][0];
            int duringTime = reqs[i][1];
            int counselNum = reqs[i][2];
            if(counsel[counselNum].size() < person[counselNum]) counsel[counselNum].offer(startTime+duringTime);
            else{
                int beforeTime = counsel[counselNum].poll();
                int waitTime = Math.max(0, beforeTime - startTime);
                totalWaitTime += waitTime;
                counsel[counselNum].offer(startTime + waitTime + duringTime);
            }
        }
        answer = Math.min(answer, totalWaitTime);
    }
    
    void permu(int n, int s){
        if(n == k+1){
            if(s != N) return;
            // for(int i = 1; i <= k; i++) System.out.print(person[i] + " ");
            // System.out.println();
            calcTime();
            return;
        }
        for(int i = 1; i < 20; i++){
            if(s+i > N) break;
            person[n] = i;
            permu(n+1, s+i);
        }
    }
    
    public int solution(int k, int n, int[][] reqs) {
        this.N = n; this.k = k; this.reqs = reqs;
        permu(1,0);
        return answer;
    }
}
