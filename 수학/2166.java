import java.util.*;

public class Main {
    static double o(double x1,double x2,double x3,double y1, double y2, double y3) {
        double a = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
        return a/2;
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n,i,j;
        double res=0.0;
        n=s.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];
        for(i=0;i<n;i++) {
            x[i]=s.nextDouble();
            y[i]=s.nextDouble();
        }
        for(i=1;i<n;i++) {
            res+=o(x[0],x[i-1],x[i],y[0],y[i-1],y[i]);
        }
        res=Math.round(res*10)/10.0;
        System.out.printf("%.1f",a(res));
    }
    static double a(double r) {
        if(r<0) return -r;
        return r;
    }
}
