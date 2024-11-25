import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int n,i;
        String king;
        String rock;
        Scanner s = new Scanner(System.in);
        king = s.next();
        rock = s.next();
        n = s.nextInt();
        int[][] mat = new int[n][n];
        String[] move = new String[n];
        int king_x, king_y;
        int rock_x, rock_y;
        king_x = (int) (king.charAt(0) - 65);
        rock_x = (int) (rock.charAt(0) - 65);
        king_y = king.charAt(1)-49;
        rock_y = rock.charAt(1)-49;
        for(i=0;i<n;i++) move[i] = s.next();
        int mov_x=0;
        int mov_y=0;
        for(i=0;i<n;i++) {
            mov_x=0;
            mov_y=0;
            if(move[i].equals("R")) mov_x++;
            if(move[i].equals("L")) mov_x--;
            if(move[i].equals("B")) mov_y--;
            if(move[i].equals("T")) mov_y++;
            if(move[i].equals("RT")) {mov_x++;mov_y++;};
            if(move[i].equals("LT")) {mov_x--;mov_y++;};
            if(move[i].equals("RB")) {mov_x++;mov_y--;};
            if(move[i].equals("LB")) {mov_x--;mov_y--;};
            int next_kx=king_x+mov_x;
            int next_ky=king_y+mov_y;
            if(next_kx>=8||next_ky>=8||next_kx<0||next_ky<0);
            else if(next_kx==rock_x&&next_ky==rock_y) {
                int next_rx=rock_x+mov_x;
                int next_ry=rock_y+mov_y;
                if(next_rx<8&&next_ry<8&&next_rx>-1&&next_ry>-1) {
                    rock_x=next_rx;
                    rock_y=next_ry;
                    king_x=next_kx;
                    king_y=next_ky;
                }
            }else {
                king_x=next_kx;
                king_y=next_ky;
            }
        }
        System.out.print((char)(king_x+65));
        System.out.println(king_y+1);
        System.out.print((char)(rock_x+65));
        System.out.println(rock_y+1);
    }
}