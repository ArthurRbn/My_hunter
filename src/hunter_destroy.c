/*
** EPITECH PROJECT, 2019
** hunter functions
** File description:
** hunter functions
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void destroy2(mark *DT, game *partie)
{
    sfText_destroy(DT->Text);
    sfText_destroy(DT->score);
    sfText_destroy(DT->streak);
    sfText_destroy(DT->Nstreak);
    sfFont_destroy(DT->font);
    sfRenderWindow_destroy(DT->window);
    free(DT);
    free(partie);
}

void destroy_h(mark *DT, game *partie, restart *rst)
{
    sfSprite_destroy(DT->Bg);
    sfTexture_destroy(DT->bg);
    sfSprite_destroy(DT->Bird);
    sfTexture_destroy(DT->bird);
    sfClock_destroy(DT->clock);
    sfSprite_destroy(DT->Fgris);
    sfTexture_destroy(DT->fgris);
    sfSprite_destroy(partie->Vie);
    sfTexture_destroy(partie->vie);
    sfSprite_destroy(rst->Btn);
    sfTexture_destroy(rst->btn);
    sfFont_destroy(DT->font);
    sfText_destroy(DT->Text);
    sfText_destroy(DT->score);
    sfText_destroy(DT->streak);
    sfText_destroy(DT->Nstreak);
    free(rst);
    free(DT);
    free(partie);
}

void destroy(mark *DT, game *partie, restart *rst)
{
    sfSprite_destroy(DT->Bg);
    sfTexture_destroy(DT->bg);
    sfSprite_destroy(DT->Bird);
    sfTexture_destroy(DT->bird);
    sfClock_destroy(DT->clock);
    sfSprite_destroy(DT->Fgris);
    sfTexture_destroy(DT->fgris);
    sfSprite_destroy(partie->Vie);
    sfTexture_destroy(partie->vie);
    sfSprite_destroy(rst->Btn);
    sfTexture_destroy(rst->btn);
    free(rst);
    destroy2(DT, partie);
}