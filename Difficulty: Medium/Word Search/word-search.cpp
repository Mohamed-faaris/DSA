//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool findMatch(int i, int j, int index,vector<vector<char>>& mat, string& word)
    {
        int n = mat.size(), m = mat[0].size();
        if(index == word.length()) return true;
        if(i >= n || j >= m || i<0 || j<0) return false;
        if(mat[i][j] != word[index]) return false;
           
        
        char temp = mat[i][j];
        mat[i][j] = '#';
                
        bool res = (    findMatch(i,j+1,index+1,mat,word)||
                        findMatch(i+1,j,index+1,mat,word)||
                        findMatch(i,j-1,index+1,mat,word)||
                        findMatch(i-1,j,index+1,mat,word)
                    ) ;
            
        mat[i][j] = temp;
        return res;
    }
    
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(findMatch(i,j,0,mat,word)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends