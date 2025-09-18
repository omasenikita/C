////////////////////////////////////////////////////////////////////////////////////////
//
// File name:   Assignment28_4.c
// Description: Used to open the file in read mode and reading file data
// input:       char(name of the file)
// output:      file data
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
    int fd = 0, iRet = 0, iCount = 0;
    int i = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    char FileName[20] = {'\0'};
    
    // Accepting the file name from user
    printf("Enter the file name that You want to check for file size : \n");
    scanf("%s",FileName);

    //open the file in read mode
    fd = open(FileName,O_RDONLY);
    
    // Ckecking for file is opened successfullly or not
    if(fd == -1)
    {
        printf("Unable to open the file!\n");
        return -1;
    }

    else
    {
        printf("File is successfully opened with fd : %d\n",fd);

        // reading the content form file
        while((iRet = read(fd,Buffer,BUFFER_SIZE))!=0)
        {
            //count the nuber of byets in the file
            for(i =0; i<iRet;i++)
            {
                 iCount++;
            }   
            memset(Buffer,'\0',BUFFER_SIZE);
        }
        printf("Total size of the file is : %d bytes\n",iCount);

    }
    

    return 0;
}