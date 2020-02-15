/*
** EPITECH PROJECT, 2019
** hunter utils 3
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/struct.h"

int flag_h(char *src, mark *DT)
{
    int fd = open("ressources/README", O_RDONLY);
    char flag[2] = "-h";
    int i = 0;

    for (i = 0; flag[i] != '\0' && flag[i] == src[i]; ++i);
    if (i == 2) {
        i = aff_h(fd);
        loop_h(DT);
    } else if (i == 84) {
        return (84);
    }
    return (0);
}

int aff_h(int fd)
{
    struct stat *des = malloc(sizeof(struct stat));
    int size;
    char *txt;

    if (fd == -1)
        return (84);
    stat("ressources/README", des);
    size = des->st_size;
    txt = malloc(sizeof(char) * (size + 1));
    read(fd, txt, size);
    txt[size] = 0;
    close(fd);
    free(des);
    my_putstr(txt);
    free(txt);
    return (0);
}