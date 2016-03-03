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

int main() {
    Linked_List *list=Create();
    int length=0;
    Element *str =list->first;
    while (str != NULL) //вывод на экран списка
    {
        cout <<str->b;
        str = str->next;
    }
}