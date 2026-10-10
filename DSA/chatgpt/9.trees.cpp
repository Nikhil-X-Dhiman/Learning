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

void preOrderTraversal(TreeNode* node);
void inOrderTraversal(TreeNode* node);
void postOrderTraversal(TreeNode* node);
vector<vector<int>> levelOrderTraversal(TreeNode* root);
void traverse2vector(const vector<vector<int>> arr);
int depthOfBinaryTree(TreeNode* root);
int nodeCounting(TreeNode* root, int count=0);
int leafNodeCounting(TreeNode* root);
bool searchBinaryTree(TreeNode* root, int target);

int main(){

  {
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(20);
    TreeNode* node2 = new TreeNode(30);
    TreeNode* node3 = new TreeNode(40);
    TreeNode* node4 = new TreeNode(50);
    TreeNode* node5 = new TreeNode(60);
    TreeNode* node6 = new TreeNode(70);
    TreeNode* node7 = new TreeNode(80);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    node2->right=node5;
    node3->left=node6;
    node3->right=node7;

    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Depth of Tree: "<<depthOfBinaryTree(root);
    cout<<endl;
    cout<<"Number of nodes in a Tree: "<<nodeCounting(root);
    cout<<endl;
    cout<<"Number of leaf nodes in a Tree: "<<leafNodeCounting(root);
    cout<<endl;
    cout<<"Searching in a Tree: "<<searchBinaryTree(root, 30);
    cout<<endl;
  }

  return 0;
}

void traverse2vector(const vector<vector<int>> arr){
  for(vector<int> subArray: arr){
    for(int n: subArray){
      cout<<n<<" ";
    }
    // cout<<" ";
  }
  return;
}

void preOrderTraversal(TreeNode* node){
  if (node==nullptr)
  {
    return;
  }
  cout<<node->data<<" ";
  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
  return;
}
void inOrderTraversal(TreeNode* node){
  if (node==nullptr)
  {
    return;
  }
  inOrderTraversal(node->left);
  cout<<node->data<<" ";
  inOrderTraversal(node->right);
  return;
}
void postOrderTraversal(TreeNode* node){
  if (node==nullptr)
  {
    return;
  }
  postOrderTraversal(node->left);
  postOrderTraversal(node->right);
  cout<<node->data<<" ";
  return;
}

vector<vector<int>> levelOrderTraversal(TreeNode* root){
  vector<vector<int>> ans;
  queue<TreeNode*> line;
  if (root==nullptr)
  {
    return ans;
  }
  line.push(root);
  while (!line.empty())
  {
    vector<int> level;
    for (int16_t i = 0; i < line.size(); i++)
    {
      TreeNode* node = line.front();
      line.pop();
      if (node->left!=nullptr)
      {
        line.push(node->left);
      }
      if (node->right!=nullptr)
      {
        line.push(node->right);
      }
      level.push_back(node->data);

    }
    ans.push_back(level);
  }
  traverse2vector(ans);
  return ans;
}

int depthOfBinaryTree(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }
  return 1+max(depthOfBinaryTree(root->left), depthOfBinaryTree(root->right));
}

int nodeCounting(TreeNode* root, int count){
  if (root==nullptr)
  {
    return 0;
  }
  return 1+nodeCounting(root->left)+nodeCounting(root->right);
}

int leafNodeCounting(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }
  if (root->left==nullptr && root->right==nullptr)
  {
    return 1;
  }
  return leafNodeCounting(root->left) + leafNodeCounting(root->right);
}

bool searchBinaryTree(TreeNode* root, int target){
  if (root==nullptr)
  {
    return false;
  }
  if (root->data==target)
  {
    return 1;
  }
  // short-circuit evaluation
  return searchBinaryTree(root->left, target) || searchBinaryTree(root->right, target);
}
