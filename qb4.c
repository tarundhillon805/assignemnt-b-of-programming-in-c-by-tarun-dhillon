#include <stdio.h>

struct OrdinaryRecord
{
    unsigned int flag1;
    unsigned int flag2;
    unsigned int flag3;
    unsigned int flag4;
};

struct BitFieldRecord
{
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
};

int main()
{
    struct OrdinaryRecord ordinary = {1, 0, 1, 0};
    struct BitFieldRecord bitField = {1, 0, 1, 0};

    printf("Ordinary Structure Values:\n");
    printf("flag1 = %u\n", ordinary.flag1);
    printf("flag2 = %u\n", ordinary.flag2);
    printf("flag3 = %u\n", ordinary.flag3);
    printf("flag4 = %u\n", ordinary.flag4);

    printf("\nBit-Field Structure Values:\n");
    printf("flag1 = %u\n", bitField.flag1);
    printf("flag2 = %u\n", bitField.flag2);
    printf("flag3 = %u\n", bitField.flag3);
    printf("flag4 = %u\n", bitField.flag4);

    printf("\nMemory Comparison:\n");
    printf("Size of ordinary structure = %zu bytes\n",
           sizeof(ordinary));

    printf("Size of bit-field structure = %zu bytes\n",
           sizeof(bitField));

    if (sizeof(bitField) < sizeof(ordinary))
        printf("Bit-field structure uses less memory.\n");
    else
        printf("Memory size may be equal because of compiler padding.\n");

    return 0;
}