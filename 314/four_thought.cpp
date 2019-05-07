#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> solutions = unordered_map<int, string>();
string operations = "+-*/";
vector<string> all_chosen_operations;
vector<char> current_chosen_operation;

void combine_all(int idx) {
    if (current_chosen_operation.size() == 3) {
        stringstream ss;
        for (char c : current_chosen_operation) {
            ss << c;
        }
        all_chosen_operations.push_back(ss.str());
    }
    else {
        for (int i = idx; i < operations.length(); i++) {
            current_chosen_operation.push_back(operations[i]);
            combine_all(i);
            current_chosen_operation.pop_back();
        }
    }
}
void preprocess() {
    combine_all(0);
}
int M;
int main() {
    preprocess();
    
    /*
    cin >> M;
    for (int m = 0; m < M; m++) {
        int target; cin >> target;
        if (solutions.find(target) != solutions.end()) {
            string solution = solutions[target];
            cout << 4 << " ";
            for (char c : solution) {
                cout << c << " ";
            }
            cout << "= " << target << endl;
        }
        else {
            cout << "no solution" << endl;
        }
    }
    */

}
