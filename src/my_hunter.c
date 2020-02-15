/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my duck hunt like
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void init_base(mark *DT, game *partie, restart *rst)
{
    sfRenderWindow_setFramerateLimit(DT->window, 30);
    sfSprite_setPosition(DT->Bird, DT->pos);
    sfSprite_setPosition(partie->Vie, partie->posvie);
    sfSprite_setColor(DT->Fgris, DT->fond);
    sfSprite_setPosition(rst->Btn, rst->posbtn);
    sfText_setPosition(DT->Text, DT->Vtxt);
    sfText_setPosition(DT->score, DT->Vscr);
    sfText_setPosition(DT->streak, DT->stk);
    sfText_setPosition(DT->Nstreak, DT->Nstk);
}

int main(int ac, char **av)
{
    mark *DT = (mark*) malloc(sizeof(mark));
    game *partie = (game*) malloc(sizeof(game));
    restart *rst = (restart *) malloc(sizeof(restart));

    init_struct(DT, partie, rst);
    if (ac > 1) {
        flag_h(av[1], DT);
    } if (DT->h == 1) {
        init_game(partie, DT);
        if (!DT->bg || !partie->vie || !DT->fgris || !rst->btn)
            return (84);
        init_base(DT, partie, rst);
        while (sfRenderWindow_isOpen(DT->window)) {
            game_loop(DT, rst, partie);
        }
        destroy(DT, partie, rst);
    } else if (DT->h == 0) {
        destroy_h(DT, partie, rst);
    }
    return (0);
}