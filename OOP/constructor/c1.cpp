    #include<iostream>
    #include<vector>
    #include<string>
    using namespace std;

    class Chai{
        public:
            string* teaName;
            int serving;
            vector<string>Ingredients;

// ________________________________________ default constructor _____________________________________

            // Chai (){
            //     cout<<"Default constructor is called "<<endl;

            //     teaName = "unknow tea";
            //     serving = 1;
            //     Ingredients = {"Water", "tea masala", "milk"};
            // }


//________________________________________ parameter constructor ____________________________________

            Chai(string name, int serv, vector<string>Ingre){
                cout<<"Parameterisd constructor is called "<<endl;
                teaName =new string (name);
                serving = serv;
                Ingredients = Ingre;
            }

//________________________________________ copy constructor ________________________________________

            Chai(const Chai& other){
                teaName = new string (*other.teaName);
                serving = other.serving;
                Ingredients = other.Ingredients;
                cout<<" copy constructor called"<<"\n \n";
            };
//________________________________________ Dstructor _____________________________________________

            ~Chai(){
                cout<<"Dstructor is called "<<endl;
                delete teaName;
            }
            void display(){
                cout<<"Tea name: "<<*teaName <<endl;
                cout<<"servings: "<<serving <<endl;
                cout<<"Ingredients: ";
                for(string Ingredient : Ingredients){
                    cout<< Ingredient<<", ";
                }
                cout<<endl;
            }
        };

    int main(){
        Chai c1 ("new Name", 3, {"water", "tea masala", "honey"});  // this line is called a constructor
        *c1.teaName = "leamon tea";
        c1.display();

        cout<<"\n \n";

        Chai c2 = c1;
        *c1.teaName = "masala tea";  // dek na thoda sa ye wala part <-------------------------------------------+
        c2.display();

        return 0;
    }