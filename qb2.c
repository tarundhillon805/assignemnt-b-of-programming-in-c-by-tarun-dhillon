#include <stdio.h>

struct DeviceStatus
{
    unsigned int power  : 1;  // 0 or 1
    unsigned int mode   : 2;  // 0 to 3
    unsigned int error  : 1;  // 0 or 1
    unsigned int battery : 4; // 0 to 15
};

int main()
{
    struct DeviceStatus device;

    unsigned int power, mode, error, battery;

    printf("Enter power status (0 or 1): ");
    scanf("%u", &power);

    printf("Enter mode (0 to 3): ");
    scanf("%u", &mode);

    printf("Enter error status (0 or 1): ");
    scanf("%u", &error);

    printf("Enter battery level (0 to 15): ");
    scanf("%u", &battery);

    if (power > 1)
    {
        printf("Invalid power value.\n");
        return 0;
    }

    if (mode > 3)
    {
        printf("Invalid mode value. Mode must be from 0 to 3.\n");
        return 0;
    }

    if (error > 1)
    {
        printf("Invalid error value.\n");
        return 0;
    }

    if (battery > 15)
    {
        printf("Invalid battery value. Battery must be from 0 to 15.\n");
        return 0;
    }

    device.power = power;
    device.mode = mode;
    device.error = error;
    device.battery = battery;

    printf("\nDevice Status:\n");
    printf("Power   = %u\n", device.power);
    printf("Mode    = %u\n", device.mode);
    printf("Error   = %u\n", device.error);
    printf("Battery = %u\n", device.battery);

    printf("\nTotal bits used = 8 bits\n");

    return 0;
}