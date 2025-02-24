//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate stock span values
vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size(); 
    vector<int> span(n);  
    stack<int> stk;  

    // Process each day's price
    for (int i = 0; i < n; i++) {
        
        // Remove elements from the stack while the current
        // price is greater than or equal to stack's top price
        while (!stk.empty() && arr[stk.top()] <= arr[i]) {
            stk.pop();
        }

        // If stack is empty, all elements to the left are smaller
        // Else, top of the stack is the last greater element's index
        if (stk.empty()) {
            span[i] = (i + 1);
        }
        else {
            span[i] = (i - stk.top());
        }

        // Push the current index to the stack
        stk.push(i);
    }

    return span;
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends