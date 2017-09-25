#include <stdio.h>
#include "mytoc.h"
#include <string.h>		/* for strlen */
#include <unistd.h>		/* for read, write */

#define INBUFLEN 1000


main(int argc, char**argv, char**envp)
{

    printf("$");



    ssize_t amtRead;		/* size_t is some sort of integer */
    char buf[INBUFLEN];
    while ((amtRead = read(0, buf, (size_t)INBUFLEN)) > 0) {
	int i;
	for (i = 0; i < amtRead; i++) {

	    char s[20];
	    char ** buff = mytoc(buf,' ');
	    sprintf(s, "[%d]:<%c>\n$", i, buff[i]);
	    write(1, s, strlen(s));
	}
    }
}


