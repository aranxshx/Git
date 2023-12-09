#include <iostream>
#include "sqlite3.h"

using namespace std;

int main()
{
    sqlite3 *db;

    sqlite3_open("PasswordDB.db", &db);
    cout << "Hello world!" << endl;
    return 0;
}
