#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

extern char search[40];
extern char str[50];
int arr[100],count =0;

void editContact(AddressBook *addressBook)
{

    int editChoice,contactchoice;
    search[0] = '\0';
    
    do{
        printf("\n========== Edit Menu ==========\n");
        printf("1. Edit Name\n");
        printf("2. Edit Phone Number\n");
        printf("3. Edit Email\n");
        printf("4. Exit\n");
        printf("===============================\n");
        printf("Enter your choice  : ");
        if(scanf("%d", &editChoice)!=1){
           while (getchar() != '\n');
            printf("\nError Message: Invalid Choice\n");
            continue;
        }
        count=0;
        switch(editChoice){
            case 1:
                printf("Enter Name         : ");
                scanf(" %[^\n]", search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");

                //Searches and displays the contacts based on Name
                
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].name,search)){
                        //Stores the index of the contact in array
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

                printf("\nSelect Contact (Enter S.No) : ");
                scanf("%d",&contactchoice);

                //To avoid taking invalid contacts choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }

                //Checks if the new name is valid
                do{
                    printf("Enter New Name         : ");
                    scanf(" %[^\n]",str);
                }while(validatename(str));
                
                contactchoice = arr[contactchoice-1];

                //If the New Name is valid Old Name will be modified
                strcpy(addressBook->contacts[contactchoice].name,str);
                printf("\nContact Edited Successfully\n\n");
            break;

            case 2:
                printf("Enter Phone Number : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");
                
                //Searches and displays the contacts based on Phone number

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].phone,search)){
                        //Stores the index of the contact in array
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

                printf("\nSelect Contact (Enter S.No) : ");
                scanf("%d",&contactchoice);

                //To avoid taking invalid contact choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }
                
                //Checks if the New Phone number is valid
                do{
                    printf("Enter New Phone Number : ");
                    scanf(" %[^\n]",str);
                }while(validatephonenumber(addressBook,str));
                
                contactchoice = arr[contactchoice-1];

                //If the New Phone Number is valid Old Phone number will be modified
                strcpy(addressBook->contacts[contactchoice].phone,str);
                printf("\nContact Edited Successfully\n\n");
            break;

            case 3:
                printf("Enter Email        : ");
                scanf("%s",search);
                printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
                printf("--------------------------------------------------------------------------\n");
                
                //Searches and displays the contact based on E-mail

                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcasestr(addressBook->contacts[i].email,search)){
                        //Stores the index of the contact in array
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

                printf("\nSelect Contact (Enter S.No) : ");
                scanf("%d",&contactchoice);
                
                //To avoid taking invalid contact choice from user
                if (contactchoice < 1 || contactchoice > count)
                {
                    printf("\nError Message: Invalid S.No\n");
                    break;
                }

                //Checks if the New E-mail is valid
                do{
                    printf("Enter New Email        : ");
                    scanf(" %[^\n]",str);
                }while(validatemailid(addressBook,str));
                
                contactchoice = arr[contactchoice-1];

                //If the New E-mail is valid Old E-mail will be modified
                strcpy(addressBook->contacts[contactchoice].email,str);
                printf("\nContact Edited Successfully\n\n");
            break;

            case 4:
            break;

            default:
            printf("\nError Message: Invalid Choice\n");

        }
        //Exits if choice is 4
    }while(editChoice!=4);  
    
}