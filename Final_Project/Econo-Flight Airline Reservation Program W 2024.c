/*
Description:The Econo-Airlines fleet consists of one plane with a seating capacity of 12. It makes one flight daily. The aircraft seating isarranged in 6 rows with 2 seats per row. The program uses an array of 12 structures. Each structure holds a seat identification number, a marker that indicates whether the seat is assigned, the last name of the seat holder, and the first name of the seat holder.
Programmer:MohammadAli Yaghmoor
Date: 2024/03/25
Version:1.1.0
*/





#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX_CAPACITY 12


struct Seat {
    int seatNumber;
    bool assigned;
    char firstName[20];
    char lastName[20];
    
};

void myMenu(struct Seat Pinfo[]);


void displaySeatMap(struct Seat initializedInfo[]);
void initializeData(struct Seat Information[]);
void saveSeatData(struct Seat seatsInfo[]);
void emptySeatList(struct Seat seatsInfo[]);
void assignedSeats(struct Seat seatsInfo[]);
void assigningSeatOperation(struct Seat info[]);
void delOneSeat(struct Seat info[]);
void delAllSeats(struct Seat info[]);
void loadSeatData(struct Seat seatsInfo[]);
void visualBuffer();
void introductionBuffer();


int main(void)
{
    struct Seat Pinfo[MAX_CAPACITY];

   
    introductionBuffer();

    loadSeatData(Pinfo);
    
    myMenu(Pinfo);
    return (0);
}
void myMenu(struct Seat Pinfo[])
{
    char choice;
    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    do
    {
        puts("\n\n\n\t\t\tPlease select one of the following options\n\n");
        puts("\t\t\tA) Display ALL seat assignments (including Empty).\n");
        puts("\t\t\tB) Show ONLY a list of empty seats and show total of empty seats\n");
        puts("\t\t\tC) Show ONLY the assigned seats with name of person and total assigned.t\n");
        puts("\t\t\tD) Assign the customer to an empty seat.\n");
        puts("\t\t\tE) Delete ONE seat assignment\n");
        puts("\t\t\tF) Delete ALL seat assignments.\n");
        puts("\t\t\tQ) Quit program.\n");
        printf("\t\t\tPlease enter your choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);
        switch (choice)
        {
        case 'A':
            displaySeatMap(Pinfo);
           
            break;
        case 'B': 
            emptySeatList(Pinfo);
            
            break;
        case 'C':
            assignedSeats(Pinfo);
           
            break;
        case 'D':
            assigningSeatOperation(Pinfo);
           
            break;
        case 'E':
            delOneSeat(Pinfo);
            break;
        case 'F':
            delAllSeats(Pinfo);
            break;
        case 'Q':
            saveSeatData(Pinfo);
            exit(0);
            break;
        default: printf("\n\t\t\tIncorrect input, please enter A, B, C, D, E, F, Q\n\n");
        }
        system("pause");
        system("cls");
    } while (choice != 'Q');
    return;
}
void emptySeatList(struct Seat seatsInfo[])
{
    int index = 0;
    int row;
    int seat;
    int numOfEmptySeats;
    numOfEmptySeats = 0;
    system("cls");
    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    puts("\n\n\t\t\tHere we have a list of empty seats in the airplane\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");

    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    printf("   \t   Seats       Status\t\t   Seats        Status\n\n");
    for (row = 1; row <= 6; row++) 
    {
        for (seat = 1; seat <= 2; seat++, index++)
        {
            if(!seatsInfo[index].assigned)
            {
              
                    if (index == 11 )
                    {
                        if (seatsInfo[index - 1].assigned)
                        {
                            printf(" ");

                            printf("\t\t\t\t\t seatNumber %d => %s \t", seatsInfo[index].seatNumber, seatsInfo[index].assigned ? "Booked" : "Empty");

                        }
                        else
                        {
                            printf(" ");

                            printf("seatNumber %d => %s \t", seatsInfo[index].seatNumber, seatsInfo[index].assigned ? "Booked" : "Empty");
                        }
                    
                    }
                    else
                    {
                        if (index % 2 == 0)
                        {
                            printf(" ");
                            printf("\tseatNumber %d => %s \t\t", seatsInfo[index].seatNumber, seatsInfo[index].assigned ? "Booked" : "Empty");
                        }
                        else
                        {
                            printf(" ");
                            if (seatsInfo[index - 1].assigned)
                            {
                                printf("\t\t\t\t\t seatNumber %d => %s \t\t", seatsInfo[index].seatNumber, seatsInfo[index].assigned ? "Booked" : "Empty");
                            }
                            else 
                            {
                                printf("seatNumber %d => %s \t\t", seatsInfo[index].seatNumber, seatsInfo[index].assigned ? "Booked" : "Empty");

                            }
                            

                        }
                        
                    }
                    numOfEmptySeats++;
                
            }
        }
        printf("\n");
    }
    if (numOfEmptySeats == 0)
    {
        printf("Sorry we dont have any seats available at the moment\n");
    }
    else
    {
        printf("\nNumber of seats available: %d\n\n\n\n", numOfEmptySeats);
    }
    
}
void assignedSeats(struct Seat seatsInfo[])
{
    int index, row, seat, numOfassignedSeats;
    index = 0;
    numOfassignedSeats = 0;


    system("cls");
    puts("\t\tEcono-Flight Airline Reservation Program\n\n");
    puts("\t\tHere we only have the Booked seats displayed \n\n");

    printf("     Seats             FirstName LastName        Status\n\n");
    for (row = 1; row <= 6; row++)
    {
        for (seat = 1; seat <= 2; seat++, index++)
        {
            if (seatsInfo[index].assigned)
            {
                printf(" ");
                printf("seatNumber %d: %15s %-15s ==> %s \n", seatsInfo[index].seatNumber, seatsInfo[index].firstName, seatsInfo[index].lastName,seatsInfo[index].assigned ? "Booked" : "Empty");
                numOfassignedSeats++;
            }
        }
        printf("\n");
    }
    if (numOfassignedSeats == 0)
    {
        printf("All seats are Empty \n");
    }
    else
    {
        printf("\nNumber of assigned seats: %d\n\n\n", numOfassignedSeats);
    }
    
}

void initializeData(struct Seat Information[])
{
    int index;
   
    for (index = 0; index < MAX_CAPACITY; index++)
    {
        Information[index].seatNumber = index + 1;
        Information[index].assigned = false;
        Information[index].firstName[0] = '\0';
        Information[index].lastName[0] = '\0';
        
    }
    
}
void displaySeatMap(struct Seat initializedInfo[])
{

    int index, row , seat;
    index = 0;



   

    system("cls");
    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    visualBuffer();

    printf("\n\n");


    for (row = 1; row <= 6; row++)
    {
        for (seat = 1; seat <= 2; seat++,index ++)
        {
            if(index < 9)
            {
                if (index%2 == 0)
                {
                    if (initializedInfo[index].assigned)
                         {
                          printf("seatNumber 0%d: %13s %-15s Booked\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                         }
                    else
                    {
                        printf("seatNumber 0%d: %14s %14s Empty  \t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
                   
                }
                else
                {

                    if (initializedInfo[index].assigned)
                    {
                        printf("seatNumber 0%d: %13s %-16s Booked\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
                    else
                    {
                        printf("seatNumber 0%d: %14s %14s  Empty  \t\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
          
                }
                
            }
            else
            {
                if (index % 2 == 0)
                {
                    if (initializedInfo[index].assigned)
                    {
                        printf("seatNumber %d: %13s %-15s Booked\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
                    else
                    {
                        printf("seatNumber %d: %13s %-15s Empty\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }

                }
                else
                {
                    if (initializedInfo[index].assigned)
                    {
                        printf("seatNumber %d: %13s %-15s  Booked\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
                    else
                    {
                        printf("seatNumber %d: %13s %-15s  Empty\t", initializedInfo[index].seatNumber, initializedInfo[index].firstName, initializedInfo[index].lastName);
                    }
                }
                
            }
           
        }
        printf("\n");
    }
    printf("\n\n\n\n");
}
void assigningSeatOperation(struct Seat info[])
{
    int userChoice = 0;
   
    emptySeatList(info);

    printf("Please choose your desired seat:");
    scanf("%d",&userChoice);
    userChoice--;

   if (userChoice < 12 && userChoice > 0)
    {
       
           if (info[userChoice].assigned)
           {
               printf("\n\n\nthe seat that you choose is occupied\n\n\n\n");
           }
           else
           {
               
               printf("Please enter your first and last name\n");
               printf("First name:");
               scanf("%s",info[userChoice].firstName);
               printf("Last name:");
               scanf("%s",info[userChoice].lastName);
               info[userChoice].assigned = true;
           }

       
       
    }
    else
    {
        
        printf("Wronge Selection");

    }
   
}
void delOneSeat(struct Seat info[])
{
    int userChoice = 0;

    assignedSeats(info);

    printf("Please choose your desired seat to delete:");
    scanf("%d", &userChoice);
    userChoice--;

    if (!info[userChoice].assigned)
    {
        system("cls");
        printf("\n\nThis seat is already empty\n\n\n");
    }
    else
    {
        
        if (userChoice < 12 && userChoice > 0)
        {

            info[userChoice].firstName[0] = '\0';
            info[userChoice].lastName[0] = '\0';
            info[userChoice].assigned = false;
            printf("seats number %d has been successfully deleted\n", info[userChoice].seatNumber);
            system("pause");
            system("cls");

            myMenu(info);
        }
        else
        {

            printf("Wronge Selection");
            system("cls");

            myMenu(info);
        }
    }
}
void delAllSeats(struct Seat info[])
{
    int index;

    for (index = 0; index < MAX_CAPACITY; index++)
    {
        info[index].seatNumber = index + 1;
        info[index].assigned = false;
        info[index].firstName[0] = '\0';
        info[index].lastName[0] = '\0';

    }
    system("cls");
    printf("All seats has been DELETED\n\n\n");

}
void loadSeatData(struct Seat seatsInfo[]) {
    FILE* file;
    file = fopen("seats_info_file.txt", "rb");
    if (file == NULL) {
        printf("Hi, I know this is your first time using my application. Have fun!\n");
        initializeData(seatsInfo);
        return;
    }

    
    fread(seatsInfo, sizeof(struct Seat), MAX_CAPACITY, file);

    fclose(file);
}

void saveSeatData(struct Seat seatsInfo[])
{
    FILE* file;
    file = fopen("seats_info_file.txt", "wb"); 
    if (file == NULL)
    {
        printf("Error opening the file for writing");
        return;
    }
    fwrite(seatsInfo, sizeof(struct Seat), MAX_CAPACITY, file);

    fclose(file);

    system("cls");
    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    printf("\n\n\n\t\t\tThank you very much for using OUR AIRLINE\n");
    printf("\t\t\tFor a better user experience this app will save all your data for your next visit\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void visualBuffer()
{

    puts("You chose Display SeatMap here you can have a overview of all the seats inside the airplane \n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
    puts("\t\tEcono-Flight Airline Reservation Program\n\n\n");
    printf("   Seats        FirstName/LastName           Status\t   Seats          FirstName/LastName        Status");
    printf("\n");
}
void introductionBuffer()
{
    puts("\t\tWelcome to Econo-Flight Airline Reservation Program in the next\n\t\t page you have the following options\n");
    puts("\t\t\t1-See avialbe seats\n ");
    puts("\t\t\t2-See empty seats\n");
    puts("\t\t\t3-See booked seats\n");
    puts("\t\t\t4-Book a seat of your choice\n");
    puts("\t\t\t5-Delete one seat or all of the booked seats\n");
    puts("\t\t\t6-Quit the program which save all the progress\n\n");
    puts("\t\t\tPress any key to move the menu page\n\n\n\n\n");
    system("pause");
    system("cls");
}