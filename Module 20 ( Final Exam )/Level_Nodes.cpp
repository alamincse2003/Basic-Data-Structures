#include<bits/stdc++.h>
using namespace std;

  class Node{
     public:
     int val;
     Node* left;
     Node* right;

     Node (int val)
     {
       this->val = val;
       this->left = NULL;
       this->right = NULL;
     }
    };

Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if (val == -1) root = NULL;
    else root = new Node(val);
    if (root == NULL) return root;

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myLeft, *myRight;
        if (l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if (r == -1) myRight = NULL;
        else myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);

    }
    return root;

}

int max_depth(Node* root)
{
    if (root == NULL)
     return 0;
     int l = max_depth(root->left);
     int r = max_depth(root->right);
     return max(l,r)+1;

}

void print_level(Node* root, int k)
{
    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node* f = q.front();
            q.pop();

            if (level == k)
                cout << f->val << " ";

            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
        level++;
    }
}

int main()
{
  Node* root = input_tree();
  int k;
  cin >> k;

  int depth = max_depth(root);

  if (k < 0 || k >= depth)
      cout << "Invalid";
  else
      print_level(root, k);

  return 0;
}
