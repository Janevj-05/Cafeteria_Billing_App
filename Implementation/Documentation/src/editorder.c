/**
 * @file editorder.c
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


void edit()
{
    int flag=0,choice;
    char x[ACS],y[ACS];
    FILE *file;
    int size;
    system("cls");
    window(20,63,20,46);
    gotoxy(35,18);
    printf("EDIT ORDERS");
    ;
    gotoxy(25,23);
    printf("Enter Item Code: ");
    scanf("%s",x);
    flag=check(x);
    if(flag==0)
    {
        file=fopen("record.txt","r+b");
        rewind(file);
        while (fread(&item,sizeof (item),1,file))
        {
            if(strcmp(item.code,x)==0)
            {
                //textcolor(0);
                gotoxy(25,27);
                printf("name       = %s",item.name);
                gotoxy(25,28);
                printf("code       = %s",item.code);
                gotoxy(25,29);
                printf("rate       = %g",item.rate);
                gotoxy(25,30);
                printf("quantity   = %d",item.quantity);
                gotoxy(25,32);;
                printf("Do You Want To Edit This Record?(y/n):");
                fflush(file);
                if(toupper(getche())=='Y')
                {
                    gotoxy(25,34);
                    printf("1- Edit Name ");
                    gotoxy(25,35);
                    printf("2- Edit Code ");
                    gotoxy(25,36);
                    printf("3- Edit Rate ");
                    gotoxy(25,37);
                    printf("4- Edit Quantity ");
                    gotoxy(25,39);  ;
                    printf(" Enter Your Choice(1, 2, 3, 4) ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                        system("cls");
                        window(23,48,20,40);
                        gotoxy(35,18);
                        printf("EDIT RECORDS");
                        gotoxy(25,24);
                        printf(" Enter New Name: ");
                        scanf("%s",item.name);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 2:
                        system("cls");
                        window(23,65,20,40);
                        gotoxy(35,18);
                        printf("EDIT RECORDS");
                        gotoxy(25,24);
                        c_code(y);
                        strcpy(item.code,y);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 3:
                        system("cls");
                        window(23,65,20,40);
                        gotoxy(35,18);
                        printf("EDIT RECORDS");
                        gotoxy(25,24);
                        printf(" Enter New Rate: ");
                        scanf("%f",&item.rate);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 4:
                        system("cls");
                        window(23,65,20,40);
                        gotoxy(35,18);
                        printf("EDIT RECORDS");
                        gotoxy(25,24);
                        printf(" Enter New Quantity: ");
                        scanf("%d",&item.quantity);
                        size=sizeof(item);
                        fseek(file,-size,1);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    }
                    gotoxy(27,30);
                    printf("--- Item Edited---");
                    break;
                }
            }
        }
    }
    if (flag==1)
    {
        gotoxy(32,30);
        printf("Item Does Not Exist.");
        gotoxy(36,32);
        printf("TRY AGAIN");
    }
    getch();
    fclose(file);
    d_mainmenu();
}
