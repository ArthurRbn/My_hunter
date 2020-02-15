/*
** EPITECH PROJECT, 2020
** hunter loops
** File description:
** hunter loops
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void routine(mark *DT, game *partie)
{
    move_rect(DT);
    modif_aff(DT, partie);
    sfRenderWindow_drawSprite(DT->window, DT->Bg, NULL);
    sfRenderWindow_drawSprite(DT->window, DT->Bird, NULL);
    sfRenderWindow_drawSprite(DT->window, partie->Vie, NULL);
    sfRenderWindow_display(DT->window);
    sfRenderWindow_clear(DT->window, sfBlack);
}

void game_loop(mark *DT, restart *rst, game *partie)
{
    sfEvent Event;
    while (sfRenderWindow_isOpen(DT->window) && partie->lives > 0) {
        handle_event(&Event, DT, partie);
        routine(DT, partie);
    }
    restart_loop(DT, rst, partie);
}

void restart_loop(mark *DT, restart *rst, game *partie)
{
    sfEvent Event;

    basic_event(&Event, partie, DT);
    prep_scr(DT, partie);
    sfRenderWindow_drawSprite(DT->window, DT->Bg, NULL);
    sfRenderWindow_drawSprite(DT->window, DT->Fgris, NULL);
    sfRenderWindow_drawSprite(DT->window, rst->Btn, NULL);
    sfRenderWindow_drawText(DT->window, DT->Nstreak, NULL);
    sfRenderWindow_drawText(DT->window, DT->streak, NULL);
    sfRenderWindow_drawText(DT->window, DT->Text, NULL);
    sfRenderWindow_drawText(DT->window, DT->score, NULL);
    sfRenderWindow_display(DT->window);
    sfRenderWindow_clear(DT->window, sfBlack);
}

void loop_h(mark *DT)
{
    DT->h = 2;
    while (DT->h == 2) {
        manage_mouse_click2(DT);
    }
}