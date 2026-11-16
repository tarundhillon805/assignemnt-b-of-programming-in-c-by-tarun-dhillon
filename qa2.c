#include <stdio.h>

enum Result
{
    FAIL,
    PASS,
    DISTINCTION
};

enum Result getResult(float average)
{
    if (average >= 75)
        return DISTINCTION;
    else if (average >= 40)
        return PASS;
    else
        return FAIL;
}

int main()
{
    float average;
    enum Result result;

    printf("Enter the average marks: ");
    scanf("%f", &average);

    result = getResult(average);

    switch (result)
    {
        case DISTINCTION:
            printf("Result: DISTINCTION\n");
            break;

        case PASS:
            printf("Result: PASS\n");
            break;

        case FAIL:
            printf("Result: FAIL\n");
            break;
    }

    return 0;
}