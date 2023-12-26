// ClassLesson.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>




using namespace std;



class person;


class inventarization {
protected:
    friend void print_by_type(vector<inventarization>& hehe, string name);
    friend class person;

    std::string name;
    std::string type;
    int number;
public:
    void print_all() {
        cout << "\nNumber: " << this->number << " Type: " << this->type << " Name: " << this->name << endl;
    }

    inventarization(string p_name, string p_type, int p_number)
    {
        this->name = p_name;
        this->type = p_type;
        this->number = p_number;
        std::cout <<  "\nObject has been created" << std::endl;
    }
    inventarization()
    {
        this->name = "";
        this->type = "";
        this->number = 0;
        std::cout << "\nObject has been created" << std::endl;
    }
    ~inventarization() {}
    inventarization(const inventarization&p) {
        name = p.name;
        type = p.type;
        number = p.number;
    }
    inventarization(inventarization&& moved) noexcept {
        name = moved.name;
        type = moved.type;
        number = moved.number;
        moved.name = "";
        moved.type = "";
        moved.number = 0;
        
    }
    
};

class person {
    string const_type = "Mouse";

public:
    void check(vector<inventarization>& hehe) {
        try {
            for (int i = 0; i < hehe.size(); i++) {
                
                if (hehe.at(i).type == this->const_type) {
                    cout << "АААААА!! Номер:" << hehe[i].number << " это мышь!" << endl;
                }
            }
                

        }
        catch (exception &e) //
        {
            cout << "ASDASFd" << endl;//  e->what();
        }
        




    };
};

void print_by_type(vector<inventarization>& hehe, string name) {
    //string type;
    for (int i = 0; i < hehe.size(); i++)
    {

        if (hehe[i].type == name) {
            hehe[i].print_all();
        }
    }

}


class mouse : public inventarization
{
public:
 //   string type = "mouse";
    string colour;
    void print_all() {
        cout << "\nNumber: " << this->number << " Type: " << this->type << " Name: " << this->name << " Colour:" << this->colour << endl;
    }

    mouse()
    {
        this->name = "Default";
        this->number = 0;
        this->colour = "Default";
        std::cout << "\nMouse has been created" << std::endl;
    }

    mouse(string p_name, string p_type, int p_number) {
        this->name = p_name;
        this->type = "Mouse";
        this->number = p_number;
        this->colour = "Default";
        std::cout << "\nMouse has been created" << std::endl;
    }

    void voice()
    {
        cout << "\n Meep meeep..." << endl;
    }
};

class chair : public inventarization
{
    int comfortable; //Level of comfortable from 0 to 10
public:
 //   string type = "chair";


    void print_all() {
        cout << "\nNumber: " << this->number << " Type: " << this->type << " Name: " << this->name << " Comfortable: " << this->comfortable << endl;
    }

    chair()
    {
        this->name = "Default";
        this->number = 0;
        this->type = "Chair";
        this->comfortable = 0;
        std::cout << "\nChair has been created" << std::endl;
    }

    chair(string p_name, string p_type, int p_number) {
        this->name = p_name;
        this->type = "Chair";
        this->number = p_number;
        this->comfortable = 0;
        std::cout << "\nChair has been created" << std::endl;
    }

    void check() {
        int c;
        c = this->comfortable;
        if (c < 3) {
            cout << "Not so comfortable";
        }
        else if (c < 7){
            cout << "Enough comfortable";
        }
        else{
            cout << "Very good";
        }

    }

};

class monitor : public inventarization
{

   // string type = "monitor";
    int height;
    int lenght;

public:

    void print_all() {
        cout << "\nNumber: " << this->number << " Type: " << this->type << " Name: " << this->name << " Height:" << this->height << " Lenght: " << this->lenght << endl;
    }

    monitor()
    {
        this->name = "Default";
        this->number = 0;
        this->height = 1;
        this->lenght = 1;
        std::cout << "\nMonitor has been created" << std::endl;
    }
    
    monitor(string p_name, string p_type, int p_number) {
        this->name = p_name;
        this->type = "Monitor";
        this->number = p_number;
        this->height = 1;
        this->lenght = 1;
        std::cout << "\nMonitor has been created" << std::endl;
    }

    void diagonal() {
        int a, b;
        a = this->lenght;
        b = this->height;
        a = a * b;
        cout << "Diagonale =" << a << endl;
    }
        
    
};

    class computer : public inventarization
    {
    
       // string type = "computer";
     
    public:

        bool status;

        void print_all() {
            cout << "\nNumber: " << this->number << " Type: " << this->type << " Name: " << this->name << " Status:" << this->status << endl;
        }
        computer() 
        {
            this->name = "Default";
            this->number = 0;
            this->status = 0;
            std::cout << "\nComputer has been created" << std::endl;
        }

        computer(string p_name, string p_type, int p_number) {
            this->name = p_name;
            this->type = "Computer";
            this->number = p_number;
            this->status = 0;
            std::cout << "\nComputer has been created" << std::endl;
        }

        void viev_status() {
            bool a;
            a = this->status;
            if (a == 0) {
                cout << "Computer is off" << endl;
            }
            else
                cout << "Computer if on" << endl;
        }


    };

    

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Hello World!\n";
    string name, type;
    int number;
    vector <inventarization> garbage;

    person bvahaha;

    name = "Хехе";
    type = "Mouse";
    number = 2341;

    mouse object1(name, type, number);

    object1.print_all();

    name = "Очередное";
    number = 2512;

    inventarization object2(name, type, number);

    name = "Чисто для разнообразия";
    type = "Не мышь";
    number = 1256;

    inventarization object3(name, type, number);

    garbage.push_back(object1);
    garbage.push_back(object2);
    garbage.push_back(object3);

 
        bvahaha.check(garbage);
 

    /*for (int i = 0; i < garbage.size(); i++)
    {
        garbage[i].print_all();
} */


}
