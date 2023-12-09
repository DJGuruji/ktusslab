#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < n; i++)
    {
        thm += abs(rq[i] - initial);
        initial = rq[i];
    }
    printf("total head movement:%d\n", thm);
}
