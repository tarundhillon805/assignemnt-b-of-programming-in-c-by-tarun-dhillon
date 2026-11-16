#include <stdio.h>

enum State
{
    IDLE,
    COIN_INSERTED,
    DISPENSE,
    OUT_OF_STOCK
};

enum Command
{
    INSERT_COIN = 1,
    SELECT_ITEM,
    REFILL,
    CANCEL,
    EXIT
};

const char *stateName(enum State state)
{
    switch (state)
    {
        case IDLE:
            return "IDLE";

        case COIN_INSERTED:
            return "COIN_INSERTED";

        case DISPENSE:
            return "DISPENSE";

        case OUT_OF_STOCK:
            return "OUT_OF_STOCK";

        default:
            return "UNKNOWN";
    }
}

void stepState(enum State *state, enum Command command, int *stock)
{
    switch (*state)
    {
        case IDLE:
            if (command == INSERT_COIN)
            {
                *state = COIN_INSERTED;
                printf("Coin inserted successfully.\n");
            }
            else
            {
                printf("Please insert a coin first.\n");
            }
            break;

        case COIN_INSERTED:
            if (command == SELECT_ITEM)
            {
                if (*stock > 0)
                {
                    *state = DISPENSE;
                    printf("Item selected.\n");
                    printf("Item dispensed successfully.\n");

                    (*stock)--;
                    *state = (*stock == 0) ? OUT_OF_STOCK : IDLE;
                }
                else
                {
                    *state = OUT_OF_STOCK;
                    printf("Item is out of stock.\n");
                }
            }
            else if (command == CANCEL)
            {
                *state = IDLE;
                printf("Transaction cancelled. Coin returned.\n");
            }
            else
            {
                printf("Please select an item or cancel.\n");
            }
            break;

        case DISPENSE:
            printf("Dispensing item...\n");
            *state = (*stock == 0) ? OUT_OF_STOCK : IDLE;
            break;

        case OUT_OF_STOCK:
            if (command == REFILL)
            {
                *stock = 5;
                *state = IDLE;
                printf("Machine refilled successfully.\n");
            }
            else
            {
                printf("Machine is out of stock. Please refill.\n");
            }
            break;
    }
}

int main()
{
    enum State state = IDLE;
    enum Command command;
    int stock = 5;

    printf("Vending Machine Started\n");

    do
    {
        printf("\nCurrent State: %s\n", stateName(state));
        printf("Stock: %d\n", stock);

        printf("\nCommands:\n");
        printf("1. Insert Coin\n");
        printf("2. Select Item\n");
        printf("3. Refill\n");
        printf("4. Cancel\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", (int *)&command);

        if (command == EXIT)
        {
            printf("Vending machine stopped.\n");
            break;
        }

        if (command < INSERT_COIN || command > CANCEL)
        {
            printf("Invalid command.\n");
            continue;
        }

        stepState(&state, command, &stock);

    } while (command != EXIT);

    return 0;
}