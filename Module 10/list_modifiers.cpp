#include<bits/stdc++.h>
using namespace std;

int main()
{
   list <int> l = {10,20,30,40,20,60,20,80};
   // list <int> l2 = {100, 200};
//    l2 = l;
//    l2.assign(l.begin(), l.end());
// l.push_back(100);
// l.push_front(5);
// l.pop_back();
// l.pop_front();
// l.insert(next(l.begin(),2), l2.begin(), l2.end());
// l.erase(next(l.begin(),2), next(l.begin(),5));
// cout << *next(l.begin(), 1);

auto it = find(l.begin(), l.end(), 200);
if(it == l.end())
{
   cout << "Not Found" << endl;
}
else
{
    cout << "Found" << endl;
}
   for(int val: l)
   {
       cout << val << endl;
   }
  return 0;
}
 
