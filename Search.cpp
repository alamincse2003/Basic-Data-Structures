#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   long long val;
   Node* next;

   Node(long long val)
   {
      this->val = val;
      this->next = NULL;
   }
};

void insert_at_tail(Node* &head, Node* &tail, long long val){
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

void delete_at_list(Node* &head){
   while (head != NULL)
   {
      Node* temp = head;
      head = head->next;
      delete temp;
   }
}

int search_at_list(Node* head, long long x){
   Node* temp = head;
   int index = 0;

   while (temp != NULL)
   {
      if (temp->val == x)
      {
         return index;
      }
      index++;
      temp = temp->next;
   }
   return -1;
}

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      Node* head = NULL;
      Node* tail = NULL;

      long long val;
      while (true)
      {
         cin >> val;
         if (val == -1)
         {
            break;
         }
         insert_at_tail(head, tail, val);
      }

      long long x;
      cin >> x;

      cout << search_at_list(head, x) << endl;

      delete_at_list(head);
   }

   return 0;
}
 
