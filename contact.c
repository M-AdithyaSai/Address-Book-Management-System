#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"



void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sorting the contacts based on the chosen criteria
    switch(sortCriteria){
        case 1:
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
                {   //Bubble Sorting
                    Contact temp;
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];      
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            // Printing the contacts
            printf("%-5d %-20s %-15s %-35s\n",
                i + 1,
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
        }
        break;

        case 2:
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcasecmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
                {   //Bubble Sorting
                    Contact temp;
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            // Printing the contacts
            printf("%-5d %-20s %-15s %-35s\n",
                i + 1,
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
        }
        break;

        case 3:
        for(int i=0;i<addressBook->contactCount;i++){
            for(int j=0;j<addressBook->contactCount-i-1;j++){
                if(strcasecmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
                {   //Bubble Sorting
                    Contact temp;
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        printf("\n%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone Number", "E-mail");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            // Printing the contacts
            printf("%-5d %-20s %-15s %-35s\n",
                i + 1,
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
        }
        break;
        default:
        printf("\nError Message: Invalid Entry\n");

    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    //populateAddressBook(addressBook);

    loadContactsFromFile(addressBook); //Loads contacts from addbook.csv

    
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Saves contacts to addbook.csv
    exit(EXIT_SUCCESS); // Exit the program
}

