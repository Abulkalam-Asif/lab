#include<stdio.h>
#include <time.h>
void menuDisplay(void);
void chartDisplay(int[], int[]);
void businessBooking(int[]);
void economyBooking(int[]);
int check_after_booking (int [],int);
void boarding_pass(char[],int,int);
char name[35];
int choice = 0;
int main() {
  int bussArr[30] = {0};
  int ecoArr[70] = {0};
  int seats = 100;

  do
  {
    menuDisplay();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      businessBooking(bussArr);
      system("cls");
      break;
    case 2:
      economyBooking(ecoArr);
      system("cls");
      break;
    case 3:
      chartDisplay(bussArr, ecoArr);
      sleep(3);
      system("cls");
      break;
    default:
      printf("Thank you for choosing AH airlines");
      return 0;
      break;
    }
  }  while(seats != 0);

}

void menuDisplay(void) {
  printf("\n\n\n");
  printf("\t\t**************************************************************************\n");
  printf("\t\t*                      1- Business Class.                                *\n");
  printf("\t\t*                      2- Economy Class.                                 *\n");
  printf("\t\t*                      3- View Seating Chart.                            *\n");
  printf("\t\t*                      Press any key to exit.                            *\n");
  printf("\t\t**************************************************************************\n");
}

void chartDisplay(int arr1[], int arr2[])
{
       printf("\n");
       printf("                               AIRLINE SEATING STATUS                    \n\n\n");
       printf("\t\t*************************************************************************\n");
       printf("\t\t*                 Seats that are sold are indicated by (1)              *\n");
       printf("\t\t*                 Seats that are sold are available by (0)              *\n");
       printf("\t\t*************************************************************************\n");

  printf("\t\t\t\tBusiness Seating chart\n\n\n\t\t\t\t");
  for(int i=0;i<30;i++)
  {
      printf("%d ", arr1[i]);
      if ((i+1) % 3 == 0 && (i+1) % 6 != 0) {
        printf("\t");
      }
      else if ((i+1)%6==0){
        printf("\n\t\t\t\t");
      }
  }
  printf("\n\n");
  printf("\t\t\t\tEconomy seating chart\n\n\t\t\t\t");
  for(int i=0;i<70;i++)
  {
      printf("%d ", arr2[i]);
      if ((i+1) % 3 == 0 && (i+1) % 6 != 0) {
        printf("\t");
      }
      else if((i+1) % 6 == 0) {
        printf("\n\t\t\t\t");
      }
  }
}

void businessBooking(int arr[]) {
  int seatNum;
  printf("Kindly enter your name: ");
  scanf("%s",&name);
  printf("Enter seat number(1-30): ");
  scanf("%d", &seatNum);
  if(seatNum<=30 && seatNum>=1)
    {
        if (check_after_booking(arr,seatNum-1))
        {

            arr[seatNum - 1] = 1;
            printf("Your seat number %d in Business Class has been booked successfully.\n", seatNum);
        }
        else
        {
            printf("Seat is already booked\n");
              sleep(3);
            return;
        }
}
    else
    {
         printf("Invalid Seat number\n");
           sleep(3);
         return;
    }
    sleep(3);
    boarding_pass(name,seatNum-1,choice);
}