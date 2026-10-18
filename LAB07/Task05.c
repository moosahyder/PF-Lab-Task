
#include <stdio.h>

int main()
{
    int a[3][3][3];
    int i, j, k;
    int same, equalCount;

    for (i = 0; i < 3; i++)
    {
        printf("Enter elements for Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        printf("\nLayer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            equalCount = 0;
            same = 1;

            for (k = 0; k < 3; k++)
            {
                int l;

                for (l = 0; l < 3; l++)
                {
                    if (a[i][k][l] == a[j][k][l])
                    {
                        equalCount++;
                    }
                    else
                    {
                        same = 0;
                    }
                }
            }

            printf("\nLayer %d and Layer %d:\n",
                   i + 1, j + 1);

            printf("Matching elements: %d out of 9\n",
                   equalCount);

            if (same == 1)
                printf("The layers are identical.\n");
            else
                printf("The layers are different.\n");
        }
    }

    return 0;
}
