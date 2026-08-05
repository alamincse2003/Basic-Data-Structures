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

void leaf_nodes(Node* root, queue<int> &leaves)
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
    {
        leaves.push(root->val);
        return;
    }
    leaf_nodes(root->left, leaves);
    leaf_nodes(root->right, leaves);
}

int main()
{
  Node* root = input_tree();
  queue<int> leaves;
  leaf_nodes(root, leaves);

  int n = leaves.size();
  int arr[n];
  for (int i = 0; i < n; i++)
  {
      arr[i] = leaves.front();
      leaves.pop();
  }

  // descending sort
  for (int i = 0; i < n; i++)
      for (int j = 0; j < n - i - 1; j++)
          if (arr[j] < arr[j+1])
          {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
          }

  for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
  return 0;
}
