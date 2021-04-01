class Solution {
    public int getDist(int pos, int num) {
        pos = (pos == 0) ? 10 : pos-1;
        num = (num == 0) ? 10 : num-1;
        
        int y = pos / 3, x = pos % 3;
        int ny = num / 3, nx = num % 3;
        
        return Math.abs(y - ny) + Math.abs(x - nx);
    }
    
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int posl = 10, posr = 12;
        for(int num : numbers) {
            if(num == 1 || num == 4 || num == 7) {
                sb.append('L');        
                posl = num;
            }
            else if(num == 3 || num == 6 || num == 9) {
                sb.append('R');        
                posr = num;
            }
            else {
                int distl = getDist(posl, num);
                int distr = getDist(posr, num);
                if(distl == distr) {
                    if(hand.equals("right")) {
                        posr = num;
                        sb.append('R');
                    }
                    else {
                        posl = num;
                        sb.append('L');
                    }
                }
                else if(distl > distr) {
                    posr = num;
                    sb.append('R');
                }
                else {
                    posl = num;
                    sb.append('L');
                }
            }
        }
        return sb.toString();
    }
}
