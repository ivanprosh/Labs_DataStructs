#include <iostream>
#include "tnode.h"

using namespace std;

Tree::Tree(char nm, char mxm, int maxr):num(nm), maxnum(mxm), maxrow(maxr), offset(40), currdepth(0), root(nullptr), SCREEN(new char * [maxrow])
{
    for(int i = 0; i < maxrow; i++) SCREEN[ i ] = new char[80];
}
Tree :: ~Tree()
{
    for(int i = 0; i < maxrow; i++) delete [ ]SCREEN[i];
    delete [ ]SCREEN;
    delete root;
}

void Tree::innerAlg(Node *v, int depth,int* ptrcount)
{
    if(depth == currdepth) (*ptrcount)++;
    if(v->left) innerAlg(v->left,depth+1,ptrcount);
    cout << v->d << '_';
    if(v->right) innerAlg(v->right,depth+1,ptrcount);
}

int Tree::CountLastLeafs()
{
    int count = 0;
    cout << "¬нутренний обход дерева: ";
    innerAlg(root,0,&count);
    return count;
}

Node * Tree :: MakeNode(int depth)
{
    Node * v = nullptr;
    int Y = (depth < rand()%7+1) && (num <= 'z');
    //  ¬ариант: cout ? "Node (" ? num ? ',' ? depth ? ")1/0: "; cin ? Y;
    if(Y) {	// создание узла, если Y = 1
        v = new Node;
        //v->d = num++;	 // разметка в пр€мом пор€дке (= Ђв глубинуї)
        v->left = MakeNode(depth+1);
        //v->d = num++;          //вариант Ч во внутреннем
        v->right = MakeNode(depth+1);
        v->d = num++;		// вариант Ч в обратном
        if(depth > currdepth) currdepth = depth; //запоминаем глубину дерева
    }
    return v;
}
void Tree :: clrscr()
{
    for(int i = 0; i < maxrow; i++)
    memset(SCREEN[i], '.', 80);
}

void Tree :: OutNodes(Node * v, int r, int c)
{
    if (r && c && (c<80)) SCREEN[ r - 1 ][ c - 1 ] = v->d; // вывод метки
    if (r < maxrow) {
    if (v->left) OutNodes(v->left, r + 1, c - (offset >> r)); //левый сын
    // if (v->mdl) OutNode(v->mdl, r + 1, c);	Ч средний сын (если нужно)
    if (v->right) OutNodes(v->right, r + 1, c + (offset >> r)); //правый сын
    }
}


void Tree :: OutTree()
{
    clrscr();
    OutNodes(root, 1, offset);
    for (int i = 0; i < maxrow; i++)
    {
        SCREEN[ i ][ 79 ] = 0;
        cout << "\n" << SCREEN[ i ];
    }
    cout << "\n";
}



