import java.util.*;

public class Main {
    static int n;
    static int mx=0;
    static int z=0;
    static int[][] mat;
    static int[][] visit;
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int i,j;
        n=s.nextInt();
        mat = new int[n+1][n+1];
        visit = new int[n+1][n+1];
        String[] str=new String[n];
        for(i=0;i<n;i++) str[i] = s.next();
        for(i=0;i<n;i++) for(j=0;j<n;j++) mat[i+1][j+1] = isFriend(str[i].charAt(j));
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                for(int k=1;k<=n;k++) {
                    if(k!=j){
                        if(mat[j][k] == 1 || (mat[j][i]==1 && mat[i][k]==1)) visit[j][k]=1;
                    }
                }
            }
        }
        for(i=1;i<=n;i++) {
            int sum=0;
            for(j=1;j<=n;j++) {
                if(visit[i][j]==1) sum++;
            }
            mx=mx>sum?mx:sum;
        }
        System.out.println(mx);
    }
    static int isFriend(char x){
        if(x=='Y') return 1;
        return 0;
    }
}