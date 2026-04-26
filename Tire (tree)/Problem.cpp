#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfword;
    int freq;
    Node(){
        endOfword = false;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }
    void Insert(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(! temp->children.count(key[i])){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            }else{
                temp->children[key[i]]->freq ++;// this line only use for prefix
            }                                // this line only use for prefix
            temp = temp->children[key[i]];// this line only use for prefix
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
    string getPrefix(string key){   //O(n*l)
        Node*temp = root;
        string prefix = " ";
        for(int i=0;i<key.size();i++){
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1){
               break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }
};
//_________________________ Word Break Problem _________________________
bool trieHalper(Trie &trie, string key){
    if(key.size() == 0 ){
        return true;
    }
    for(int i=0;i<key.size();i++){
        string first = key.substr(0,i+1);   // start 0 ,end i+1
        string second = key.substr(i+1);    // start i+1 ,end size
        if(trie.Search(first) && trieHalper(trie,second)){
            return true;
        }
    }
    return false;
}
bool wordBreak(vector<string>dict,string key){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.Insert(dict[i]);
    }
    return trieHalper(trie,key);
}
//--------------------------- sortest Prefix ---------------------------

    void Prefix(vector<string>words){
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.Insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            cout<<trie.getPrefix(words[i])<<endl;
        }
    }
//--------------------------- start'sWith Prefix ------------------------

    void Startwith(vector<string>word){
        
    }
int main(){
    // vector<string> word = {"i", "like", "sam", "samsung", "mobile", "ice"};
    // string key = {"ilikesung"};
    // cout<<wordBreak(word,key);
    vector<string> word = {"zebra","dog","duck","dove"};
    Prefix(word);
    return 0;
}
// minor style fix
