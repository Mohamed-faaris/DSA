//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool compare(const vector<int>& pts1 ,const vector<int>& pts2){
    return (pts1[0]*pts1[0] + pts1[1] * pts1[1]) < (pts2[0]*pts2[0] + pts2[1] * pts2[1]);
}
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> result;
        priority_queue<vector<int>,vector<vector<int>>,decltype(&compare)> kpts(compare);
        for(auto pt:points)
        {
            kpts.push(pt);
            if(kpts.size()>k)  kpts.pop();
        }
        while(kpts.size())
        {
            result.push_back(kpts.top());
            kpts.pop();
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends