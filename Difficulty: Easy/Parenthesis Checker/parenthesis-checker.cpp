//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> stk;
        for(char c:s)
        {
            
            //cout<<c<<'\n'; 
            if(c=='(' ||c=='[' ||c=='{') stk.push(c);
            else
            {
                if(stk.size())
                {
                    char t = stk.top();
                    
                    //cout<<c<<t<<'\n';    
                    if(c==')' && t == '('
                    || c==']' && t == '['
                    || c=='}' && t == '{'
                    ) stk.pop();
                    else return false;
                }
                else return false;
            }
        }
        return stk.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends