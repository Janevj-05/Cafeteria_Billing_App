/**
 * @file addorder.c
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


void add ()
{
    FILE *file;
    char y[ACS],x[12];
    system("cls");
    gotoxy(25,25);
    printf("Enter New Record(Y/N)?");
    while(toupper(getche())=='Y')
    {
        system("cls");
        file=fopen("record.txt","ab");
        c_code(y);
        strcpy(item.code,y);
        gotoxy(22,28);
        printf("Enter Rate Of The Item:");
        scanf("%f",&item.rate);
        gotoxy(22,30);
        printf("Enter Quantity Of The Item:");
        scanf("%d",&item.quantity);
        gotoxy(22,32);
        printf("Enter Name Of The Item:");
        scanf("%s",item.name);
        fseek(file,0,SEEK_END);
        fwrite(&item,sizeof(item),1,file);
        fclose(file);
        gotoxy(22,34);
        printf("Enter New Record(Y/N)?");

    }
    d_mainmenu();
}
