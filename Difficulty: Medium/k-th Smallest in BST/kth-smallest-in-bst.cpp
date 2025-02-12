//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    // Function to find kth smallest element in a BST.
int kthSmallest(Node* root, int k) {
    int cnt = 0;
    
    Node* curr = root;
    while (curr != nullptr) {
        
        // If left child is null, check 
        // curr node and move to right node.
        if (curr->left == nullptr) {
            cnt++;
            
            // If curr is kth smallest node 
            if (cnt == k) return curr->data;
            
            curr = curr->right;
        }
        else {

            // Find the inorder predecessor of curr
            Node* pre = curr->left;
            while (pre->right != nullptr
                   && pre->right != curr)
                pre = pre->right;

            // Make curr as the right child of its
            // inorder predecessor and move to 
            // left node.
            if (pre->right == nullptr) {
                pre->right = curr;
                curr = curr->left;
            }

            // Revert the changes made in the 'if' part to
            // restore the original tree i.e., fix the right
            // child of predecessor
            else {
                pre->right = nullptr;
                
                cnt++;
                if (cnt == k) return curr->data;
                
                curr = curr->right;
            }
        }
    }
    
    // If k is greater than size of 
    // BST, return -1.
    return -1;
}
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.kthSmallest(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends