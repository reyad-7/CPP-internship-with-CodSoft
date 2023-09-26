#include<bits/stdc++.h>
using namespace std;
int main() {
    int num1 , num2 ;
    char operation;
    char choice='Y';
    cout << "enter First number: \n";
    cin>>num1;
    cout << "enter Second number: \n";
    cin>>num2;
    while (tolower(choice)=='y'){
        cout << "enter your operator: \n";
        cin>>operation;
        if (operation=='-'){
            cout <<num1 <<" - "<<num2<<" = "<< num1-num2<<"\n";
        }
        else if (operation=='+'){
            cout << num1 <<" + "<<num2<<" = "<<num1+num2<<"\n";
        }
        else  if (operation=='*'){
            cout <<num1 <<" * "<<num2<<" = "<< num1*num2<<"\n";
        }
        else if (operation=='/'){
            if (num2 != 0) {
                cout << num1 <<" / "<<num2<<" = "<<num1/num2<<"\n";
            } else {
                cout << "Error: Division by zero" << endl;
            }
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    }


}
