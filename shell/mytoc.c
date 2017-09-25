#include <stdlib.h>
#include <stdio.h>
#include "mytoc.h"
#include "stdlib.h"

char **mytoc(char *string, char delim)
{

    int length,i,j,k;
    int words = 0;
    int count = 0;

    for(length = 0; string[length] != '\0'; length++);

    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == delim && string[i+1] != delim && string[i+1] != '\0')
        {
            words++;
        }
    }
    if(string[0] != delim)
    {
        words++;
    }

    char * copyToken(char *str, int tokLength)
    {
        char * strCopy = (char *)malloc(tokLength +1);
        int i;
        for(i = 0; i< tokLength; i++)
        {
            strCopy[i] = str[i];
        }

        strCopy[tokLength+1] = '\0';
        return strCopy;

    }

    char **token = (char **)calloc(words + 1, sizeof(char *));

    for(j = 0; string[j] != '\0'; j++)
    {
        token[words] = (char *)malloc(words + 1);

        if(string[j] == delim && string[j+1] != delim && string[j+1] != '\0')
        {
            token[count] = copyToken(string, j);
            count++;
        }
    }


    free(token);
    return token;
}

