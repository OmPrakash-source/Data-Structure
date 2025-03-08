#include<iostream>
#include<queue>
#include<vector>
using namespace std;

    class Node{
        public:
            Node* left;
            Node* right;
            int data;
            Node(int data){
                this->data =data;
                this->left =NULL;
                this->right =NULL;
            }
    };

    Node* createtree(){
        cout<<"value ";
        int value;
        cin>>value;
        if(value==-1){
            return NULL;
        }
        Node*root = new Node(value);
        root->left = createtree();
        root->right = createtree();

        return root;

    }

    void preOrder(Node* root){
        if(root == NULL){
            return;
        }

        cout<<root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root){
        if(root == NULL){
            return;
        }

        inOrder(root->left);
        cout<<root->data <<" ";
        inOrder(root->right);
    }

    void postOrder(Node* root){
        if(root == NULL){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        
        cout<<root->data <<" ";
    }

    void levelOrder(Node* root){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
                if(temp == nullptr){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                     if(temp->left!=nullptr){
                        q.push(temp->left);
                    }
                    cout<<temp->data<<" ";
                    if(temp->right!=nullptr){
                        q.push(temp->right);
                    }
                   
                }
        }

    }
        // left viwe if array ka size (arr.size == level ) 

    void leftViwe(Node* root, int level, vector<int>& leftviwe){
        if(root == NULL){
            return;
        }

        if(level == leftviwe.size()){
            //iska matlab value mill gai hai
            leftviwe.push_back(root->data);
        }
        leftViwe(root->left, level+1, leftviwe);
        leftViwe(root->right, level+1, leftviwe);
    } 

    void rightView(Node* root, int level, vector<int>& rightview) {
        if (root == NULL) {
            return;
        }

        if (level == rightview.size()) {
            rightview.push_back(root->data);
        }
        rightView(root->right, level + 1, rightview);
        rightView(root->left, level + 1, rightview);
    }

    int main(){
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        root->right->right->left= new Node(8);
        root->right->right->right= new Node(9);

        levelOrder(root);
        vector<int>arr;
        leftViwe(root, 0, arr);
        cout<<"Printing left viwe: "<<endl;
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout << endl;

        vector<int> rightview;
        rightView(root, 0, rightview);
        cout << "Printing right view: " << endl;
        for (int i = 0; i < rightview.size(); i++) {
            cout << rightview[i] << " ";
        }

        return 0;
    }
