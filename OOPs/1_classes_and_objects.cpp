#include<iostream>
using namespace std;

class Hero{
    // Access modifiers are of three types : 1. public: , 2. private: , 3. protected:;
    public:
    int health;
    char level;

    void emptyClass(){
        cout<<"Empty class has memory of 1 byte"<<endl;
    }
};
int main(){
    //object_____>
    Hero h1;
    h1.health = 70;
    h1.level = 'Y';
    cout<<"Health of h1 is: "<<h1.health<<endl;
    cout<<"Level of H1 is: "<<h1.level<<endl;
    cout<<"Size of class Hero is: "<<sizeof(Hero)<<endl;
    return 0;
}
