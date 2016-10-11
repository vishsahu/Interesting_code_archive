import java.util.Scanner;

class basic {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // total number of test cases
        int val1, val2;
        for (int i = 0; i < N; i++) {
            val1 = in.nextInt();
            val2 = in.nextInt();
            if (val1 > val2) System.out.println(">\n");
            else if (val1 < val2) System.out.println("<\n");
            else System.out.println("=\n");
        }
        in.close();
    }
}