#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

char change;
string user, pass, confirm, currentPW, currentUser, currentChange;
int errors = 0, game;

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

    box("Welcome");

    loginStart:

    cout << endl << "Enter User: ";
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
                system("cls");
                box("Welcome");
                slowPrint("\nEnter New User: ", 50);
                cin.ignore();
                getline(cin, currentUser);

                slowPrint("Enter New Password: ", 50);
                getline(cin, currentPW);

                startChangePW:
                slowPrint("Confirm Password: ", 50);
                getline(cin, currentChange);

                if (currentChange != currentPW)
                { // START OF CHANGE PASS IF
                    cout << "\nPlease input the correct new password.\n" << endl;
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
            cout << "\nWrong User/Password!\n" << endl;
            Sleep(1000);
            system("cls");
            goto loginTitle;

            break; // DEFAULT BREAK

        } // END OF SWITCH ERRORS

    } // END OF ELSE

    userStart:

    system("cls");

    box("Welcome to the Game!");

    slowPrint("Welcome User", 100);

    cout << endl << "1. Ping Pong \n2. Tic Tac Toe\n3. Snake Game" << endl;

    Choose:
    cout << "Choose Game: ";
    cin >> game;

    switch (game)
    {
    case 1:
        system("cls");

        box("Welcome to Ping Pong!");

        break;

    case 2:
        system("cls");

        box("Welcome to Tic Tac Toe!");

        break;

    case 3:
        system("cls");

        box("Welcome to Snake Game!");

        break;

    default:

        cout << "Invalid Input!" << endl;
        goto Choose;

        break;

    }
    return 0;
} // END OF INT MAIN
