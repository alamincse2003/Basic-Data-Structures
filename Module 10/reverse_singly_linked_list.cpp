#include<bits/stdc++.h>
using namespace std;

 class Node{
    public: 
    int val;
    Node* next;

    Node (int val)
    {
      this->val = val;
      this->next = NULL;
    }
   };

void insert_at_tail(Node* &head,Node* &tail, int val){
    Node * newnode = new Node(val);
     if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_linked_list(Node* head){
    Node* temp = head;
   
    
while (temp != NULL)
{
    cout << temp->val << endl;
    temp = temp->next;
}
}

void reverse_singly_linked_list(Node* head, Node* tail,Node* tmp){
    if(tmp->next == NULL)
    {
        head = tmp;
        return;
    }
    reverse_singly_linked_list(head, tail, tmp->next);
    tmp->next->next = tmp;
    tail = tmp;
   
}
int main()
{ 
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    reverse_singly_linked_list(head, tail, head);
    
    cout << head->val << endl;
    cout << tail->val << endl;
  return 0;
}
 
