
public class acm_2012_1st {
    int max;
    
    acm_2012_1st() {
        max = 0;
    }
    private int max_val(int p) {
        while (p != 1) {
            max = max < p ? p : max;
            if(p % 2 == 0) p = p>>1;
            else p = p*3 + 1;
        }
        if (max > p) return max;
        else return 1;
    }
    public static void main(String[] argc) {
        acm_2012_1st m = new acm_2012_1st();
        System.out.println(m.max_val(100000));
        
    }
    
}
