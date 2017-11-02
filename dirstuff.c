#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR * d; 
    d = opendir(".");
    struct dirent * entry;
    entry = readdir(d);

    printf("Directories:\n");
    while (entry != NULL) {
        if (entry -> d_type == DT_DIR) {
            printf("\t%s\n", entry -> d_name);
        }
        entry = readdir(d);
    }

    int total = 0;
    struct stat sb;

    printf("Files:\n");
    d = opendir(".");
    entry = readdir(d);
    while (entry != NULL) {
        if (entry -> d_type == DT_REG) {
            stat(entry -> d_name, &sb);
            total += sb.st_size;
            printf("\t%s\n", entry -> d_name);
        }
        entry = readdir(d);
    }
    printf("Total size of regular files is: %d\n", total);
    return 0;
}