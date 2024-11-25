import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double ax,bx,ay,by,cx,cy;
        ax=s.nextDouble();
        ay=s.nextDouble();
        bx=s.nextDouble();
        by=s.nextDouble();
        cx=s.nextDouble();
        cy=s.nextDouble();
        double t1,t2,t3;
        t1=dist(ax,ay,bx,by)+dist(bx,by,cx,cy);
        t2=dist(ax,ay,cx,cy)+dist(bx,by,cx,cy);
        t3=dist(ax,ay,cx,cy)+dist(ax,ay,bx,by);
        t1*=2;
        t2*=2;
        t3*=2;
        double res=-1;
        if(!isP(ax,ay,bx,by,cx,cy)) System.out.println(res);
        else {
            double max=t1;
            double min=t1;
            max=max>t2?max:t2;
            max=max>t3?max:t3;

            min=min<t2?min:t2;
            min=min<t3?min:t3;
            System.out.println(max-min);
        }
    }
    static double dist(double x1,double y1, double x2, double y2){
        return Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    static boolean isP(double x1, double y1, double x2, double y2, double x3, double y3){
        if(x2-x1 != 0 && x3-x2 != 0){
            if((y2-y1)/(x2-x1) == (y3-y2)/(x3-x2)) return false;
            return true;
        }
        else {
            if((x2-x1)==(x3-x2)) return false;
            return true;
        }
    }
}