#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#include  <ctype.h>
#include  <string.h>
#include  <iostream>
#include  <Windows.h>

using namespace std;

class Node {
    int d;
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
    int num, * NUM, * L, * STACK, ust, n, m;
public:
    void DBL (int v, int p);
    void Make (int [ MaxV ][ MaxV ]);
    void DBL_Exec( );
    GR(int);
    ~GR( );
};

GR::GR(int MaxV) : num(0), ust(0), n(0), m(0), LIST(new Node * [ MaxV ]), NUM(new int[ MaxV ]), L(new int[ MaxV ]), STACK(new int[ MaxV ]) {}
GR :: ~GR() {delete []STACK; delete []L; delete []NUM; delete []LIST; }

void GR :: DBL_Exec()
{

}
void GR :: DBL (int v, int p)
{

}

void GR :: Make(int G[ MaxV ][ MaxV ])
{
    int ls = 0, f;
    n = m = 0;
    for (int i=0; i<MaxV; i++)
    {
        LIST[ i ] = 0;
        G[ i ][ i ] = 0;
        f = 0;
        cout << "\n" << Ch(i) << ": ";
        for (int j = 0; j < MaxV; j++)
            if(G[ i ][ j ])
            {
                f++;
                Node *v = new Node;
                v->d = j;
                v->next = LIST[ i ];
                LIST[ i ] = v;
                cout << Ch( j );
            }
            else cout << "-";
        if( f ) n++;
        m += f;
        if (!(( ++ls ) % 10)) _getch();
    }
    cout << "\n" << "| V |=" << n <<  " | E |=" << m/2;
}
int main()
{
    int i, j, f, n = 0, G[ MaxV ][ MaxV ];
    char s[ 80 ];
    SetConsoleCP(1251);//для корректного отображения русских букв в консоли, кодировка windows cp-1251
    SetConsoleOutputCP(1251); //

    for ( i = 0; i < MaxV; i++)
        for ( j = 0; j < MaxV; j++) G[ i ][ j ] = 0;
    cout << "\n" << "DBL test ============== (C)lgn, 10.10.03;14.01.13" <<
            "\n" << " Введите списки смежности (строки букв a до z)..." << "\n";
    do{
        cout << "v[" << Ch(n) << "]=";
        cin >> s;
        cout << "\n" << "[" << s << "]" << strlen(s) << endl;
        _getch();
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
    Gr.Make(G);
    //Тестирование функции DBL
    //Gr.DBL_Exec( );
    cout << "\n ===== Конец =====\n";
    system("pause");
}


