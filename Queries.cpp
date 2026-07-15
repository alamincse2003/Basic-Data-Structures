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

void insert_at_head(Node* &head, Node* &tail, int val){
   Node* newnode = new Node(val);
   newnode->next = head;
   head = newnode;
   if (tail == NULL)
   {
      tail = newnode;
   }
}

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

void delete_at_any_pos(Node* &head, Node* &tail, int idx){
   if (head == NULL)
   {
      return;
   }

   int length = 0;
   Node* temp = head;
   while (temp != NULL)
   {
      length++;
      temp = temp->next;
   }
   if (idx < 0 || idx >= length)
   {
      return;
   }

   // delete head
   if (idx == 0)
   {
      Node* deleteNode = head;
      head = head->next;
      if (head == NULL)
      {
         tail = NULL;
      }
      delete deleteNode;
      return;
   }

   // delete any other position
   Node* tmp = head;
   for (int i = 1; i < idx; i++)
   {
      tmp = tmp->next;
   }
   Node* deleteNode = tmp->next;
   tmp->next = deleteNode->next;
   if (deleteNode->next == NULL)
   {
      tail = tmp;
   }
   delete deleteNode;
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

   int q;
   cin >> q;

   while (q--)
   {
      int x, v;
      cin >> x >> v;

      if (x == 0)
      {
         insert_at_head(head, tail, v);
      }
      else if (x == 1)
      {
         insert_at_tail(head, tail, v);
      }
      else if (x == 2)
      {
         delete_at_any_pos(head, tail, v);
      }

      print_linked_list(head);
   }

   return 0;
}
 
