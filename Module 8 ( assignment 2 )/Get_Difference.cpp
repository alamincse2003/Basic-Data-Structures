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

long long get_difference(Node* head){
   long long maxVal = head->val;
   long long minVal = head->val;

   Node* temp = head;
   while (temp != NULL)
   {
      if (temp->val > maxVal)
      {
         maxVal = temp->val;
      }
      if (temp->val < minVal)
      {
         minVal = temp->val;
      }
      temp = temp->next;
   }
   return maxVal - minVal;
}

int main()
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

   cout << get_difference(head) << endl;

   return 0;
}
 
