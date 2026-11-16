#include <stdio.h>

struct Permission
{
    unsigned int read    : 1;
    unsigned int write   : 1;
    unsigned int execute : 1;
    unsigned int admin   : 1;
};

int main()
{
    struct Permission permission;
    unsigned int input;

    printf("Enter read permission (0 or 1): ");
    if (scanf("%u", &input) != 1 || input > 1)
    {
        printf("Invalid input. Enter only 0 or 1.\n");
        return 0;
    }
    permission.read = input;

    printf("Enter write permission (0 or 1): ");
    if (scanf("%u", &input) != 1 || input > 1)
    {
        printf("Invalid input. Enter only 0 or 1.\n");
        return 0;
    }
    permission.write = input;

    printf("Enter execute permission (0 or 1): ");
    if (scanf("%u", &input) != 1 || input > 1)
    {
        printf("Invalid input. Enter only 0 or 1.\n");
        return 0;
    }
    permission.execute = input;

    printf("Enter admin permission (0 or 1): ");
    if (scanf("%u", &input) != 1 || input > 1)
    {
        printf("Invalid input. Enter only 0 or 1.\n");
        return 0;
    }
    permission.admin = input;

    printf("\nPermissions:\n");

    printf("Read:    %s\n", permission.read ? "Allowed" : "Denied");
    printf("Write:   %s\n", permission.write ? "Allowed" : "Denied");
    printf("Execute: %s\n", permission.execute ? "Allowed" : "Denied");
    printf("Admin:   %s\n", permission.admin ? "Allowed" : "Denied");

    printf("\nPermission format: ");
    printf("%c", permission.read ? 'r' : '-');
    printf("%c", permission.write ? 'w' : '-');
    printf("%c", permission.execute ? 'x' : '-');
    printf("%c\n", permission.admin ? 'a' : '-');

    return 0;
}