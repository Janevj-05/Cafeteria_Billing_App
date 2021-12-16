/**
 * @file main.c
 * @author SDLC GROUP-12 ()
 * @brief Project to generate cafeteria invoice
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"cafeteria.h"

#define ANS 15
#define ACS 4
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y);

/* declaration of checking functions */
void c_code(char[]);
int check(char[]);
typedef struct
    {
        char name[ANS],code[ACS];
        float rate;
        int quantity;
    } rec;
rec item;


/*constructing function for login credentials*/
void login();

/*start of main*/
int main()
{
    login();
    d_mainmenu();
    return 0;
}
/*declaration of mainmenu function*/
void d_mainmenu();

/*declaration of search function*/
void d_search();

/*declaration of cursor function*/
void cursor(int no)
{
    int count=1;
    char ch='0';
    gotoxy(30,23);
    while(1)
    {
        switch(ch)
        {
        case 80:
            count++;
            if (count==no+1) count=1;
            break;
        case 72:
            count--;
            if(count==0) count=no;
            break;
        }
        highlight(no,count);
        ch=getch();
        if(ch=='\r')
        {
            if(no==7)
            {
                if (count==1) bill() ;
                else if(count==2) add();
                else if(count==3) edit();
                else if (count==4) d_all();
                else if (count==5) d_search();
                else if (count==6) del();
                else   exit(0);
            }
            if(no==4)
            {
                if (count==1) d_code();
                else if (count==2)d_rate();
                else if (count==3) d_quan();
                else d_mainmenu();
            }
        }
    }
}

/*declaration of highlight function*/
void highlight(int no,int count)
{
    if (no==4)
    {
        //textbackground(11);
        //textcolor(0);
        gotoxy(30,23);
        printf("   By Code          ");
        gotoxy(30,24);
        printf("   By Rate          ");
        gotoxy(30,25);
        printf("   By Quantity      ");
        gotoxy(30,26);
        printf("   Back to main menu");
        //textcolor(0);
        //textbackground(2);
        switch (count)
        {
        case 1:
            gotoxy(30,23);
            printf(" - By Code          ");
            break;
        case 2:
            gotoxy(30,24);
            printf(" - By Rate          ");
            break;
        case 3:
            gotoxy(30,25);
            printf(" - By Quantity      ");
            break;
        case 4:
            gotoxy(30,26);
            printf(" - Back to main menu");
            break;
        }
    }

    if(no==7)
    {
        //textbackground(11);
        //textcolor(0);
        gotoxy (30,23);
        printf("   Calculate Bill ");
        gotoxy (30,24);
        printf("   Add Orders      ");
        gotoxy (30,25);
        printf("   Edit Orders     ");
        gotoxy (30,26);
        printf("   Display Orders   ");
        gotoxy (30,27);
        printf("   Search         ");
        gotoxy (30,28);
        printf("   Delete Orders  ");
        gotoxy (30,29);
        printf("   Exit           ");
        //textcolor(0);
        //textbackground(2);
        switch(count)
        {
        case 1:
            gotoxy (30,23);
            printf(" - Calculate Bill ");
            break;
        case 2:
            gotoxy (30,24);
            printf(" - Add Orders      ");
            break;
        case 3:
            gotoxy (30,25);
            printf(" - Edit Orders    ");
            break;
        case 4:
            gotoxy (30,26);
            printf(" - Display Orders    ");
            break;
        case 5:
            gotoxy (30,27);
            printf(" - Search         ");
            break;
        case 6:
            gotoxy (30,28);
            printf(" - Delete Orders   ");
            break;
        case 7:
            gotoxy (30,29);
            printf(" - Exit           ");
            break;
        }
    }
}
/**
 * @brief declaration of bill display function
 * 
 */

void bill();

void dbill();


/*declaration of record adding function*/
void add ();

/**
 * @brief declaration of order availability checking function
 * 
 * @param y 
 */
void c_code(char y[])
{
    int flag;
    FILE *file;
    file=fopen("record.txt","rb");
    while(1)
    {
        system("cls");
        window(20,58,23,36);
        gotoxy(32,18);
        printf(" ADD ORDERS ")  ;
        flag=1;
        rewind(file);
        gotoxy(22,25);
        printf("Enter New Code Of Item:");
        scanf(" %s[^\n]",y);
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                gotoxy(26,30);
                printf("Code Already Exists");
                gotoxy(29,32);
                printf("Enter Again");
                getch();
                break;
            }
        }
        if (flag==1)
            break;
    }
}

/**
 * @brief declaration of order edit function
 * 
 */
void edit();

/**
 * @brief function to display all records
 * 
 */
void d_all()
{
    int i,j=1;
    FILE *file;
    dis_con();
    file=fopen("record.txt","rb");
    rewind(file);
    i=26;
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        display(&item,i,j);
        i++;
        j++;
        if ((j%20)==0)
        {
            gotoxy(27,47);/*textcolor(0)*/;
            printf("Press Any Key To See More...........");
            getch();
            system("cls");
            dis_con();
            i=26;
            continue;
        }
    }
    getch();
    if (i==26)
    {
        gotoxy(24,30);
        printf("-- No Order Found --");
    }
    getch();
    fclose(file);
    d_mainmenu();
}

/**
 * @brief function to display by quantity
 * 
 */
void d_quan()
{
    int i,j=1;
    int a,b;
    FILE *file;
    dis_con();
    file=fopen("record.txt","rb");
    rewind(file);
    i=26;
    gotoxy(16,20);;
    printf("Enter Lower Range: ");
    scanf("%d",&a);
    gotoxy(16,21);
    printf("Enter Upper Range:");
    scanf("%d",&b);
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((item.quantity>=a)&&(item.quantity<=b))
        {
            display(&item,i,j);
            i++;
            j++;
            if ((j%20)==0)
            {
                gotoxy(27,47);
                printf("Press Any Key To See More......");
                getch();
                system("cls");
                dis_con();
                i=26;
                continue;
            }
        }
    }
    getch();
    if (i==26)
    {
        gotoxy(28,30);
        printf(" No Items Found.");
    }
    getch();
    d_search();
    fclose(file);
}

/**
 * @brief function to display by rate
 * 
 */
void d_rate()
{
    int i,j=1;
    float a,b;
    FILE *file;
    dis_con();
    file=fopen("record.txt","rb");
    rewind(file);
    i=26;
    gotoxy(16,20);;
    printf("Enter Lower Range: ");
    scanf("%f",&a);
    gotoxy(16,21);
    printf("Enter Upper Range: ");
    scanf("%f",&b);
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((item.rate>=a)&&(item.rate<=b))
        {
            display(&item,i,j);
            i++;
            j++;
            if ((j%20)==0)
            {
                gotoxy(27,47);
                printf("Press Any Key To See More.....");
                getch();
                system("cls");
                dis_con();
                i=26;
                continue;
            }
        }
    }
    getch();
    if (i==26)
    {
        gotoxy(28,30);
        printf(" No Item Found ");
    }
    getch();
    fclose(file);
    d_search();
}

/**
 * @brief function to display by Item code
 * 
 */
void d_code()
{
    int i,j=1;
    char x[4]= {0};
    FILE *file;
    dis_con();
    file=fopen("record.txt","rb");
    rewind(file);
    i=26;
    gotoxy(16,20);;
    printf("Enter Item Code: ");
    scanf("%s",x);
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((strcmp(item.code,x)==0))
        {
            display(&item,i,j);
            i++;
            j++;
            break;
        }
    }
    if (i==26)
    {
        gotoxy(28,30);
        printf("No Item Found");
    }
    getch();
    fclose(file);
    d_search();
}

/**
 * @brief function for item display window 
 * 
 */
void dis_con()
{
    int i;
    system("cls");
    gotoxy(20,10);
    ;
    for (i=1; i<=10; i++)
        printf("\xdb");
    printf(" FOOD PARADISE ");
    for (i=1; i<=10; i++)
        printf("\xdb");
    printf("\n\n");
    gotoxy(30,11);
    printf(" CAFE");
//textcolor(1);
    gotoxy(32,17);
    printf("DISPLAYING ALL ORDERS") ;
//textcolor(8);
    gotoxy(18,23);
    printf ("SN.   Item Name   Item Code      Rate     Quantity");
}

/**
 * @brief function to display in screen
 * 
 * @param item 
 * @param i 
 * @param j 
 */
void display(rec *item,int i,int j)
{
    gotoxy(16,i);//textcolor(13);
    printf("%4d",j);
    printf("%9s",item->name);
    printf("%12s",item->code);
    printf("%14.2f",item->rate);
    printf("%11d",item->quantity);
}

/*function to delete records*/
void del();

/**
 * @brief function to check validity of item code while editing and deleting
 * 
 * @param x 
 * @return int 
 */
int check(char x[ANS])
{
    FILE *file;
    int flag=1;
    file=fopen("record.txt","rb");
    rewind(file);
    while (fread(&item,sizeof (item),1,file))
    {
        if(strcmp(item.code,x)==0)
        {
            flag=0;
            break;
        }
    }
    fclose(file);
    return flag;
}

/**
 * @brief function to display window
 * 
 * @param a 
 * @param b 
 * @param c 
 * @param d 
 */
void window(int a,int b,int c,int d)
{
    int i;
    system("cls");
    gotoxy(20,10);
//textcolor(1);
    for (i=1; i<=10; i++)
        printf("\xdb");
    printf(" WELCOME TO FOOD PARADISE! ");
    for (i=1; i<=10; i++)
        printf("\xdb");
    printf("\n\n");
    gotoxy(30,11);
    printf("CAFETERIA BILLING APPLICATION");
//textcolor(4);
    for (i=a; i<=b; i++)
    {
        gotoxy(i,17);
        printf("\xdb");
        gotoxy(i,19);
        printf("\xdb");
        gotoxy(i,c);
        printf("\xdb");
        gotoxy(i,d);
        printf("\xdb");
    }

    gotoxy(a,17);
    printf("\xdb");
    gotoxy(a,18);
    printf("\xdb");
    gotoxy(a,19);
    printf("\xdb");
    gotoxy(b,17);
    printf("\xdb");
    gotoxy(b,18);
    printf("\xdb");
    gotoxy(b,19);
    printf("\xdb");

    for(i=c; i<=d; i++)
    {
        gotoxy(a,i);
        printf("\xdb");
        gotoxy(b,i);
        printf("\xdb");
    }
    gotoxy(a,c);
    printf("\xdb");
    gotoxy(a,d);
    printf("\xdb");
    gotoxy(b,c);
    printf("\xdb");
    gotoxy(b,d);
    printf("\xdb");

}
