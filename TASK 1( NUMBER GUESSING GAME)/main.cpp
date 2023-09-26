#include<bits/stdc++.h>
using namespace std;
int main() {
    int userNumber,counter=0;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomNumber = (std::rand() % 100) + 1;
    while (true){
        cout <<  "enter your number to check : \n";
        cin >> userNumber;
        counter++;
        if (userNumber>randomNumber){
            cout<<"your number is bigger\ntry again :)\n";
        }
        else if (userNumber<randomNumber){
            cout<<"your number is smaller\ntry again :)\n";
        }
        else if (userNumber==randomNumber){
            cout<<"bravoo \nit is the number :)\nyour number of tries = " << counter<<"\n";
            return 0;
        }
    }
}
