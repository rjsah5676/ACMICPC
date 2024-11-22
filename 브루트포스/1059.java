import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int l,n;
        Scanner s= new Scanner(System.in);
        l=s.nextInt();
        int[] x = new int[l];
        int i;
        for(i=0;i<l;i++) x[i] = s.nextInt();
        Arrays.sort(x);
        n=s.nextInt();
        int res=0;
        for(int g=1;g<x[0]-1; g++) for(int gg=g+1; gg<x[0]; gg++) if(n>=g&&n<=gg) res++;
        for(i=0;i<l-1;i++) {
            int p=x[i]+1;
            int q=x[i+1]-1;
            for(int y=p;y<q;y++) for(int z=y+1;z<=q;z++) if(n>=y && n<=z) res++;
        }
        System.out.println(res);
    }
}