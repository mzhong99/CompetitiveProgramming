import java.util.*;

public class Leaky {
    static double R = 0;
    static double C = 0;
    static char[][] board = null;
    static class Point {
        int r, c, t;
        public Point(int _r, int _c, int _t) {
            r = _r;
            c = _c;
            t = _t;
        }
        public Point() {
            r = 0;
            c = 0;
            t = 0;
        }
        Point up() {
            return new Point(r - 1, c, t + 1 > 9 ? 9 : t + 1);
        }
        Point down() {
            return new Point(r + 1, c, t + 1 > 9 ? 9 : t + 1);
        }
        Point left() {
            return new Point(r, c - 1, t + 1 > 9 ? 9 : t + 1);
        }
        Point right() {
            return new Point(r, c + 1, t + 1 > 9 ? 9 : t + 1);
        }
    }
    static boolean isReady(Point p) {
        return p.r >= 0 && p.r < R && 
               p.c >= 0 && p.c < C &&
               board[p.r][p.c] == ' ';
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int L = in.nextInt();
        in.nextLine();
        board = new char[L][];
        for (int l = 0; l < L; l++) {
            String s = in.nextLine();
            board[l] = s.toCharArray();
        }
        R = board.length;
        C = board[0].length;
        Queue<Point> frontier = new ArrayDeque<Point>();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 'o') {
                    frontier.add(new Point(r, c, 0));
                }
            }
        }
        while (frontier.size() != 0) {
            Point cursor = frontier.poll();
            Point next;
            if (isReady(cursor.left())) {
                next = cursor.left();
                board[next.r][next.c] = (char)((int)'0' + next.t);
                frontier.add(next);
            }
            if (isReady(cursor.right())) {
                next = cursor.right();
                board[next.r][next.c] = (char)((int)'0' + next.t);
                frontier.add(next);
            }
            if (isReady(cursor.up())) {
                next = cursor.up();
                board[next.r][next.c] = (char)((int)'0' + next.t);
                frontier.add(next);
            }
            if (isReady(cursor.down())) {
                next = cursor.down();
                board[next.r][next.c] = (char)((int)'0' + next.t);
                frontier.add(next);
            }
        }
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                System.out.print(board[r][c]);
            }
            System.out.println();
        }
    }
}


