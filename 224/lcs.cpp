#include <bits/stdc++.h>
using namespace std;
struct HashStructure {
	string str;
	const long chunk_size = 100000000;
	const long prime = 10000000000000061;
	const long base = 257;
	long* prefixHashes;
	long* cachePower;
	HashStructure(string in) {
		str = in;
		buildPrefixHashes();
		makePowerCache();
	}
	~HashStructure() {
		delete [] prefixHashes;
		delete [] cachePower;
	}
	void buildPrefixHashes() {
		prefixHashes = new long[str.length() + 1];
		long hashStart = 0;
		prefixHashes[0] = hashStart;
		for (int a = 0; a < str.length(); a++) {
			hashStart *= base;
			hashStart += str[a] + 1;
			hashStart %= prime;
			prefixHashes[a + 1] = hashStart;
		}
	}
	void makePowerCache() {
		cachePower = new long[str.length() + 1];
		long start = 1;
		for (int a = 0; a < str.length() + 1; a++) {
			cachePower[a] = start;
			start *= base;
			start %= prime;
		}
	}
	long getSubstringHash(int startIdx, int endIdx) {
		long fullPrefix = prefixHashes[endIdx];
		long prefix = prefixHashes[startIdx];
		long power = cachePower[endIdx - startIdx];
		long ans = fullPrefix - modular_multiply(prefix, power);
		return ((ans % prime) + prime) % prime;
	}
	long modular_multiply(long op1, long op2) {
		long prefix = op1;
		long power = op2;
		long prefixA = prefix % chunk_size;
		long prefixB = prefix / chunk_size;
		long powerA = power % chunk_size;
		long powerB = power / chunk_size;
		long smallChunk = prefixA * powerA;
		long mediumChunk = powerA * prefixB + powerB * prefixA;
		long largeChunk = prefixB * prefixB;
		long mediumChunkLeft = mediumChunk / chunk_size;
		long mediumChunkRight = mediumChunk % chunk_size;
		smallChunk += mediumChunkRight * chunk_size;
		largeChunk += mediumChunkLeft;
		smallChunk += largeChunk * -61;
		return smallChunk;
	}
	vector<long> getAllXSubstringHashes(int x) {
		vector<long> output = vector<long>();
		for (int a = 0; a < str.length() - x + 1; a++) {
			output.push_back(getSubstringHash(a, a + x));
		}
		return output;
	}
};
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() > s2.length()) {
		swap(s1, s2);
	}
	HashStructure magic1 = HashStructure(s1);
	HashStructure magic2 = HashStructure(s2);
	for (int i = s1.length(); i > 0; i--) {
		vector<long> vect = magic1.getAllXSubstringHashes(i);
		for (int j = 0; j < vect.size(); j++) {
			long hash2 = magic2.getSubstringHash(j, j + i);
			long hash1 = vect[j];
			if (hash2 == hash1) {
				cout << j << endl;
				return 0;
			}
		}
	}
}

