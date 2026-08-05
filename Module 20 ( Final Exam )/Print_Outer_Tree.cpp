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

void print_left_path(Node* root)
{
    if (root == NULL) return;

    if (root->left)
        print_left_path(root->left);
    else
        print_left_path(root->right);

    cout << root->val << " ";
}

void print_right_path(Node* root, Node* skipLeaf)
{
    if (root == NULL) return;
    if (root == skipLeaf) return;

    cout << root->val << " ";

    if (root->right)
        print_right_path(root->right, skipLeaf);
    else
        print_right_path(root->left, skipLeaf);
}

Node* leftmost_leaf(Node* root)
{
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;

    if (root->left)
        return leftmost_leaf(root->left);
    else
        return leftmost_leaf(root->right);
}

int main()
{
  Node* root = input_tree();

  if (root == NULL) return 0;

  if (root->left)
  {
      print_left_path(root);
      Node* leftLeaf = leftmost_leaf(root);
      print_right_path(root->right, leftLeaf);
  }
  else
  {
      print_right_path(root, NULL);
  }

  return 0;
}
