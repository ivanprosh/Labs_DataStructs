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
    char num,maxnum;		//счЄтчик тегов и максимальный тег
    int maxrow, offset;		//максимальна€ глубина, смещение корн€
    char **SCREEN;	// пам€ть дл€ выдачи на экран
    void clrscr();	// очистка рабочей пам€ти

    //констр.
    Tree(const Tree&);
    Tree(Tree&&);
    Tree operator = (const Tree&) const;
    Tree operator = (Tree&&) const;
    //методы
    Node* MakeNode(int depth); // создание поддерева
    void OutNodes(Node * v, int r, int c); // выдача поддерева
    void innerAlg(Node * v,int*);
public:  
    Tree(char num, char maxnum,int maxrow);
    ~Tree();
    void MakeTree() // ввод Ч генераци€ дерева
    { root = MakeNode(0); }
    bool exist() { return root != 0; } // проверка Ђдерево не пустої
    int CountLastLeafs();	// внутренний обход дерева (подсчет листьев на нижнем уровне)
    void OutTree();	// выдача на экран

};

#endif // TNODE_H
