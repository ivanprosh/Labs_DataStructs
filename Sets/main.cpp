#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include <cstdio>
#include <new>
#include <conio.h>
#include <ctime>

using namespace std;

const int max_size = 20;
char Set_A[max_size] = {'А','Г','П','\0'};
char Set_B[max_size] = {'К','П','Р','Я','А','\0'};
char Set_C[max_size] = {'Г','Э','М','П','\0'};
char Set_D[max_size] = {'В','У','Я','Д','Н','К','Ж','М','П','\0'};
char Set_E[max_size];

struct list
{
    char el;
    list* next;
    list(char init):el(init),next(0){}
    list(){}
    ~list(){if(next) delete next;}
};
list *LA,*LB,*LC,*LD,*LE;

void printSet(char* buf)
{
    short i = 0;
    while(buf[i])
    {
        cout << buf[i] << '\t';
        i++;
    }
    cout << endl;
}
void LprintSet(list* head)
{
    list* temp = head;
    while(temp)
    {
        cout << temp->el << '\t';
        temp=temp->next;
    }
    cout << endl;
}

void compare(char* result, char* first, char* second)
{
    int i(-1) ,j(-1), k(0);
    while(first[++i])
    {
       j = -1;
       while(second[++j])
        if(first[i] == second[j])
        {
            result[k++] = first[i];
            //cout << "совпадение! " << first[i] << endl;
            break;
        }
    }
    result[k] = '\0';
}
list* Lcompare(list* first, list* second)
{
    list* buf = NULL, *result = NULL, *temp = NULL;
    while(first)
    {
       buf=second;
       while(buf){
        if(first->el == buf->el)
        {
            list *node = new list(first->el);
            if(temp) temp->next=node;
            else result=node;
            temp = node;
            break;
        }
        buf = buf->next;
       }
       first = first->next;
    }
    return result;
}
list* diff(list* first, list* second)
{
    list* buf = NULL, *result = NULL, *temp = NULL;
    while(first)
    {
       buf=second;
       while(buf){
        if(first->el == buf->el) break;
        buf = buf->next;
       }
       if(!buf) {
           list *node = new list(first->el);
           if(temp) temp->next=node;
           else result=node;
           temp = node;
       }
       first=first->next;
    }
    return result;
}
void diff(char* result, char* first, char* second)
{
    int i(-1) ,j(-1), k(0);
    while(first[++i])
    {
       j = -1;
       while(second[++j]) if(first[i] == second[j]) { break;  }
       if(first[i] != second[j]) result[k++] = first[i];
    }
    result[k] = '\0';
}
void arrays()
{
    //сравнение массивов
    char temp1[max_size],temp2[max_size],result[max_size];
    compare(temp1,Set_A,Set_B);
    compare(temp2,Set_C,Set_D);
    //printSet(temp1);
    //printSet(temp2);
    diff(Set_E,temp1,temp2);
    cout << "Результирующее множество E: ";
    printSet(Set_E);
}
list* arrToList(char* buf)
{
    short i = 0;
    list *temp = NULL;
    list *head = NULL;
    while(buf[i])
    {
        list *node = new list(buf[i]);
        if(temp) {
            temp->next = node;
        } else head = node;
        temp = node;
        i++;
    }
    return head;
}

void lists()
{
    LA = arrToList(Set_A);
    LB = arrToList(Set_B);
    LC = arrToList(Set_C);
    LD = arrToList(Set_D);
    list* temp1 = Lcompare(LA,LB);
    //LprintSet(temp1);
    list* temp2 = Lcompare(LC,LD);
    //LprintSet(temp2);
    LE = diff(temp1,temp2);
    cout << "Результирующее множество E: ";
    LprintSet(LE);
    delete LA;
    delete LB;
    delete LC;
    delete LD;
}
void fillbits(char* source, bool* dest)
{
    int i=0;
    while(source[i])
    {
        dest[int(source[i]-'А')] = true;
        //cout << source[i]-'А' << ' ';
        i++;
    }
    cout << endl;
}

void bits()
{
    const short bit_size = 256;
    //массивы битов
    bool temp1[bit_size],temp2[bit_size],result;
    memset(temp1,0,bit_size);
    memset(temp2,0,bit_size);

    bool* bitSetA = new bool[bit_size];
    bool* bitSetB = new bool[bit_size];
    bool* bitSetC = new bool[bit_size];
    bool* bitSetD = new bool[bit_size];

    memset(bitSetA,0,bit_size);
    memset(bitSetB,0,bit_size);
    memset(bitSetC,0,bit_size);
    memset(bitSetD,0,bit_size);
    memset(Set_E,0,max_size);

    fillbits(Set_A,bitSetA);
    fillbits(Set_B,bitSetB);
    fillbits(Set_C,bitSetC);
    fillbits(Set_D,bitSetD);

    int j = 0;
    for(int i=0;i<bit_size;i++)
    {
        temp1[i] = bitSetA[i] && bitSetB[i];
        temp2[i] = bitSetC[i] && bitSetD[i];
        if(!temp2[i] && temp1[i])
        {
           result = i;
           Set_E[j++] = result +'А';
        }
    }

    cout << "Результирующее множество E: "<<endl;;
    printSet(Set_E);

    delete bitSetA;
    delete bitSetB;
    delete bitSetC;
    delete bitSetD;
}
void task()
{
    cout<<"Исходные данные для задания"<<endl;
    cout<<"A: ";
    printSet(Set_A);
    cout<<"B: ";
    printSet(Set_B);
    cout<<"C: ";
    printSet(Set_C);
    cout<<"D: ";
    printSet(Set_D);

    cout<< "Множество, содержащее буквы, общие для A и B, но не являющиеся общими для C и D" << endl;
    //E = (A пересечение B) \ (C пересечение D) - по всем вопросам по решению пиши на
    //                         i v a n p r o s h [c о б а к а] g m a i l . c o m
    cout << "Результат при использовании массивов" << endl;
    int t = clock();
    arrays();
    std::cout << "Для вычисления понадобилось " << t << " тиков времени или " << ((float)t) / CLOCKS_PER_SEC << " секунд.n" << endl;
    cout << "Результат при использовании списков" << endl;
    //t = clock();
    lists();
    //std::cout << "Для вычисления понадобилось " << t << " тиков времени или " << ((float)t) / CLOCKS_PER_SEC << " секунд.n" << endl;
    cout << "Результат при использовании массивов бит" << endl;
    t = clock();
    bits();
    std::cout << "Для вычисления понадобилось " << t << " тиков времени или " << ((float)t) / CLOCKS_PER_SEC << " секунд.n" << endl;
}

void fillingSet(char* buf, int max_size)
{
    memset(buf,0,max_size);
    short i = 0;
    fgets(buf,max_size,stdin);
    while(buf[i] && buf[i]!='\n')
    {
        if(buf[i] >= 'Я')
        {
            cout << "Не верный формат множества, повторите попытку ввода" << endl;
            fillingSet(buf,max_size);
            return;
        }
        i++;
    }
}

void init()
{
    //Обработка статических данных
    task();
}
void userFilling()
{
    char ch;
    cin.get(ch);

    cout<< "Введите данные множества А" <<endl;
    fillingSet(Set_A,max_size);
    cout<< "Введите данные множества B" <<endl;
    fillingSet(Set_B,max_size);
    cout<< "Введите данные множества C" <<endl;
    fillingSet(Set_C,max_size);
    cout<< "Введите данные множества D" <<endl;
    fillingSet(Set_D,max_size);

    task();
}

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);//для корректного отображения русских букв в консоли, кодировка windows cp-1251
    SetConsoleOutputCP(1251); //
    char x;

    cout << endl << "Выбор варианта заполнения множества" << endl;
    cout << "1. Инициализация" << endl;
    cout << "2. Ввод пользователя" << endl;
    cout << "3. Выход" << endl;
    cin.get(x);

    switch (x) {
    case '1':
        init();
        break;
        //return 0;
    case '2':
        userFilling();
        break;
        //return 0;
    case '3':
        return 0;
    default:
        cout << "Недопустимый пункт меню";
    }

   _getch();
   return 0;
}

