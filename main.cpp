#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

char change;
string user, pass, confirm, currentPW, currentUser, currentChange;
int errors = 0;

void slowPrint(const string& text, int delayTime)
{
    for (size_t i = 0; i != text.length(); i++)
    {
        cout << text[i];
        Sleep(delayTime);
    }
}

void box(const string& text)
{
    const int boxW = text.length() + 4;

    cout << string(boxW, '*') << endl;
    cout << "| " << text << " |" << endl;
    cout << string(boxW, '*') << endl;
}

int main()
{ // START OF INT MAIN
    string currentUser = "user", currentPW = "password";

    loginTitle:


    Sleep(1000);

    box("Welcome");

    loginStart:

    cout << "Enter User: ";
    getline(cin, user);

    cout << "Enter Password: ";
    getline(cin, pass);

    if (pass == currentPW && user == currentUser)
    { // START OF IF
        goto userStart;
    } // END OF IF
    else
    { // START OF ELSE
        errors = errors + 1;

        switch (errors)
        { // START OF SWITCH ERRORS

        case 2:

            changePWstart:
            slowPrint("Do you want to change password? (y/n): ", 20);
            cin >> change;

            if (change == 'y')
            { // START OF CHANGE IF

                slowPrint("Enter New Password: ", 50);
                cin.ignore();
                getline(cin, currentPW);

                startChangePW:
                slowPrint("Confirm Password: ", 50);
                getline(cin, currentChange);

                if (currentChange != currentPW)
                { // START OF CHANGE PASS IF
                    cout << "Please input the correct new password." << endl;
                    goto startChangePW;
                } // END OF CHANGE PASS IF

                else
                { // START OF CHANGE PASS ELSE
                    Sleep(1000);
                    slowPrint("Password changed successfully!", 50);
                    system("cls");
                    goto loginTitle;
                } // END OF CHANGE PASS ELSE
            } // END OF CHANGE IF
            else
            { // START OF CHANGE ELSE
                if (change == 'n')
                {
                    cout << "Program Terminated!" << endl;
                    return 0;
                }
                else
                {
                    cout << "This is an invalid input" << endl;
                    cin.ignore();
                    goto changePWstart;
                }
            } // END OF CHANGE ELSE

            break; // CASE 2 BREAK

        default:
            cout << "Wrong User/Password!" << endl;
            goto loginStart;

            break; // DEFAULT BREAK

        } // END OF SWITCH ERRORS

    } // END OF ELSE

    userStart:

    system("cls");

    slowPrint("Welcome User", 100);


    return 0;
} // END OF INT MAIN
