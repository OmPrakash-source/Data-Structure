#include<iostream>
#include<map>
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
// beadth 
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

    
    int searchInorder(int in[], int size, int target){
        for(int i=0; i<size; i++){
            if(in[i]==target){
                return i;
            }
        }
        return -1;
    }
 
    void SerchByMap(int inOrder[], int n, map<int,int> &m){
        for(int i =0; i<n; i++){
            m[inOrder[i]] = i;
        }
    }
// pre and in use to create tree


    Node* construct_tree_preandin(int pre[], int in[], int &preindex, int instart, int inend, int size ){
        //base 
        if(preindex >= size || instart > inend ){
            return NULL;
        }

        // first case 
        int element = pre[preindex];
        preindex++;
        Node*root = new Node(element);

        //left or right ke node to inorder
        int position = searchInorder(in, size, element);

        root->left = construct_tree_preandin(pre ,in ,preindex ,instart ,position-1 ,size);

        root->right = construct_tree_preandin(pre ,in ,preindex ,position+1 ,inend ,size);
        
        return root;

    }

// post and in use to create tree


    Node* construct_tree_postandin(map<int,int>&m, int post[], int in[], int &postindex, int instart, int inend, int size ){ 

        
    // yaha pe preindex ko by refrence bhejna hai kyiki wo position change kare or recursion se restart n ho
        //base 
        if(postindex < 0 || instart > inend ){
            return NULL;
        }

        // first case 
        int element = post[postindex];
        postindex--;
        Node*root = new Node(element);

        //left or right ke node to inorder
                // int position = searchInorder(in, size, element);

        // search position by map in O(1)
        int position = m[element];

    /* that is most importent first call right then call left*/
        root->right = construct_tree_postandin(m,post ,in ,postindex ,position+1 ,inend ,size);

        root->left = construct_tree_postandin(m,post ,in ,postindex ,instart ,position-1 ,size);

        return root;

    }
    int main(){
        //     int inorder[] = {10,8,6,2,4,12};
        //     int preorder[] = {2,8,10,6,4,12};
        //     int size = 6;
        //     int preorderIndex = 0;
        //     int inorderstart = 0;
        //     int inorderend = 5;
            
        // Node* root = construct_tree_preandin( preorder,inorder, preorderIndex, inorderstart,inorderend, size);
        // cout<<"printing a tree\n";
        // levelOrder(root);
        cout<<endl;

        int inorder[] ={8,14,6,2,10,4};
        int postorder[] ={8,6,14,4,10,2};
        int postindex = 5; 
        int size =6;
        int inorderstart = 0;
        int inorderend = 5;


        map<int,int>m;
        SerchByMap(inorder, size, m);
        Node* root = construct_tree_postandin( m,postorder,inorder, postindex, inorderstart,inorderend, size); 

        levelOrder(root);


            return 0;
    }
// minor style fix
