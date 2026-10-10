#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value, TreeNode* leftValue=nullptr, TreeNode* rightValue=nullptr){
    data=value;
    left=leftValue;
    right=rightValue;
  }
};

bool searchBST(TreeNode* root, int target);
TreeNode* insertBST(TreeNode* root, int value);
void traverseBST(TreeNode* root);
void minBSTValue(TreeNode* root);
void maxBSTValue(TreeNode* root);

int main(){

  TreeNode* root = new TreeNode(10);
  TreeNode* node1 = new TreeNode(5);
  TreeNode* node2 = new TreeNode(15);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(7);
  TreeNode* node5 = new TreeNode(12);
  TreeNode* node6 = new TreeNode(20);
  // TreeNode* node7 = new TreeNode(80);
  root->left=node1;
  root->right=node2;
  node1->left=node3;
  node1->right=node4;
  node2->left=node5;
  node2->right=node6;

  {
    cout<<"Search in BST: "<<searchBST(root, 9)<<endl;
  }
  traverseBST(root);
  cout<<endl;
  {
    insertBST(root, 0);
  }
  traverseBST(root);
  cout<<endl;
  minBSTValue(root);
  maxBSTValue(root);

  return 0;
}
// inorder traversal
void traverseBST(TreeNode* root){
  if (root==nullptr)
  {
    return;
  }
  traverseBST(root->left);
  cout<<root->data<<" ";
  traverseBST(root->right);
}

bool searchBST(TreeNode* root, int target){
  if (root==nullptr)
  {
    return 0;
  }
  if (root->data==target)
  {
    return 1;
  }
  if (root->data<target)
  {
    return searchBST(root->right, target);
  }
  if (root->data>target)
  {
    return searchBST(root->left, target);
  }
  return 0;
}

TreeNode* insertBST(TreeNode* root, int value){
  if (root==nullptr)
  {
    return new TreeNode(value);
  }
  if (root->data<value)
  {
    root->right = insertBST(root->right, value);
  }
  if (root->data>value)
  {
    root->left = insertBST(root->left, value);
  }
  return root;
}

void minBSTValue(TreeNode* root){
  if (root==nullptr)
  {
    return;
  }

  if (root->left==nullptr)
  {
    cout<<"Min Value: "<<root->data<<endl;
    return;
  }

  minBSTValue(root->left);
  return;
}

void maxBSTValue(TreeNode* root){
  if (root==nullptr)
  {
    return;
  }

  if (root->right==nullptr)
  {
    cout<<"Max Value: "<<root->data<<endl;
    return;
  }

  maxBSTValue(root->right);
  return;
}

TreeNode* minNode(TreeNode* root){
  while (root->left!=nullptr)
  {
    root=root->left;
  }
  return root;
}

TreeNode* removeBSTValue(TreeNode* root, int target){
  if (root==nullptr)
  {
    return nullptr;
  }
  if (root->left==nullptr && root->right==nullptr)
  {
    delete root;
    return;
  }
  if (root->data==target)
  {
    TreeNode* minNodeRef=minNode(root->right);
    root->data=minNodeRef->data;
    
  }
  if (target<root->data)
  {
    root->left=removeBSTValue(root->left, target);
  }else if (target>=root->data)
  {
    root->right=removeBSTValue(root->right, target);
  }



}
