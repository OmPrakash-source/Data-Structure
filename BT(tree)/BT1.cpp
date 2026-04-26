#include<iostream>
#include<queue>
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

// it is return a root node
Node* createtree(){
    cout<<"enter a value for node : ";
    int data;
    cin>>data;

    // for leaf node 
    if(data == -1){
        return NULL;
    }

    // step1: create a root node
     Node* root = new Node(data);
     
     //step2: create a left node
     cout<<"left node : "<< root->data <<endl;
     root->left = createtree();

     //step3: create a right node
      cout<<"right node : "<< root->data <<endl;
     root->right = createtree();
     

     return root;
     }
//____________________________ pre in post order travarsal _____________________________
        void preOrder(Node* root){
            if(root == NULL){
                return;
            }
        //root
        cout<<root->data<<" ";
        //L
        preOrder(root->left);

        //R
        preOrder(root->right);

        }

        void inOrder(Node*root){
            if(root == NULL){
                return;
            }
            // LNR 
            //L
            inOrder(root->left);

            //N
            cout<<root->data<<" ";

            //R
            inOrder(root->right);
        }

        void postOrder(Node* root){
            if(root == NULL){
                return;
            }

            //LRN
            //L
             postOrder(root->left);

             //R
              postOrder(root->right);

              //N
              cout<<root->data<<" ";
        }

//____________________________ level order travarsal _____________________________

        void levelOrder(Node* root){
            queue<Node*>q;

            if (root == NULL) {
                return ; // Handle empty tree
            }

            q.push(root);
            q.push(NULL);   // Marker for end of level

            while(!q.empty()){
                Node* front = q.front();
                q.pop(); // prasent time queue is empty
                
                // yaha pe jo node front pe hai uske child queue me insert ho gai hai to NULL push kar do 
                // Non-Valid condition 
                if(front == NULL){
                    cout<<endl;
                    if(!q.empty()){  // if queue is not empty only that time NULL insert 
                    q.push(NULL);
                    }
                }
                // Valid condition
                else{
                    cout<<front->data<<" ";  // queue ka first new pointer me hai
                    if(front->left != NULL){ 
                    q.push(front->left);}
    
                    if(front->right != NULL){
                    q.push(front->right);}
                }
            } 
        }
//_________________________________ height ________________________________________
  int height(Node* root){
        if(root == NULL){
            return 0;
        }
        // search height in both side
        int leftans = height(root->left);
        int rightans = height(root->right);
        // it search maximum result in both side + 1 for root
        int ans = max(leftans,rightans)+1; 

        return ans;
    }
//_________________________________ Diameter ________________________________________
    int diameterOfTree(Node* root){
        if(root == NULL){
            return 0;
        }
        int option1 = height(root->left)+height(root->right);
        int option2 = diameterOfTree(root->left);
        int option3 = diameterOfTree(root->right);
        int ans = max(option1 , max(option2,option3));
        
        return ans;
    }
//_________________________________ height balance tree ________________________________________
    bool balance(Node* root){
        if(root == NULL){
            return true;
        }

        int option1 = height(root->left);
        int option2 = height(root->right);
        if (abs(option1 - option2)> 1){
            return false;
        }
        
        int leftbalance = balance(root->left);
        int rightbalance = balance(root->right);

        return leftbalance && rightbalance;
    }
    // __________________ OR ____________________
    bool Balance (Node* root){
        if(root == NULL){
            return true;
        }
        int option1 = height(root->left);
        int option2 = height(root->right);  
        int curr = abs(option1 - option2);

        int leftans = Balance(root->left); 
        int rightans = Balance(root->right);
        bool currAns = (curr <= 1 && curr >= -1);

        if(currAns && leftans && rightans){
            return true;
        }
        else{
            return false;
        }
    }
//______________________________________236 ancester _______________________

 // given a two value p and q  a one node there it both meet 

    Node* LowestAncestor(Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    // If the current node is either p or q, return it
    if (root->data == p || root->data == q) {
        return root;
    }

    // Search for LCA in the left and right subtrees
    Node* leftans = LowestAncestor(root->left, p, q);
    Node* rightans = LowestAncestor(root->right, p, q);

    // If both leftans and rightans are not NULL, this node is the LCA
    // jaha dono node left and right se non null ans aay wo hi Ancestor hai yo yaha hoga
    if (leftans != NULL && rightans != NULL) {
        return root;
    }
    
    // Otherwise, return the non-NULL answer
    return leftans != NULL ? leftans : rightans;

    // if(leftans != nullptr){ aagar left se not null ans aay or right se null aay to left node hi ans hogi
    //     return leftans;
    // }
    // else{ aagar right se not null ans aay or left se null aay to right node hi ans hogi
    //     return rightans; 
    // }
 }



    

     int main(){
        //  Node* root = createtree();
        //  cout<< root->data<<endl;

        //  cout<<"Printing preorder " ;
        //  preOrder(root);
        //  cout<<endl;
        //  cout<<"Printing inorder "  ;
        //  inOrder(root);
        //  cout<<endl;
        //  cout<<"Printing postorder ";
        //  postOrder(root);
        //  cout<<endl;
        Node* root = new Node(3);
        root->left = new Node(5);
        root->right = new Node(1);
        root->left->left = new Node(6);
        root->left->right = new Node(2);
        root->right->left = new Node(0);
        root->right->right = new Node(8);
        root->left->right->left = new Node(7);
        root->left->right->right = new Node(4);
            // cout<<"Printing levelorder \n";
            // levelOrder(root);
            // cout<<endl;

            // cout<<"diameter of tree is: "<<diameterOfTree(root)<<endl;

            // cout<<"height of tree: "<<height(root)<<endl;
        
            // if (Balance(root)) {
            //     cout << "The tree is balanced." << endl;
            // } else {
            //     cout << "The tree is not balanced." << endl;
            // }

    int p = 7, q = 5;

    Node* lca = LowestAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->data << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }
     }
// minor style fix
