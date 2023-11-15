#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

void listDir(char *dir, int show_hidden, int show_details, int recursive);

int main(int argc, char **argv)
{
    char *dir = ".";
    int show_hidden = 0;
    int show_details = 0;
    int recursive = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0) {
            show_hidden = 1;
        } else if (strcmp(argv[i], "-l") == 0) {
            show_details = 1;
        } else if (strcmp(argv[i], "-R") == 0) {
            recursive = 1;
        } else {
            dir = argv[i];
        }
    }

    listDir(dir, show_hidden, show_details, recursive);

    return 0;
}

void listDir(char *dir, int show_hidden, int show_details, int recursive)
{
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(EXIT_FAILURE);
    }

    while ((d = readdir(dp)) != NULL) {
        if (!show_hidden && d->d_name[0] == '.') {
            continue;
        }

        sprintf(path, "%s/%s", dir, d->d_name);

        if (lstat(path, &st) < 0) {
            perror(path);
        } else {
            if (show_details) {
                printStat(path, d->d_name, &st);
            } else {
                printf("%s\n", d->d_name);
            }

            if (recursive && S_ISDIR(st.st_mode) && strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0) {
                printf("\n%s:\n", path);
                listDir(path, show_hidden, show_details, recursive);
            }
        }
    }

    closedir(dp);
}

void printStat(char *pathname, char *file, struct stat *st)
 {
     printf("%5d ", st->st_blocks);
     printf("%c%s ", type(st->st_mode), perm(st->st_mode));
     printf("%3d ", st->st_nlink);
     printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
     printf("%9d ", st->st_size);
     printf("%.12s ", ctime(&st->st_mtime)+4);
     printf("%s\n", file);
}
 char type(mode_t mode) 
 {
     if (S_ISREG(mode))
         return('-');
     if (S_ISDIR(mode))
         return('d');
     if (S_ISCHR(mode))
         return('c');
     if (S_ISBLK(mode))
         return('b');
     if (S_ISLNK(mode))
         return('l');
     if (S_ISFIFO(mode))
         return('p');
     if (S_ISSOCK(mode))
        return('s');
}
char* perm(mode_t mode) 
{
     static char perms[10];
     strcpy(perms, "---------");
 
     for (int i=0; i < 3; i++) {
         if (mode & (S_IRUSR >> i*3))
             perms[i*3] = 'r';
         if (mode & (S_IWUSR >> i*3))
            perms[i*3+1] = 'w';
         if (mode & (S_IXUSR >> i*3))
            perms[i*3+2] = 'x';
	}
    return(perms);
}

