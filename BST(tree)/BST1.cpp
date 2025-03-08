#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;  // variable declarations
    Node *right; // variable declarations
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{ // Node* explicitly states that the function returns a pointer to a Node.
    if (root == NULL)
    {
        root = new Node(data); // Create a new node
        return root;
    }
    if (data > root->data) // agar data root ke data se bada ho to right me
    {
        root->right = insertIntoBST(root->right, data);
    }
    else // agar data root ke data se chhota ho to left me
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    cout << "Enter values to create BST (-1 to stop): ";
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data); // Update the root
        cout << "Enter values : ";
        cin >> data;
    }
}

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//____________________________ minvalue __________________________
Node *MinValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No MIN value\n";
        return NULL;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
//____________________________ maxvalue __________________________
Node *MaxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MAX DATA\n";
        return NULL;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
//__________________________ SearchBST _______________________

bool SearchBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    bool leftans = false;
    bool rightans = false;
    if (target < root->data)
    {
        leftans = SearchBST(root->left, target);
    }
    else
    {
        rightans = SearchBST(root->right, target);
    }
    return leftans || rightans;
}
Node *BinarySearch(Node *root, int target)
{
    if (root == NULL)
    {
        return nullptr;
    }
    if (root->data == target)
    {
        return root;
    }
    Node *RightAns = nullptr;
    Node *LeftAns = nullptr;

    if (target < root->data)
    {
        LeftAns = BinarySearch(root->left, target);
    }
    else
    {
        RightAns = BinarySearch(root->right, target);
    }
    if (LeftAns != NULL)
    {
        return LeftAns;
    }
    return RightAns;
}

Node *deleteFromBST(Node *root, int target)
{
    /// target ko dhundo
    // target ko delete karo

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // ab delete karenge
        // 4 cases
        if (root->left == NULL && root->right == NULL)
        {
            // 1 case -> leaf node
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            // 2 case -> left non null and right null
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // 3 case -> left me NULL and right NON NULL
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        // 4 case -> left NON NULL && right NON NULL
        else
        {
            // a -> left subtree ki max value lao
            Node *maxi = MaxValue(root->left);
            // replacement
            root->data = maxi->data;

            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    // agar target nhi milaa or targer chota hoga
    // left me chalo
    else if (root->data > target)
    {
        root->left = deleteFromBST(root->left, target);
    }
    // agar target nhi milaa or targer Bada hoga
    // right me jao
    else
    {
        root->right = deleteFromBST(root->right, target);
    }

    return root;
}

Node* BST(Node* root, int target){
    if(root == NULL){
        return NULL;
    }
    if(root->data == target ){
        //first case when leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            Node*childvalue = root->left;
            delete root;
            return childvalue;
        }
        else if(root->left == nullptr && root->right != nullptr){
            Node*childvalue = root->right;
            delete root;
            return childvalue;
        }
        else{
            Node* maxi = MaxValue(root->left);
            root->data = maxi->data;
            root->left = BST(root->left, maxi->data);
        }
    }
    else{
        if(root->data > target){
            root->left = BST(root->left,target);
        }
        else{
            root->right = BST(root->right,target);
        }
        return root;
    }

}
int main()
{
    Node *root = NULL;
    createBST(root);
    // cout << "Level-Order traversal: " << endl;
    cout << endl;
    levelorder(root);
    cout << endl;

    Node *MIN = MinValue(root);
    cout << "leftmost element is :" << MIN->data;
    cout << endl;

    int target;
    cout<<"Enter a Deleted node: \n";
    cin>>target;
    while(target != -1){
        root = BST(root,target);
        cout<<"\nPrinting a level order \n";
        levelorder(root);
        cout<<endl;

        cout<<"Enter a Deleted node: \n";
        cin>>target;

    }
    // Node *MAX = MaxValue(root);
    // cout << "Rightmost element is :" << MAX->data;
    cout << endl;
    
    // if(SearchBST(root,target)){
    //     cout<<target<<" target is exixt in tree\n";
    // }
    // else{
    //     cout<<target<<" target is not exist\n";
    // }

    // Node *BS = BinarySearch(root, target);
    // cout << "result :- " << BS->data;
    return 0;
}
