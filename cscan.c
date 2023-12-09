#include <stdio.h>

void bt(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter number of requests:\t");
    scanf("%d", &n);
    int initial;
    printf("Enter initial head position: \t");
    scanf("%d", &initial);
    int size;
    printf("Enter total disc size\t");
    scanf("%d", &size);
    int rq[n];
    printf("Enter request");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &rq[i]);
    }
    int thm = 0;

    bt(rq, n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (rq[i] >= initial)
        {
            index = i;
            break;
        }
    }

    thm = size - 1 - initial + rq[index - 1];

    printf("thm : %d\n", thm);
}
