#include<bits/stdc++.h>
using namespace std;

class compfractional{
    private:
    int numerator, denomenator;
    public:
    compfractional(){}
    compfractional(int numerator, int denomenator){
        this->numerator = numerator;
        this->denomenator = denomenator;
    }

    friend bool check_if_zero(compfractional& fraction);

    bool operator==(compfractional& fraction){
        this->numerator = this->numerator / __gcd(this->numerator,this->denomenator);
        this->denomenator = this->denomenator / __gcd(this->numerator, this->denomenator);
        fraction.numerator = fraction.numerator / __gcd(fraction.numerator, fraction.denomenator);
        fraction.denomenator = fraction.denomenator / __gcd(fraction.numerator,fraction.denomenator);
        if(this->numerator == fraction.numerator && this->denomenator == fraction.denomenator){
            return true;
        }else{
            return false;
        }
    }

    bool operator!=(compfractional& fraction){
        this->numerator = this->numerator / __gcd(this->numerator,this->denomenator);
        this->denomenator = this->denomenator / __gcd(this->numerator, this->denomenator);
        fraction.numerator = fraction.numerator / __gcd(fraction.numerator, fraction.denomenator);
        fraction.denomenator = fraction.denomenator / __gcd(fraction.numerator,fraction.denomenator);
        if(this->numerator == fraction.numerator && this->numerator == fraction.denomenator){
            return false;
        }else{
            return true;
        }
    }

    bool operator>=(compfractional& fraction){
        this->numerator = this->numerator / __gcd(this->numerator,this->denomenator);
        this->denomenator = this->denomenator / __gcd(this->numerator, this->denomenator);
        fraction.numerator = fraction.numerator / __gcd(fraction.numerator, fraction.denomenator);
        fraction.denomenator = fraction.denomenator / __gcd(fraction.numerator,fraction.denomenator);
        if(((double)this->numerator/this->denomenator)<((double)fraction.numerator/fraction.denomenator)){
            return false;
        }else{
            return true;
        }
    }

    bool operator<=(compfractional& fraction){
        this->numerator = this->numerator / __gcd(this->numerator,this->denomenator);
        this->denomenator = this->denomenator / __gcd(this->numerator, this->denomenator);
        fraction.numerator = fraction.numerator / __gcd(fraction.numerator, fraction.denomenator);
        fraction.denomenator = fraction.denomenator / __gcd(fraction.numerator,fraction.denomenator);
        if(((double)this->numerator/this->denomenator) > ((double)fraction.numerator/fraction.denomenator)){
            return false;
        }else{
            return true;
        }
    }
};

bool check_if_zero(compfractional& fraction){
    if(fraction.denomenator == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    compfractional fraction1(2,3), fraction2(4,5);
    if(check_if_zero(fraction1) && check_if_zero(fraction2)){
        cout<<"They can't be compared!"<<endl;
        return 1;
    }else{
        if(fraction1 == fraction2){
            cout<<"They are equal!"<<endl;
        }
        if(fraction1 != fraction2){
            cout<<"They are equal!"<<endl;
        }
        if(fraction1>=fraction2){
            cout<<"fractional number 1 is greater than fractional number 2!"<<endl;
        }
        if(fraction1<=fraction2){
            cout<<"fractional number 2 is greater than fractional number 1!"<<endl;
        }
    }
    return 0;
}