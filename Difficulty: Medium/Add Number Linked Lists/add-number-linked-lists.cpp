//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* remove0(Node* head){
        while(head !=nullptr  && head->data == 0) head = head->next;
        return head;
    }
    Node* rev(Node* head){
        Node *pre = nullptr,*cur = head,*nex;
        while(cur != nullptr){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *h1 = rev(remove0(num1)),*h2 = rev(remove0(num2));
        Node *head = nullptr,*tmp,*newNode;
        int carry = 0,sum = 0;
        
        while(h1 != nullptr || h2 != nullptr || carry != 0)
        {
            sum = (h1?h1->data:0) + (h2?h2->data:0) + carry;
            carry = sum/10;
            sum   = sum%10;
            newNode = new Node(sum);
            if (h1 != nullptr) h1 = h1->next;
            if (h2 != nullptr) h2 = h2->next;
            if(head==nullptr)
            {
                head = newNode;
                tmp = newNode;
            }
            else{
                tmp -> next = newNode;
                tmp = tmp->next;
            }
        }
        
        return remove0(rev(head));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends