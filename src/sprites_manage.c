/*
** EPITECH PROJECT, 2020
** managing sprites
** File description:
** managing sprites
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void move_rect(mark *DT)
{
    float sec = 0;

    DT->time = sfClock_getElapsedTime(DT->clock);
    sec = DT->time.microseconds / 1000000.0;

    if (sec > 0.1) {
        DT->Rsp.left += 110;
        if (DT->Rsp.left >= 330)
            DT->Rsp.left = 0;
        sfClock_restart(DT->clock);
    }
    sfSprite_setTextureRect(DT->Bird, DT->Rsp);
}

void modif_aff(mark *DT, game *partie)
{
    int posy = sfSprite_getPosition(DT->Bird).y;
    int inter = 600 - posy;

    if (sfSprite_getPosition(DT->Bird).x > 800) {
        --partie->lives;
        DT->pos.y += (posy < 300)?rand() % (inter - 100):0;
        DT->pos.y -= (posy > 300)?rand() % posy:0;
        DT->decal.x += 1;
        sfSprite_setPosition(DT->Bird, DT->pos);
        partie->lsk = (partie->lsk <= partie->strk)?partie->strk:partie->lsk;
        partie->strk = 0;
    }
    partie->Rpv.width = partie->lives * 60;
    sfSprite_setTextureRect(partie->Vie, partie->Rpv);
    sfSprite_move(DT->Bird, DT->decal);
}

void prep_stk(mark *DT, game *partie)
{
    if (partie->lsk > 0) {
        DT->scr = nbr_str(partie->lsk);
        sfText_setString(DT->Nstreak, DT->scr);
        free(DT->scr);
    } else if (partie->lsk == 0)
        sfText_setString(DT->Nstreak, "0");
}

void prep_scr(mark *DT, game *partie)
{
    if (partie->score > 0) {
        DT->scr = nbr_str(partie->score);
        sfText_setString(DT->score, DT->scr);
        free(DT->scr);
    } else if (partie->score == 0)
        sfText_setString(DT->score, "0");
    prep_stk(DT, partie);
}