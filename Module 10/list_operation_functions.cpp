#include<bits/stdc++.h>
using namespace std;

int main()
{
   list <int> l = {30, 10,10, 40, 20,60,50,10,80,70};
   l.sort(); //ascending
//    l.sort(greater<int>()); //decending
l.unique(); 
// l.reverse();
   for(int val: l)
   {
    cout << val << endl;
   }
  return 0;
}
 
