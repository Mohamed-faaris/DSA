//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge2Lists(Node* head1,Node* head2)
    {
        if(nullptr == head1) return head2;
        if(nullptr == head2) return head1;
        Node *head,*temp;
        if(head1->data<head2->data) 
        {
            head = head1;
            head1 = head1->next;
        }
        else
        {
            head = head2;
            head2 = head2->next;
        }
        temp = head;
        while(head1 && head2)
        {
            if(head1->data<head2->data) 
            {
                temp->next  = head1;
                head1 = head1->next;
            }
            else{
                temp->next  = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
             if(head1) temp->next = head1;
        else if(head2) temp->next = head2;
        return head;
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* head = nullptr;
        for(auto h:arr){
            head = merge2Lists(head,h);
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends