#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 //A Macro which defines max no.of contacts

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//Prototypes for all functions

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validatename(char []);
int validatephonenumber(AddressBook *AddressBook,char []);
int validatemailid(AddressBook *AddressBook,char []);

#endif

