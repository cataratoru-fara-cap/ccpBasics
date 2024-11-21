#include <iostream>
using namespace std;

struct date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;    
};

bool valideDate(date D){
    if(D.day > 31)
        return false;
    if(D.month > 12)
        return false;
    if(D.month == 2 && D.year % 4 != 0 && D.day > 29 )
        return false;
    if (D.month == 4 || D.month == 6 || D.month == 9 || D.month == 11 && D.day > 30 )
        return false;
    if (D.month == 1 || D.month == 3 || D.month == 5 || D.month == 7 || D.month == 8 || D.month == 10 || D.month == 12 && D.day > 31)
        return false;
    return true;
}

/* int main(){
    date D;
    cin >> D.day >> D.month >>D.year;
    if(valideDate(D) == true)
        cout<<"date valide";
    else   
        cout << "date invalide";
    return 0;
} */