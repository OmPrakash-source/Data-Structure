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
        this->left = NULL;
        this->right = NULL;
    } 
     
};


    Node* insertBST(Node*root,int data){
        if(root == NULL){
            return new Node(data); // int newnode = Node*(data) esa kiya tha pahle
        }
        if(root->data > data){
            root->left = insertBST(root->left,data);
        }
        else{
            root->right = insertBST(root->right,data);
        }
        return root;
    }
//_____________ Create BST by array _______________
    Node* BuildBST(int arr[], int size){
        Node*root = NULL;
        for(int i=0; i<size; i++){
            // insert ke ander (NULL,arr[1]) to first or root node
            root = insertBST(root,arr[i]);
        }
        return root;
    }
//_____________ Create BST by user input _______________
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

    void InOrder(Node* root) {
        if (root == NULL) return;
        InOrder(root->left);
        cout << "Node: " << root->data << endl;
        InOrder(root->right);
    }

    void PreOrder(Node*root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
//__________________________ Max _______________________
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
//__________________________ LeftMaxSuccessor _______________________
 // left me jo sabse badi value hai usko print karna hai
    Node* LeftMaxSuccessor (Node* root){
        // agar root null mill gai to usko hi return kar do 
        if(root == NULL){
            return root;
        }
        // root ke left ko call karo 
        // max function se jo high value return karega
        return Max(root->left);
    }
//__________________________ Min _______________________
    Node* Min(Node*root){
        if(root == NULL){
            return root;
        }
        Node*temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
//__________________________ RightMinSuccessor _______________________
    Node* RightMinSuccessor(Node*root){
        if(root == NULL){
            return root;
        }
        return Min(root->right);
    }

//___________________________Range B/W start and end ____________________
    // koi bhi 2 value di hogi uske bich me kitni node hai wo batana hai

    void PrintInRange(Node*root, int st, int ed){
        // base case 
        if(root == NULL){
            return;
        }
        //agar root start or end ke bich me hai
        if(st <= root->data && root->data <= ed){
            cout<<root->data<<" ";  // print data
            PrintInRange(root->left,st,ed); // call for left tree pahle ye pure chack karega fir |
            PrintInRange(root->right,st,ed); // call for right tree
        }
        /* agar root->data chota hai start se to right call \(3) < 5   */
        //kyoki fir root se bada data sirfh right me milega
        if(st > root->data ){
            PrintInRange(root->right,st,ed);
        }
        // agar root->data bada hai end se  to left call  /(15) > 12
        //kyoki fir root se chota data sirfh left me milega
        if(root->data > ed){
            PrintInRange(root->left,st,ed);
        }
    }

//______________________ Print Path ___________________

    void PrintPath(vector<int>path){
        cout<<"path :";
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    void Pathhelper(Node*root, vector<int> &path){
        //base if root is null then excution over
        if(root == NULL){
            return;
        }
        // jo root hai usko vector me push kiya
        path.push_back(root->data);
        // agar leaf node pe aa gaye to ->
        if(root->left == NULL && root->right == NULL){
            // ye function value ko print karvata hai
            PrintPath(path);
            //fir back jate time vo value ko pop bhi karna hai
            path.pop_back();
        }
        // then left ke liye call
        Pathhelper(root->left,path);
        // then right ke liye call
        Pathhelper(root->right,path);
                            // return jane ke bad 
        path.pop_back();    // jo bhi vector me hai delete karna
    } 
    // main function 
    void RootToLeaf(Node*root){
        vector<int>path;
        Pathhelper(root,path);
    }

//______________________ Valid BST But not all condition1 ___________________
    // bool ValidBST(Node*root){
    //     if(root == NULL){
    //         return true;
    //     }
    //     Node*LeftMax = Max(root->left);
    //     Node*RightMin = Min(root->right);

    //     return LeftMax->data < root->data && RightMin->data > root->data ? true:false;
    // }

//______________________ Valid BST  ___________________
    bool ValidateBSTHelper(Node*root,Node*min,Node*max){
        if(root == NULL) return true;

        if(min!=nullptr && min->data >= root->data) return false;   // agar min hai or min ki value root se badi hai to false 
        if(max!=nullptr && max->data <= root->data) return false;   // agar max hai or max ki value root se choti hai to false

        return ValidateBSTHelper(root->left, min, root) &&
        ValidateBSTHelper(root->right, root, max);
    }

    bool ValidateBST(Node*root){
        return ValidateBSTHelper(root,NULL,NULL);
    }

//______________________ Array to balance BST ___________________

    Node* ArrayToBST(int arr[],int st,int end){
        if(st > end){
            return NULL;
        }
        int mid = st + (end-st)/2;
        Node*curr = new Node(arr[mid]); //new node hamesha mid hogi
        curr->left = ArrayToBST(arr, st, mid-1);
        curr->right = ArrayToBST(arr, mid+1, end);

        return curr;    // ye root return karga fir left call than right call
    }
//___________ Convert BST to Balance tree _____________
    Node* VectorToBST(vector<int> arr,int st,int end){
        if(st > end){
            return NULL;
        }
        int mid = st + (end-st)/2;
        Node*curr = new Node(arr[mid]); //new node hamesha mid hogi
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
    Node* NonBalanceToBalance(Node*root){
        // to get inorder
        vector<int>nodes;
        getInorder(root,nodes);

        return VectorToBST(nodes,0,nodes.size()-1);
    } 

//______________________ deleteTree ___________________
    void deleteTree(Node* root) {
        if (root == NULL) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }


int main(){
    // Node* root = createNode();
    //_________________________________________
    // cout<< "Left most Greater value is: ";
    // Node* leftmax = LeftMaxSuccessor(root);
    // cout<< leftmax->data <<endl;
    //_________________________________________
    // cout<< "Right most Smaller value is: ";
    // Node* rightmin = RightMinSuccessor(root);
    // cout<< rightmin->data <<endl;
    //_________________________________________
    // inorder(root);
    // cout<<endl;
    // PrintInRange(root,5,12);
     //_________________________________________
    // RootToLeaf(root);
    // if (!ValidateBST(root)) {
    //     cout << "Binary search tree is invalid\n";
    // } else {
    //     cout << "Binary search tree is valid\n";
    // }
     //_________________________________________
    // int arr[] = {3,4,5,6,7,8,9};
    //Node*root = BuildBST(arr,6);
    // Node* root = ArrayToBST(arr,0,6);
     //_________________________________________
     Node* root = new Node(6);
     root->left = new Node(5);
     root->left->left = new Node(4);
     root->left->left->left = new Node(3);
     root->right = new Node(7);
     root->right->right = new Node(8);
     root->right->right->right = new Node(9);
     cout<<"befour balance - ";
     PreOrder(root); cout<<endl;
     cout<<"after belence - ";
     root = NonBalanceToBalance(root);
     PreOrder(root);
    
    // Clean up memory
    deleteTree(root);
    root = NULL; // ✅ Prevents use-after-free errors
    return 0;
}

// minor style fix
