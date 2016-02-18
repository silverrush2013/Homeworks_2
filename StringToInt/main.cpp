#include <stdio.h>

const int N=3;

bool isDigit(char a)
{
    return ((a >=(int)'0') && (a <=(int)'9'));
}

int charDigitToInt(char a)
{
    return a-'0';
}

int parse(char arr_char[],int &number, bool &success)
{
    int j=N-1;
    int x=1;
    while ((success==true)&&(j>=0))
    {
        if (isDigit(arr_char[j])==false)
        {
            printf("Not a number");
            success=false;
        }
        else
        {
            number=number+charDigitToInt(arr_char[j])*x;
            x=x*10;
            j--;
            if (j<0)
            {
                return number;
            }
        }
    }
}
int main() {

    char arr_char[N]={'5','-1','2'};
    int number=0;
    bool success=true;
    parse(arr_char,number, success);
    if (success==true)
    {
        printf("%d", number);
    }

}