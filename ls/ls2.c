/*
 * bugs:    
 * 1.this file's argv can only be this type like 'ls2 /home/', but can not be 'ls2 /home'
 * 2.the format of time is not good         
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include<sys/types.h>
#include<dirent.h> // opendir, readdir, closedir

#include<sys/stat.h>
#include<unistd.h> // stat

#include<pwd.h> // getpwuid()
#include<grp.h> // getgrpid()

void ls(char[]);
void ls_stat(struct stat*, char[]);
char* get_username(uid_t);
char* get_groupname(gid_t);

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        ls("./");
    }
    else
    {
        while(--argc)
        {
            printf("%s\n", * ++argv);
            ls(*argv);
        }
    }
    return 0;
}

void ls(char name[])
{
    DIR* dir;
    struct dirent* dt;
    struct stat sb;
    int path_size = strlen(name);

    if((dir = opendir(name)) == NULL)
    {
        //opendir is worng if name is not a dir
        printf("Error: opendir()");
        perror(name);
        exit(1);
    }
    // opendir success
    // look at the stat
    while((dt = readdir(dir)) != NULL)
    {
        //get the filepath  --->>> stat(filepath, sb)
        int file_size = strlen(dt->d_name);
        int filepath_size = path_size + file_size;
        char filepath[filepath_size];
        strcpy(filepath, name);
        strcat(filepath, dt->d_name);
        //printf("filepath:\t%s\n", filepath);

        char str[] = "----------";
        char* user_name;
        char* group_name;
        //get the sb across stat
        stat(filepath, &sb);

        //get the st_mode of string 
        ls_stat(&sb, str);
        printf("%s ", str);
        
        printf("%ld ", (long)sb.st_nlink);

        //get the user name by sb.st_uid using the function getpwuid(uid_t)
        user_name = get_username((uid_t)sb.st_uid);
        printf("%s ", user_name);

        //get the group name by sb.st_gid using the function getgrpid(gid_t)
        group_name = get_groupname((gid_t)sb.st_gid);
        printf("%s ", group_name);
        
        printf("%lld ", (long long)sb.st_size);
        printf("%s ", 11+ ctime(&sb.st_mtime));
        printf("%s\n", dt->d_name);
    }
}


char* get_groupname(gid_t gid)
{
    struct group* gp;
    if((gp = getgrgid(gid)) == NULL)
    {
        perror("Error: getgrpid()!");
        exit(1);
    }
    return gp->gr_name;
}

char* get_username(uid_t uid)
{
    struct passwd* pw;
    if((pw = getpwuid(uid)) == NULL)
    {
        perror("Error: getpwuid()!");
        exit(1);
    }
    return pw->pw_name;
}


void ls_stat(struct stat* sb, char str[])
{
    
    if(S_ISDIR(sb->st_mode)) str[0] = 'd';
    
    if(S_IRUSR & sb->st_mode) str[1] = 'r';
    if(S_IWUSR & sb->st_mode) str[2] = 'w';
    if(S_IXUSR & sb->st_mode) str[3] = 'x';

    if(S_IRGRP & sb->st_mode) str[4] = 'r';
    if(S_IWGRP & sb->st_mode) str[5] = 'w';
    if(S_IXGRP & sb->st_mode) str[6] = 'x';

    
    if(S_IROTH & sb->st_mode) str[7] = 'r';
    if(S_IWOTH & sb->st_mode) str[8] = 'w';
    if(S_IXOTH & sb->st_mode) str[9] = 'x';
}
