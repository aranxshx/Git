#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

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

    cout << string(boxW, '-') << endl;
    cout << "| " << text << " |" << endl;
    cout << string(boxW, '-') << endl;
}

int main()
{
    Sleep(1000);

    
}
