/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>
#include "struct.h"

void move_rect(mark *DT);
void destroy(mark *DT, game *partie, restart *rst);
void routine(mark *DT, game *partie);
void modif_aff(mark *DT, game *partie);
void init_struct(mark *DT, game *partie, restart *rst);
void init_struct2(mark *DT, game *partie, restart *rst);
void manage_mouse_click(sfMouseButtonEvent event, mark *DT, game *partie);
void handle_event(sfEvent *event, mark *DT, game *partie);
void basic_event(sfEvent *event, game *partie, mark *DT);
void init_game(game *partie, mark *DT);
void init_base(mark *DT, game *partie, restart *rst);
void game_loop(mark *DT, restart *rst, game *partie);
void restart_loop(mark *DT, restart *rst, game *partie);
void mouse_restart(game *partie, sfMouseButtonEvent event, mark *DT);
int flag_h(char *src, mark *DT);
void my_putstr(char const *str);
void my_putchar(char c);
int aff_h(int fd);
void loop_h(mark *DT);
void manage_mouse_click2(mark *DT);
char *nbr_str(int nb);
void init_struct4(mark *DT);
void prep_scr(mark *DT, game *partie);
void prep_stk(mark *DT, game *partie);
void destroy2(mark *DT, game *partie);
void destroy_h(mark *DT, game *partie, restart *rst);

#endif //MY_H
