/*
 * > File Name: xuemei.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月18日 星期日 21时21分28秒
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <linux/limits.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

char *name[100];

int my_readir_not_a(const char *path)
{
    DIR *dir;
    struct dirent *ptr;
    int i = 0;
    if((dir = opendir(path)) == NULL)
    {
        perror("opendir");
        return -1;
    }

    while((ptr = readdir(dir)) != NULL&&i < 99)
    {
        name[i] = ptr -> d_name;
        i++;
    }

    closedir(dir);
    return i; //count
}
/*
void bubble_sort_simple(int len)
{
    int i,j;
    char temp[50]={0};
    for(i = 0; i < len; i++)
        for(j = 0; j < len - i - 1; j++)
        {
            if(strcmp(name[j],name[j + 1]) > 0)
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
                for(i = 0; i < 50; i++)
                    temp[i] = '\0';
            }
        }
    
}
*/
void print_simple(int len)
{
    int i;
    printf("sum is %d\n",len);
    for(i = 0; i < len; i++)
    {
        printf("%-s\t\t\t",name[i]);
        if((i+1)%5 == 0)
        printf("\n");
    }
    printf("\n");
    return;
}

int main(int argc, char **argv)
{
        int i;

        char path[100];

        getcwd(path, 512);
        
        i =  my_readir_not_a(path);

        //bubble_sort_simple(i);

        print_simple(i);  
}

