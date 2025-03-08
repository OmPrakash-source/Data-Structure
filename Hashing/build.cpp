#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    string key;
    int val;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        this->next = NULL; // Initialize next to NULL
    }
    // delete LL agar node ka next null nhi hai to pahle usko delete karna
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class HaseTable
{
    int totSize;
    int currSize;
    Node **table; // Node*(int*table) => Node**table
    int hashFunction(string key)
    {
        int idx = 0;
        // key (string) se idx banara hai
        for (int i = 0; i < key.size(); i++)
        {
            idx = (idx + (key[i] * key[i])) % totSize;
        }
        return idx;
    }

public:
    HaseTable(int size = 5)
    {
        totSize = size;
        currSize = 0;

        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        { // by default starting value is garbage value we initialize it to null
            table[i] = NULL;
        }
    }

    void rehash()
    {
        Node **oldTable = table; // purani table ko oldtable me store kiya or table ko update kiye
        int oldSize = totSize;
        totSize = 2 * totSize;       // size bada kar diya new updated table ka
        table = new Node *[totSize]; // size ke barabar new node bana di
        // table ki first value null hogi isme bhi
        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }
        // old table ki value copy karna hai
        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldTable[i]; // LL ka head temp me store
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (oldTable[i] != NULL)
            {
                delete oldTable[i]; // LL ka head delete but first call destructor
            }
        }
        delete[] oldTable; // delete old table because new table is created
    }
    void insert(string key, int value)
    { // O(1) but rehash = O(n)
        int idx = hashFunction(key);
        Node *newNode = new Node(key, value);
        newNode->next = table[idx]; // it also be NULL
        table[idx] = newNode;       // Update the table with the new head

        currSize++;
        double lambda = currSize / (double)totSize;
        if (lambda > 1)
        {
            rehash(); // O(n)
        }
    }
    bool Exist(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true; // if key is found
            }
            temp = temp->next;
        }
        return false;
    }
    int search(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->val; // if key is found value
            }
            temp = temp->next;
        }
        return -1;
    }
 
    void Print(){
        for (size_t i = 0; i < totSize; i++){
        cout<<"idx"<<i<<"->";
        Node*temp = table[i];
        while(temp != NULL){
            cout<<"("<<temp->key <<","<<temp->val<<") -> ";
            temp = temp->next;
        }
        cout<<endl;
        }
    }

    void remove(string key)
    {
        // Implementation for remove function
        int idx = hashFunction(key);
        Node*temp = table[idx];
        Node* prev = temp;
        while (temp != NULL)
        {
            if(temp->key == key){
                //for head
                if (prev == temp){ 
                    table[idx] = temp->next;
                }
                //for mid or last node
                else{
                    prev->next = temp->next;
                }    
                break;
            }
            prev = temp;
            temp = temp->next;
    
        }
    }
};
int main()
{
    HaseTable ht;
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Uk", 20);
    ht.insert("Nepal", 10);

    // if (ht.Exist("India"))
    // {
    //     cout << "India's population " << ht.search("India") << endl;
    // }
    // if (ht.Exist("caneda"))
    // {
    //     cout << "caneda's population " << ht.search("caneda") << endl;
    // }

    ht.Print();
    ht.remove("China");
    cout<<"_____________\n";
    ht.Print();
    return 0;
}