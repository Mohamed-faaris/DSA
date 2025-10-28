/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node* root) {
        queue<Node*> q;
        vector<int> result;
        q.push(root);
        while(q.size()){
            Node* temp = q.front();
            //cout << temp->data;
            q.pop();
            while(temp){
                result.push_back(temp->data);
                if(temp->left)q.push(temp->left);
                temp = temp->right;
            }
        }
    return result;        
    }
    
};