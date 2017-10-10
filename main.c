// Original File by Arup Guha
// 8/17/2015

// Modified by Sarah Angell
// 2/10/2016

#include <stdio.h>

#define MAX_CUSTOMERS 100

int main() {
    // declare variables
    int numCommands, i, accounts[MAX_CUSTOMERS];
    int command, id, amount, j, ok;
    char filename[20];

    FILE *ifp;

    // Open file.
    printf("What is the name of the file?\n");
    scanf("%s", filename);
    /***Open Input File***/
    ifp = fopen(filename, "r");

    // Initialize accounts.
    /***Set all values in accounts to zero***/
    for (int i = 0; i < MAX_CUSTOMERS; i++)
        accounts[i] = 0;

    // Read the number of commands from the file
    fscanf(ifp, "%d", &numCommands);

    // Process each command.
    for (i = 0; i < numCommands; i++) {

        // Get type of this command.
        fscanf(ifp, "%d", &command);

        // Add money.
        if (command == 1) {
            /***Read id and amount from file***/
            fscanf(ifp, "%d %d", &id, &amount);
            // fscanf(ifp, "%d", &amount);
            accounts[id] += amount;
        } else if (command == 2) { // subtract money
            fscanf(ifp, "%d %d", &id, &amount);
            /***Deduct amount from the account with identification number id***/
            accounts[id] -= amount;
        } else {// Print delinquents.
            // Go through each account, flagging negative balances.
            ok = 1;
            for (j = 0; j < MAX_CUSTOMERS; j++) {
                if (accounts[j] < 0) { /***check if jth account is less than zero***/
                    printf("Customer %d, you owe $%d. Please pay immediately!\n", j, -accounts[j]);
                    ok = 0;
                }
            }

            // Best case scenario.
            if (ok)
                printf("All accounts are paid up to date!!!\n");

        }
    }

    /***close file pointer***/
    fclose(ifp);

    return 0;
}
