import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int n, m;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        m = s.nextInt();
        int res = 0;
        int i, j;
        int[][] num = new int[n][m];
        String[] x = new String[n];
        for (i = 0; i < n; i++) {
            x[i] = s.next();
        }
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) num[i][j] = (int) x[i].charAt(j) - 48;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) {
                int start = num[i][j];
                for(int k=j+1;k<m;k++) {
                    if(start==num[i][k]) {
                        if(isThere(n,m,i,j,start,k-j,num)){
                            res = res>k-j?res:k-j;
                        };
                    }
                }
            }
        }
        System.out.println((res+1)*(res+1));
    }
    static boolean isThere(int n, int m, int x, int y, int start,int dis,int[][] num){
        if(x+dis>=n || y+dis>=m) return false;
        if(start == num[x+dis][y] && start==num[x+dis][y+dis]) return true;
        return false;
    }
}