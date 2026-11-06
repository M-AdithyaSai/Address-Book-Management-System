#include <stdio.h>
#include<string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen("addbook.csv","w");
    if(fp == NULL){
        printf("\nError Message : File Not Found\n");
        return;
    }
    //Saves the contacts to the file 
    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(fp,"%s,%s,%s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email
        );
    }
    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {

    FILE *fp = fopen("addbook.csv","r");
    if(fp == NULL){
        printf("\nError Message : File Not Found\n");
        return;
    }
        //Reads the contacts from file
       while(( fscanf(fp,"%[^,],%[^,],%[^\n]\n",
            addressBook->contacts[addressBook->contactCount].name,
            addressBook->contacts[addressBook->contactCount].phone,
            addressBook->contacts[addressBook->contactCount].email
       ))==3)
       { 
        
        addressBook->contactCount++;
        }
    
    fclose(fp);
    
}
