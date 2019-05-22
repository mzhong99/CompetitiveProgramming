import java.util.*;

public class Goldbach {
	static boolean[] sieve(int N) {
		boolean[] s = new boolean[N + 1];
		Arrays.fill(s, true);
		s[0] = s[1] = false;
		for (int p = 2; p * p <= N; p++) {
			if (s[p]) {
				for (int c = p * p; c <= N; c += p) {
					s[c] = false;
				}
			}
		}
		return s;
	}
	static int[] generatePrimes(int N) {
		List<Integer> primes = new ArrayList<Integer>();
		boolean[] isPrime = sieve(N);
		for (int i = 0; i <= N; i++) {
			if (isPrime[i]) {
				primes.add(i);
			}
		}
		int[] primesArr = new int[primes.size()];
		for (int i = 0; i < primes.size(); i++) {
			primesArr[i] = primes.get(i);
		}
		return primesArr;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int[] trials = new int[T];
		for (int t = 0; t < T; t++) {
			trials[t] = in.nextInt();
		}
		for (int trial : trials) {
			gold(trial);
		}
	}
	static void gold(int trial) {
		boolean[] isPrime = sieve(trial);
		int[] primes = generatePrimes(trial);
		boolean[] used = new boolean[trial + 1];
		Arrays.fill(used, false);
		List<Integer> answers = new ArrayList<Integer>();
		for (int p : primes) {
			if (used[p]) {
				continue;
			}
			int target = trial - p;
			if (isPrime[target]) {
				answers.add(p);
			}
			used[p] = true;
			used[target] = true;
		}
		System.out.printf("%d has %d representation(s)\n\n", trial, answers.size());
		for (int answer: answers) {
			System.out.printf("%d+%d\n", answer, trial - answer);
		}
	}
}
