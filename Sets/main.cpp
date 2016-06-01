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
    SetConsoleCP(1251);//для корректного отображения русских букв в консоли, кодировка windows cp-1251
    SetConsoleOutputCP(1251); //
    int x;
    while(true)
    {
       cout << "Выбор варианта заполнения универсума" << endl;
       cout << "1. Инициализация" << endl;
       cout << "2. Ввод пользователя" << endl;
       cout << "3. Выход" << endl;
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
           cout << "РќРµРґРѕРїСѓСЃС‚РёРјР°СЏ РєРѕРјР°РЅРґР°" << endl;
       }

    }

    return 0;
}

