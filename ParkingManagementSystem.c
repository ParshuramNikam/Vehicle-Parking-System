/*=======================================================================================================
  Developed by: Parshuram Nikam
                parshunikam0612@gmail.com
                'C' Programming.
                Sem 2, 2020. Mini Project
                Vishwaniketan college of Engineering, Kumbhivali, Tal- Khalapur,Maharashtra 410203
                Project on:-  Vehicle Parking System
  =======================================================================================================*/



/*===|===================================================================================================
  Table Of Content
  -------------------------------------------------------------------------------------------------------
  Line no.  Contents
  -------------------------------------------------------------------------------------------------------
    39.     System source build include.
    54.     System variables.
    66.     Function prototype.
    80.     Structure.
    99.     Generic function to get passowrd from user and showing * except real characters.
    137.    Function to print Table ( userTable ) 
    158.    Fuction for Car 
    174.    Function for vehicle Rickshaw 
    190.    Function for vehicle Bus
    206.    Function for Billslip.
    259.    Function for showDetails 
    278.    Function for Repeat
    292.    Main Function.
  ===|=====================================================================================================*/



/*===|======================================================================================================
  System source build includes.
  ===|======================================================================================================*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define SPACE 32


/*===|==========================================================================================================
  System variables
  ===|==============================================*============================================================*/

struct bill b;
int op, i, say;
int hour, charges = 0, amount;
int nocar, norickshaw, nobus;
char user[10], pass[10];
FILE *fptr;


/*===|===========================================================================================================
  Functions prototypes
  ===|===========================================================================================================*/

int userTable() ;
int car() ;
int bus() ;
int rickshaw() ;
int billslip() ;
int repeat() ;
int passwordMasking() ; 
int showDetails();  


/*===|===========================================================================================================
  Structure :-
  ===|===========================================================================================================*/

struct bill
{
    //char details[10];
    char name[30];
    char number[10];
    char type[10];
};
struct bill b;


/*===|===========================================================================================================
   ALL THE FUNCTIONS DEFINAIONS ARE BELOW :- 
  ===|===========================================================================================================*/


/*===|===========================================================================================================
   1.  Generic function to get passowrd from user and showing '*' except real characters.
  ===|============================================================================================================*/

int passwordMasking()
{
    int j = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER)
        {
            pass[j] = '\0';
            break;
        }
        else if (ch == BACKSPACE)
        {
            if (j > 0)
            {
                j--;
                printf("\b \b");
            }
        }
        else if (ch == TAB || ch == SPACE)
        {
            continue;
        }
        else
        {
            pass[j] = ch;
            j++;
            printf("*");
        }
    }
}


/*===|===========================================================================================================
   2.  Function to print Table ( userTable ) :-
  ===|===========================================================================================================*/

int userTable()
{
    printf("\n+-------------+-------------------------+-------------------+");
    printf("\n|    Sr.No    |       Type              |    charge/hr.     |");
    printf("\n+-------------+-------------------------+-------------------+");
    printf("\n|      1.     |        Car.             |     Rs.  70.      |");
    printf("\n|      2.     |        Rickshaw.        |     Rs.  50.      |");
    printf("\n|      3.     |        Bus.             |     Rs.  100.     |");
    printf("\n+-------------+-------------------------+-------------------+\n");

    printf("\n--> Press 4 OR any number For EXIT <--\n");
    printf("\nYour option is: ");

    return 0;
}


/*===|===========================================================================================================
   3.  Fuction for Car :-
  ===|===========================================================================================================*/

int car()
{
    scanf("%d", &hour);
    charges = 70 * hour;
    printf("\nCharges are:%d", charges);
    amount = amount + charges;
    nocar++;

    return 0;
}


/*===|===========================================================================================================
   4.  Function for vehicle Rickshaw :-
  ===|===========================================================================================================*/

int rickshaw()
{
    scanf("%d", &hour);
    charges = 50 * hour;
    printf("\nCharges are:%d", charges);
    amount = amount + charges;
    norickshaw++;

    return 0;
}


/*===|===========================================================================================================
   5.  Function for vehicle Bus :-
  ===|===========================================================================================================*/

int bus()
{
    scanf("%d", &hour);
    charges = 100 * hour;
    printf("\n>>> Charges are :  %d \n", charges);
    amount = amount + charges;
    nobus++;

    return 0;
}


/*===|===========================================================================================================
   6.  Function for vehicle Billslip :-
  ===|===========================================================================================================*/

int billslip()
{
    char fileName[40];
    printf("\n>> ENTER A FILE NAME AS :  \"CustomerName_Date.txt\" \n ");
    printf("enter a file name : ");
    scanf(" %s", &fileName);
    fptr = fopen(fileName, "a");

    char details[1];
    gets(details);

    printf("\n\n\t  >>> YOUR BILL IS <<<\n");

    printf("================================================");

    printf("\nDate & Time    : ");
    time_t timer;
    char buffer[26];
    struct tm *tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, " %Y-%m-%d    %H:%M:%S", tm_info);
    puts(buffer);
    fprintf(fptr, "Date and Time :   %s  \n", buffer);

    printf("Customer Name  : ");
    gets(b.name);
    fprintf(fptr, "Customer Name :   %s \n", b.name);

    printf("Car Number:    : ");
    gets(b.number);
    fprintf(fptr, "Car Number    :   %s \n", b.number);

    printf("Car Type       : ");
    gets(b.type);
    fprintf(fptr, "Car Type      :   %s \n", b.type);

    printf("Parking Hours  : %d", hour);
    fprintf(fptr, "Parking Hours :   %d \n", hour);

    fprintf(fptr, "Bill Paid     :   %d \n", amount);

    fclose(fptr);

    printf("\n  -------------------------------------------\t");
    return 0;
}


/*===|===========================================================================================================
   7.  Function for showDetails :-
  ===|===========================================================================================================*/

int showDetails()
{
    printf("\t   DO VISIT AGAIN\n");
    printf("\n>>> Todays Parking Detils & Earning <<<\n");
    printf("=========================================");
    printf("\n     Today's Revenue       : %d", amount);
    printf("\n     No. of Cars parked    : %d", nocar);
    printf("\n     No. of Buses parked   : %d", nobus);
    printf("\n    No. of rickshaws parked : %d", norickshaw);
    printf("\n========================================");
    return 0 ;
}


/*===|===========================================================================================================
   8.  Function for Repeat :-
  ===|===========================================================================================================*/

int repeat()
{
    printf("\nDO YOU WANT TO CONTINUE :\n1.YES \t 2.NO \n>>");
    scanf("%d", &i);

    return 0;
}


/*===|===========================================================================================================
  MAIN FUNCTION STARTS HERE :-
  ===|===========================================================================================================*/

int main()
{
    char ch;

    printf("\n");
    printf("============================================\n");
    printf("\t   USERNAME : ");
    gets(user);

    printf("\t   PASSWORD : ");
    passwordMasking();

    printf("\n==========================================\n");

    printf("\n\n");

    if (strcmp(user, "abcd") == 0 || strcmp(pass, "12345") == 0)
    {
        if ((strcmp(user, "abcd")) == 0)
        {
            if ((strcmp(pass, "12345")) == 0)
            {
                do
                {
                    printf("\n>>> Choose Vehicle type");
                    userTable();

                    scanf("%d", &op);

                    if (op == 1 || op == 2 || op == 3)
                    {
                        printf("\nCharges per hour are as follows:  \n1.car- Rs.70\n2.rickshaw- Rs.50\n3.Bus- Rs100");
                        printf("\nEnter number of hours: ");
                        switch (op)
                        {
                        case 1:
                            car();
                            break;
                        case 2:
                            rickshaw();
                            break;
                        case 3:
                            bus();
                            break;
                        default:
                            printf("wrong option");
                        }

                        billslip();

                        repeat();
                    }

                    if (op == 0 || op >= 4)
                    {
                        i = 2;
                    }

                    if (i == 2)
                    {
                        showDetails();
                    }

                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-\n");
                } while (i != 2);

            } // password verified
            //username verified

            else
            {
                printf("\n WRONG PASSWORD");
            }

        } //loop close

        if ((strcmp(user, "abcd")) != 0)
        {
            if ((strcmp(pass, "12345")) == 0)
            {
                printf("\n  WRONG USERNAME");
            }
            else
            {
                printf("\n WRONG USERNAME &PASSWORD");
            }
        }
    }

    else
    {
        printf("==========================================\n");
        printf("    >>> INVALID Username & Password <<<\t\n");
        printf("==========================================\n\n");
    }

    return 0;
}


