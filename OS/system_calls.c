/*
 *            Author : Shannu
 *            Topic: System Calls --- Open Read Write and Close
 *            Date   : 14 - March - 2025
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fcntl.h>
#include<unistd.h>


int main() {
    int fd1, fd2;
    char buffer[1024];
    ssize_t bytespread, byteswritten;

    fd1 = open("file1.txt", _O_RDONLY);
    
    if(fd1 < 0){
        perror("error opening the file");
        exit(1);
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);
    if(fd2 < 0){
        perror("error opening the file");
        exit(1);
    }
    
    while ((bytespread = read(fd1, buffer, sizeof(buffer))) > 0){
        byteswritten = write(fd2, buffer, (ssize_t)bytespread);
        if(byteswritten != bytespread){
            perror("error writing to the file");
            exit(1);
        }
    }
    if(bytespread < 0){
        perror("error reading from the file");
        exit(1);
    }
    close(fd1);
    close(fd2);
    printf("file copied succesfully\n");
    

    
    return 0;
}