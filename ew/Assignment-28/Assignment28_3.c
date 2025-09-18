////////////////////////////////////////////////////////////////////////////////////////
//
// File name:   Assignment28_3.c
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

//defining the user defined macro
# define BUFFER_SIZE 1024 

int main()
{
    char FileName[20] = {'\0'};
    int fd = 0;
    int iRet = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};

    // Accepting the file name from user
    printf("Enter the file name you want to open for reading\n");
    scanf("%s",FileName);

    // open file in read mode

    fd = open(FileName,O_RDONLY);

    //checking for file successfully created or not
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    else
    {
      
        printf("File is successfully open with fd :%d\n",fd);
        
        // reading the content from the file with BUFFER_SIZE
        while((iRet = read(fd,Buffer,BUFFER_SIZE))!=0)
        {
            //Writing it to the console
            write(1,Buffer,iRet);
            memset(Buffer,'\0',BUFFER_SIZE);
        }

        printf("\n");
        close(fd);

    }

    return 0;
}