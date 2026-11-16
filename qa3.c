#include <stdio.h>

enum DataType
{
    VALUE,
    FLOAT_VALUE,
    CHAR_VALUE
};

union Data
{
    int integerValue;
    float floatValue;
    char charValue;
};

struct TaggedData
{
    enum DataType type;
    union Data data;
};

int main()
{
    struct TaggedData item;
    int choice;

    printf("Choose the data type:\n");
    printf("1. Integer\n");
    printf("2. Float\n");
    printf("3. Character\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        item.type = VALUE;

        printf("Enter an integer: ");
        scanf("%d", &item.data.integerValue);

        printf("Stored integer: %d\n", item.data.integerValue);
    }
    else if (choice == 2)
    {
        item.type = FLOAT_VALUE;

        printf("Enter a float value: ");
        scanf("%f", &item.data.floatValue);

        printf("Stored float: %.2f\n", item.data.floatValue);
    }
    else if (choice == 3)
    {
        item.type = CHAR_VALUE;

        printf("Enter a character: ");
        scanf(" %c", &item.data.charValue);

        printf("Stored character: %c\n", item.data.charValue);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}