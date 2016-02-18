#include <stdio.h>

struct mas
{
    int chis;   //Струтура из числителя и знаменателя
    int znam;
};


int Create(mas fraction[], int n)
{   int i;
    int k=2;

    for ( i=2; i<=n; i++) //Идем с третьей дроби,т.к. первые две уже есть
    {
        int j=0;
        while (j<=(k-1)) //проверка того,вычислены ли все дроби на данном шаге
        {
            if ((fraction[j].znam+fraction[j+1].znam)==i) //Если знаменатели равны шагу,то вычисляем дробь
            {
                for (int h=k+1;h>j+1;h--)
                {
                    fraction[h]=fraction[h -1]; //сдвиг массива
                }
                fraction[j+1].chis = fraction[j].chis + fraction[j + 2].chis;//создаем новую дробь
                fraction[j+1].znam = fraction[j].znam + fraction[j + 2].znam;
                j++;
                k++; //увеличиваем и j,и k, чтобы вычислить симметричную дробь,либо выйти из цикла while
            }
            else
            {
                j++; //если знаменатели не равны i, увеличиваем j,чтобы создать симметричную дробь или дробь,вычисляемую на этом шаге
            }
       }
    }
    for (int l=0; l<k;l++)
    {
        printf("%d/%d \n", fraction[l].chis, fraction[l].znam);
    }
};

int main() {
    mas fraction[1000];//Массив структур из числителей и знаменателей
    int n=6;
    fraction[0].chis=0;
    fraction[0].znam=1;
    fraction[1].chis=1;
    fraction[1].znam=1;
    Create(fraction,n);

}