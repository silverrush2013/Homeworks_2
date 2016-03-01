#include <iostream>

using namespace std;


struct Element
{
    char b;
    Element *next=NULL;
};

struct Linked_List
{
    Element *first = NULL;
    Element *last = NULL;
};


bool IsChar(char a)
{
    return (((a >=65) && (a <=90))||((a >=97) && (a <=122)));
}

Linked_List *Create()
{
    Linked_List *Words= new Linked_List;
    string wrd;
    getline(cin,wrd);
    for (int i=0; i<(wrd.length());i++ )
    {
        if (Words->first==NULL)
        {
            Element *elm=new Element;
            elm->b=wrd[i];
            Words->first=elm;
            Words->last=elm;
            elm->next=NULL;
        }
        else
        {
            Element *elm=new Element;
            elm->b=wrd[i];
            Words->last->next=elm;
           Words->last=elm;
            elm->next=NULL;
        }
    }
    return Words;
}

Linked_List *Max_Word(Linked_List *list,int &max_length )
{
    Linked_List *Mword=new Linked_List; //искомый список - максимальное слово
    int cur_length=0;
    Element *chrc=list->first;
    Element *CurChar; //буква слова,на котором останавливаемся,чтобы потом записать его в максимальное слово,если его длина больше,чем макс
    Element *maxword; //указатель на символ максимального слова Mword
    while(chrc!=NULL)//пока не конец списка
    {
        if (IsChar(chrc->b)==true) //если это буква
        {
            CurChar=chrc; //оставляем указатель на начале нового слова,чтобы потом его записать,в случае,если его длина наибольшая
            while ((chrc!=NULL)&&(IsChar(chrc->b)==true)) //пока не конец списка и символ является буквой
            {
                cur_length++;
                chrc=chrc->next;
            }
            if (cur_length>max_length)
            {
                max_length=cur_length;
                maxword=Mword->first;
                while (CurChar!=chrc)
               {
                   if (Mword->first==NULL)
                   {
                        maxword->b=CurChar->b;
                       Mword->first=maxword;
                       Mword->last=maxword;
                       maxword->next=NULL;
                        maxword=maxword->next;
                   }
                    else
                    {
                       maxword->b=CurChar->b;
                        Mword->last->next=maxword;
                        Mword->last=maxword;
                        maxword->next=NULL;
                        maxword=maxword->next;
                    }
                    CurChar=CurChar->next;
                }

           }
            cur_length=0;
        }
        else
        {
            do {
                chrc = chrc->next;
            } while (chrc->b!=' ');
            chrc = chrc->next;
        }
    }
    return Mword;
}

int main() {
    Linked_List *list=Create();
    int length=0;
   Linked_List *maxword = Max_Word(list,length);
    Element *str = maxword->first;
   while (str != NULL) //вывод на экран списка
   {
        cout <<str->b;
       str = str->next;
   }
    cout << endl<<"It is the longest word and its length is " << length;
}