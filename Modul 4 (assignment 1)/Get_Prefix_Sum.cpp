#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;

   vector<long long> v(n + 1);
   for (int i = 1; i <= n; i++)
   {
      cin >> v[i];
   }

    
   vector<long long> pre(n + 1);
   pre[1] = v[1];
   for (int i = 2; i <= n; i++)
   {
      pre[i] = pre[i - 1] + v[i];
   }

   
   for (int i = n; i >= 1; i--)
   {
      cout << pre[i];
      if (i > 1)
      {
         cout << " ";
      }
   }
   cout << "\n";

   return 0;
}
 
