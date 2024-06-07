#include<iostream>
#include<random>
using namespace std;

int randomBullets(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min,max);

    return dis(gen);
}

class Gun {
    public:
    //Data members;
    string name;
    string model;
    int maxbullet;

    //Member function;
    void PickUp(){
        cout<<"Gun has picked up\n";
        maxbullet = 0;
    }
    void loadbullets(int bullet){
        maxbullet = maxbullet + bullet;
        if (maxbullet == 30){
            cout<<"The gun is fully loaded\n";
        }
        else if(maxbullet>0 && maxbullet<30){
            cout<<"The gun is loaded and have "<<maxbullet<<" bullets\n";
        }
        else{
            cout<<"Please put the bullets in the range of 30\n";
            maxbullet = 0;
        }
    }
    void fire(){
        int random = randomBullets(1,28);
        cout<<"Bullets are fired and your enemy is dead in "<<random<<" and the remaining bullets are "<<(maxbullet - random)<<" in the gun\n";
    }
};

int main(){
    Gun gun1, gun2;

    gun1.name = "AK-47";
    gun1.model = "cv-20";
    gun1.maxbullet = 30;

    gun2.name = "Machine-Gun";
    gun2.model = "Is-20v35";
    gun2.maxbullet = 30;

    gun1.PickUp();
    gun1.loadbullets(30);
    gun1.fire();

    gun2.PickUp();
    gun2.loadbullets(30);
    gun2.fire();

    return 0;
}