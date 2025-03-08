
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node()
    {
        cout << "deNodeore is called\n";
    }
};

//________________________________________ path sum ______________________

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // search height in both side
    int leftans = height(root->left);
    int rightans = height(root->right);
    // it search maximum result in both side + 1 for root
    int ans = max(leftans, rightans) + 1;

    return ans;
}
// __________________________________ path sum ______________________________________________

void hasPathSum(Node *root, int target, vector<vector<int>> &ans, vector<int> &temp, int sum)
{
    if (root == NULL)
        return;
    sum += root->data;
    temp.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == target)
        {
            ans.push_back(temp);
        }
        temp.pop_back();
        return;
    }
    hasPathSum(root->left, target, ans, temp, sum);
    hasPathSum(root->right, target, ans, temp, sum);

    temp.pop_back();
}

vector<vector<int>> pathSum(Node *root, int target)
{
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    hasPathSum(root, target, ans, temp, sum);
    return ans;
}

//_____________________________________ move to k up ______________________________________

Node *findKthAncestor(Node *root, int target, int &k, Node *&ans)
{
    if (root == NULL)
        return NULL;

    // If the current node is the target
    if (root->data == target)
        return root;

    // check left and right both side using recursion
    Node *leftans = findKthAncestor(root->left, target, k, ans);
    Node *rightans = findKthAncestor(root->right, target, k, ans);

    // if left and right any one side given true then ->
    if (leftans || rightans)
    {

        // deccrease avalue of k
        k--;

        if (k == 0)
        {
            ans = root;
        }
        // root->val is stored in ans
        return root;
    }
    return NULL;
}

// ____________________________________ IN-PRE to convert a tree  ____________________________

int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // cout<<"height :"<<height(root)<<endl;
    // vector<vector<int>> paths = pathSum(root ,14);
    // for (int i = 0; i < paths.size(); i++) {
    // for (int j = 0; j < paths[i].size(); j++) {
    //     cout << paths[i][j] << " "; // Access elements using indices
    // }
    // cout << endl; // Print a newline after each path
    // }

    int target = 5;
    int k = 2;
    Node *ans = NULL;
    findKthAncestor(root, target, k, ans);

    // first ans is NULL but after find a value it increase that print true
    if (ans != NULL)
    {
        cout << "The " << k << "-th ancestor of " << target << " is: " << ans->data << endl;
    }
    else
    {
        cout << "The " << k << "-th ancestor of " << target << " is not exist \n";
    }
}