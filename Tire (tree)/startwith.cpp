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
    bool startwith(string prefix){
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(temp->children.count(prefix[i])){
                temp = temp->children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<string> word = {"i", "like", "sam", "samsung", "mobile", "ice"};
    Trie trie;
    for (int i = 0; i < word.size(); i++){
        trie.Insert(word[i]);
    }
    

    cout<<trie.startwith("i")<<endl;
    return 0;
}