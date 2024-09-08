#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions_prototype.h"
#include"projectkeys.h"


void main (void)
{
	  int mode;
    int password_admin_entered;
    int operation_user;
    int operation_admin;

    while(1)
    {
    printf("Welcome! \n");
    printf("Please select 1 for admin mode or 2 for user mode or 0 to exit: \n");
    fflush(stdin);
	  scanf("%d", &mode);
    while((mode!=0) && (mode!=1) && (mode!=2))
        {
          printf("Please try again, select 1 for admin mode or 2 for user mode or 0 to exit: \n");
          fflush(stdin);
	        scanf("%d", &mode);
        }
    switch(mode)
    {
    /*******************************************EXIT  MODE*********************************************************/
    case exit_program:
    printf("Program will terminate, Thank you! \n");
    exit(1);
    break;

    /*******************************************ADMIN  MODE*********************************************************/
    case admin:
    printf("Please enter admin password: \n");
    for(int i=0;i<3;i++)
    {
      fflush(stdin);
	    scanf("%d", &password_admin_entered);
        if (password_admin_entered!=password_admin)
        { 
          if(i==0 || i==1 )
          printf("Wrong Paswword, Please try again, enter admin password: \n");
          else
          {
            printf("Wrong Paswword, no trials left. \nThank You!\n");
            exit(2);
          }
        }
        else 
    {
    printf("Welcome Admin!\n");
    printf("Please select your operation: \n1)Add new patient record \n2)Edit patient record \n3)Reserve a slot with the doctor \n4)Cancel reservation\n");
    fflush(stdin);
    scanf("%d", &operation_admin);
    while(operation_admin!=1 && operation_admin!=2 && operation_admin!=3 && operation_admin!=4)
          { 
            printf("Please enter a valid choice: \n");
            fflush(stdin);
            scanf("%d", &operation_admin);
          }
            switch(operation_admin)
            {
              case Add_new_patient_record:
              add();
              break;
             
              case Edit_patient_record:
              edit();
              break;

              case Reserve_slot:
              reserve();
              break;

              case Cancel_reservation:
              cancel();
              break;
            }  // switch operation_admin terminated
      break;
    } //if else terminated
    }//for loop (password trials) terminated
    break;//case admin terminated

    /*******************************************USER  MODE*********************************************************/
   
   case user:
    printf("Welcome User! \n");
    printf("Please select your operation: \n1)View patient record \n2)View today's reservations.\n");
    fflush(stdin);
    scanf("%d", &operation_user);
    while(operation_user!=1 && operation_user!=2)
          { 
            printf("Please enter a valid choice: \n");
            fflush(stdin);
            scanf("%d", &operation_user);
          }
          switch(operation_user)
            {
              case View_patient_record:
              view_record();
              break;

              case View_today_reservations:
              view_reservation();
              break;
              
            }
     break;//case user terminated
    } // switch case termination (basic mode)
    } // while loop terminated
    } // main terminated
  