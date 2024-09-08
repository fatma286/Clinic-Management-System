#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions_prototype.h"
#include"projectkeys.h"

int all_slots[5]= {0,0,0,0,0}; //initializing slots as unreserved
int slot_no;

typedef struct node node;
struct node {
   char name[100];
   int age;
   char gender;
   int id;
   node *next;
   node *prev;
   int *reserveptr;
   int reservno;
};

node* first=NULL;
node* last = NULL;
/**********************************************admin mode functions*************************************************************/

// add function 
void add(void)
{

    node* new= (node*) malloc(sizeof(node));
    if(new!=NULL)
    {
        new->prev=NULL;
        new->next=NULL;
        printf("Please enter patient's name: \n");
        int i=0;
        fflush(stdin);
        while (1) {
		char check = getchar();
		if (check == '\n')
		break;
	    new->name[i]=check;
	    i++;
	    }
	    new->name[i]='\0';
        printf("Please enter patient's age: \n");
        fflush(stdin);
        scanf("%d",&new->age);
        printf("Please enter patient's gender (f:female, m:male): \n");
        fflush(stdin);
        scanf("%c",&new->gender);
        while(new->gender!='f' && new->gender!='m' ) 
        {
        
            printf("Wrong entry\nPlease enter patient's gender (f:female, m:male): \n");
            fflush(stdin);
            scanf("%c",&new->gender);
        }
        new->id= abs(rand());
        printf("Patient's ID is: %d\n",new->id);
        if(first==NULL && last==NULL){
            first=new;
            last=first;
        }
            else
            if (first==last){
                last->next=new;
                new->prev = last;
                last=new;
                first->next=last;
            }
            else
            {
                last->next=new;
                new->prev=last;
                last=new;
            }
    }
    else
    printf("memory error \n");
} //function add terminated


// edit function 
void edit(void)
{
    int id_search;
    node* current = first;
    int counter = 0;
    int found = 0;
    printf("Please enter patient's ID: \n");
    fflush(stdin);
    scanf("%d",& id_search);

    while (current != NULL) 
    {
    counter++;
    if (current->id == id_search) 
    {
      found = 1;
      printf("ID %d is found.\n",id_search);
      break;
    }
    else
    current = current->next;
   }
  if (!found)
    printf("Incorrect ID, ID %d is not found.\n", id_search);
    else
    {
        printf("Please enter edited patient's name: \n");
        int i=0;
        fflush(stdin);
        while (1) {
		char check = getchar();
		if (check == '\n')
		break;
	    current->name[i]=check;
	    i++;
	    }
	    current->name[i]='\0';
        printf("Please enter edited patient's age: \n");
        fflush(stdin);
        scanf("%d",&current->age);
        printf("Please enter edited patient's gender (f:female, m:male): \n");
        fflush(stdin);
        scanf("%c",&current->gender);
        while(1) 
        {
        if (current->gender!='f' && current->gender!='m' )
        {
            printf("Wrong entry\nPlease enter patient's gender (f:female, m:male): \n");
            fflush(stdin);
            scanf("%c",&current->gender);
        }
        else 
        break;
        }
    }
} //function edit terminated


//reserve function
void reserve(void)
{
    int id_given;
    node* current = first;
    int found = 0;
    printf("Please enter patient's ID: \n");
    fflush(stdin);
    scanf("%d",& id_given);

    while (current != NULL) 
    {
    if (current->id == id_given) 
    {
      found = 1;
      printf("ID %d is found.\n",id_given);
      break;
    }
    else
    current = current->next;
   }
  if (!found)
    printf("Incorrect ID, ID %d is not found.\n", id_given);
    else //id found, ready to reserve a slot
    {
        while(1) 
        {
        printf("Please enter the number of your desired slot:\n1) 2pm to 2:30pm \n2) 2:30pm to 3pm \n3)3pm to 3:30pm \n4)4pm to 4:30pm \n5)4:30pm to 5pm \n");
        fflush(stdin);
        scanf("%d",& slot_no);
        slot_no-=1;
        if (slot_no < 0 || slot_no >= NUM_SLOTS) {
        printf("Invalid slot number. Please try again\n");}
        else{
        break;}
        }
        while (all_slots[slot_no]) {
        printf("Slot %d is already reserved.\n", slot_no+1);
        printf("Please enter the number of another slot:\n1) 2pm to 2:30pm \n2) 2:30pm to 3pm \n3)3pm to 3:30pm \n4)4pm to 4:30pm \n5)4:30pm to 5pm \n");
        fflush(stdin);
        scanf("%d",& slot_no);
        slot_no-=1;
        if (slot_no < 1 || slot_no > NUM_SLOTS) 
        {
        printf("Invalid slot number. Please try again\n");
        printf("Please enter the number of your desired slot:\n1) 2pm to 2:30pm \n2) 2:30pm to 3pm \n3)3pm to 3:30pm \n4)4pm to 4:30pm \n5)4:30pm to 5pm \n");
        fflush(stdin);
        scanf("%d",& slot_no);
        slot_no-=1;
        }
        }
    all_slots[slot_no]=1;
    current->reserveptr=&all_slots[slot_no];
    switch(slot_no) //displaying reserved slot
    {
        case slot_1:
        printf("Slot reserved successfully, your slot is from 2pm to 2:30pm\n");
        current->reservno=1;
        break;
        case slot_2:
        printf("Slot reserved successfully, your slot is from 2:30pm to 3:00pm\n");
        current->reservno=2;
        break;
        case slot_3:
        printf("Slot reserved successfully, your slot is from 3:00pm to 3:30pm\n");
        current->reservno=3;
        break;
        case slot_4:
        printf("Slot reserved successfully, your slot is from 4pm to 4:30pm\n");
        current->reservno=4;
        break;
        case slot_5:
        printf("Slot reserved successfully, your slot is from 4:30pm to 5pm\n");
        current->reservno=5;
        break;
    }  // reserved slot displayed successfully
    
    }//reservation terminated
    
} //function reserve terminated


//function cancel
void cancel(void)
{
    int id_given_cancel;
    node* current = first;
    int found = 0;
    printf("Please enter patient's ID: \n");
    fflush(stdin);
    scanf("%d",& id_given_cancel);

    while (current != NULL) 
    {
    if (current->id == id_given_cancel) 
    {
      found = 1;
      printf("ID %d is found.\n",id_given_cancel);
      break;
    }
    else
    current = current->next;
   }
  if (!found)
    printf("Incorrect ID, ID %d is not found.\n", id_given_cancel);
    else //id found, ready to cancel reservation
    {
        if(*(current->reserveptr)!=0) 
        {
           *(current->reserveptr)=0;
        }
        printf("Slot is unreserved.\n");
        current->reservno=0;
    }//reservation canceled

} //function cancel terminated


/**********************************************user mode functions*************************************************************/

// view record function 

void view_record(void)
{
    int id_search;
    node* current = first;
    int counter = 0;
    int found = 0;
    printf("Please enter patient's ID: \n");
    fflush(stdin);
    scanf("%d",& id_search);

    while (current != NULL) 
    {
    counter++;
    if (current->id == id_search) 
    {
      found = 1;
      printf("ID %d is found.\n",id_search);
      break;
    }
    else
    current = current->next;
   }
  if (!found)
    printf("Incorrect ID, ID %d is not found.\n", id_search);
    else //id is found, ready to view record
    {
        printf("Patient's name: %s \n",current->name);
	    printf("Patient's age: %d \n",current->age);
	    printf("Patient's gender (f:female, m:male): %c \n",current->gender);
    }

}// function view record terminated

// view reservation function 
void view_reservation(void)
{
    node* current=first;
    while(current!=NULL)
    {

  switch(current->reservno) //displaying reserved slots
        {
        case 1:
        printf("Patient's ID: %d, Reservation slot from 2pm to 2:30pm\n",current->id);
        break;
        case 2:
        printf("Patient's ID: %d, Reservation slot from 2:30pm to 3:00pm\n",current->id);
        break;
        case 3:
        printf("Patient's ID: %d, Reservation slot from 3pm to 3:30pm\n",current->id);
        break;
        case 4:
        printf("Patient's ID: %d, Reservation slot from 4pm to 4:30pm\n",current->id);
        break;
        case 5:
        printf("Patient's ID: %d, Reservation slot from 4:30pm to 5pm\n",current->id);
        break;
        } // reserved slot displayed successfully
    current=current->next;
    }
}// function view reservation terminated