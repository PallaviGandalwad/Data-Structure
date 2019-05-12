#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 #pragma comment(lib, "windowscodecs.lib")

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
	int Data;
	struct node * Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

BOOL InsertFirst(PPNODE ,int);

void Display(PNODE);
int Count(PNODE);

BOOL InsertLast(PPNODE,int);
BOOL DeleteFirst(PPNODE);
BOOL DeleteLast(PPNODE);

BOOL InsertAtPos(PPNODE ,int,int);
BOOL DeleteAtPos(PPNODE,int);
int main()
{
	PNODE Head=NULL;
	BOOL bRet=FALSE;
	int iRet=0;


	bRet=InsertFirst(&Head ,51);
	bRet=InsertFirst(&Head ,21);
	bRet=InsertFirst(&Head ,11);
	
	printf("Inserting Element->\n");
	Display(Head);
	
	iRet=Count(Head);
	printf("\n\nNumber of elements in Linked List->%d\n",iRet);
	bRet=InsertLast(&Head,101);
	bRet=InsertLast(&Head,111);
	Display(Head);

	printf("\n\nDeleted First element->\n");
	bRet=DeleteFirst(&Head);
	Display(Head);

	printf("\n\n Deleted Last Element->\n");
	bRet=DeleteLast(&Head);
	Display(Head);

	bRet=InsertLast(&Head,111);
	bRet=InsertLast(&Head,121);

	printf("\n\n Insert At  Position->\n");
	bRet=InsertAtPos(&Head,105,4);
	bRet=DeleteAtPos(&Head,4);
	Display(Head);
	return 0;

}

BOOL InsertFirst(PPNODE First, int no)
{
	PNODE newn=NULL;
	//PNODE Head =NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->Data = no;

	newn->Next = NULL;
	 
	newn->Next = *First ;

	*First = newn;
 
	return TRUE;

}

void Display(PNODE First)
{
	while(First!=NULL)
	{
		printf("|%d|->",First->Data);
		First=First->Next;

	}
}

int Count(PNODE First)
{
	int iCnt=0;
	while(First!=NULL)
	{
		iCnt++;
		First=First->Next;
	}
	return iCnt;
}

 
BOOL InsertLast(PPNODE First ,int no)
{
	PNODE newn=NULL;
	PNODE Temp=*First;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->Data=no;//Memory allocation
	newn->Next=NULL;//initialization

	if(*First == NULL)
	{
		*First=newn;
	}
	else
	{
		while(Temp->Next !=NULL)
		{
			Temp=Temp->Next;
		}

		Temp->Next=newn;
	}

	return TRUE;}

BOOL DeleteFirst(PPNODE First)
{
	PNODE Temp=*First;

	if(*First !=NULL)
	{
		*First=(*First)->Next;
		free(Temp);
	}

	return TRUE;
}

BOOL DeleteLast(PPNODE First)
{
	PNODE Temp=*First;

	if(*First==NULL)
	{
		return TRUE;
	}
	else if((*First)->Next == NULL )
	{
		*First=NULL;
		free(Temp);
	}
	else
	{
		while(Temp->Next->Next !=NULL)
		{
			Temp=Temp->Next;
		}
		free(Temp->Next);
		Temp->Next=NULL;
	}

	return TRUE;
}

BOOL InsertAtPosition(PPNODE First,int no,int iPos)
{
	PNODE Temp=*First;
	int iCnt=Count(*First) ,i=0;
	BOOL bRet=FALSE;
	PNODE newn=NULL;

	if((iPos < 1) || (iPos > iCnt+1))
	{
		return FALSE;
	}

	if(iPos==1)
	{
		bRet=InsertFirst(First,no);
		return bRet;
	}
	else if(iPos==iCnt+1)
	{
		bRet=InsertLast(First,no);
		return bRet;
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));

		newn->Data=no;
		newn->Next=NULL;

		for(i=1;i<=iPos-2;i++)
		{
			Temp=Temp->Next;
		}

		newn->Next =Temp->Next;
		Temp->Next=newn;
	}
	return TRUE;
}

BOOL DeleteAtPos(PPNODE First,int iPos)
{
	PNODE Temp1=*First,Temp2=NULL;
	int iCnt=Count(*First);
	int i=0;
	BOOL bRet=FALSE;

	if((iPos<1) || (iPos >iCnt))
	{
		return FALSE;
	}

	if(iPos==1)
	{
		bRet=DeleteFirst(First);
		return bRet;
	}
	else if(iPos==iCnt)
	{
		bRet=DeleteLast(First);
		return bRet;
	}
	else
	{
		for(i=1; i<=iPos-2 ;i++)
		{
			Temp1=Temp1->Next;
		}

		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		free(Temp2);

	}
	return TRUE;
}