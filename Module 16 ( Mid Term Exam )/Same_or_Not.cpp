#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n, m;
   cin >> n >> m;

   stack<long long> st;
   for (int i = 0; i < n; i++)
   {
      long long val;
      cin >> val;
      st.push(val);
   }

   queue<long long> q;
   for (int i = 0; i < m; i++)
   {
      long long val;
      cin >> val;
      q.push(val);
   }

   int flag = 1;

   if (st.size() != q.size())
   {
      flag = 0;
   }
   else
   {
      while (!st.empty())
      {
         if (st.top() != q.front())
         {
            flag = 0;
            break;
         }
         st.pop();
         q.pop();
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
