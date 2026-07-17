#include<bits/stdc++.h>
using namespace std;

int main()
{

    // list<int> v (50, 10);
    // list<char> v (20, 'a');
    // list<float> v (30, 2.5);
    // list<long long> v (40,100);

    // list < int > my_list1 = {1,2,3,4,5};
    // list < int > my_list(v1);

    // int array[5] = {1,2,3,4,5};
    // list < int > copy_list(array, array + 5);

    // vector<int> v = {1,2,3,4,5} ;
    // list < int > copy_list(v.begin(), v.end());

    // list <int> my_list = {1,2,3,4,5};

    // for (int element: my_list)
    // {
    //     cout << element << endl;
    // }
    
    vector <int> v = {10,20,30};
    list <int> l2(v.begin(), v.end());

    // l2.clear();
    // cout << l2.size() << endl;
    l2.resize(5,100);
    for(int val : l2)
    {
       cout << val << endl;
    }
 
  return 0;
}
 
