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
        size = 0;
    }
    void Insert(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(! temp->children.count(key[i])){
                temp->children[key[i]] = new Node();
                size ++;
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
    int Result(vector<string>total, Node*root){
        int count = 0;
        for(int i=0;i<root->children;i++){
            count += Result(children[i]);
        }
        return count;
    }
};


int Count(string s){
    Trie trie;
    vector<string> total = {" "};
    string cot;
    for(int i=0;i<s.size();i++){
        cot = s.substr(i); 
        for(int i=0;i<cot.size();i++){
            trie.Insert(total[i]);
        }
        total = Result(total, root);
    }
    
}

   
int main(){
    string str = "ababa";
    return 0;
}
// minor style fix
