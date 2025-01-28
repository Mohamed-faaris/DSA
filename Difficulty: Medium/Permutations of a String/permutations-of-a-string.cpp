//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recurPermute(int index, string &s,
                    vector<string> &ans) {

    // Base Case
    if (index == s.size()) {
        ans.push_back(s);
        return;
    }

    // Swap the current index with all
    // possible indices and recur
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

// Function to find all unique permutations
vector<string> findPermutation(string &s) {
    vector<string> ans;
    // Stores the final answer
    
    recurPermute(0, s, ans);

    // sort the resultant vector
    unordered_set<string> set(ans.begin(), ans.end());
    vector<string> res(set.begin(),set.end());
    
    return res;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends