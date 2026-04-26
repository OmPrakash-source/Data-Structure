    #include<iostream>  // header file
    #include<limits.h>  // header file
    using namespace std;
    class Node{
        public:
            Node*left;
            Node*right;
            int data;
            Node(int data){
                this->data = data;
                left = right = NULL;
            }
    };
    Node* InsertIntoBST(Node*root,int val){
        if(root == NULL){
            root = new Node(val);
            return root;
        }
        if(root->data > val){
            root->left = InsertIntoBST(root->left,val);
        }
        else{
            root->right = InsertIntoBST(root->right,val);
        }
        return root;
    }
    Node* BuildBST(int arr[],int size){
        Node*root = NULL;
        for(int i=0;i<size;i++){
            root = InsertIntoBST(root,arr[i]);
        }
        return root;

    }
    void InOrder(Node*root){
        if(root == NULL) return;

        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
    class Info{
        public:
            bool IsBST;
            int Min;
            int Max;
            int Size;
            Info(bool isBST,int Min,int Max,int Size){
                this->IsBST = IsBST;
                this->Min = Min;
                this->Max = Max;
                this->Size = Size;
            }
    };

        static int MaxSize = 0;
        static Node* largestroot;

        Info * largestBST(Node*root){
            // if(root == NULL){
            //     // INT_MAX left ke liye parent ki value min me choti hogi to return parent(check for left)
            //     // INT_MIN right ke liye parent ki value max me badi hogi same (check for right)
            //     return new Info(true,INT_MAX,INT_MIN,0);
            // }
            if(root==NULL){
                return NULL;
            }
            // root ka max or min wo khud hi hoga
            if(root->left==NULL&&root->right==NULL){
                return new Info(true,root->data,root->data,1);
            }

            Info*leftInfo = largestBST(root->left);
            Info*rightInfo = largestBST(root->right);
            int currMin = min(root->data,min(leftInfo->Min,rightInfo->Min));
            
            int currMax = max(root->data,max(leftInfo->Max,rightInfo->Max));
            // size = leftinfo se jo size aaya or right ka size or parent ka size
            int currSize = leftInfo->Size + rightInfo->Size + 1;
            

            if(leftInfo->IsBST && rightInfo->IsBST &&
                root->data > leftInfo->Max && root->data < rightInfo->Min){
                    // maxsize or currSize me se jo bhi max ho wo
                    MaxSize = max(MaxSize,currSize);
                    largestroot = root;

                    return new Info(true,currMin,currMax,currSize);
                }
     
            return new Info(false,currMin,currMax,currSize);
        }



    int main(){
        Node*root = new Node(50);
        root->left = new Node(30);
        root->left->left = new Node(5);
        root->left->right = new Node(20);
        root->right = new Node(60);
        root->right->left = new Node(45);
        root->right->right = new Node(70);
        root->right->right->left = new Node(65);
        root->right->right->right = new Node(80);
        largestBST(root);
        cout<<"Max value : "<<MaxSize <<endl;
        cout<<"Max root value : "<<largestroot->data <<endl;
        InOrder(root);
    }

// minor style fix
