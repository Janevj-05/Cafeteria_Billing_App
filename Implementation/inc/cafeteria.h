/**
 * @file cafeteria.h
 * @author Team 12 
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _cafeteria_H_
#define _cafeteria_H_

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

/**
 * @brief declaration of display functions
 * 
 */
void cursor(int);
void dbill();
void d_mainmenu();
void display(rec *,int,int);
void window(int,int,int,int);
void dis_con();
void d_search();
void highlight(int,int);

/**
 * @brief declaration of main menu functions
 * 
 */
void bill() ;
void edit();
void add();
void del();
void exit();

/**
 * @brief declaration of display submenu functions
 * 
 */
void d_code();
void d_rate();
void d_quan();
void d_all();
/**
 * @brief constructing function for login credentials
 * 
 */
void login()


#endif  /* #define _cafeteria_H_  */

