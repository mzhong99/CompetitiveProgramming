#include <bits/stdc++.h>
using namespace std;

int main() {
	char** words;
	int N;
	cin >> N;
	words = new char*[N];
	for (int n = 0; n < N; n++) {
		words[n] = new char[100];
		for (int i = 0; i < 100; i++) {
			words[n][i] = ' ';
		}
	}
	char c = getchar();
	int row = 0;
	int col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			row++;
			col = 0;
		}
		else {
			words[row][col++] = c;
		}
	}
	row = 0;
	col = 0;
	while (row < N) {
		if (words[row][col] == ' ') {
			row++;
		}
		else {
			col++;
		}
	}
	cout << col + 1 << endl;
	for (int n = 0; n < N; n++) {
		delete [] words[n];
	}
	delete [] words;
}
