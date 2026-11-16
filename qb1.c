#include <stdio.h>

struct Flags
{
    unsigned int isOn : 1;
    unsigned int isReady : 1;
};

int main()
{
    struct Flags flag;

    printf("Enter isOn value (0 or 1): ");
    scanf("%u", flag.isOn);

    printf("Enter isReady value (0 or 1): ");
    scanf("%u", flag.isReady);

    if (flag.isOn > 1 || flag.isReady > 1)
    {
        printf("Invalid input. Enter only 0 or 1.\n");
        return 0;
    }

    printf("\nFlag Values:\n");
    printf("isOn = %u\n", flag.isOn);
    printf("isReady = %u\n", flag.isReady);

    return 0;
}