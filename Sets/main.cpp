#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

void init()
{
    return;
}
void userFilling()
{
    cin.clear();
    char mass[10];
    char ch = ' ';
    short i = 0;

    do{
    cin.get(ch);
    cout << endl << "symb" << endl;
    } while(ch!='\n' && (isspace(ch) || isdigit(ch) || ch < 1000) );
    return;
}

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);//��� ����������� ����������� ������� ���� � �������, ��������� windows cp-1251
    SetConsoleOutputCP(1251); //
    int x;
    while(true)
    {
       cout << "����� �������� ���������� ����������" << endl;
       cout << "1. �������������" << endl;
       cout << "2. ���� ������������" << endl;
       cout << "3. �����" << endl;
       cin >> x;
       switch (x) {
       case 1:
           init();
           break;
       case 2:
           userFilling();
           break;
       case 3:
           return 0;
       default:
           cout << "Недопустимая команда" << endl;
       }

    }

    return 0;
}

