#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Node{
public:
    unordered_map<char, Node *> children;
    bool endOfword;
    Node(){
        endOfword = false;
    }
};
class Trie{
    Node *root;

public:
    Trie(){
        root = new Node();
    }
    void Insert(string key){
        Node *temp = root;
        for (int i = 0; i < key.size(); i++){
            // if value is not exist create a new node for key
            if (temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }
    bool Search(string key){
        Node *temp = root;
        for (int i = 0; i < key.size(); i++){
            // if word is exist update temp
            if (temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{ 
                return false;
            }
        }
        return temp->endOfword;
    }
};



int main(){
    vector<string> word = {"i", "like", "sam", "samsung", "mobile", "ice"};
    Trie trie;
    // insert each opration
    for (int i = 0; i < word.size(); i++){
        trie.Insert(word[i]);
    }

    // for Search
    cout<<"Enter a word ";
    string i;
    cin>>i;
    if(trie.Search(i)){
        cout<<"word "<<i<<" is exist\n";
    }
    else{
        cout<<"word "<<i<<" dose't exist\n";
    }

    return 0;
}

// minor style fix
