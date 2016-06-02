#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "tnode.h"

using namespace std;

int main(int argc, char *argv[])
{
    Tree MyTree('a','z',6);
    srand(time(nullptr));

    MyTree.MakeTree();
    MyTree.OutTree();
    MyTree.CountLastLeafs();
    return 0;
}

