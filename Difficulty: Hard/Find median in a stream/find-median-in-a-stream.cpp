//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        
        priority_queue<int> smallHeap; // Max heap (stores smaller half)
        priority_queue<int, vector<int>, greater<int>> bigHeap; // Min heap (stores larger half)
        
        for (int i : arr) {
            // Insert into appropriate heap
            if (smallHeap.empty() || i <= smallHeap.top()) {
                smallHeap.push(i);
            } else {
                bigHeap.push(i);
            }

            // Balance the heaps
            if (smallHeap.size() > bigHeap.size() + 1) {
                bigHeap.push(smallHeap.top());
                smallHeap.pop();
            } else if (bigHeap.size() > smallHeap.size()) {
                smallHeap.push(bigHeap.top());
                bigHeap.pop();
            }

            // Compute median
            if ((smallHeap.size() + bigHeap.size()) % 2 == 0) {
                result.push_back((smallHeap.top() + bigHeap.top()) / 2.0);
            } else {
                result.push_back(smallHeap.top());
            }
        }
        
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends