#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int val;
   Node* next;

   Node(int val)
   {
      this->val = val;
      this->next = NULL;
   }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
   Node* newnode = new Node(val);
   if (head == NULL)
   {
      head = newnode;
      tail = newnode;
      return;
   }
   tail->next = newnode;
   tail = newnode;
}

void remove_duplicate(Node* head){
   for (Node* i = head; i != NULL; i = i->next)
   {
      Node* j = i;
      while (j->next != NULL)
      {
         if (j->next->val == i->val)
         {
            Node* deleteNode = j->next;
            j->next = j->next->next;
            delete deleteNode;
         }
         else
         {
            j = j->next;
         }
      }
   }
}

void print_linked_list(Node* head){
   Node* temp = head;
   while (temp != NULL)
   {
      cout << temp->val;
      if (temp->next != NULL)
      {
         cout << " ";
      }
      temp = temp->next;
   }
   cout << "\n";
}

int main()
{
   Node* head = NULL;
   Node* tail = NULL;

   int val;
   while (true)
   {
      cin >> val;
      if (val == -1)
      {
         break;
      }
      insert_at_tail(head, tail, val);
   }

   remove_duplicate(head);
   print_linked_list(head);

   return 0;
}
 
