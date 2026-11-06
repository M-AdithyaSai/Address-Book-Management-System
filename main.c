/*
Description :
Name            : M ADITHYA SAI
Roll No         : 26012_15
Start date      : 17/07/2026
End date        : 19/07/2026
Sample input    : 
========== Address Book Menu ==========
1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Exit
=======================================
Enter your choice  : 1

Sample output   : 
Enter your choice  : 1

Enter Name         : adithya

Enter Phone Number : 9908799779

Enter Email        : adi@gmail.com

Contact Created Successfully
*/

#include <stdio.h>
#include<unistd.h>
// Structure definitions & Prototypes for all functions are present here
#include "contact.h" 


int main() {
    int choice;
    AddressBook addressBook;
    // Initialize the address book
    initialize(&addressBook); 

    do {
        printf("\n========== Address Book Menu ==========\n");
        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List All Contacts\n");
        printf("6. Exit\n");
        printf("=======================================\n");
        printf("Enter your choice  : ");

        if(scanf("%d", &choice)!=1){
           while (getchar() != '\n');
           // Clears the buffer if scanf is unsuccessful
            printf("\nError Message: Invalid Choice\n"); 
            continue;
        }
        
        
        switch (choice) {
            // Based on the choice, it calls the function accordingly
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("\nSelect Sort Criteria\n");
                printf("--------------------\n");
                printf("1. Sort by Name\n");
                printf("2. Sort by Phone\n");
                printf("3. Sort by Email\n");
                printf("Enter your choice  : ");
                int sortChoice;
                if(scanf("%d", &sortChoice)!=1){
                    while (getchar() != '\n');
                    // Clears the buffer if scanf is unsuccessful
                        printf("\nError Message: Invalid Choice\n"); 
                        continue;
                }
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                 //Prints an animation for saving and exiting
                for(int i=0;i<=100;i++){
                    printf("Saving and Exiting[");
                    for(int dash=0;dash<i;dash++){
                        printf("-");                   
                    }
                    printf(">");
                    for(int space=i;space<100;space++)
                        printf(" ");
                    printf("] %d%%\r",i);
                    usleep(40000);
                    fflush(stdout);
                }
                saveContactsToFile(&addressBook);

                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        //Exits if choice is 6
    } while (choice != 6); 
    
       return 0;
}
