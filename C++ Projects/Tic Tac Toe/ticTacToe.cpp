#include<bits/stdc++.h>
using namespace std;

char square[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board(){
    cout<<"\n===============================";
    cout<<"\n\tTic Tac Toe";
    cout<<"\n===============================\n\n";
    cout<<"Player 1 (X) - Player 2 (O)"<<endl;
    cout<<"___________________________"<<"\n\n";
    cout<<"     |     |     "<<endl;
    cout<<"  "<< square[0] <<"  |  "<< square[1]<< "  |  "<< square[2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<< square[3] <<"  |  "<< square[4]<<"  |  " << square[5]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[6] <<"  |  "<<square[7]<<"  |  "<<square[8]<<endl;
    cout<<"     |     |     "<<endl<<endl;
}

int main(){
    cout<<"Press a key for the toss: ";
    cin.get();
    std::srand(std:: time(0));
    int lower_limit = 1, upper_limit = 2;
    int random_number = lower_limit + std::rand() % (upper_limit - lower_limit + 1);
    int player = 1, i, choice;
    char mark;
    do{
        board();
        if(player % 2 == 1){
            player = 1;
        }else{
            player = 2;
        }
        cout<<"Player "<<player<<" Enter a number: ";
        cin>>choice;
        if(player == 1){
            mark = 'X';
        }else{
            mark = 'O';
        }
        if(choice == 1 && square[0] == '1'){
            square[0] = mark;
        }else if(choice == 2 && square[1] == '2'){
            square[1] = mark;
        }else if(choice == 3 && square[2] == '3'){
            square[2] = mark;
        }else if(choice == 4 && square[3] == '4'){
            square[3] = mark;
        }else if(choice == 5 && square[4] == '5'){
            square[4] = mark;
        }else if(choice == 6 && square[5] == '6'){
            square[5] = mark;
        }else if(choice == 7 && square[6] == '7'){
            square[6] = mark;
        }else if(choice == 8 && square[7] == '8'){
            square[7] = mark;
        }else if(choice == 9 && square[8] == '9'){
            square[8] = mark;
        }else{
            cout<<"Invalid move, Try Again"<<endl;
        }
    }while(1);
    
    return 0;
}