// Header file
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

//  class for game
class casion{
    string user_name;
    int acc_bal;
    public:
    casion(string str){
        user_name=str;
        acc_bal=0;
    }
    void balance();//UPDATE BALANCE
    void balance_check();//DISPLAY BALANCE
    void account();// USER ACCOUNT
    void gen_code();//GENERATE COUPON CODE
    void red_code();//REDEEM CODE 
    void delete_code(int value,string code);//DELETE CODE AFTER USE
    void coupon_code();// SHOW ALL GENERATED CODE 
    void casino();// MAIN GAME
    friend void registration();//FRIEND FUNCTION FOR HELP IN TO CREATE USER ACCOUNT
    friend void login();// FRIEND FUNCTION 
    ~casion(){}

};

    // function 
    void login();//LOGIN FUNCTION
    void registration();// USER REGISTRATION FUNCTION 
    void forgot();// USER PASSWORD RECOVER FUNCTION 
    // main function
int main(){ 
system("color F5");

cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t   welcome to  casino"<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"press 1) LOGIN"<<endl;
cout<<"press 2) REGISTRATION "<<endl;
cout<<"press 3) FORGOT PASSWORD "<<endl;
cout<<"press 4) exit "<<endl;
char op;
cout<<"Enter you option : ";
cin>>op;
switch (op)
{

case '1':
    login();
    break;
case '2':
    registration();
    break;
case '3':
    forgot();
    break;

case '4':
    exit;
    break;

default:
cout<<"invalid input"<<endl;
main();
    break;
}
return 0;
 }



// function stact
 void login(){
    system("CLS");
    string user_name,password,us,pass;
    int counter=0;
    cout<<"user name :";
    cin>>user_name;
    cout<<"password :";
    cin>>password;
    ifstream reg("database.txt");
    while (reg>>us>>pass)
    {
        if(user_name==us &&  password==pass){

            counter=1;
            system("CLS");
       }
    }
    reg.close();
    if(counter==1){
        cout<<"Welcome "<<user_name <<" login successful"<<endl;
        casion obj(user_name);
        obj.balance_check();


        obj.account();
    }
    else{
    cout<<"user not found "<<endl;
    main();
    }
}


  void registration(){
    string user_name,password;
    system("CLS");
    cout<<"User name:";
    cin>>user_name;
    cout<<" Password :";
    cin>>password;
    ofstream reg("database.txt",ios::app);
    reg<<user_name<<" "<<password<<endl;
    system("CLS");
    cout<<"REGISTRATION SUCCESSFUL"<<endl;
    reg.close();
     casion obj(user_name);
     obj.acc_bal=0;
     obj.balance();
     obj.account();
    

}



void forgot(){
    system("CLS");
    string user_name,us,pass;
    int counter=0;
    cout<<"Enter your  user name : ";
    cin>>user_name;
    ifstream reg("database.txt");
    while(reg>>us>>pass){
        if(us==user_name){
                counter=1;
                system("CLS");
        }
    }
    reg.close();
    if(counter==1){
        cout<<"Account found"<<endl;
        cout<<"Your password is "<<pass<<endl;
        main();
    }
    else{
        cout<<"Account not found"<<endl;
        main();
    }

}



void casion::account(){
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t   "<<user_name<<"\t\t Account balance "<<acc_bal<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"press 1) START GAME "<<endl;
cout<<"press 2) COUPON CODE"<<endl;
cout<<"press 3) GENERATE COUPON CODE "<<endl;
cout<<"press 4) REDEEM CODE  "<<endl;
cout<<"press 5) MAIN MENU"<<endl;
cout<<"press 6) Exit "<<endl;
char op;
cout<<"Enter you option : ";
cin>>op;
switch (op)
{
case '1':
    casino();
    break;
case '2':
    coupon_code();
    break;
case '3':
    gen_code();
    break;
case '4':
    red_code();
    break;
case '5':
    system("CLS");
    main();
    break;
case '6':
    exit;
    break;

default:
cout<<"invalid input "<<endl;
system("CLS");
account();
    break;
}
}


void casion::casino(){
    system("ClS");
int lucky_number,bet_amount;
string str;
str=user_name;


balance_check();
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t   welcome "<<user_name<<"\t\t Account balance "<<acc_bal<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"Choose the number between 1 to 10"<<endl;
cout<<"1 2 3 4 5 6 7 8 9 10"<<endl;
int number;
cin>>number;
cout<<"Enter the bet amount :";
cin>>bet_amount;
if(bet_amount<=acc_bal){
    if(number>=1 && number <= 10){
        lucky_number=rand()%10+1;
        if(number==lucky_number){
            system("CLS");
            cout<<"congratulations you won the "<<bet_amount*10<<"RS"<<"  jackpot "<<endl;
            int temp,total;
            temp=acc_bal-bet_amount;
            total=temp+(bet_amount*=10);
            acc_bal=total;
            balance();
            account();
            
         
        }
        else{
            system("CLS");
            cout<<"The lucky number is "<<lucky_number<<endl;
            cout<<"better luck next time "<<endl;
           acc_bal-=bet_amount;
           balance();
           
           account();
        }

    
    }
    else{
        system("CLS");
        cout<<"not a valid input"<<endl;
        casino();
    }
}
else{
    system("CLS");
    cout<<"not a sufficient amount in your account"<<endl;
        account();
}
 }



void casion::gen_code(){
     char co;
     int code_size=12,code_value;
    string code;
    cout<<"Enter the value of code :";
    cin>>code_value;

    srand(time(0));
    while(code_size--){
        co=rand()%26+65;
        code+=co;
    }
    string str;
    str=user_name;
    str+="coupon.txt";
    ofstream CODE(str,ios::app);
    CODE<<code_value<<" "<<code<<endl;
    system("CLS");
    cout<<"Your code is : "<<code<<endl;
    CODE.close();
    account();

}




void casion::red_code(){
    string code,c_code;
    int code_value,c;
    int ac_money;
    cout<<"Enter the code : ";
    cin>>code;
    string temp,str;
    str=user_name;
    str+="coupon.txt";
    ifstream CODE(str);
   
    
    while(CODE>>code_value>>c_code){
        if(code==c_code){
            c=1;
            system("CLS");
            cout<<"coupon code accepted "<<endl;
        cout<<"coupon code redeem\t\t "<<code_value<<"cr"<<"  to your account"<<endl;
        CODE.close();

               acc_bal+=code_value;
               balance();
               delete_code(code_value,c_code);
        break;
        }
    }
    CODE.close();
    if(c==1){
        account();
    }
    else{
        system("CLS");
        cout<<"not a valid coupon code"<<endl;
        cout<<"try again "<<endl;
        account();
    }


}

void casion::balance(){
    string str;
    str=user_name;
    str+="account_bal.txt";
    ofstream fout(str);
    fout<<acc_bal;
}



void casion::balance_check(){
    string str;
    str=user_name;
    str+="account_bal.txt";
    ifstream fin(str);
    fin>>acc_bal;
}



void casion::delete_code(int value,string code){
    string str;
    str=user_name;
    str+="coupon.txt";
    ifstream fin(str);
    ofstream fout("temp.txt",ios::app);
    int c_v;
    string c_c;

while (fin>>c_v>>c_c){
    if(c_v==value && c_c==code){
        continue;
    }
    fout<<c_v<<" "<<c_c<<endl;

}
fin.close();
fout.close();
int n=str.length();
char *ch=new char[n+1];
int i=0;
while (n--)
{
    ch[i]=str[i];
    i++;
}
ch[i]='\0';
remove(ch);
rename("temp.txt",ch);

delete [] ch;
}

void casion::coupon_code(){
    system("CLS");
    string str;
    str=user_name;
    str+="coupon.txt";
    ifstream fin(str);
    int value;
    string code;
    cout<<"code"<<"\t\t"<<"amount"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    while (fin>>value>>code)
    {
        cout<<code<<"\t"<<value<<endl;
    }
    fin.close();
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"press 1) back"<<endl;
    cout<<"press 2) redeem code"<<endl;
    char op;
    cin>>op;
        switch (op)
        {
        case '1':
            system("CLS");
            account();
            break;
            
        case '2':
            red_code();
            break;

        
        default:
        system("CLS");
        cout<<"invalid input"<<endl;
        coupon_code();
            break;
        }  
}