#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char **newargs;

    /* form our new arguments */
    newargs = alloca((argc + 2) * sizeof(char*));
    memcpy(newargs + 1, argv, (argc + 1) * sizeof(char*));
    newargs[0] = "/usr/bin/microcosm"; /* FIXME */

    /* then call */
    execv(newargs[0], newargs);
    fprintf(stderr, "Failed to call %s\n", newargs[0]);
    return 0;
}