#include <stdio.h>

enum Operation
{
    ADD = 1,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    EXIT
};

int main()
{
    enum Operation choice;
    double num1, num2, result;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. ADD\n");
        printf("2. SUBTRACT\n");
        printf("3. MULTIPLY\n");
        printf("4. DIVIDE\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", (int *)&choice);

        if (choice == EXIT)
        {
            printf("Program ended.\n");
            break;
        }

        if (choice < ADD || choice > DIVIDE)
        {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (choice)
        {
            case ADD:
                result = num1 + num2;
                printf("Result = %.2lf\n", result);
                break;

            case SUBTRACT:
                result = num1 - num2;
                printf("Result = %.2lf\n", result);
                break;

            case MULTIPLY:
                result = num1 * num2;
                printf("Result = %.2lf\n", result);
                break;

            case DIVIDE:
                if (num2 == 0)
                {
                    printf("Error: Division by zero is not allowed.\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result = %.2lf\n", result);
                }
                break;
        }

    } while (choice != EXIT);

    return 0;
}