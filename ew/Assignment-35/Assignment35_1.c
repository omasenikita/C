#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
   
}
void Display(PNODE Head)
{
   
}

int main()
{
    PNODE First = NULL;
    int iValue = 0;
    int iRet = 0;
    printf("Enter a Number\n");
    scanf("%d", &iValue);
    InsertFirst(&First, iValue);
    Display(First);

    

    return 0;

}