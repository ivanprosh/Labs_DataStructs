#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include "tnode.h"

using namespace std;

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);//для корректного отображения русских букв в консоли, кодировка windows cp-1251
    SetConsoleOutputCP(1251); //

    Tree MyTree('a','z',7);
    //Tree SecondTree(MyTree); //конструктор копирования запрещен
    Tree SecondTree('a','z',7);
    //SecondTree = MyTree; //оператор присваивания запрещен

    srand(time(nullptr));

    MyTree.MakeTree();
    MyTree.OutTree();
    cout << endl << "Кол-во листьев на самом нижнем уровне имеющем листья: " << MyTree.CountLastLeafs() << endl;
    return 0;
}

