#include <iostream>
#include <fstream>
using namespace std;


void login();
void registration();
void forgot();
int main()
{
    int a;

    cout << "   \n\n\n         Hello there ! , Welcome to the login /  registration window            \n  " << endl;
    cout << "        -------------------------------------------------------------------              \n     " << endl;
    cout << "                  please select anyone of the following -                    " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "          press 1 for Login                     " << endl;
    cout << "          press 2 for new registration          " << endl;
    cout << "          press 3 if you forgot your password " << endl;
    cout << "          press 4 to exit\n\n\n " << endl;
    cout << "\n please enter your choice : ";
    cin >> a;
    switch (a)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << " Thankyou for using our service !";
        break;
    default:
        system("cls");
        cout << "please select from the options given above only ...";
        main();
    }
   
}


void login()
{
    int count;
    string userId, userPass, id, pass;
    cout << "\n\nPlease enter the userId\n";
    cin >> userId;
    cout << "\n\nPlease enter the Password\n";
    cin >> userPass;

    // reading using the ifstream class

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        {
            if (id == userId && pass == userPass)
            {
                count = 1;
            }
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << " Login success !!" << endl;
        main();
    }
    else
    {
        cout << "user name and password not found, please try again ..  ";
        main();
    }
}

// registration method
void registration()
{
    string userId, userPass;
    cout << "\n\nPlease enter a new user name\n";
    cin >> userId;
    cout << endl;
    cout << "\n\nCreate a new Password\n";
    cin >> userPass;
    cout << endl;

    // writing int the records file (database) using ofstream
    ofstream f1("records.txt", ios::app);
    f1 << userId << ' ' << userPass << endl;
    f1.close();
    cout << " Your registration is successfull !" << endl;
    main();
}
// forgot
void forgot()
{
    int option;
    cout<<"\nForgot your password ? , No worries ..\n";
    cout<<"\nPress 1 to search your password by username..\n";
    cout<<"\nPress 2 to return to main menu..\n";
    cout<<"\nplease enter your choice : ";
    cin>>option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string userId , sId , sPass;
        cout<<"\nEnter the username you remembered:";
        cin>>userId;

        ifstream f2("records.txt");
        while(f2>>sId>>sPass){
            if(sId == userId){
                count = 1;
            }
        }
        f2.close();
        if(count ==1){
            cout<<"\nUser found ! , Your password is : "<<sPass;
            main();
        }
        else{
            cout<<"\nUsername not found , please register frist\n";
            main();
        }
        break;
    }
        
    case 2:
        {
            main();
        }
    default:
        cout<<"\nWrong choice , please try again !!"<<endl;
        forgot();
    }
}
