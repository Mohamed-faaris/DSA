//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void serializePreOrder(Node* root, vector<int> &arr) {
    
    // Push -1 if root is null.
    if (root == nullptr) {
        arr.push_back(-1);
        return;
    }
    
    // Push the root into result.
    arr.push_back(root->data);
    
    // Recursively traverse the 
    // left and right subtree.
    serializePreOrder(root->left, arr);
    serializePreOrder(root->right, arr);
}

// Main function to serialize a tree.
vector<int> serialize(Node *root) {
    vector<int> arr;
    serializePreOrder(root, arr);
    return arr;
}

    // Function to deserialize a list and construct the tree.
    Node* h(int& i,vector<int> &arr)
    {
        if(arr[i] != -1){
            Node *head = new Node(arr[i++]);
            head -> left  = h(i,arr);
            head -> right = h(i,arr);
            return head;
        }
        i++;
        return nullptr;
    }
    
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        int i = 0;
        return h(i,arr);
    }
        // // Your code here
        // vector<int> result;
        // queue<Node*> q;
        // q.push(root);
        // while(q.size())
        // {
        //     Node* temp = q.front();
        //     q.pop();
        //     if(temp){
        //         result.push_back(temp->data);
        //         q.push(temp->left );
        //         q.push(temp->right);
        //     }
        //     else{
        //         result.push_back(-1);
        //     }
        // }
        // return result;
};
        // queue<Node*> q;
        // if(arr[0] == -1) 
        // return nullptr;
        
        // int i = 0;
        // Node* head = New Node(arr[i++]);
        // q.push(head);
        // while(q.size())
        // {
        //     int temp = arr[i];
        //     if(arr)
        // }
        // return head;

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends