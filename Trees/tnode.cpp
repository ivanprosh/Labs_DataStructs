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
    cout << "���������� ����� ������: ";
    innerAlg(root,0,&count);
    return count;
}

Node * Tree :: MakeNode(int depth)
{
    Node * v = nullptr;
    int Y = (depth < rand()%7+1) && (num <= 'z');
    //  �������: cout ? "Node (" ? num ? ',' ? depth ? ")1/0: "; cin ? Y;
    if(Y) {	// �������� ����, ���� Y = 1
        v = new Node;
        //v->d = num++;	 // �������� � ������ ������� (= �� �������)
        v->left = MakeNode(depth+1);
        //v->d = num++;          //������� � �� ����������
        v->right = MakeNode(depth+1);
        v->d = num++;		// ������� � � ��������
        if(depth > currdepth) currdepth = depth; //���������� ������� ������
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
    if (r && c && (c<80)) SCREEN[ r - 1 ][ c - 1 ] = v->d; // ����� �����
    if (r < maxrow) {
    if (v->left) OutNodes(v->left, r + 1, c - (offset >> r)); //����� ���
    // if (v->mdl) OutNode(v->mdl, r + 1, c);	� ������� ��� (���� �����)
    if (v->right) OutNodes(v->right, r + 1, c + (offset >> r)); //������ ���
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



