#include<stdio.h>
#include<unistd.h>
int main() {

    printf("First : Print to stdout\n");


    // Print second message to redirect_out.txt
    FILE *fptr;
    fptr = fopen("redirect_out.txt", "w+");
    
    // if file does not exist, create it
    if (fptr == NULL) freopen("redirect_out.txt", "w+", fptr);
    int fo = dup(1);
    int fr = fileno(fptr); // Cast file pointer to int file descriptor
    close(1);
    int f1 = dup(fr);

    printf("Second : Print to redirect_out.txt\n");


    // Close file, restore stdout and print 3rd message
    close(1);
    f1 = dup(fo);

    printf("Third : Print to stdout\n");

    return 1;

}