//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        int res,a,b;
        stack<int> stk;
        for(string op:arr){
            if(op == "+"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                stk.push(a+b);
            }
            else if(op == "-"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                stk.push(b-a);
            }
            else if(op == "*"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                stk.push(b*a);
            }
            
            else if(op == "/"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                stk.push(b/a);
            }
            else
            {
                stk.push(stoi(op));
            }
        }
        return stk.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends