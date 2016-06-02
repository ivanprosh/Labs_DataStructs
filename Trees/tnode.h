#ifndef TNODE_H
#define TNODE_H

class Node
{
    char d;
    Node* left;
    Node* right;
public:
    Node():left(nullptr),right(nullptr){}
    ~Node() { if(left) delete left; if(right) delete right;}
friend class Tree;
};

class Tree
{
    Node* root;
    char num,maxnum;		//������� ����� � ������������ ���
    int maxrow, offset;		//������������ �������, �������� �����
    char **SCREEN;	// ������ ��� ������ �� �����
    void clrscr();	// ������� ������� ������

    //������.
    Tree(const Tree&);
    Tree(Tree&&);
    Tree operator = (const Tree&) const;
    Tree operator = (Tree&&) const;
    //������
    Node* MakeNode(int depth); // �������� ���������
    void OutNodes(Node * v, int r, int c); // ������ ���������
    void innerAlg(Node * v,int*);
public:  
    Tree(char num, char maxnum,int maxrow);
    ~Tree();
    void MakeTree() // ���� � ��������� ������
    { root = MakeNode(0); }
    bool exist() { return root != 0; } // �������� ������� �� �����
    int CountLastLeafs();	// ���������� ����� ������ (������� ������� �� ������ ������)
    void OutTree();	// ������ �� �����

};

#endif // TNODE_H
