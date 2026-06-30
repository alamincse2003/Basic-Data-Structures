#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }

   int m;
   cin >> m;
   int b[m];
   for (int i = 0; i < m; i++)
   {
      cin >> b[i];
   }

   int x;
   cin >> x;

   vector<int> result;

    
   for (int i = 0; i < x; i++)
   {
      result.push_back(a[i]);
   }

    
   for (int i = 0; i < m; i++)
   {
      result.push_back(b[i]);
   }

    
   for (int i = x; i < n; i++)
   {
      result.push_back(a[i]);
   }

   for (int i = 0; i < result.size(); i++)
   {
      cout << result[i];
      if (i < result.size() - 1)
      {
         cout << " ";
      }
   }
   cout << "\n";

   return 0;
}
 
