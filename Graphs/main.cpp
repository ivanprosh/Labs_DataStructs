#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#include  <ctype.h>
#include  <string.h>
#include  <iostream>
#include  <Windows.h>

using namespace std;

class Vertex {
public:
    enum color{white,gray,black};
    short d, //discover time
          f; //finish time
    color curcolor;
    Vertex* p;
    Vertex():d(0),f(0),p(nullptr),curcolor(white) {}
};

class Node {
    int vertex;
    Node * next;
public:
    Node( ){ next = NULL; }
    ~Node( ){ if (next) delete next; }
    friend class GR;
};

const int MaxN = 700, MaxV = 26;
char Ch(int s) { return s+'a'; }

class GR {
    Node ** LIST;
    int num,
        n,    //кол-во вершин
        m,    //кол-во ребер
        time; //время обхода в глубину
    Vertex *L;   //указатель на массив вершин
    char **SCREEN;	// память для выдачи на экран
public:
    void DBL (int v); //рекурсивная функция обхода
    void Make (int [ MaxV ][ MaxV ],int countV);
    void DBL_Exec(); //старт алг.
    void OutTree();
    void clrscr();
    GR(int);
    ~GR( );
};

GR::GR(int MaxV) : num(0),n(0),m(0),time(0), LIST(new Node * [ MaxV ]), SCREEN(new char * [MaxV])
{
    for(int i = 0; i < MaxV; i++) SCREEN[ i ] = new char[80];
}
GR :: ~GR() {
    delete []L;
    delete []LIST;
    for(int i = 0; i < MaxV; i++) delete [ ]SCREEN[i];
    delete []SCREEN;
}

void GR :: DBL_Exec()
{
    time = 0;
    for (int i = 0; i < n; i++) {
      L[i].curcolor = Vertex::white;
      L[i].p = NULL;
    }
    for (int i = 0; i < n; i++) {
        if (L[i].curcolor == Vertex::white)
            DBL(i);
    }
}

void GR :: DBL (int v)
{ 
    time++;
    L[v].d = time;
    L[v].curcolor = Vertex::gray;
    for (Node* u = LIST[ v ]; u ; u = u->next)
    { 
        if (L[u->vertex].curcolor == Vertex::white)
        {
            L[u->vertex].p = &L[v];
            DBL(u->vertex);
        }
    }
    L[v].curcolor = Vertex::black;
    time++;
    L[v].f = time;
}

void GR :: Make(int G[ MaxV ][ MaxV ], int countV)
{
    Node* temp;
    int ls = 0, f;
    n = m = 0;
    cout<< "Списки смежности полученного графа:"<<endl;
    for (int i=0; i<countV; i++)
    {
        temp = 0;
        LIST[ i ] = 0;
        //G[ i ][ i ] = 0;
        f = 0;
        cout << "\n" << Ch(i) << ": ";
        for (int j = 0; j < countV; j++)
            if(G[ i ][ j ])
            {
                f++;
                Node *v = new Node;
                v->vertex = j;
                if(temp) temp->next = v;
                else LIST[ i ] = v;
                temp = v;
                cout << Ch( j );
            }
            else cout << "-";
        n++;
        m += f;
        if (!(( ++ls ) % 10)) _getch();
    }
    L = new Vertex[ n ];
    cout << "\n" << "| V |=" << n <<  " | E |=" << m << endl;
}
void GR :: clrscr()
{
    for(int i = 0; i < MaxV; i++)
    memset(SCREEN[i], '.', 80);
}

void GR :: OutTree()
{
    clrscr();
    int center,l=0;
    cout << "Последовательность обхода вершин:" << endl;
    for (int t = 0; t < time; t++)
    {
        for(int curV = 0; curV < n; curV++)
        {
            if(L[curV].d == t)
            {
                cout << "Вершина " << Ch(curV) << ", время открытия " << L[curV].d << ", время закрытия " << L[curV].f << endl;
                center = (L[curV].f - L[curV].d + 1)/2;
                for(int i = L[curV].d+1;i<L[curV].f;i++) SCREEN [l][i] = '_';
                SCREEN [l++][t+center] = Ch(curV);
            }
            if(L[curV].f == t) l--;
        }
    }
    cout << "Вывод глубинного стягивающего леса на экран:" << endl;
    for (int i = 0; i < n; i++)
    {
        SCREEN[ i ][ 79 ] = 0;
        cout << "\n" << SCREEN[ i ];
    }
    cout << "\n";
}
int main()
{
    int i, j, n = 0, G[ MaxV ][ MaxV ];
    char s[ 80 ];
    SetConsoleCP(1251);//для корректного отображения русских букв в консоли, кодировка windows cp-1251
    SetConsoleOutputCP(1251); //

    for ( i = 0; i < MaxV; i++)
        for ( j = 0; j < MaxV; j++) G[ i ][ j ] = 0;
    cout << "\n" << "DBL test ============== (C)lgn, 10.10.03;14.01.13" <<
            "\n" << " Введите списки смежности (строки букв a до z)" <<
            "\n" << " Если из вершины не выходят ребра - '_', конец ввода - '0'" << "\n";
    do{
        cout << "v[" << Ch(n) << "]=";
        cin >> s;
        //cout << "\n" << "[" << s << "]" << strlen(s) << endl;
        //_getch();
        for (int i = 0; i < strlen(s); i++)
            if (isalpha(s[ i ])){
                j = tolower(s[ i ]) - 'a';
                G[ n ][ j ] = 1;
            }
        n++;
    } while((strlen(s) > 0) && (n < MaxV) && s[0]!='0');
    //Преобразование строк в матрицу, затем – в списки смежности,
    //подсчёт мощностей и контрольный вывод
    GR Gr(MaxN);
    Gr.Make(G,n-1);
    //Тестирование функции DBL
    Gr.DBL_Exec( );
    //вывод леса на экран
    Gr.OutTree();
    cout << "\n ===== Конец =====\n";
    system("pause");
}


