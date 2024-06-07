#include<iostream>
using namespace std;

class B; // Forward declaration

class A{
private:
    int x;
public:
    void setData(int n1){
        x = n1;
    }
    friend void compareAandB(A&, B&);; // Friend declaration
};

class B{
private:
    int y;
public:
    void setData(int n2){
        y = n2;
    }
    friend void compareAandB(A &, B &);; // Friend declaration
};

// Standalone function definition
void compareAandB(A &a, B &b){
    if(a.x > b.y){
        cout << a.x << endl;
    }
    else{
        cout << b.y << endl;
    }
}

int main(){
    A object_a;
    B object_b;
    object_a.setData(10);
    object_b.setData(17);
    compareAandB(object_a, object_b);
    return 0;
}
