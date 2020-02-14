#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct stat st_mode;

   if (argc != 2) {
        fprintf(stderr, "input path you want to check: \n", argv[0]);
        exit(EXIT_FAILURE);
    }

   if (stat(argv[1], &st_mode) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
   }

   printf("i-node #:          %ld\n", (long) st_mode.st_ino);
   printf("hard-links #:      %ld\n", (long) st_mode.st_nlink);


   exit(EXIT_SUCCESS);
}