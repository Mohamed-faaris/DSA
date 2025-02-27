//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> stk,min_stk;
  
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) {
            min_stk.push(x);
        } else {
            min_stk.push(min_stk.top());
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(stk.empty()) return;
        stk.pop();
        min_stk.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return stk.size()?stk.top():-1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
         return min_stk.size()?min_stk.top():-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends