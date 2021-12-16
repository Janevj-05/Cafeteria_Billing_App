/**
 * @file login.c
 * @author Team 12
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include"cafeteria.h"

COORD coord= {0,0}; 
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void c_code(char[]);
int check(char[]);
typedef struct
{
    char name[ANS],code[ACS];
    float rate;
    int quantity;
} rec;
rec item;


void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  LOGIN FORM ");
    printf(" \n\n  ENTER USERNAME:-");
	c=pword[i];
	if(c==13)
    {
        break;
    } 
	else{
            printf("*");
         
	    i++;
	}
	pword[i]='\0';
	i=0;
	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
    {
            printf("  \n\n\n       WELCOME TO CAFETERIA BILLING APPLICATION !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
    }
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
	}
		system("cls");
		
}
	scanf("%s", uname); 
	printf(" \n\n   ENTER PASSWORD:-");
	while(i<10)
	{
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO CAFETERIA BILLING APPLICATION !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
    {
        if (a>2)
        {
            printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		    getch();
		
        }
		system("cls");
		
    
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13){
            break;
        } 
	    else
        {
            printf("*");
	        i++;
	    }
	    pword[i]='\0';
	    i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
        {
            printf("  \n\n\n       WELCOME TO CAFETERIA BILLING APPLICATION !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
	        getch();
	        break;
	    }
	    else
	    {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		    a++;
		    getch();
		
	    }
    }
	while(a<=2);
    {
        if (a>2)
        {
            printf("\nSorry you have entered the wrong username and password for four times!!!");
            getch();
		
		}
		system("cls");

		
    }

