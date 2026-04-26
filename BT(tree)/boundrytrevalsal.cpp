#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

void forleft(Node* root){
    if(root == NULL) return;
    if(!root->left && !root->right) return;
    cout<<root->data<<" ";
    if(root->left) forleft(root->left);
    else forleft(root->right);
}

void forleaf(Node* root){
    if(root == NULL) return;

    if(!root->left && !root->right){ // leaf node milne pe data print 
        cout<<root->data<<" ";
        return;
    }

    forleaf(root->left);
    forleaf(root->right);
}
void forright(Node* root){
    if(root == NULL) return;
    if(!root->left && !root->right) return; //leaf note to include nhi karna hai iss liye
    
    if(root->right) forleft(root->right); // agar right exist karta hai to right me hi jana hai

    else forleaf(root->left);

    cout<<root->data<<" "; // jab base case hit ho jay to  print karte aayga last se 
}
void boundry(Node* root){
    cout<<root->data<<" ";
    forleft(root->left);
    forleaf(root->left);
    forleaf(root->right);
    forright(root->right);
}

// ZIG ZAG taversal 
/*
------->
        |
<-------
|
-------->
*/

vector<vector<int>> zigZag(Node* root){
    bool flag = true;
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size); 
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();

            int idx = flag ? i : size-i-1;
            //        T/F ? idx or last idx
            temp[idx] = front->data;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        flag = !flag; // help for zig zag
        ans.push_back(temp);
    }
    return ans;

}

int main(){
    Node* root = new Node(3);
        root->left = new Node(5);
        root->right = new Node(1);
        root->left->left = new Node(6);
        root->left->right = new Node(2);
        root->right->left = new Node(0);
        root->right->right = new Node(8);
        root->left->right->left = new Node(7);
        root->left->right->right = new Node(4);
        vector<vector<int>>ans = zigZag(root);
        
        cout << "ZigZag Traversal:\n";
        for (const auto& row : ans) {
            for (int val : row) cout << val << " ";
            cout << endl;
        }

        // boundry(root);
}
// minor style fix
