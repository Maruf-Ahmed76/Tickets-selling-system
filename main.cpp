// Admin panel email and password:
// Email : admin@gmail.com
// Password : admin

// 3 users email and password:
// Maruf
// Email : maruf@gmail.com
// Password : 12345
// Juairea
// Email : juairea@gmail.com
// Password : 12345
// Emon
// Email : emon@gmail.com
// Password : 12345


// Please run
// Please run
// Please run

#include <iostream>
#include <vector>
using namespace std;

// New user creation class
int user_id = 0;
class new_users
{
private:
    // private data
    string name, phone, email, password;
public:
    int id;
    new_users(string n, string p, string e, string pass)
    {
        id = user_id;
        name = n;
        phone = p;
        email = e;
        password = pass;
    }
    // access private information
    string get_user_info(string what)
    {
        if(what == "name")
            return name;
        else if(what == "phone")
            return phone;
        else if(what == "email")
            return email;
        else if(what == "password")
            return password;
        else
            return "Error access!";
    }

};

vector <new_users> users;



// New bus creation class
class new_bus
{
public:
    int sit[32];
    string bus_number, driver_name, arrival_time, from, to;
    new_bus(string bus_no, string driver, string arriv, string f, string t)
    {
        bus_number = bus_no;
        driver_name = driver;
        arrival_time = arriv;
        from = f;
        to = t;
    }
};

vector <new_bus> bus_store;



// Reserve tickets
class ticket_reservation{
public:
    int user_id,sit_number;
    string bus_number;
    // set all the information
    ticket_reservation(int id, string bus_num, int sit_num){
        user_id = id;
        bus_number = bus_num;
        sit_number = sit_num;
    }
};

vector <ticket_reservation> tickets_store;


// authentication class
class Auth
{
private:
    // user's information
    string userEmail, userPassword;
    string adminEmail = "admin@gmail.com", adminPassword = "admin";
public:
    // check user info is valid or not
    int authentication(string email, string pass, int role)
    {
        // check the user is normal user or admin
        if(role == 1)
        {
            // checking admin info
            if(adminEmail == email && adminPassword == pass)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(role == 0)
        {
            // checking user info
            for (int i = 0; i < users.size(); i++)
            {
                if(email == users[i].get_user_info("email") && pass == users[i].get_user_info("password"))
                {
                    return 1;
                    break;
                }
            }
            return 0;
        }

    }

    // returning the user id
    int user_id(string email){
        for (int i = 0; i < users.size(); i++)
        {
            if(email == users[i].get_user_info("email"))
            {
                return users[i].id;
                break;
            }
        }
    }
};
// user auth class
class user_login:public Auth
{
private:
    string email,password;
public:
    // constructor
    user_login(string e, string pass)
    {
        email = e;
        password = pass;
    }
    // user authentication
    int user_auth()
    {
        return authentication(email, password, 0);
    }
    // returning the user id
    int user_id(){
        return Auth::user_id(email);
    }
};

// admin auth class
class admin_login:public Auth
{
private:
    string email,password;
public:
    admin_login(string e, string pass)
    {
        email = e;
        password = pass;
    }
    // admin authentication
    int admin_auth()
    {
        return authentication(email, password, 1);
    }
};



//Bus management's component's
    // add bus
void add_bus();
    //remove bus from the bus_store
void remove_bus();
    // bus list
void bus_list();
    // available sit
void available_sit();
    // reserve ticket
void reserve_ticket(int users_id);



// Common option
    // Go back function
int go_back();
    // Line draw
void line(string type, int length);
    // Find the bus_index from the bus_store
int bus_index(string bus_num);
    // Find the user index
int user_index(int users_id);
    // payment method
void payment_method();

// admin panel component
void admin_panel();
void admin_available_bus_list();
void admin_available_sit();



// user component
void user_panel(int user_id = -1);
void user_available_bus_list(int users_id);
void my_tickets(int users_id);
void profile(int users_id);
void user_available_sit(int users_id);



//Create account page component
void create_account();




// Login component's
    // Admin login component
void admin_access(string err_msg = " ");
    // User login component
void user_access(string err_msg = " ");




// Create home page component
void home()
{
    system("cls");
    cout << "\t\t\t\tWelcome to the biggest online ticket's platform" << endl << endl;
    cout << "\t\t\t\t\t1. Admin panel" << endl;
    cout << "\t\t\t\t\t2. User panel" << endl;
    cout << "\t\t\t\t\t3. Create New Account" << endl;
    cout << "\t\t\t\t\t4. exit" << endl;

    // condition
    int select;
    cout << "\t\t\t\t\tSelect: ";
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
    else if(select == 4){
        system("cls");
        exit(0);
    }
    else
    {
        cout << "\t\t\t\t\tInvalid input! Please try again" << endl;
        home();
    }
}





// Initialize users
void initialize_users()
{
    // 1st user
    new_users new_user_1("Maruf","01789393745","maruf@gmail.com","12345");
    users.push_back(new_user_1);
    user_id++;
    // 2nd user
    new_users new_user_2("Juairea","015010101010","juairea@gmail.com","12345");
    users.push_back(new_user_2);
    user_id++;
    // 3rd user
    new_users new_user_3("Emon","017010101010","emon@gmail.com","12345");
    users.push_back(new_user_3);
    user_id++;
}

// Initialize users
void initialize_bus()
{
    // 1st bus
    new_bus new_bus_1("01","Sajol","08:00","Dhaka","Bogura");
    for(int i = 0; i < 32; i++){
        new_bus_1.sit[i] = 0;
    }
    bus_store.push_back(new_bus_1);
    // 2nd bus
    new_bus new_bus_2("02","Fahim","08:30","Dhaka","Barishal");
    for(int i = 0; i < 32; i++){
        new_bus_2.sit[i] = 0;
    }
    bus_store.push_back(new_bus_2);
    // 3rd bus
    new_bus new_bus_3("03","Adif","09:00","Dhaka","Joypurhat");
    for(int i = 0; i < 32; i++){
        new_bus_3.sit[i] = 0;
    }
    bus_store.push_back(new_bus_3);
}



int c = 0;
// Main component
int main()
{
    if(c == 0){
        initialize_users();
        initialize_bus();
        c++;
    }
    // Home component
    home();
    return 0;
}




// Login component's
void admin_access(string err_msg)
{
    system("cls");
    string email, password;
    // Check the login error message
    if(err_msg == " ")
        cout << "\n\t\t\t\tLogin to your account" << endl << endl;
    else
        cout << "\n\t\t\t\t" << err_msg << endl << endl;
    // Take admin authentication information
    cout << "\t\t\t\tEnter your email:";
    cin >> email;
    cout << "\t\t\t\tEnter your password:";
    cin >> password;

    // check admin authentication validity
    admin_login obj(email,password);

    if(obj.admin_auth() == 0)
    {
        admin_access("Something is wrong! Please try again");
    }
    else
    {
        admin_panel();
    }
}
void user_access(string err_msg)
{
    system("cls");
    string email, password;
    // Check the login error message
    if(err_msg == " ")
        cout << "\n\t\t\t\tLogin to your account" << endl << endl;
    else
        cout << "\n\t\t\t\t" << err_msg << endl << endl;
    // Take user authentication information
    cout << "\t\t\t\tEnter your email:";
    cin >> email;
    cout << "\t\t\t\tEnter your password:";
    cin >> password;
    // check user's authentication validity
    user_login obj(email,password);

    if(obj.user_auth() == 0)
    {
        user_access("Something is wrong! Please try again");
    }
    else
    {
        int users_id = obj.user_id();
        user_panel(users_id);
    }
}





    // Create account component
void create_account()
{
    system("cls");
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
    // Store user information
    new_users new_user_obj(name, phone, email, password);
    // Push new user to the vector space
    users.push_back(new_user_obj);
    user_id++;
    // back to the main menu
    home();

}





//User component
void user_panel(int users_id)
{
    system("cls");
    // variables
    int select;
    // Print users name
    if(users_id >= 0){
        int login_user_index = user_index(users_id);
        // store the user name
        string user_name = users[login_user_index].get_user_info("name");
        cout << "\t\t\t\tHi " << user_name << endl;
    }

    cout << "\t\t\t\tWelcome to user panel" << endl << endl;
    cout << "\t\t\t\t\t1. Available Bus" << endl; // done
    cout << "\t\t\t\t\t2. Available sit" << endl; // done
    cout << "\t\t\t\t\t3. Reserve a sit" << endl; // Done
    cout << "\t\t\t\t\t4. My Tickets" << endl; // done
    cout << "\t\t\t\t\t5. My Profile" << endl;
    cout << "\t\t\t\t\t6. Logout" << endl;
    // take input
    cout << "\n\t\t\t\t\tSelect: ";
    cin >> select;
    if(select == 1)
        user_available_bus_list(users_id);
    else if(select == 2)
        user_available_sit(users_id);
    else if(select == 3)
        reserve_ticket(users_id);
    else if(select == 4)
        my_tickets(users_id);
    else if(select == 5)
        profile(users_id);
    else if(select == 6)
        main();
    else
        user_panel(users_id);
}

// Buy tickets component
void reserve_ticket(int users_id){
    system("cls");
    int sit_number;
    string bus_number;
    cout << "\t\t\t\tInput all the information: " << endl << endl;;
    cout << "\t\t\t\tNote: All of our bus have 32 sit"<< endl << endl;
    cout << "\t\t\t\tBus number: ";
    cin >> bus_number;
    cout << "\t\t\t\tSit number: ";
    cin >> sit_number;
    // Payment (Not really working)
    payment_method();
    // create a object of ticket_reservation class
    ticket_reservation booking_ticket(users_id, bus_number, sit_number);
    // store the tickets info to the store
    tickets_store.push_back(booking_ticket);

    // Update the bus sit status
    int bus_position = bus_index(bus_number);
    bus_store[bus_position].sit[sit_number-1] = 1;
    // Go back
    system("cls");
    cout << "\t\t\t\tYour are done" << endl;
    int Back = go_back();
    if(Back)
        user_panel(users_id);

}
// list of available bus
void user_available_bus_list(int users_id){
    bus_list();
    // Go back
    int Back = go_back();
    if(Back != 0){
        user_panel(users_id);
    }else{
        user_available_bus_list(users_id);
    }
}
// user ticket's list
void my_tickets(int users_id){
    system("cls");
    cout << "\t\t\t\tYour ticket's: "<< endl << endl;
    //variable's
    int i,t = 1;

    for(i = 0; i < tickets_store.size(); i++){
        if(tickets_store[i].user_id == users_id){
            t = 0;
            cout << "\t\t\t\t";
            line("*",50);
            cout << "\t\t\t\tBus NO: " << tickets_store[i].bus_number << endl;
            cout << "\t\t\t\tSit NO: " << tickets_store[i].sit_number << endl;
            //getting info from the bus store
            string bus_number = tickets_store[i].bus_number;
            int bus_position = bus_index(bus_number);

            cout << "\t\t\t\tDriver name: " << bus_store[bus_position].driver_name << endl;
            cout << "\t\t\t\tArrival time: " << bus_store[bus_position].arrival_time << endl;
            cout << "\t\t\t\tFrom: " << bus_store[bus_position].from << endl;
            cout << "\t\t\t\tTo: " << bus_store[bus_position].to << endl;
        }
     }
    if(t){
        cout << "\t\t\t\tYou don't have any ticket"<< endl;
    }
     // Go back
    int Back = go_back();
    if(Back != 0){
        user_panel(users_id);
    }else{
        my_tickets(users_id);
    }
}
void profile(int users_id){
    system("cls");
    // variable's
    int user_position = user_index(users_id);

    cout << "\t\t\t\t\tYour profile" << endl;
    cout << "\t\t\t\t";
    line("*",25);
    cout << "\t\t\t\tName: " << users[user_position].get_user_info("name") << endl;
    cout << "\t\t\t\tEmail: " << users[user_position].get_user_info("email") << endl;

    // Go back
    int Back = go_back();
    if(Back != 0){
        user_panel(users_id);
    }else{
        profile(users_id);
    }
}
// Available sit
void user_available_sit(int users_id){
    system("cls");

    available_sit();

    // Go back
    int Back = go_back();
    if(Back != 0){
        user_panel(users_id);
    }else{
        user_available_sit(users_id);
    }
}



    // Admin component
void admin_panel()
{
    system("cls");
    // variables
    int select;

    cout << "\t\t\t\tWelcome to admin panel" << endl << endl;
    cout << "\t\t\t\t\t1. Add Bus" << endl; // done
    cout << "\t\t\t\t\t2. Remove Bus" << endl; // done
    cout << "\t\t\t\t\t3. Bus List" << endl; // done
    cout << "\t\t\t\t\t4. Available sit" << endl; // done
    //cout << "\t\t\t\t\t4. Total sells" << endl;
    cout << "\t\t\t\t\t5. Logout" << endl; // done
    // take input
    cout << "\n\t\t\t\t\tSelect: ";
    cin >> select;
    if(select == 1)
        add_bus();
    else if(select == 2)
        remove_bus();
    else if(select == 3)
        admin_available_bus_list();
    else if(select == 4)
        admin_available_sit();
    else if(select == 5)
        main();
    else
        admin_panel();

}
// add bus component
void add_bus()
{
    system("cls");
    string bus_no, driver_name, arriv, from, to;
    cout << "\n\t\t\t\tInput all the information" << endl << endl;
    cout << "\t\t\t\tBus number: ";
    cin >> bus_no;
    cout << "\t\t\t\tDriver name: ";
    cin >> driver_name;
    cout << "\t\t\t\tArrival time: ";
    cin >> arriv;
    cout << "\t\t\t\tFrom: ";
    cin >> from;
    cout << "\t\t\t\tTo: ";
    cin >> to;

    // Store all the information
    new_bus add_new_bus(bus_no, driver_name, arriv, from, to);
    for(int i = 0; i < 32; i++){
        add_new_bus.sit[i] = 0;
    }
    // store new bus
    bus_store.push_back(add_new_bus);
    admin_panel();

}
// Remove bus component
void remove_bus(){
    system("cls");
    // variables
    string bus_num;
    cout << "\t\t\tWarning! Please make sure the bus you want to remove is passenger free." << endl << endl;
    cout << "\t\t\t\tEnter bus number: ";
    cin >> bus_num;
    int bus_position = bus_index(bus_num);
    //removing the bus
    bus_store.erase(bus_store.begin() + bus_position);
    cout << "\t\t\t\tRemove successful.";
    // go back
    int Back = go_back();
    if(Back){
        admin_panel();
    }else{
        remove_bus();
    }
}
// Bus list component
void admin_available_bus_list()
{
    bus_list();
    // Go back
    int Back = go_back();
    if(Back != 0){
        admin_panel();
    }else{
        admin_available_bus_list();
    }

}
// Available sit
void admin_available_sit(){
    system("cls");

    available_sit();

    // Go back
    int Back = go_back();
    if(Back != 0){
        admin_panel();
    }else{
        admin_available_sit();
    }
}



    // Common Helper function's
// Find the bus_index from the bus_store
int bus_index(string bus_num){
    int bus_position;
    for(int i = 0; i < bus_store.size(); i++){
        if(bus_store[i].bus_number == bus_num){
            bus_position = i;
            return bus_position;
        }
    }
    return -1;
}
// Find the user index
int user_index(int users_id){
    int i;
    for(i = 0; i < users.size(); i++){
        if(users[i].id == users_id){
            return i;
            break;
        }
    }
    return -1;
}
// Bus list component
void bus_list()
{
    system("cls");
    cout << "\n\t\t\t\tBus list" << endl << endl;
    for(int i = 0; i < bus_store.size(); i++)
    {
        cout << "\t\t\t\t";
        line("*",50);
        cout << "\t\t\t\tBus Number: " << bus_store[i].bus_number << "\t\tDriver Name: " << bus_store[i].driver_name << endl << endl;
        cout << "\t\t\t\tArrival Time: "<< bus_store[i].arrival_time << endl << endl;
        cout << "\t\t\t\tFrom: " << bus_store[i].from << "\t\tTo: " << bus_store[i].to << endl;
    }
    cout << endl;

}
// available sit component
void available_sit(){
    // variable
    string bus_number;
    // Print all bus number
    cout << "\t\t\t\tAvailable bus number's: " << endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < bus_store.size();i++){
        cout << bus_store[i].bus_number << " ";
    }
    cout << "\n\n\t\t\t\tEnter the bus number: ";
    cin >> bus_number;
    // search the bus index from the bus_store
    int bus_position = bus_index(bus_number);
    // Print all sit status
    int j = 0, k = 4, counter = 1;
    if(bus_position >= 0){
        for(int i = 0; i < 8; i++){
            for(j;j < k; j++){
                // print two decimal number
                counter < 10 ? cout << "\t0" << counter : cout << "\t" << counter;
                // check the sit status
                if(bus_store[bus_position].sit[j] != 0){
                    cout << ". Booked" << "\t";
                }else{
                    cout << ". Empty" << "\t";
                }
                counter++;
            }
            k += 4;
            cout << endl;
        }
        cout << endl;
    }else{
        // error message
        cout << "\t\t\t\tBus not found!" << endl << endl;
    }

}
// payment (not working)
void payment_method(){
    system("cls");
    // variables
    int select;
    string account, pass;

    cout << "\t\t\t\tSelect your payment method:" << endl;
    cout << "\t\t\t\t1. Bkash" << endl;
    cout << "\t\t\t\t2. Roket" << endl;
    cout << "\t\t\t\tSelect: ";
    cin >> select;
    system("cls");
    if(select == 1){
        cout << "\n\t\t\t\tEnter your Bkash account number: ";
        cin >> account;
        cout << "\t\t\t\tEnter your password: ";
        cin >> pass;
    }else if(select == 2){
        cout << "\n\t\t\t\tEnter your Roket account number: ";
        cin >> account;
        cout << "\t\t\t\tEnter your password: ";
        cin >> pass;
    }
}
// Go back function
int go_back()
{
    int select;
    cout << "\n\n\t\t\t\tPress 0 to go back: ";
    cin >> select;
    if(select == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Line draw
void line(string type, int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << type;
    }
    cout << endl;
}
