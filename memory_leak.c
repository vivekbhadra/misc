#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(int argc, char **argv)
{
    char *mem = (char *) malloc(20);

    memset(mem, 0, 20);

    return 0;
}
