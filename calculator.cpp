#include <iostream>

using namespace std;

int add(int num1, int num2){
return num1+num2;
}

int subtract(int num1, int num2){
return num1-num2;
}

int multiply(int num1, int num2){
return num1*num2;
}

int divide(int num1, int num2){
return num1/num2;
}

int remainder(int num1, int num2){
return num1%num2;
}


int main()
{   bool flag=false;
    int userInput=0;
    int num1, num2;
    cout<<"Welcome to a simple menu based calculator"<<endl;
    while(!flag){
        cout<<"Press the desired number"<<endl;
        cout<<"1.Addition"<<endl;
        cout<<"2.Subtraction"<<endl;
        cout<<"3.Multiply"<<endl;
        cout<<"4.Divide"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>userInput;
        switch(userInput){
            case 1:
                cout<<"We are doing number1+number2 so please start by inputing number1 and then number2 : "<<endl;
                cin>>num1;
                cin>>num2;
                cout<<add(num1, num2)<<endl;
                break;

            case 2:
                cout<<"We are doing number1-number2 so please start by inputing number1 and then number2 : "<<endl;
                cin>>num1;
                cin>>num2;
                cout<<subtract(num1, num2)<<endl;
                break;

            case 3:
                cout<<"We are doing number1*number2 so please start by inputing number1 and then number2 : "<<endl;
                cin>>num1;
                cin>>num2;
                cout<<multiply(num1, num2)<<endl;
                break;

            case 4:
                cout<<"We are doing number1/number2 so please start by inputing number1 and then number2 : "<<endl;
                cin>>num1;
                cin>>num2;
                cout<<divide(num1, num2)<<" and the remainder is "<<remainder(num1, num2)<<endl;
                break;

            case 5:
                flag=true;
                cout<<"Thank you for trying out the program, hope u had fun :)"<<endl;
                cout<<"The Program will now terminate........."<<endl;
                break;

        default: cout<<"invalid input please try again"<<endl;
        break;
        }
    }
    return 0;
}
