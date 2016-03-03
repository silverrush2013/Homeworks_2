#include <iostream>

using namespace std;


struct Element
{
    char b;
    Element *next=NULL;
    Element *prev=NULL;
};

struct Linked_List
{
    Element *first = NULL;
    Element *last = NULL;
};


void DeleteElement(Element **ch3,Element **beg,Element **end)
{
    if (*ch3==*beg)
    {
    *beg=(*beg)->next;
    (*beg)->prev=0;}
    else if(*ch3==*end)
    {
    *end=(*end)->prev;
        (*end)->next=0;
    }
    else
    {
        (*ch3)->prev->next=(*ch3)->next;
        (*ch3)->next->prev=(*ch3)->prev;
    }
    delete *ch3;
}

Linked_List *DeleteWord(Linked_List *word,Linked_List *text,int length2)
{
    int i=0;
    int j=0;
    Element *beg;
    beg=text->first;
    Element *end;
    end=text->last;
    Element *ch1;
    ch1=text->first;//указатель в тексте на элемент слова(по всему тексту)
    Element *ch2;
    ch2=word->first;// указатель в слове
    Element *ch3;//указатель на элемент слова,который совпадает с искомым
    while (ch1!=NULL) {
        ch3=ch1;
        while ((ch1=ch2)&&(ch1!=NULL)) //пока не конец списка и символ является буквой
        {
            i++;
            ch1=ch1->next;
            ch2=ch2->next;
            if (i==length2)
            {

                if (i>1) {
                    while (j != length2) {
                        DeleteElement(&ch3, &beg, &end);
                        ch3 = ch3->next;
                        j++;
                    }
                }
                else
                {
                    DeleteElement(&ch3, &beg, &end);
                }
            }

        }
        i=0;
        j=0;
        ch2=word->first;
        ch1=ch1->next;
    }
    return text;
}


Linked_List *Create(string wrd)
{
    Linked_List *Words= new Linked_List;
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
    string txt;
    string wrd;
    int length2;
    cout <<"Enter the text"<<endl;
    getline(cin,txt);
    Linked_List *text=Create(txt);
    cout <<"Enter the word" << endl;
    getline(cin,wrd);
    length2=wrd.length();
    Linked_List *word=Create(wrd);
   DeleteWord(word,text,length2);
    Element *str =text->first;
        while (str != NULL) //вывод на экран списка
        {
            cout << str->b;
            str = str->next;
        }
}