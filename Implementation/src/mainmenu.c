/**
 * @file mainmenu.c
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


void d_mainmenu()
{
    int i;
    char ch;
    const char *menu[]= {"   Calculate Bill","   Order Items","   Edit Items","   Display Orders  ","   Search Orders", "   Delete Orders","   Exit"};
    system("cls");
    window(25,50,20,32);
    gotoxy(33,18);
    printf("CAFE MENU");
    for (i=0; i<=6; i++)
    {
        gotoxy(30,22+i+1);
        printf("%s\n\n\n",menu[i]);
    }
    curser(7);
}
