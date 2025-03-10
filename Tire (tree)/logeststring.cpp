#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfword;
    Node(){
        endOfword = false;
      
    }
};
class Trie{
    Node* root;
public:

    int size;
    Trie(){
        root = new Node();
    }
    void Insert(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(! temp->children.count(key[i])){
                temp->children[key[i]] = new Node();
            }
        }
        temp->endOfword = true;
    }
    bool Search(string key){
        Node *temp = root;
        for (int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfword;
    }

    void longesthelper(Node* root, string &ans, string temp){
        for(pair<char,Node*> child: root->children){
          if(child.second->endOfword){
            temp += child.first;
            if((temp.size()==ans.size() && temp < ans) || temp.size() > ans.size()) {
             ans = temp;
            }
            longesthelper(child.second, ans, temp);
            temp = temp.substr(0, temp.size()-1);
          }
        }
    }
    string longeststring(){
        string ans ="";
        longesthelper(root, ans ,"");
        return ans;
    }
};

string longestString(vector<string>dict){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.Insert(dict[i]);
    }
    return trie.longeststring();
}
   
int main(){
    vector<string>dict = {"a","banana","app","ap","apply","apple"};
    cout<<longestString(dict)<<endl;
    return 0;
}