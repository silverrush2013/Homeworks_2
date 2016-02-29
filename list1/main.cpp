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
    return (!((a >=(int)'0') && (a <=(int)'9')));
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
    Linked_List *Mword=new Linked_List;
    int cur_length=0;
    Element *chrc=list->first;
    Element *CurChar;
    Element *maxword;
    while(chrc!=NULL)
    {
        if (IsChar(chrc->b)==true)
        {
            CurChar=chrc;
            while ((chrc!=NULL)&&(IsChar(chrc->b)==true))
            {
                cur_length++;
                chrc=chrc->next;
            }
            if (cur_length>max_length)
            {
                max_length=cur_length;
                maxword=Mword->first;

            }
        }
    }

}

int main() {
    Linked_List *list=Create();
    int length=0;
    Linked_List *maxword = Max_Word(list,length);
    Element *str = maxword->first;
    while (str != NULL) //вывод на экран списка
    {
        cout <<str->b << endl;
        str = str->next;
    }
}