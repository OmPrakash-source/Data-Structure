#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};
Node* insertBST(Node*root,int data){
    if(root == NULL){
        return new Node(data);
    }
    if(root->data > data){
        root->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;
}
Node* createNode(){
    Node* root = NULL;
    cout<<"enter a value :";
    int data;
    cin>>data;
    while(data != -1){
        root = insertBST(root,data);
        cin>>data;
    }
    return root;
}
Node* BuildBST(int arr[],int n){
    Node*root = NULL;
    for(int i=0;i<n;i++){
        root = insertBST(root,arr[i]);
    }
}

Node* Max(Node*root){
    if(root == nullptr){
        return root;
    }
    Node*temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

void PreOrder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

Node* DeletefromBST(Node*root,int target){
    if(root==NULL){
        return NULL;
        }
    if(root->data == target){
        if(root->left==nullptr&&root->right==nullptr){
            delete root;
            return NULL; // root return kar di thi iske pahle
        }
        else if(root->left == nullptr && root->right!=nullptr){
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != nullptr && root->right==nullptr){
            Node* child = root->left;
            delete root;
            return child;
        }
        
        else{
            Node * maxi = Max(root->left);
            root->data = maxi->data;
            root->left = DeletefromBST(root->left,maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = DeletefromBST(root->left, target);
    }
    // agar target nhi milaa or targer Bada hoga
    // right me jao
    else
    {
        root->right = DeletefromBST(root->right, target);
    }

    return root;
}

Node* VectorToBST(vector<int> arr,int st,int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node*curr = new Node(arr[mid]); //new node banai jisme array ke mid value push kar di fir repeat
    curr->left = VectorToBST(arr, st, mid-1);
    curr->right = VectorToBST(arr, mid+1, end);

    return curr;    // ye root return karga fir left call than right call
}
// similer to InOrder program but it store value to vector
void getInorder(Node*root, vector<int> &nodes){
    if(root == NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);    // push value to Vector nodes use same print code
    getInorder(root->right,nodes);
}

Node*Marge(Node*root1,Node*root2){
    vector<int>nodes1;
    vector<int>nodes2;
    vector<int>marged;
    getInorder(root1,nodes1);   // sort both tree 1
    getInorder(root2,nodes2);   // sort both tree 2
    int i , j = 0;
    while(i<nodes1.size()&&j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){    // check size of value 
            marged.push_back(nodes1[i++]); // push into marge and incresses 
        }else{
            marged.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){ // fir agar koi or value tree me ho uske liye 
        marged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        marged.push_back(nodes2[j++]);
    }
    return VectorToBST(marged,0,marged.size()-1); // create tree by  marge value
}
void DeleteBST(Node*root){
    if(root == NULL){
        return;
    }
    DeleteBST(root->left);
    DeleteBST(root->right);
    delete root;
}

int main(){
    // Node*root = createNode();
    
    // PreOrder(root);
    // cout<<"\n\n";
    // DeletefromBST(root,40);
    Node*root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node*root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(15);

    Node*root = Marge(root1,root2);
    PreOrder(root);
    DeleteBST(root);
    root = NULL;
    return 0;
}