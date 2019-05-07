import java.util.*;
public class SuperNQueens {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		String[][] board = new String[N][];
		boolean[][] canPlace = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			board[i] = in.next().split("");
		}
		if (!initiallyValid(board, N)) {
			System.out.println("impossible");
		}
		else {
			int numQueens = update(board, canPlace, N);
			if (!attemptToSolve(numQueens, board, canPlace, N)) {
				System.out.println("impossible");
			}
		}
	}
	public static boolean initiallyValid(String[][] board, int N) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (board[r][c].equals("x")) {
					if (isAttackingOthers(r, c, board, N)) {
						return false;
					}
				}
			}
		}
		return true;
	}
	public static boolean isAttackingOthers(int r_idx, int c_idx, String[][] board, int N) {
		for (int i = 0; i < N; i++) {
			if (i == r_idx) {
				continue;
			}
			else {
				if (board[i][c_idx].equals("x")) {
					return false;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (i == c_idx) {
				continue;
			}
			else {
				if (board[r_idx][i].equals("x")) {
					return false;
				}
			}
		}
		for (int i = 0, r = r_idx - N, c = c_idx - N; i < 2 * N; i++, r++, c++) {
			if (r == r_idx && c == c_idx) {
				continue;
			}
			else {
				if (r >= 0 && r < N && c >= 0 && c < N && board[r][c].equals("x")) {
					return false;
				}
			}
		}
		for (int i = 0, r = r_idx - N, c = c_idx + N; i < 2 * N; i++, r++, c--) {
			if (r == r_idx && c == c_idx) {
				continue;
			}
			else {
				if (r >= 0 && r < N && c >= 0 && c < N && board[r][c].equals("x")) {
					return false;
				}
			}
		}
		return true;
	}
	public static boolean attemptToSolve(int numQueens, String[][] board, boolean[][] canPlace, int N) {
		if (numQueens == N) {
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					System.out.print(board[r][c]);
				}
				System.out.println();
			}
			return true;
		}
		else {
			boolean completelyFilled = true;
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (canPlace[r][c]) {
						completelyFilled = false;
					}
				}
			}
			if (completelyFilled) {
				return false;
			}
			else {
				for (int r = 0; r < N; r++) {
					for (int c = 0; c < N; c++) {
						if (canPlace[r][c]) {
							board[r][c] = "x";
							update(board, canPlace, N);
							if (attemptToSolve(numQueens + 1, board, canPlace, N)) {
								return true;
							}
							else {
								board[r][c] = ".";
								update(board, canPlace, N);
							}
						}
					}
				}
			}
		}
		return false;
	}
	public static int update(String[][] board, boolean[][] canPlace, int N) {
		int numQueens = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				canPlace[r][c] = true;
			}
		}
		for (int r_idx = 0; r_idx < N; r_idx++) {
			for (int c_idx = 0; c_idx < N; c_idx++) {
				if (board[r_idx][c_idx].equals("x")) {
					wipeout(r_idx, c_idx, canPlace, N);
					numQueens++;
				}
			}
		}
		return numQueens;
	}
	public static void wipeout(int r_idx, int c_idx, boolean[][] canPlace, int N) {
		for (int i = 0; i < N; i++) {
			canPlace[r_idx][i] = false;
			canPlace[i][c_idx] = false;
		}
		for (int i = 0, r = r_idx - N, c = c_idx - N; i < 2 * N; i++, r++, c++) {
			if (r < N && r >= 0 && c < N && c >= 0) {
				canPlace[r][c] = false;
			}
		}
		for (int i = 0, r = r_idx - N, c = c_idx + N; i < 2 * N; i++, r++, c--) {
			if (r < N && r >= 0 && c < N && c >= 0) {
				canPlace[r][c] = false;
			}
		}
	}		
}	
