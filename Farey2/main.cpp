#include <iostream>
using namespace std;


struct fraction
{
    int chis;   //Струтура из числителя и знаменателя
    int znam;
    fraction *next=NULL;
};

struct List
{
    fraction *first=NULL; //создали список
};


List *Create(int n)
{
    List *Fractions=new List;
    fraction *fract1 = new fraction;
    fract1->znam=1; // создаем 2 первые дроби 0/1 и 1/1
    fract1->chis=0;
    Fractions->first=fract1;
    fraction *fract2 = new fraction;
    fract2->znam=1;
    fract2->chis=1;
    Fractions->first->next = fract2;
    for (int i=0; i<=n; i++)
    {
        fract1=Fractions->first; // указатели на первую и вторую дроби для того,чтобы значения вычислялись равномерно в зависимости от n
        fract2=Fractions->first->next;//и для того,чтобы шли не в разброс
        while (fract2 != NULL) //до тех пор,пока не дойдет до последнего элемента
        {
            if ((fract1->znam+fract2->znam)==i) //пока сумма знаменателей не равна шагу
            {
                fraction *fract=new fraction;
                fract->chis=fract1->chis+fract2->chis;
                fract->znam=fract1->znam+fract2->znam;
                fract1->next=fract;
                fract->next=fract2;
                fract1=fract2;
                fract2=fract2->next;
            }
            else
            {
                fract1=fract1->next; // если она равна шагу пере ходим к следующей паре дробей
                fract2=fract2->next;
            }
        }
    }
    return Fractions;
};

int main() {
    int n=6;
    List *Far = Create(n);
    fraction *str =  Far->first;
    while (str != NULL) //вывод на экран списка
    {
      cout << str->chis <<'/' << str->znam << endl;
        str = str->next;
    }
}
