#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir("C:\\Users\\Cool\\Desktop");
    if(dir == NULL){
        perror("Error opening the directory: ");
        exit(1);
    }
    while ((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}