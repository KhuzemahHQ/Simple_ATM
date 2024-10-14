#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;

void mainMenu(double &balance); // function prototype so it can be called in later functions even before defining

bool login()
{
    int user_ID, pin;
    cout<<endl<<"\t\tWelcome! Please enter your User ID and pin to login to your account."<<endl;
    cout<<" User ID: ";
    cin>>user_ID;
    cout<<" Pin: ";
    cin>>pin;
    int tries=0;
    int set_ID=12;
    int set_pin[3]={1234, 4321, 1111};
    string set_security_question_answer="Sam";
    bool correct_pin = false;

    for(int i = 0; i < 3; i++)  // checks array of pins for user entered pin
        {
        if(set_pin[i] == pin)
            {
                correct_pin=true;
            }
        }

    do
    {
        tries++;
        if (user_ID==set_ID && correct_pin==true)
        {
            cout<<"\t\t\t\t\tLogin successful!"<<endl<<endl;
            return true;
            break;
        }

        if (tries==2)
        {
            cout<<"\t\t\t\tYour ID or pin is incorrect."<<endl<<endl<<" Please answer the following security question to proceed: "<<endl<<endl;
            cout<<" What is the name of your childhood best friend?"<<endl;
            string security_question_answer;
            cin>>security_question_answer;
            if(security_question_answer==set_security_question_answer)
            {
                cout<<endl<<"\t\t\t\t\tLogin successful!"<<endl<<endl;
                return true;
                break;
            }
            else
            {
                cout<<"\t\t\tYou have answered the security question incorrectly"<<endl<<"\t\t\t\tPlease re-enter your ID and pin."<<endl;
                cout<<endl<<"\t\t\t\t   WARNING: LAST ATTEMPT!"<<endl;
                cout<<" User ID: ";
                cin>>user_ID;
                cout<<" Pin: ";
                cin>>pin;

                for(int i = 0; i < 3; i++)
                {
                    if(set_pin[i] == pin)
                        {
                            correct_pin=true;
                        }
                }

                if (user_ID==set_ID && correct_pin==true)
                {
                    cout<<"\t\t\t\t\tLogin successful!"<<endl<<endl;
                    return true;
                    break;
                }
                else
                {
                    cout<<endl<<" You have entered the wrong ID or pin twice. The program will now shut down.";
                    return false;
                }
            }
            break;
        }

    }while(true);
}

double randomNumberGenerator () //This function randomizes a balance for the user between $100,000 and $500,000
{
    srand(time(0));
    int UPPER_BOUND = 500000, LOWER_BOUND = 100000;
    double random_number = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
    return random_number;
}

double withdrawFunction (double &balance, double withdrawal_amount) //This function subtracts the amount withdrawn from the balance
{
    if (withdrawal_amount > balance)
    {
        cout<<" You do not have enough balance for this transaction."<<endl;
        return balance;
    }

    balance = balance - withdrawal_amount;
    return balance;
}
double depositFunction (double &balance, double deposit_amount) //This function adds the amount deposited to the balance
{
    balance = balance + deposit_amount;
    return balance;
}
void mobileMenu(double &balance) // menu for paying mobile bills
{
    string mobile_number;
    cout<<endl<<" Please enter your 11-digit mobile number: "<<endl;
    cin>>mobile_number;
    if(mobile_number.length() != 11 )
    {
        cout<<" Error: Invalid number. Please try again."<<endl;
        mainMenu(balance);
    }
    string first_two_digits = mobile_number.substr(0,2);
    if (first_two_digits != "03")
    {
        cout<< "Error: The entered number is invalid in Pakistan. Please try again."<<endl;
        mainMenu(balance);
    }

    char mobile_company;

    cout<<endl<<" Please select the Mobile Company:"<<endl;
    cout<<" Enter 'j' for Jazz."<< endl;
    cout<<" Enter 'z' for Zong."<< endl;
    cout<<" Enter 'u' for Ufone."<< endl;
    cout<<" Enter 'b' to go back to main menu."<< endl;

    cin >> mobile_company;

    switch (mobile_company)
    {
        case 'j':
            balance = withdrawFunction(balance,25);
            cout<<endl<<" Your Jazz mobile bill of $25 has been paid, please collect your receipt."<<endl<<endl;
            break;

        case 'z':
            balance = withdrawFunction(balance,20);
            cout<<endl<<" Your Zong mobile bill of $20 has been paid, please collect your receipt."<<endl<<endl;
            break;

        case 'u':
              balance = withdrawFunction(balance,28);
            cout<<endl<<" Your Ufone mobile bill of $28 has been paid, please collect your receipt."<<endl<<endl;
            break;

        case 'b':
            mainMenu(balance);
            break;

        default:
            cout<<endl<<" Please enter a valid option.";
            break;
        }
}
void billsMenu(double &balance) //Menu for paying bills
{
    char bill_option;

    cout<<endl<<" Enter 'm' to pay mobile phone bills."<< endl;
    cout<<" Enter 'g' to pay gas bills."<< endl;
    cout<<" Enter 'e' to pay electricity bills."<< endl;
    cout<<" Enter 'b' to go back to main menu."<< endl;

    cin>>bill_option;

    switch(bill_option)
    {
    case 'm':
        mobileMenu(balance);
        break;

    case 'g':
        balance = withdrawFunction(balance,500);
        cout<<" Your gas bill of $500 has been paid."<<endl;
        break;
    case 'e':
        balance = withdrawFunction(balance,700);
        cout<<" Your electricity bill of $700 has been paid."<<endl;
        break;
    case 'b':
        mainMenu(balance);
        break;
    default:
        cout<<" Please enter a valid option"<<endl;
        break;
    }

}

void mainMenu(double &balance) //Main Menu for user after logging in
{
    char purpose;

    cout<<" Enter 'w' to Withdraw amount from balance."<<endl;
    cout<<" Enter 'd' to Deposit amount."<<endl;
    cout<<" Enter 'c' to Check your Balance."<<endl;
    cout<<" Enter 'p' to Pay any bills."<<endl;
    cout<<" Enter 'e' to Exit the program."<<endl;
    cin>>purpose;

    switch(purpose)
    {
    case 'w':
        double withdrawal_amount;
        cout<<endl<<" Enter amount you want to withdraw."<<endl;
        cin>>withdrawal_amount;
        balance = withdrawFunction(balance,withdrawal_amount);
        cout<<"\t\t\t\t Your balance is now: $"<<balance<<endl<<endl;
        break;
    case 'd':
        double deposit_amount;
        cout<<" Enter amount you want to deposit."<<endl;
        cin>>deposit_amount;
        balance = depositFunction(balance,deposit_amount);
        cout<<"\t\t\t\t Your balance is now: $"<<balance<<endl<<endl;
        break;
    case 'c':
        cout<<"\t\t\t\tYour balance is currently: $"<<balance<<endl<<endl;
        break;
    case 'p':
        billsMenu(balance);
        break;
    case 'e':
        exit(0);
        break;
    default:
        cout<<endl<<" Please enter a valid option."<<endl;
        break;

    }
}
 int main()
    {
        double balance;
        balance = randomNumberGenerator();

        if (login() == true) //carries out login function as well as sees if its true
        {
            while (1)
            {
                mainMenu(balance); // continues operating main menu function until user exits by choice
            }
        }

        else
        {
            cout<<" Restart the system to continue."<<endl;
        }


        return 0;
    }
