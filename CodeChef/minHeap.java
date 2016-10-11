
public class minHeap {
    int[] harr; // pointer to array containing heap elements
    int capacity; // maximum capacity of heap
    int hsize; // current elements in heap
    
    //constructor
    public minHeap(int c) {
        capacity = c;
        harr = new int[c];
        hsize = 0;
    }
    
    private int parent(int i) {
        if (i > 1) return i/2;
        else return i; // parent of root is root itself
    }
    private int left(int i) {return 2*i;}
    private int right(int i) {return 2*i+1;}
    
    // maintenance
    private void minHeapify(int i) { // minHeapify a subtree with root at given index
        int p = parent(i+1) - 1;
        int l = left(i+1) - 1;
        int r = right(i+1) - 1;
        int min = i;
        if (p < hsize && harr[p] > harr[min]) {min = p;} // bubble up
        else { // bubble down
            if (l < hsize && harr[l] < harr[min]) {min = l;}
            if (r < hsize && harr[r] < harr[min]) {min = r;}
        }
        if (min != i) {
            swap(i,min);
            minHeapify(min);
        }
    }
       
    // insert element in heap
    private void insertKey(int x) {
        if (hsize < capacity) {
            harr[hsize] = x; // insert at end
            minHeapify(hsize);
            hsize++;
        }
        else {
            System.out.println("HeapFullException ! "+hsize+" ,"+capacity);
        }
    }
    
    // delete element from ith index in heap
    private void deleteKey(int i) {
        harr[i-1] = harr[hsize-1];
        hsize--;
        minHeapify(i-1);
    }
    
    // remove min element from heap
    private int extractMin() {
        int root = harr[0];
        harr[0] = harr[hsize-1];
        hsize--;
        minHeapify(0);
        return root;
    }
    
    // Get minimum value, no removal
    private int getMin() {return harr[0];}

    private void swap(int a, int b) {
        int temp = harr[a];
        harr[a] = harr[b];
        harr[b] = temp;
    }
    
    private int heapSize() {return hsize;}
    
    // test client optional
    public static void main(String[] args) {        
        minHeap minh = new minHeap(20); // creates heap
                
        minh.insertKey(786);
        minh.insertKey(343);
        minh.insertKey(53);
        minh.insertKey(1);
        minh.insertKey(342);
        minh.insertKey(67);
        minh.insertKey(13);
        
        for (int i = 0; i < minh.heapSize(); i++) System.out.print(minh.harr[i]+" ");
        System.out.println();
        minh.deleteKey(1);
        for (int i = 0; i < minh.heapSize(); i++) System.out.print(minh.harr[i]+" ");
        System.out.println();
        
        System.out.println("total heap size is "+minh.heapSize()+" min value is "+minh.getMin());
        
        //minh.deleteKey(4);
    }
        
        
};

