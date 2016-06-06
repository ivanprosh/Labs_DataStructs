#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include <cstdio>
#include <new>

using namespace std;

const int max_size = 20;
char Set_A[max_size] = {'�','�','�','\0'};
char Set_B[max_size] = {'�','�','�','�','�','\0'};
char Set_C[max_size] = {'�','�','�','�','\0'};
char Set_D[max_size] = {'�','�','�','�','�','�','�','�','�','\0'};
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
            //cout << "����������! " << first[i] << endl;
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
    //��������� ��������
    char temp1[max_size],temp2[max_size],result[max_size];
    compare(temp1,Set_A,Set_B);
    compare(temp2,Set_C,Set_D);
    //printSet(temp1);
    //printSet(temp2);
    diff(Set_E,temp1,temp2);
    cout << "�������������� ��������� E: ";
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
    cout << "�������������� ��������� E: ";
    LprintSet(LE);
    delete LA;
    delete LB;
    delete LC;
    delete LD;
}

void task()
{
    cout<<"�������� ������ ��� �������"<<endl;
    cout<<"A: ";
    printSet(Set_A);
    cout<<"B: ";
    printSet(Set_B);
    cout<<"C: ";
    printSet(Set_C);
    cout<<"D: ";
    printSet(Set_D);

    cout<< "���������, ���������� �����, ����� ��� A � B, �� �� ���������� ������ ��� C � D" << endl;
    //E = (A ����������� B) \ (C ����������� D) - �� ���� �������� �� ������� ���� ��
    //                         i v a n p r o s h [c � � � � �] g m a i l . c o m
    cout << "��������� ��� ������������� ��������" << endl;
    arrays();
    cout << "��������� ��� ������������� �������" << endl;
    lists();
}

void fillingSet(char* buf, int max_size)
{
    memset(buf,0,max_size);
    short i = 0;
    fgets(buf,max_size,stdin);
    while(buf[i] && buf[i]!='\n')
    {
        if(buf[i] >= '�')
        {
            cout << "�� ������ ������ ���������, ��������� ������� �����" << endl;
            fillingSet(buf,max_size);
            return;
        }
        i++;
    }
}

void init()
{
    //��������� ����������� ������
    task();
}
void userFilling()
{
    char ch;
    cin.get(ch);

    cout<< "������� ������ ��������� �" <<endl;
    fillingSet(Set_A,max_size);
    cout<< "������� ������ ��������� B" <<endl;
    fillingSet(Set_B,max_size);
    cout<< "������� ������ ��������� C" <<endl;
    fillingSet(Set_C,max_size);
    cout<< "������� ������ ��������� D" <<endl;
    fillingSet(Set_D,max_size);

    task();
}

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);//��� ����������� ����������� ������� ���� � �������, ��������� windows cp-1251
    SetConsoleOutputCP(1251); //
    char x;
    while(true)
    {
       cout << endl << "����� �������� ���������� ���������" << endl;
       cout << "1. �������������" << endl;
       cout << "2. ���� ������������" << endl;
       cout << "3. �����" << endl;
       cin.get(x);
       switch (x) {
       case '1':
           init();
           return 0;
       case '2':
           userFilling();
           return 0;
       case '3':
           return 0;
       default:
           cout << "������������ ����� ����";
       }

    }

    return 0;
}

