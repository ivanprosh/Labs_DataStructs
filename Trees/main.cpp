#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include "tnode.h"

using namespace std;

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);//��� ����������� ����������� ������� ���� � �������, ��������� windows cp-1251
    SetConsoleOutputCP(1251); //

    Tree MyTree('a','z',7);
    //Tree SecondTree(MyTree); //����������� ����������� ��������
    Tree SecondTree('a','z',7);
    //SecondTree = MyTree; //�������� ������������ ��������

    srand(time(nullptr));

    MyTree.MakeTree();
    MyTree.OutTree();
    cout << endl << "���-�� ������� �� ����� ������ ������ ������� ������: " << MyTree.CountLastLeafs() << endl;
    return 0;
}

