////////////////////////////////////////////////////////////////////////////////////////
//
// File name:   Assignment28_2.c
// Description: Used to creating the new file
// input:       char(name of the file)
// output:      new file gets created
// Author :     Nikita Shahaji Omase
// Date :       12/08/2025
//
////////////////////////////////////////////////////////////////////////////////////////  


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char FileName[20] = {'\0'};
    int fd = 0;
    
    //Accepting the filename as an input from user
    printf("Enter a file name that you want to create :\n");
    fgets(FileName,sizeof(FileName),stdin);

    // creating a file with all permissions
    fd = creat(FileName,0777);

    // checking for file is create or not
    if(fd == -1)
    {
        printf("Unable to create a file\n");
        return -1;
    }
    else
    {
        printf("File is sucessfully created with fd (File descriptor): %d\n",fd);
    }

    //close the file(releasing the resorces)
    close(fd);


    
    return 0;
}