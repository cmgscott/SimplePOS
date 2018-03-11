//Christin Scott
#include<stdio.h> //standard
#include<math.h> // for transactions
#include<stdlib.h> // to exit program

// Transaction structure. Holds information on an individual transaction.
// pre:    none
// post:   transaction structure
typedef struct Transaction
{
    int* prices;
    char* customerName;
    int numOfInts;
} Transaction;
// structs here
// Node structure. Represents the element at that position in the list.
// pre:    none
// post:   none
typedef struct node
{
    Transaction data;
    struct node* next;
} Node;
// List structure. Holds the list of transactions.
// pre:    none
// post:   none
typedef struct listType
{
    struct node* front;
    int size;
} LinkedList;
// Customer structure. Holds information on a single customer.
// pre:    none
// post:   none
struct Customer
{
    char *customerName;
};

// methods here

// List methods

// Create method. Creates a new LinkedList. Borrowed code from class documents.
// pre:    none
// post:   LinkedList
//                   a new empty linked list
LinkedList* create( /* in/out */ void)
{
    LinkedList* listPtr = malloc(sizeof(LinkedList));
    if (listPtr != NULL)
    {
        listPtr->front = NULL;
        listPtr->size = 0;
    }
    return listPtr;
}

// Push method. Adds the arguement to the top of the list stack. Borrowed code
// from class documents.
// pre:    newTransaction:
//                       The transaction being added to the list
// post:   none
void push( /* in/out */ LinkedList* ll, /* out */ Transaction newTransaction)
{
    Node* newNode = malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = newTransaction;
        newNode->next = ll->front;
        ll->front = newNode;
        (ll->size)++;
    }
//    free(newNode);
}

// Destroy method. Frees the mallocs in each node in the linked list.
// pre:    nodeToDestroy
//                      the node that will be freed
// post:   none
void destroyNode(/* in */ Node* nodeToDestroy)
{
    free(nodeToDestroy->data.customerName);
    free(nodeToDestroy->data.prices);
}

// Destroy list method. Frees the malloc of the list only after the list has 
// no more mallocs.
// pre:    listToDestroy
//                      the list the be freed
// post:   none
void destroyList(/* in */ LinkedList* ll)
{
    free(ll);
}

// POS methods

// Add Customer method. Adds a customer struct to the list of all customers.
// pre:    none
// post:   none
void addCustomer(/* in/out */ LinkedList* transactionsList)
{
    // declare variables for use in addCustomer
    int nameLength;
    int numOfItems;
    int price;
    int numOfTransactions;

    // print add customer instructions to console
    printf("Enter the customer name length and number of items: ");
    scanf(" %d %d", &nameLength, &numOfItems);
    printf("\n");
    char *newName = malloc(sizeof(char) * nameLength);
    printf("Enter a name: ");
    scanf(" %s", newName);
    printf("\n");
    printf("Enter prices one at a time.\n");

    Transaction newTransaction;
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
    push(transactionsList, newTransaction);
}


// List method. Lists information about the transaction
// pre:    String option
//                      decides whether to print full or compact list
//         int numOfTransactions
//                      the number of transactions created
// post:   none
void list(/* in */ char *option, /* in/out */ LinkedList* ll, /* in/out */ int numOfTransactions)
{
    Node* tempNode;
    tempNode = ll->front;
    // print out full details
    if (strcmp(option, "full") == 0)
    {
        while (tempNode != NULL)
        {
            printf("Name: %s\n", tempNode->data.customerName);
            printf("Transactions: ");
            int i;
            for (i = 0; i < tempNode->data.numOfInts; i++)
            {
                printf("%d ", tempNode->data.prices[i]);
            }
            printf("\n");
            tempNode = tempNode->next;
        }
        //free(tempNode->data.customerName);
        //free(tempNode->data.prices);
        free(tempNode);
    }
    // print out compact details
    else if (strcmp(option, "compact") == 0)
    {
        int sum, i;
        while (tempNode != NULL)
        {
            sum = 0;
            for (i = 0; i < tempNode->data.numOfInts; i++)
            {
                sum += tempNode->data.prices[i];
            }
            printf("Name: %s\n", tempNode->data.customerName);
            printf("Total Sales: %d\n", sum);
            tempNode = tempNode->next;
        }
        free(tempNode);
    }
    free(tempNode);
}

// main method. Queries the user for action option, and calls method based on
// user choice. Loops infinitely until an appropriate choice is input.
// pre:    none
// post:   none
void main(/* in/out */ void)
{
    // declare variables for use in main
    char userChoice;
    int numOfTransactions = 0;
    LinkedList* transactionsList = create();
    // array to hold customers
//    struct Transaction *transactionsArray = malloc(500);
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
        int i;
        // switch statement to run correct method
        switch(userChoice)
        {
            // add new customer order
            case 'a' :
            addCustomer(transactionsList);
            numOfTransactions++;
            break;

            // print full list of transactions
            case 'l' :
            list("full", transactionsList, numOfTransactions);
            break;

            // print compact list of transactions
            case 'c' :
            list("compact", transactionsList, numOfTransactions);
            break;

            // quit program
            case 'q' :;
            Node* tempNode;
            Node* tempNode2;
            tempNode = transactionsList->front;
            //Node* const forFree = tempNode;
            //Node* const forFree2 = tempNode2;
            while (tempNode != NULL)
            {
                tempNode2 = tempNode->next;
                free(tempNode->data.customerName);
                free(tempNode->data.prices);
                free(tempNode);
                tempNode = tempNode2;
            }
            free(tempNode2);
            free(tempNode);
            free(transactionsList);
            tempNode = NULL;
            tempNode2 = NULL;
            exit(1);
            break;

            // something went wrong; try again
            default :
            printf("Please enter valid choice. Entry is case-sensitive.\n\n");
        }
    }
}
