#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int val;
   Node* next;
   Node* prev;

   Node(int val)
   {
      this->val = val;
      this->next = NULL;
      this->prev = NULL;
   }
};

void print_forward(Node* head)
{
   cout << "L -> ";
   Node* tmp = head;
   while (tmp != NULL)
   {
      cout << tmp->val;
      if (tmp->next != NULL)
      {
         cout << " ";
      }
      tmp = tmp->next;
   }
   cout << "\n";
}

void print_backward(Node* tail)
{
   cout << "R -> ";
   Node* tmp = tail;
   while (tmp != NULL)
   {
      cout << tmp->val;
      if (tmp->prev != NULL)
      {
         cout << " ";
      }
      tmp = tmp->prev;
   }
   cout << "\n";
}

int get_length(Node* head)
{
   int len = 0;
   Node* tmp = head;
   while (tmp != NULL)
   {
      len++;
      tmp = tmp->next;
   }
   return len;
}

void insert_at_index(Node* &head, Node* &tail, int idx, int val)
{
   int len = get_length(head);

   if (idx < 0 || idx > len)
   {
      cout << "Invalid\n";
      return;
   }

   Node* newnode = new Node(val);

   // insert at head
   if (idx == 0)
   {
      newnode->next = head;
      if (head != NULL)
      {
         head->prev = newnode;
      }
      head = newnode;
      if (tail == NULL)
      {
         tail = newnode;
      }
   }
   // insert at tail
   else if (idx == len)
   {
      newnode->prev = tail;
      tail->next = newnode;
      tail = newnode;
   }
   // insert at middle
   else
   {
      Node* tmp = head;
      for (int i = 0; i < idx - 1; i++)
      {
         tmp = tmp->next;
      }
      newnode->next = tmp->next;
      newnode->prev = tmp;
      tmp->next->prev = newnode;
      tmp->next = newnode;
   }

   print_forward(head);
   print_backward(tail);
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
      insert_at_index(head, tail, x, v);
   }

   return 0;
}
