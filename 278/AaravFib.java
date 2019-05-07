import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;
public class AaravFib {
	
	static HashMap<Integer, Integer> dp = new HashMap<Integer, Integer>();

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		StringBuilder sb = new StringBuilder();
		dp.put(1, 1);
		dp.put(2, 1);
		for (int i = 0; i < n; i++) {
			int query = s.nextInt();
			sb.append(fib(query));
			sb.append('\n');
		}
		System.out.println(sb);
	}

	public static int fib(int n) {
		if (n < 3) { 
			return 1;
		} 
		
		if (dp.containsKey(n)) {
			return dp.get(n);
		}
		
		int value = fib(n-1) + fib(n-2);
		dp.put(n, value);

		return value;
	}
}
