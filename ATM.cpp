#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

/*  MINI Project - ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Update Mobile No.
*/

class atm                                  // class atm
{
    private:
        long int account_no;
        string name;
        int PIN;
        double balance;
        string mobile_no;

    public:
        void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_no_a){
            account_no = account_No_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }

        // Returning user's account no.
        long int getAccountNo(){
            return account_no;
        }

        // Returning user's name
        string getName(){
            return name;
        }

        // Returning user's PIN
        int getPIN(){
            return PIN;
        }

        // Returning user's Bank Balance
        double getBalance(){
            return balance;
        }

        // Returning user's mobile no.
        string getMobileNo(){
            return mobile_no;
        }



        // Updating the user mobile no.
        void setMobile(string mob_prev, string mob_new){
            if(mob_prev == mobile_no){
                mobile_no = mob_new;
                cout<<"\nSucessfully Updated Mobile No."<<endl;
                getch();
            }
            else{
                cout<<"\nIncorrect !!! Old Mobile No. "<<endl;
                getch();
            }
        } 

        // Used to Withdraw Money from ATM
        void cashWithDraw(int amount_a){
            if(amount_a > 0 && amount_a <= balance){
                balance -= double(amount_a);
                cout<<"\nPlease Collect Your Cash"<<endl;
                cout<<"Available Balance : "<<balance<<endl;
                getch();
            }
            else{
                cout<<"Invalid Input or Insufficient Balance";
                getch();
            }
        }

};



int main(){
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");

    // Creating User
    atm user1;
    user1.setData(123456,"Sachin",1331,197823.58,"9893687788");

    do{
        system("cls");

        cout<<"\n*****Welcome to ATM*****"<<endl;
        cout<<"\nEnter Your Account No ";
        cin>> enterAccountNo;
        cout << "\nEnter PIN ";
        cin>>enterPIN;

        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())){
            
            do{
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                cout<<"\n*****Welcome to ATM*****"<<endl;
                cout<<"\nSelect Options : ";
                cout<<"\n1. Check Balance";
                cout<<"\n2. Cash Withdraw";
                cout<<"\n3. Show User Details";
                cout<<"\n4. Update Mobile No.";
                cout<<"\n5. Exit"<<endl;
                cin>> choice;

                switch (choice)
                {
                case 1:
                    cout<<"\nYour Bank balance is : "<<user1.getBalance();
                    getch();
                    break;
                
                case 2:
                    cout<<"\nEnter the amount :";
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout<<"\n*** User Details are :- ";
                    cout<<"\n-> Account No : "<<user1.getAccountNo();
                    cout<<"\n-> Name : "<<user1.getName();
                    cout<<"\n-> Balance : "<<user1.getBalance();
                    cout<<"\n-> Mobile No. : "<<user1.getMobileNo();

                    getch();
                    break;

                case 4:
                    cout<<"\nEnter Old Mobile no. : ";
                    cin>>oldMobileNo;
                    cout<<"\nEnter New Mobile no. : ";
                    cin>>newMobileNo;
                    user1.setMobile(oldMobileNo,newMobileNo);
                    break;
                
                case 5:
                    exit(0);


                default:
                    cout<<"\n Enter Valid Data !!";
                }


                
            }while(1);
        }
        else{
            cout<<"\nUser Does not exist !!!!"<<endl;
            getch();
        }


    }while(1);
}