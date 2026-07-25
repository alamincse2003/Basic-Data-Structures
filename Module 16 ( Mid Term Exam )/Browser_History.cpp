#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   string val;
   Node* next;
   Node* prev;

   Node(string val)
   {
      this->val = val;
      this->next = NULL;
      this->prev = NULL;
   }
};

void insert_at_tail(Node* &head, Node* &tail, string val)
{
   Node* newnode = new Node(val);
   if (head == NULL)
   {
      head = newnode;
      tail = newnode;
      return;
   }
   tail->next = newnode;
   newnode->prev = tail;
   tail = newnode;
}

int main()
{
   Node* head = NULL;
   Node* tail = NULL;

   string s;
   while (true)
   {
      cin >> s;
      if (s == "end")
      {
         break;
      }
      insert_at_tail(head, tail, s);
   }

   Node* current = head;

   int q;
   cin >> q;

   while (q--)
   {
      string cmd;
      cin >> cmd;

      if (cmd == "visit")
      {
         string address;
         cin >> address;

         Node* tmp = head;
         Node* found = NULL;
         while (tmp != NULL)
         {
            if (tmp->val == address)
            {
               found = tmp;
               break;
            }
            tmp = tmp->next;
         }

         if (found != NULL)
         {
            current = found;
            cout << current->val << "\n";
         }
         else
         {
            cout << "Not Available\n";
         }
      }
      else if (cmd == "next")
      {
         if (current->next != NULL)
         {
            current = current->next;
            cout << current->val << "\n";
         }
         else
         {
            cout << "Not Available\n";
         }
      }
      else if (cmd == "prev")
      {
         if (current->prev != NULL)
         {
            current = current->prev;
            cout << current->val << "\n";
         }
         else
         {
            cout << "Not Available\n";
         }
      }
   }

   return 0;
}
