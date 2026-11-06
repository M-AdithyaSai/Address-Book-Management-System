#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"

extern char search[40];
extern int arr[100],count;

void deleteContact(AddressBook *addressBook)
{
	int deleteChoice,contactchoice,e;
    char warn;
    search[0] = '\0';
    do{
        printf("\n========= Delete Menu =========\n");
        printf("1. Delete by Name\n");
        printf("2. Delete by Phone Number\n");
        printf("3. Delete by Email\n");
        printf("4. Exit\n");
        printf("===============================\n");
        printf("Enter your choice  : ");
        if(scanf("%d", &deleteChoice)!=1){
           while (getchar() != '\n');
            printf("\nError Message: Invalid Choice\n");
            continue;
        }
        count = 0;
        switch(deleteChoice){
            case 1:
                printf("Enter Name         : ");
                scanf(" %[^\n]", search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");

                //Searches and displays the contacts based on Name

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].name,search)){
                        arr[count] = i;
                        count++;
                        printf("%-5d %-20s %-15s %-35s\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);    
                    }

                }
                if (count == 0) {
                    printf("\nContact Not Found\n");
                    break;
                }
                printf("\nSelect Contact to Delete (Enter S.No) : ");
                scanf("%d",&contactchoice);

                //To avoid taking invalid contact choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }

                //Re-Conforming  the decision
                printf("Are You Sure You Want to Delete This Contact (Y/N) : ");
                scanf(" %c",&warn);
                if(toupper(warn)!='Y'){
                    printf("\nContact is not deleted\n\n");
                    break;
                }

                e=0;
                contactchoice = arr[contactchoice-1];
                for(int i=0;i<addressBook->contactCount;i++){
                    //Skipping the contact that the user selected for deletion
                    if(i!=contactchoice){
                        //Copying the remaining contacts to the front of the array
                        addressBook->contacts[e++] = addressBook->contacts[i];
                    }  
                }

                //Decresing the contact count
                addressBook->contactCount--;
                printf("\nContact Deleted Successfully\n\n");
            break;

            case 2:
                printf("Enter Phone Number : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");

                //Searches and displays the contacts based on Phone Number

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].phone,search)){
                        arr[count] = i;
                        count++;
                       printf("%-5d %-20s %-15s %-35s\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);    
                    }

                }
                if (count == 0) {
                    printf("\nContact Not Found\n");
                    break;
                }

                printf("\nSelect Contact to Delete (Enter S.No) : ");
                scanf("%d",&contactchoice);
                
                //To avoid taking invalid contact choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }

                //Re-Conforming  the decision
                printf("Are You Sure You Want to Delete This Contact (Y/N) : ");
                scanf(" %c",&warn);
                if(toupper(warn)!='Y'){
                    printf("\nContact is not deleted\n\n");
                    break;
                }

                e=0;
                contactchoice = arr[contactchoice-1];

                for(int i=0;i<addressBook->contactCount;i++){
                    //Skipping the contact that the user selected for deletion
                    if(i!=contactchoice){
                        //Copying the remaining contacts to the front of the array
                        addressBook->contacts[e++] = addressBook->contacts[i];
                    }  
                }

                //Decresing the contact count
                addressBook->contactCount--;
                printf("\nContact Deleted Successfully\n\n");
            break;

            case 3:
                printf("Enter Email        : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");


                //Searches and displays the contacts based on E-mail

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].email,search)){
                        arr[count] = i;
                        count++;
                     printf("%-5d %-20s %-15s %-35s\n",
                                count,
                                addressBook->contacts[i].name,
                                addressBook->contacts[i].phone,
                                addressBook->contacts[i].email);    
                    }

                }

                if (count == 0) {
                    printf("\nContact Not Found\n");
                    break;
                }
                
                printf("\nSelect Contact to Delete (Enter S.No) : ");
                scanf("%d",&contactchoice);

                //To avoid taking invalid contact choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }

                //Re-Conforming  the decision
                printf("Are You Sure You Want to Delete This Contact (Y/N) : ");
                scanf(" %c",&warn);
                if(toupper(warn)!='Y'){
                    printf("\nContact is not deleted\n\n");
                    break;
                }
                e=0;
                contactchoice = arr[contactchoice-1];
                for(int i=0;i<addressBook->contactCount;i++){
                    //Skipping the contact that the user selected for deletion
                    if(i!=contactchoice){
                        //Copying the remaining contacts to the front of the array
                        addressBook->contacts[e++] = addressBook->contacts[i];
                    }  
                }

                //Decresing the contact count
                addressBook->contactCount--;
                printf("\nContact Deleted Successfully\n\n");
            break;

            case 4:
            break;

            default:
            printf("\nError Message: Invalid Choice\n");
            break;

        }
        //Exits if choice is 4
    }while(deleteChoice!=4);    
   
}
