#include<iostream>
#include<unordered_map>
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
        left = NULL;
        right= NULL;
    }
};
//_________________________ Build Tree ________________________
    Node* buildtree(){
        cout<<"enter data: ";
        int data;
        cin>>data;
        if(data == -1){
            return NULL;
        }
        //create Node
        Node* root = new Node(data);
        //left Node
        cout<<"left Node: "<<root->data<<endl;
        root->left = buildtree(); 
        //right Node
        cout<<"right Node: "<<root->data<<endl;
        root->right = buildtree();

        return root;
    }
    Node* preOrder(Node* root){ //Time O(n), Space O(n)
        if(root == NULL) return NULL;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    Node* inorder(Node*root){
        if(root == NULL) return NULL;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    Node* postOrder(Node* root){
        if(root == NULL) return NULL;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
//_________________________ Levelorder ________________________
    Node* LevelOrder(Node*root){
        queue<Node*>q;
        if(root == NULL) return NULL;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL)q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }

    }
    Node* levelorder(Node* root){
        queue<Node*>q;
        if(root == NULL){
            return NULL;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty()){ // first me q empty nhi hogi kyoki usme root or null hoga
            Node* temp = q.front(); // root to store then pop
            q.pop();
            if(temp == NULL){   // agar top pe nullptr mill to next line 
                cout<<endl;
                if(!q.empty()){ //check kar liya agar or value hai aage q me to NULL push kro nhi to katam karo 
                    q.push(NULL); // NULL push huaa matlab q me root ke child hai prasent 
                }
            }else{  
                // nhi to valid case hai 
                cout<<temp->data<<" "; // top ka data print 
                if(temp->left){ // agar left not null hai to push karo q me
                    q.push(temp->left);
                }
                if(temp->right){ // agar right not null hai to push karo q me 
                    q.push(temp->right);
                }
            }
        }
    }

    int height(Node* root){
        if(root == NULL) return 0;
        int leftans = height(root->left);
        int rightans = height(root->right);
        int ans = max(leftans,rightans) + 1;
        return ans;
    }


    // left viwe
    void leftView(Node* root, int level, vector<int>&ans) {
        if (root == NULL) return;
        if (level == ans.size()) {
             ans.push_back(root->data);
        }

        leftView(root->left, level + 1, ans);
        leftView(root->right, level + 1, ans);
   }

   // by level order
    void levelleft(Node* root, vector<int>&ans){
        if(!root) return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                if(i==0) ans.push_back(front->data);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
    }
// Right view __________________________________ 

    void levelright(Node* root, vector<int>&ans){
        if(!root) return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* front = q.front();
                q.pop();
                // har level pe q me right val push kar di wo right view hoge 
                if(i == 0) ans.push_back(front->data);
                if(front->right)q.push(front->right);
                if(front->left)q.push(front->left);
            }
        }
    }
    void rightView(Node* root, int level, vector<int>&ans) {
        if (root == NULL) return;
        if (level == ans.size()) {
            ans.push_back(root->data);
        }
        rightView(root->right, level + 1, ans);
        rightView(root->left, level + 1, ans);
    
    }
// __________________________________ TOP VIEW BY level order ________________________________

    void topView(Node* root){
        if(root == NULL) return;
        unordered_map<int,int>m;  // map me horisontal level store hoge  174
        // hd, front->data
        queue<pair<Node*,int>>q;
        // front->data, hd
        q.push(make_pair(root,0));

        while(!q.empty()){
            Node* front = q.front().first;
            int hd = q.front().second;
            q.pop();

            if(m.find(hd) == m.end()){ //or batayge ki uss particuler level pe nnode thi ya nhi agar nhi to store kardege
                m[hd] = front->data; // hd me front ka data
            }

            if(front->left) q.push(make_pair(front->left, hd-1) ); // left me jayga to horizontal level -1 hoga current se
            if(front->right) q.push(make_pair(front->right, hd+1) );// right me jayga to horizontal level +1 hoga current se 
        }
        for(auto num : m){
            cout<<num.second<<" ";
        }
    }

// __________________________________ Bottom VIEW BY level order ________________________________
    void bottomView(Node* root){
        if(root == NULL) return;
        queue<pair<Node*,int>>q;
        unordered_map<int,int>m;
        q.push(make_pair(root,0));
        while(!q.empty()){
            Node* front = q.front().first;
            int hd = q.front().second;
            q.pop();

            // yaha agar value map me hai to bhi push karna hai kyoki old value override ho ke new val push hogi jo ki last tak jaygi 
            m[hd] = front->data;

            if(front->left) q.push(make_pair(front->left, hd-1) ); // left me jayga to horizontal level -1 hoga current se
            if(front->right) q.push(make_pair(front->right, hd+1) );// right me jayga to horizontal level +1 hoga current se 
        }
        for(auto num : m){
            cout<<num.second<<" ";
        }
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
        levelorder(root);
        cout<<endl;
        vector<int>ans;
        
        levelleft(root, ans);
        for(int i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<int>ans2;
        levelright(root, ans2);
        for(int i : ans2){
            cout<<i<<" ";
        }
        cout<<endl;
        topView(root);
        cout<<endl;
        bottomView(root);
    }
// minor style fix
