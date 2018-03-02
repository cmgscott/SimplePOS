//Christin Scott
#include<stdio.h> //standard
#include<math.h> // for transactions
#include<stdlib.h> // to exit program

// structs here
// Transaction structure. Holds information on an individual transaction.
// pre:    none
// post:   transaction structure
struct Transaction
{
    int* prices;
    char* customerName;
    int numOfInts;
};

// Next customer structure. Links customers in linked list.
// pre:    none
// post:   none
struct NextCustomer
{
    char *nextCustName;
};

// Customer structure. Holds information on a single customer.
// pre:    none
// post:   none
struct Customer
{
    char *customerName;
    struct NextCustomer nextCustomerName;
};

// methods here
// Add Customer method. Adds a customer struct to the list of all customers.
// pre:    none
// post:   none
void addCustomer()
{
    // declare variables for use in addCustomer
    int nameLength;
    int numOfItems;
    int price;

    // print add customer instructions to console
    printf("Enter the customer name length and number of items: ");
    scanf(" %d %d", &nameLength, &numOfItems);
    printf("\n");
    char newName[nameLength + 1];
    printf("Enter a name: ");
    scanf(" %s", newName);
    printf("\n");
    printf("Enter prices one at a time.\n");

    struct Transaction newTransaction;
    newTransaction.customerName = newName;
    newTransaction.prices = malloc(sizeof(int) * numOfItems);
    newTransaction.numOfInts = numOfItems;
    // loop to add items one at a time
    int i;
    for (i = 0; i < numOfItems; i++)
    {
        printf("%d of %d: ", i + 1, numOfItems);
        scanf(" %d", &price);
        newTransaction.prices[i] = price;
    }
    printf("\n");
}

// List method. Lists information about the transaction
// pre:    String option
//                      decides whether to print full or compact list
//         int numOfTransactions
//                      the number of transactions created
// post:   none
void list(char *option, int numOfTransactions)
{
    // print out full details
    if (strcmp(option, "full") == 0)
    {
        int i;
        for (i = 0; i < numOfTransactions; i++)
        {
             
        }
    }
    // print out compact details
    else if (strcmp(option, "compact") == 0)
    {
        printf("compact\n");
    }
}

// main method. Queries the user for action option, and calls method based on
// user choice. Loops infinitely until an appropriate choice is input.
// pre:    none
// post:   none
void main(void)
{
    // declare variables for use in main
    char userChoice;
    int numOfTransactions = 0;
    // initial console output
    printf("Starting program:\n");
    while (1>0)
    {
        if (numOfTransactions == 0)
        {
            printf("You have no transactions.\n");
        } else
        {
            printf("You have %d transactions.\n", numOfTransactions);
        }
        printf("a to add, l to list(full), c to list(compact), q to quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &userChoice);
        printf("\n");
        // switch statement to run correct method
        switch(userChoice)
        {
            // add new customer order
            case 'a' :
            addCustomer();
            numOfTransactions++;
            break;

            // print full list of transactions
            case 'l' :
            list("full", numOfTransactions);
            printf("full\n");
            break;

            // print compact list of transactions
            case 'c' :
            list("compact", numOfTransactions);
            break;

            // quit program
            case 'q' :
            exit(1);
            break;

            // something went wrong; try again
            default :
            printf("Please enter valid choice. Entry is case-sensitive.\n\n");
        }
    }
}
