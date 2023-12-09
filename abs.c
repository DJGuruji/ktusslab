#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

    FILE *fp1, *fp2;
    int i, j, hexaddr;
    char ch, line[50], addr[10];
    fp1 = fopen("./inputt.txt", "r");
    while (!feof(fp1))
    {

        fscanf(fp1, "%s", line);
        if (line[0] == 'T')
        {

            for (i = 1, j = 0; i <= 6; i++, j++)
            {

                addr[j] = line[i];
            }
            addr[j] = '\0';
            hexaddr = strtol(addr, NULL, 16);
            fp2 = fopen("samp.txt", "w");
            i = 9;
            while (line[i] != '\0')
            {

                printf("00%04x\t%c%c\n", hexaddr, line[i], line[i + 1]);
                fprintf(fp2, "00%04x\t%c%c\n", hexaddr, line[i], line[i + 1]);

                hexaddr = hexaddr + 1;
                i = i + 2;
            }
        }

    } 
    fclose(fp1);
}
