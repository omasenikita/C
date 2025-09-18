////////////////////////////////////////////////////////////////////////////////////////
//
// File name:   Assignment28_1.c
// Description: Used to opening the exiting file in read mode
// input:       char(name of the file)
// output:      open the file
// Author :     Nikita Shahaji Omase
// Date :       12/08/2025
//
////////////////////////////////////////////////////////////////////////////////////////  


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char FileName[80] = {'\0'};
    int fd = 0;

    //Accepting the name of file from user
    printf("Enter a file name that you want to open:\n");
    scanf("%s", FileName);

    //opened file in read mode
    fd = open(FileName, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file\n");
        return 1;
    }

    printf("File '%s' opened successfully with file descriptor: %d\n", FileName, fd);

    // Close the file descriptor
    close(fd);
    printf("File descriptor %d closed successfully.\n", fd);

    return 0;

}