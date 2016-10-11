
public class PercolationStats {
    private double[] open_site_fraction;
	private int t; // for iteration
	private double mean, sd;
    
    public PercolationStats(int N, int T) { 
        //if(N<=0 | T<=0) java.lang.IllegalArgumentException();
		t = T;
		int rand_row = 0, rand_col = 0;
        int iter = T, open_site_cnt;
        
        open_site_fraction = new double[T];
        
        while (iter-- > 0) {
            
            open_site_cnt = 0;
            
            Percolation pc = new Percolation(N); 
            do {
                // start opening sites randomly which are closed
                do {
                    rand_row = (int) (Math.random()*N);
                    rand_col = (int) (Math.random()*N);
                } while (pc.isOpen(rand_row, rand_col));
                
                //System.out.println("row:"+rand_row+" col:"+rand_col);
                pc.open(rand_row, rand_col); 
                open_site_cnt++;
                //System.out.println();
            } while(!pc.percolates());
            
            open_site_fraction[iter] = (double) open_site_cnt/(N*N);
        }
    }
    
    public double mean() {   // sample mean of percolation threshold
        double aggr_sum = 0;
        for (int i = 0; i < t; i++)
			aggr_sum += open_site_fraction[i];
		mean = aggr_sum/t;
        return mean;
    }
    
    public double stddev() { // sample standard deviation of percolation threshold
        double var_sum = 0;
        for (int i = 0; i < t; i++) 
			var_sum += (open_site_fraction[i]-mean)*(open_site_fraction[i]-mean);
        var_sum = var_sum/(t-1);
		sd = Math.sqrt(var_sum);
        return sd;
    }
    
    public double confidenceLo() { // low  endpoint of 95% confidence interval
        return mean - ((1.96*sd)/Math.sqrt(t));
    }
    
    public double confidenceHi() { // high endpoint of 95% confidence interval
        return mean + ((1.96*sd)/Math.sqrt(t));
    }
    
    /*public static void main(String[] args)   // test client (optional)
    {
        int N =Integer.parseInt(args[0]);
        int T =Integer.parseInt(args[1]);
        
        PercolationStats pstats = new PercolationStats(N, T);
        double mean = pstats.mean();
        double sd = pstats.stddev();
        double clo = pstats.confidenceLo();
        double chi = pstats.confidenceHi();
        
        System.out.println("mean                    = "+mean);
        System.out.println("stddev                  = "+sd);
        System.out.println("95% confidence interval = "+clo+", "+chi);
    }*/
}
