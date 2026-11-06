    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "contact.h"
    #include "file.h"

    extern char ch;

    //Validates the name
    int validatename(char str[]){

            if(strlen(str)<4){
                printf("\nError Message : Name must contain at least 4 characters\n");
                return 1;
            }
            //Checks if any special characters or digits are present
            for(int i=0;ch = str[i];i++){
                if(!(ch >='A' && ch <='Z' || ch >='a' && ch<='z' || ch == ' ')){
                    printf("\nError Message: Only characters are allowed\n");
                    return 1;
                }

            }
        return 0;
    }

    //Validates the Phone Number
    int validatephonenumber(AddressBook *addressBook,char str[]){

            //Checks if any characters are present other than digits
            for(int i=0;ch = str[i];i++){

                if(!(ch >='0' && ch <='9')){
                    printf("\nError Message : Other than digits, any other character is not allowed in Phone Number\n");
                    return 1;
                }

            }
            
            //Checks the length of the Phone Number
            if(strlen(str)!=10){
                printf("\nError Message : Phone number must contain exactly 10 digits\n");
                return 1;
            }

            //Checks the first digit of the Phone Number
            if(str[0] < '6' || str[0] > '9'){
                printf("\nError Message : First digit must be between 6 and 9 \n");
                return 1;

            }
            // Checks whether the phone number is already present
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(addressBook->contacts[i].phone,str)==0){
                    printf("\nError Message : Phone Number Must be Unique\n");
                    return 1;
                }
                
            }

        return 0;

    }

    //Validates the E-mail
    int validatemailid(AddressBook *addressBook,char str[]){
            // Flags used to validate the email format
            int at_flag =0;
            int dot_flag =0;
            int err_flag1 =0,err_flag2=0;
            
            for(int i=0;ch = str[i];i++){

                //Count the number of '@' symbols
                if(ch == '@'){
                    at_flag++;
                    if(at_flag>1){
                    printf("\nError Message : Email ID must contain exactly one @ symbol \n");
                        return 1;
                    }

                }

                // Count the number of '.' symbols
                if(ch == '.'){
                    dot_flag++;
                    if(dot_flag>1){
                    printf("\nError Message : Email ID must contain exactly one . (dot)\n");
                    return 1;
                    }

                }
                else if(!(ch >='a' && ch <='z' || ch >='0' && ch <='9'|| ch == '@' || ch == '.')){
                    printf("\nError Message : Email ID contains only lowercase letters and digits\n");
                    return 1;
                }

                //Checks if '.' appears before '@'
                if(at_flag == 0 && dot_flag >= 1){
                    err_flag1 =1;
                    
                }

                //Checks if there is no character between '@' and '.'
                if(str[i]=='@'&&str[i+1]=='.'){
                    err_flag2 = 1;
                    
                }
        

            }
            if(at_flag == 0){
                printf("\nError Message : Missing @ \n");
                return 1;
            }
            if(dot_flag == 0){
                printf("\nError Message : Missing . (dot) \n");
                return 1;
            }
            if(err_flag1==1){
                printf("\nError Message : The . (dot) must appear after @ symbol\n");
                return 1;
            }
            if(err_flag2==1){
                printf("\nError Message : There must be at least one character between @ and .(dot)\n");
                return 1;
            }

            //Checks if .com is present
            char *com = strstr(str,".com");
            if(com == NULL){
                printf("\nError Message : .com is not present\n");
                return 1;
            }

            // No extra characters should come after ".com"
            if(strcmp(com,".com")){
                printf("\nError Message : Extra characters after the domain\n");
                return 1;
            }
            
            //Checks if the E-mail id is unique
            for(int i=0;i<addressBook->contactCount;i++){

                if(strcmp(addressBook->contacts[i].email,str)==0){
                    printf("\nError Message: E-mail Must be Unique\n");
                    return 1;
                }
                
            }

        return 0;
    }