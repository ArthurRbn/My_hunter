/*
** EPITECH PROJECT, 2019
** hunter utils 2
** File description:
** hunter functions
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void handle_event(sfEvent *event, mark *DT, game *partie)
{
    while (sfRenderWindow_pollEvent(DT->window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(DT->window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            manage_mouse_click(event->mouseButton, DT, partie);
        }
    }
}

void basic_event(sfEvent *event, game *partie, mark *DT)
{
    while (sfRenderWindow_pollEvent(DT->window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(DT->window);
        } else if (event->type == sfEvtMouseButtonPressed)
            mouse_restart(partie, event->mouseButton, DT);
    }
}

void mouse_restart(game *partie, sfMouseButtonEvent event, mark *DT)
{
    if (event.x > 230 && event.x < 560 &&
    event.y > 200 && event.y < 330) {
        partie->lives = 3;
        partie->score = 0;
        partie->strk = 0;
        partie->lsk = 0;
        DT->decal.x = 5;
    }
}

void manage_mouse_click(sfMouseButtonEvent event, mark *DT, game *partie)
{
    int posx = sfSprite_getPosition(DT->Bird).x;
    int posy = sfSprite_getPosition(DT->Bird).y;
    int inter = 600 - posy;

    if (event.x > posx && event.x < (posx + 70) && event.y > posy &&
    event.y < (posy + 80)) {
        DT->pos.y += (posy < 300)?rand() % (inter - 100):0;
        DT->pos.y -= (posy > 300)?rand() % posy:0;
        sfSprite_setPosition(DT->Bird, DT->pos);
        partie->score += 1;
        partie->strk += 1;
        DT->decal.x += 1;
    }
}

void manage_mouse_click2(mark *DT)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        DT->h = 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue) {
        DT->h = 0;
    }
}