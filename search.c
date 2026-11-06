#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

char search[40];
int found = 0;

void searchContact(AddressBook *addressBook) 
{

    int searchChoice;

    //Clearing the variable to use it
    search[0] = '\0';

    do{
        printf("\n========== Search Menu ==========\n");
        printf("1. Search by Name\n");
        printf("2. Search by Phone Number\n");
        printf("3. Search by Email\n");
        printf("4. Exit\n");
        printf("=================================\n");
        printf("Enter your choice : ");
        if(scanf("%d", &searchChoice)!=1){
        //Clearing the buffer if the scanf is unsuccessful
        while (getchar() != '\n');
            printf("\nError Message: Invalid Choice\n");
            continue;
        }
        found = 0;
        switch(searchChoice){
            case 1:
                found = 0;
                printf("Enter Name         : ");
                scanf(" %[^\n]", search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------------\n");

                //Searches and displays the contact based on name

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].name,search)){
                        printf("%-5d %-20s %-15s %-35s\n",
                            i + 1,
                            addressBook->contacts[i].name,
                            addressBook->contacts[i].phone,
                            addressBook->contacts[i].email);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nContact Not Found\n");
                }

            break;

            case 2:
                found = 0;
                printf("Enter Phone Number : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------------\n");

                 //Searches and displays the contact based on Phone number

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].phone,search)){
                     printf("%-5d %-20s %-15s %-35s\n",
                            i + 1,
                            addressBook->contacts[i].name,
                            addressBook->contacts[i].phone,
                            addressBook->contacts[i].email);        
                            found = 1;
                    }
                }

                if (!found) {
                    printf("\nContact Not Found\n");
                }

            break;
            case 3:
                
                printf("Enter Email        : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------------\n");

                //Searches and displays the contact based on E-mail

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].email,search)){
                     printf("%-5d %-20s %-15s %-35s\n",
                            i + 1,
                            addressBook->contacts[i].name,
                            addressBook->contacts[i].phone,
                            addressBook->contacts[i].email);        
                            found = 1;
                    }
                }

                if (!found) {
                    printf("\nContact Not Found\n");
                }
            break;

            case 4:
            break;

            default:
            printf("\nError Message: Invalid Choice\n");

        }

        //Exits if choice is 4
    }while(searchChoice!=4);    

}