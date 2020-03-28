//Please run!
//Please run!
//Please run!
#include <iostream>
using namespace std;

// admin panel function
void admin_panel()
{
    cout << "\t\t\t\tWelcome to admin panel" << endl << endl;
    cout << "\t\t\t\t\t1. Add Tickets" << endl;
    cout << "\t\t\t\t\t2. Remove Tickets" << endl;
    cout << "\t\t\t\t\t3. Total sells" << endl;
    cout << "\t\t\t\t\t4. Logout" << endl;
}

// user panel function
void user_panel()
{
    cout << "\t\t\t\tWelcome to user panel" << endl << endl;
    cout << "\t\t\t\t\t1. Buy a Ticket" << endl;
    cout << "\t\t\t\t\t2. My Tickets" << endl;
    cout << "\t\t\t\t\t3. My Profile" << endl;
    cout << "\t\t\t\t\t4. Logout" << endl;
}

//Create account page function
void create_account()
{
    // info variable
    string name, phone, email, password;

    cout << "\t\t\t\tCreate new account" << endl << endl;
    cout << "\t\t\t\tEnter your information:" << endl;
    cout << "\t\t\t\tEnter your name:";
    cin >> name;
    cout << "\t\t\t\tEnter your phone number:";
    cin >> phone;
    cout << "\t\t\t\tEnter your email address:";
    cin >> email;
    cout << "\t\t\t\tEnter your password:";
    cin >> password;
}
// Admin login function
void admin_access()
{
    string email, password;
    cout << "\t\t\t\tEnter your email:";
    cin >> email;
    cout << "\t\t\t\tEnter your password:";
    cin >> password;
    // check admin information is it valid admin or not

    admin_panel();
}
// User login function
void user_access()
{
    string email, password;
    cout << "\t\t\t\tEnter your email:";
    cin >> email;
    cout << "\t\t\t\tEnter your password:";
    cin >> password;
    // check user's information is it valid user or not

    user_panel();
}
// Create home page function
void home()
{
    cout << "\t\t\t\tWelcome to the biggest online ticket's platform" << endl << endl;
    cout << "\t\t\t\t\t1. Admin panel" << endl;
    cout << "\t\t\t\t\t2. User panel" << endl;
    cout << "\t\t\t\t\t3. Create New Account" << endl;

    // condition
    int select;
    cout << "\t\t\t\t\tSelect:";
    cin >> select;
    if(select == 1)
    {
        admin_access();
    }
    else if(select == 2)
    {
        user_access();
    }
    else if(select == 3)
    {
        create_account();
    }
    else
    {
        cout << "\t\t\t\t\tInvalid input! Please try again" << endl;
        home();
    }
}


int main()
{
    //Home page
    home();

    return 0;
}
