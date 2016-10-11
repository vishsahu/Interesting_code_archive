public class Percolation {
    private int[][] grid;
    private int[] size; // size of each component
    private int[] parent; //parent of each node. stored in row*n+col format
    private int n;
    
    public Percolation(int N) // create nxn grid,with all sites blocked
    {
        n = N;
        grid = new int[n][n];
        size = new int[n*n+1]; // including root also
        parent = new int[n*n+1];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 0; // all closed
                parent[i*n+j] = i*n+j;
                size[i*n+j] = 1; 
            }
        }
        parent[n*n] = n*n; // root is parent of itself
        size[n*n] = 1; // initially no one is connected to root  
    }   
    private boolean validate(int i, int j) {
        if (i < 1 | i > n | j < 1 | j > n) return false;
        else return true;
    }   
    private int find(int p) {
        while (parent[p] != p) p = parent[p];
        return p;
    }
    private void connect(int pr, int pc, int qr, int qc) {
        pr--; // index correctiona as per array
        pc = pc-1;
        qr = qr-1;
        qc = qc-1;
        int rootP = find(pr*n+pc);
        int rootQ = find(qr*n+qc);
        if (rootP == rootQ) return;
        
        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
    }
    public boolean isOpen(int i, int j)     // is site (row i, column j) open?
    {
        if (!validate(i, j)) return false; // invalid index 
        else return (grid[i-1][j-1] != 0);
    }
    public void open(int i, int j)  
    {
        //System.out.println(count+" "+root);
        if (isOpen(i, j)); // do nothing
        else {
            grid[i-1][j-1] = 1; // mark the site as opened
            if (i == 1 & j > 0 & j <= n) connect(i, j, n, n+1); 
			// connect the first row to root. passing n, n+1 because 
			// in connect, input offset correction happens
            else {
                if (isOpen(i-1, j)) connect(i, j, i-1, j); // upper check
            }
            if (isOpen(i+1, j)) connect(i, j, i+1, j); // lower check
            if (isOpen(i, j-1)) connect(i, j, i, j-1); // left check
            if (isOpen(i, j+1)) connect(i, j, i, j+1); // right check 
        }
        //System.out.println("("+i+","+j+") "+find((i-1)*n+(j-1))+" "+find(n*n));
        /*// print grid
        for (int r=0;r<n;r++){
            for(int c=0;c<n;c++) System.out.print(grid[r][c]+" ");
            System.out.println();
        }*/
    }
    public boolean isFull(int i, int j) // is site (i,j) connected to top?
    {
        //System.out.println("checking for full !");
        if (isOpen(i, j)) {
            //System.out.println("("+i+","+j+") "+find((i-1)*n+(j-1))+" "+find(n*n));
            return (find((i-1)*n+(j-1)) == find(n*n));
        }
        else return false;
    }
    public boolean percolates()             // does the system percolate?
    {
        for (int i = 0; i < n; i++) {
            if (find((n-1)*n+i) == find(n*n)) return true;
        }
        return false;
    }   
}