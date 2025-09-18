////////////////////////////////////////////////////////////////////////////////////////
//
// File name:   Assignment28_5.c
// Description: Used to open the file to write
// input:       char(name of the file) ,char(Data)
// output:      Content add into the file
// Author :     Nikita Shahaji Omase
// Date :       12/08/2025
//
////////////////////////////////////////////////////////////////////////////////////////  


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

// Defining macros
#define BUFFER_SIZE 1024

int main()
{
    int fd = 0, iRet = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    char FileName[20] = {'\0'};
    char Data[50] = {'\0'};
    
    // Accepting the file name from user
    printf("Enter the file name that You want to check for file size : \n");
    scanf("%s",FileName);

    //open the file in read mode
    fd = open(FileName,O_CREAT | O_WRONLY| O_APPEND);
    
    // Ckecking for file is opened successfullly or not
    if(fd == -1)
    {
        printf("Unable to open the file!\n");
        return -1;
    }

    else
    {
        printf("File is successfully opened with fd : %d\n",fd);
        printf("Enter the string u wnat to enter:\n");
        scanf("%s",Data);
        if (iRet = write(fd,Data,strlen(Data)))
        {
            printf("Succesfully data written in to the file\n");
        }
        else
        {
            printf("Unable to write into the file");

        }

        close(fd);
    }
    

    return 0;
}