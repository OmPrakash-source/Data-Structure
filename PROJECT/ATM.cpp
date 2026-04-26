#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Account{
public:

    int pin;
    string accountno;
    string name;
    double balance;
    Account(string accno, string uname, int p, double bal) {
        accountno = accno;
        name = uname;
        pin = p;
        balance = bal;
    }
    bool login(string enteredAccNo, int enteredPin) {
        return (accountno == enteredAccNo && pin == enteredPin);
    }
    void checkbalance(){
        cout<<"your current balance is: "<<balance<<endl;
    }

    void deposit(double amount){
        if(amount < 0){
            cout<<"Can't deposit \n";
            return;
        }
        balance += amount;
        cout<<"Your new balance is: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(amount > balance){
            cout<<"Not sufficient amount \n";
            return;
        }
        if(amount < 0){
            cout<<"Can't Withdrow\n";
            return;
        }
        balance = balance - amount;
        cout<<amount << " is Withdrow\n";
    }
    void changePin(int oldpin, int newpin){
        if(oldpin == pin){
            pin = newpin;
            cout<<"sucessful pin changed\n";
            return;
        }else{
            cout<<"Enter valid pin\n";
        }
    }
};

class ATM {
    vector<Account>accounts;
    int currentidx = -1;

public:
    void registerasnew(){
        string accno;
        int pin;
        int amount;
        string name;
        cout << "Enter user name: ";
        cin>>name;
        cout << "Enter Account Number: ";
        cin>>accno;
        cout << "Enter PIN: ";
        cin >> pin;
        cout << "Enter amount for deposit: ";
        cin >> amount;

        accounts.push_back(Account(accno,name,pin,amount));
        cout<<name<< " !Wellcome \n";
        mainMenu();
        return;

    }
    void atmmanu(){
        int choice;
        do{
            cout<<"1.Login 2.register 3.exit\n Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:{
                    loginMenu();
                    break;
                } 
                case 2: {
                    registerasnew();
                    break;
                }
                case 3: return;
            }
        }while(choice != 2);
    }
    void loginMenu() {
        string accno;
        int pin;
        cout << "Enter Account Number: ";
        cin >> accno;
        cout << "Enter PIN: ";
        cin >> pin;

        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].login(accno, pin)) {
                currentidx = i;
                cout << "Login successful\n";
                mainMenu();
                return;
            }
        }
        cout << "Invalid account number or PIN!\n";
    }

    void mainMenu() {
        int choice;
        do {
            cout << "\n1. Check Balance 2. Deposit 3. Withdraw 4. Change PIN 5. Exit\nEnter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    accounts[currentidx].checkbalance();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter amount: ";
                    cin >> amount;
                    accounts[currentidx].deposit(amount);
                    break;
                }
                case 3: {
                    float amount;
                    cout << "Enter amount: ";
                    cin >> amount;
                    accounts[currentidx].withdraw(amount);
                    break;
                }
                case 4: {
                    int oldpin, newpin;
                    cout << "Enter old PIN: ";
                    cin >> oldpin;
                    cout << "Enter new PIN: ";
                    cin >> newpin;
                    accounts[currentidx].changePin(oldpin, newpin);
                    break;
                }
                case 5:
                    cout << "Thank you for using ATM.\n";
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } while (choice != 5);
    }
};
int main(){
    ATM a1;
    a1.atmmanu();
}