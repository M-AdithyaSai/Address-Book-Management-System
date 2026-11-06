#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"

char ch;

//Temporary variable
char str[50];   

void createContact(AddressBook *addressBook)
{
	//Creates new contact
    if(addressBook->contactCount>=MAX_CONTACTS){
        printf("\nError Message: Maximum Contact Count Reached\n");
        return;
    }

    //Runs until the enterd name is valid
    do{                                 
        printf("\nEnter Name         : ");
        scanf(" %[^\n]",str);
        //str[0] = toupper(str[0]);

        //Checks if the name is valid
    }while(validatename(str));         
    
    // If valid, it copies the name into addbook.csv
    strcpy(addressBook->contacts[addressBook->contactCount].name,str);

    //Clearing the variable to reuse it
    str[0] = '\0';  

    do{
        printf("\nEnter Phone Number : ");
        scanf(" %[^\n]",str);

        //Checks if the Phone number is valid
    }while(validatephonenumber(addressBook,str));    

    //If valid, it copies Phone Number into addbook.csv
    strcpy(addressBook->contacts[addressBook->contactCount].phone,str);

    //Clearing the variable to reuse it
    str[0] = '\0';  
    
    do{
        printf("\nEnter Email        : ");
        scanf(" %[^\n]",str);


        //Checks if the Email is valid
    }while(validatemailid(addressBook,str));      
    
    strcpy(addressBook->contacts[addressBook->contactCount].email,str);

    printf("\nContact Created Successfully\n");
    // If everything is successful, contact count will be increased
    addressBook->contactCount++;
}
