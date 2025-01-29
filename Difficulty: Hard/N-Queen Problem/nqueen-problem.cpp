//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col))
            return false;
    }
    return true;
}

void solve(vector<int>& board, int col, int n, vector<vector<int>>& solutions) {
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    for (int row = 1; row <= n; row++) {
        if (isSafe(board, row, col)) {
            board[col] = row;
            solve(board, col + 1, n, solutions);
            board[col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> solutions;
    vector<int> board(n, 0);
    solve(board, 0, n, solutions);
    return solutions;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends