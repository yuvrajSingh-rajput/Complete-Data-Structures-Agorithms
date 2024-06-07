#include<iostream>
using namespace std;

void HelloWorld(void){
    cout<<"Hello World!";
}

int main(){
    //! Method 1-->
    auto function1 = HelloWorld;
    //* Here it works like as function pointer whichm can also be written as [function = &HelloWorld];
    function1();

    //! Method 2-->
    void(*function2)(void);
    //* Or it can be written as [void(*function3)() = Helloworld;]
    function2();

    //! Method 3-->
    typedef void(*HelloWorldFUnction)(void);
    HelloWorldFUnction function3 = HelloWorld;
    function3();

    return 0;
}