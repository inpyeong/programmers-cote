class Solution {
    boolean check(int[] stones, int mid, int k) {
        int cnt = 0;
        for(int i = 0; i < stones.length; ++i) {
            if(stones[i] - mid <= 0) cnt++;
            else cnt = 0;
            if(cnt == k) return false;
        }
        return true;
    }
    
    public int solution(int[] stones, int k) {
        int answer = 0;
        int lo = 0, hi = 0;
        for(int stone : stones) 
            hi = Math.max(hi, stone);
        while(lo+1 < hi) {
            int mid = (lo + hi) / 2;
            if(check(stones, mid, k))
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
}
