#include <stdio.h>

bool IsPrime(int Numb)
{
    bool check=true;
    for (int i=2; i*i <Numb; i++)
    {
        if (Numb%i ==0)
        {
           check=false;
        }
    }
    if (check==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main() {
    int Numb;
    printf("Enter the number");
    scanf("%d", &Numb );
    if (IsPrime(Numb)==false)
    {
        printf("Statement that the number is prime is false");
    }
   else
    {
        printf("Statement that the number is prime is true");
    }
}


