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

// Stack - LIFO  
class Stack{
   public:
   Node* top;

   Stack()
   {
      top = NULL;
   }

   void push(int val)
   {
      Node* newnode = new Node(val);
      newnode->next = top;
      top = newnode;
   }

   int pop()
   {
      int val = top->val;
      Node* deleteNode = top;
      top = top->next;
      delete deleteNode;
      return val;
   }

   bool isEmpty()
   {
      return top == NULL;
   }
};

// Queue - FIFO  
class Queue{
   public:
   Node* front;
   Node* back;

   Queue()
   {
      front = NULL;
      back = NULL;
   }

   void push(int val)
   {
      Node* newnode = new Node(val);
      if (front == NULL)
      {
         front = newnode;
         back = newnode;
         return;
      }
      back->next = newnode;
      back = newnode;
   }

   int pop()
   {
      int val = front->val;
      Node* deleteNode = front;
      front = front->next;
      delete deleteNode;
      return val;
   }

   bool isEmpty()
   {
      return front == NULL;
   }

   int size()
   {
      int count = 0;
      Node* temp = front;
      while (temp != NULL)
      {
         count++;
         temp = temp->next;
      }
      return count;
   }
};

int main()
{
   int n, m;
   cin >> n >> m;

   Stack st;
   for (int i = 0; i < n; i++)
   {
      int val;
      cin >> val;
      st.push(val);
   }

   Queue q;
   for (int i = 0; i < m; i++)
   {
      int val;
      cin >> val;
      q.push(val);
   }

   int flag = 1;

   if (n != m)
   {
      flag = 0;
   }
   else
   {
      while (!st.isEmpty())
      {
         if (st.pop() != q.pop())
         {
            flag = 0;
            break;
         }
      }
   }

   if (flag == 1)
   {
      cout << "YES" << endl;
   }
   else
   {
      cout << "NO" << endl;
   }

   return 0;
}
