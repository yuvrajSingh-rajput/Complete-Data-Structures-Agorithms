#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
using namespace std;

class Player{
    protected:
    int computer;
    int player;
    public:
    Player(int c,int p):computer(c),player(p){}
    string option_choosen_by_computer(int computer){
        if(computer==1){
            return "rock";
        }else if(computer==2){
            return "paper";
        }else{
            return "scissor";
        }
    }
    string option_choosen_by_player(int player){
        if(player==1){
            return "rock";
        }else if(player==2){
            return "paper";
        }else{
            return "scissor";
        }
    }
};
class Rock_Paper_Scissor{
    string 
};
int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int comp = 1 + (rand()%3);
    int player_1;
    cout<<"Choose any number between [1,3]: ";
    cin>>player_1;
    if(player_1<1 || player_1>3){
        cout<<"Wrong input!"<<endl;
        return 1;
    }
    return 0;
}