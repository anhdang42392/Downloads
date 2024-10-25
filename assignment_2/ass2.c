#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <time.h>
int main()
{
    DIR *dirp;
    struct dirent *entry;
    struct stat fileInformation;

    char pathfile[100] = "/home/anhdang/Downloads/assignment_2/";

    dirp = opendir(pathfile);
    if (dirp == NULL)
    {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dirp)) != NULL)
    {
        if ((!strcmp(entry->d_name, ".")) || (!strcmp(entry->d_name, "..")) || entry->d_type == 4)
        {
            printf("name file %-30s\n", entry->d_name);
        }
        else
        {
            char filePath[sizeof(pathfile)];
            strcpy(filePath, pathfile);
            strcat(filePath, entry->d_name);

            if (stat(filePath, &fileInformation) == 0)
            {
                printf("File: %s\n", filePath);
                printf("Size: %ld bytes\n", fileInformation.st_size);
                printf("Last modified: %s", ctime(&fileInformation.st_mtime));
                // ... other information from st
            }
            else
            {
                perror("stat");
            }
        }
    }

    closedir(dirp);

    return 0;
}