#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining an enum structure for the user account type
typedef enum type {
    savings,
    current
} type;

// Defining user account information structure
typedef struct AccountInfo {
    int Acc_No;
    type Acc_Type;
    char Name[16];
    float Balance;
    struct AccountInfo* next; 
} AccountInfo;
typedef AccountInfo* LinkedList;

// Defining the database structure
typedef struct database {
    AccountInfo* user;
    int user_count;
} database;

// Function Prototypes
LinkedList INSERT(int num, int typ, char* naam, float bal, int pos, LinkedList user) {
    /* Input  : Data of the user, integer position for the insert and the LinkedList
       Output : Adds the new user to the database, at the required index based on the
                account number
    */

    if (pos == 0) {
        AccountInfo *node = (AccountInfo*) malloc(sizeof(AccountInfo));
        node->Acc_No = num;
        node->Acc_Type = typ;
        strcpy(node->Name, naam);
        node->Balance = bal;

        node->next = user;
        return node;
    }

    else {
        user->next = INSERT(num, typ, naam, bal, pos - 1, user->next);
        return user;
    }
}

void DISPLAY(LinkedList user, int N) {
    /* Input  : Address of the first user record & the number of users in the database.
       Output : Prints the records on the screen, with the latest records in the end.
    */

    printf(" *******************************************************************\n");

    if (user == NULL) {
        printf("\n * No accounts to display! * \n");
    }

    else {
        char acc[2][10] = {"savings", "current"};

        printf("    Account Number     Account Type       Name \t\t Balance");
        printf("\n -------------------------------------------------------------------\n");

        while (user != NULL) {
            printf("\t %-15d %-15s %-15s %7.2f \n", user->Acc_No, acc[user->Acc_Type], user->Name, user->Balance);
            user = user->next;
        }
        printf(" *******************************************************************\n");
    }
}

LinkedList CREATE(LinkedList user, int acc_type, char name[], float balance) {
    /* Input  : Address of the first user record & the account details of the new user.
       Output : Checks if the user already exists, and raise suitable error text. Otherwise,
                create a new record containing user's details and append it to the database.
    */

    LinkedList original = user;
    LinkedList check = user;

    while (check != NULL) {
        if (check->Acc_Type == acc_type && strcmp(check->Name, name) == 0) {
            printf(" * Account already exists! * \n");
            return original;
        }
        check=check->next;
    }

    AccountInfo* data = (AccountInfo*) malloc(sizeof(AccountInfo));

    if (user == NULL) {
        data->Acc_No = 100;
        data->Acc_Type = acc_type;
        strcpy(data->Name, name);
        data->Balance = balance;
        data->next = NULL;
        original = data;
    }

    else {
        LinkedList lst = user;
        int count = 0;
        int flag = 0;

        while (lst != NULL) {
            if (lst->Acc_No != 100 + count) {
                flag = 1;
                break;
            }
            lst = lst->next;
            count++;
        }

        LinkedList prev = NULL;

        if (flag == 0) {
            while (user != NULL) {
                prev = user;
                user = user->next;
            }

            data->Acc_No = 100 + count;
            data->Acc_Type = acc_type;
            strcpy(data->Name, name);
            data->Balance = balance;
            data->next = NULL;

            prev->next = data;
        }

        else {
            data->Acc_No = 100 + count;
            data->Acc_Type = acc_type;
            strcpy(data->Name, name);
            data->Balance = balance;

            original = INSERT(100+count, acc_type, name, balance, count, original);
        }
    }

    printf("\n********************************************************************\n");
    printf("\n * User added Successfully! * \n");
    // char acc[2][10] = {"savings", "current"};
    // printf("Account Number: %d\n", data->Acc_No);
    // printf("Account Holder: %s\n", data->Name);
    // printf("Account Type: %s\n", acc[data->Acc_Type]);
    // printf("Balance: Rs %.2f\n", data->Balance);
    // printf("\n");

    return original;
}
    


LinkedList DELETE(LinkedList user, int acc_type, char name[]) {
    /* Input  : Address of the first user record & the account details of the user.
       Output : Checks if the user exists, and then deletes that record. Otherwise,
                raise suitable error text.
    */

    LinkedList original = user;
    LinkedList prev = NULL;
    while (user != NULL) {
        if (user->Acc_Type == acc_type && strcmp(user->Name, name) == 0) {
            break;
        }
        prev = user;
        user = user->next;
    }

    if (user == NULL) {
        printf("\n * Invalid: User does not exist! * \n");
    }

    else {
        if (prev != NULL) {
            prev->next = user->next;
            free(user);
        }
        else {
            original = original->next;
        }

        printf("\n********************************************************************\n");
        printf("\n * Account deleted successfully. * \n");
    }
    return original;
}

void DEPOSIT(LinkedList user, int acc_num, float amount) {
    /* Input  : Address of the first user record, account number of the user & the amount to be deposited.
       Output : Checks if the user exists, and then adds the amount to the user's balance. Otherwise,
                raise suitable error text.
    */  

    printf("\n********************************************************************\n");

    while (user != NULL) {
        if (user->Acc_No == acc_num) {
            break;
        }
        user = user->next;
    }

    if (user == NULL) {
        printf("\n * Invalid: User does not exist! * \n");
    }

    else {
        user->Balance += amount;
        printf("\n * Updated Balance for Acc. No. %d now is Rs %.2f. * \n", user->Acc_No, user->Balance);
    }

}

void WITHDRAW(LinkedList user, int acc_num, float amount) {
    /* Input  : Address of the first user record, account number of the user & the amount to be withdrawn.
       Output : Checks if the user exists, and then withdraws the amount to the user's balance, if the
                net balance does not go less than 100. Otherwise, raises suitable error text.
    */

    printf("\n********************************************************************\n");

    while (user != NULL) {
        if (user->Acc_No == acc_num) {
            break;
        }
        user = user->next;
    }

    if (user == NULL) {
        printf("\n * Invalid: User does not exist! * \n");
    }

    else if (user->Balance - amount < 100) {
        printf("\n * Insufficient funds for transaction. Current Balance: Rs %.2f. * \n", user->Balance);
    }

    else {
        user->Balance -= amount;
        printf("\n * Updated Balance for Acc. No. %d now is Rs %.2f. * \n", user->Acc_No, user->Balance);
    }
}

void TRANSACTION(LinkedList lst, int acc_num, float amount, int code) {
    if (code == 1) {
        DEPOSIT(lst, acc_num, amount);
    }

    else {
        WITHDRAW(lst, acc_num, amount);
    }

} 

void LOWBALANCE(LinkedList user, int lim) {
    /* Input  : Address of the first user record & minimum amount balance.
       Output : Scours the whole database, and prints the details of all the users having account
                balance less than the minimum account balance.
    */

    printf("\n   *******************************************************\n");
    printf("   *     Account Number       Name          Balance      * ");
    printf("\n   *-----------------------------------------------------*\n");

    while (user != NULL) {
        if (user->Balance < lim) {
           printf("   *          %-14d %-15s %-11.2f * \n", user->Acc_No, user->Name, user->Balance);
        }
        user = user->next;
    }
    printf("   *******************************************************\n");
}


int main() {
    /* Declaring Initial Database */

    // AccountInfo user5 = {104, savings, "Kriti", 50.00, NULL};
    // AccountInfo user4 = {103, savings, "Ayan", 700.00, &user5};
    // AccountInfo user3 = {102, current, "Aditya", 300.00, &user4};
    // AccountInfo user2 = {101, current, "Pramod", 80.00, &user3};
    // AccountInfo user1 = {100, savings, "Keval", 1500.00, &user2};
    // database data = {&user1, 5};
    database data = {NULL, 0};

    // Displayinng a Welcome Message!
    printf("\n********************************************************************\n");
    printf("\tWelcome to \"da La' Ssignment-4 International Bank\"!");

    // Indefinite looping for the Banking Services
    while (69) {
        // Displaying the Menu
        char op[10];
        printf("\n********************************************************************\n");
        printf(" EXIT     : EXIT \n");
        printf(" DISPLAY  : DISPLAY DATABASE \n");
        printf(" CREATE   : ADDING NEW RECORD \n");
        printf(" DELETE   : DELETE EXISTING RECORD \n");
        printf(" DEPOSIT  : DEPOSIT MONEY \n");
        printf(" WITHDRAW : WITHDRAW MONEY \n");
        printf(" MIN_BAL  : MINIMUM BALANCE CHECK \n");
        printf(" --> Select a service to proceed [ Enter operation code ] : ");
        scanf("%s", op);
        printf("********************************************************************\n");
        printf("\n");

        // Defining the operation codes
        char op0[] = "EXIT";
        char op1[] = "DISPLAY";
        char op2[] = "CREATE";
        char op3[] = "DELETE";
        char op4[] = "DEPOSIT";
        char op5[] = "WITHDRAW";
        char op6[] = "MIN_BAL";

        // EXIT
        if (strcmp(op, op0) == 0) {
            break;
        }

        // DISPLAY
        else if (strcmp(op, op1) == 0) {
            DISPLAY(data.user, data.user_count);
        }

        // CREATE
        else if (strcmp(op, op2) == 0) {
            printf("--> ADDING NEW USER:\n");
            int type;
            char nam[24];
            float bal;
            
            printf("    Account Type [ 0: savings, 1: current ] : ");
            scanf("%d", &type);
            printf("    Account Holder Name : ");
            scanf("%s", nam);
            printf("    Account Balance : ");
            scanf("%f", &bal);

            data.user = CREATE(data.user, type, nam, bal);
            data.user_count++;
        }

        // DELETE
        else if (strcmp(op, op3) == 0) {
            printf("--> DELETING RECORDS:\n");
            int t;
            char n[24];

            printf("    Account Type [ 0: savings, 1: current ] : ");
            scanf("%d", &t);
            printf("    Account Holder Name : ");
            scanf("%s", n);

            data.user = DELETE(data.user, t, n);
            data.user_count--;
        
        }

        // DEPOSIT
        else if (strcmp(op, op4) == 0) {
            printf("--> ADDING MONEY:\n");
            int acc_no;
            float amount;

            printf("    Account Number : ");
            scanf("%d", &acc_no);
            printf("    Amount : ");
            scanf("%f", &amount);

            TRANSACTION(data.user, acc_no, amount, 1);
        }

        // WITHDRAW
        else if (strcmp(op, op5) == 0) {
            printf("--> WITHDRAWING MONEY:\n");
            int num;
            float money;

            printf("    Account Number : ");
            scanf("%d", &num);
            printf("    Amount : ");
            scanf("%f", &money);

            TRANSACTION(data.user, num, money, 0);
        }

        // MIN_BAL
        else if (strcmp(op, op6) == 0) {
            printf("--> BALANCE LIMIT:\n");
            float max_amount;
            printf("    Minimum Balance Limit : ");
            scanf("%f", &max_amount);

            LOWBALANCE(data.user, max_amount);
        }

        // Invalid Input
        else {
            // printf("\n * Ur mom gey! [ Invalid Input ] * \n");
            printf("\n * Task Failed Successfully! [ Invalid Input ] * \n");
        }
    }
    return 0;
}
