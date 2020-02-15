/*
** EPITECH PROJECT, 2019
** utils
** File description:
** hunter utis
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void init_struct4(mark *DT)
{
    DT->stk.x = 100;
    DT->stk.y = 120;
    DT->streak = sfText_create();
    DT->Nstk.x = 275;
    DT->Nstk.y = 120;
    DT->Nstreak = sfText_create();
    sfText_setFont(DT->streak, DT->font);
    sfText_setFont(DT->Nstreak, DT->font);
    sfText_setCharacterSize(DT->streak, 20);
    sfText_setCharacterSize(DT->Nstreak, 20);
    sfText_setString(DT->streak, "Plus grande serie :");
}

void init_struct3(game *partie, restart *rst, mark *DT)
{
    DT->Vscr.x = 170;
    DT->Vscr.y = 100;
    DT->score = sfText_create();
    sfText_setFont(DT->score, DT->font);
    sfText_setCharacterSize(DT->score, 20);
    partie->Rpv.left = 0;
    partie->Rpv.top = 0;
    partie->Rpv.height = 60;
    partie->Rpv.width = 180;
    partie->posvie.x = 5;
    partie->posvie.y = 530;
    partie->vie = sfTexture_createFromFile("ressources/vies.png", NULL);
    partie->Vie = sfSprite_create();
    sfSprite_setTexture(partie->Vie, partie->vie, sfTrue);
    rst->posbtn.x = 230;
    rst->posbtn.y = 200;
    rst->btn = sfTexture_createFromFile("ressources/restart.png", NULL);
    rst->Btn = sfSprite_create();
    sfSprite_setTexture(rst->Btn, rst->btn, sfTrue);
    init_struct4(DT);
}

void init_struct2(mark *DT, game *partie, restart *rst)
{
    DT->Rsp.left = 0;
    DT->Rsp.top = 0;
    DT->Rsp.width = 110;
    DT->Rsp.height = 110;
    DT->clock = sfClock_create();
    DT->pos.x = -100;
    DT->pos.y = 100;
    DT->decal.x = 5;
    DT->decal.y = 0;
    DT->fgris = sfTexture_createFromFile("ressources/fond_gris.jpg", NULL);
    DT->Fgris = sfSprite_create();
    sfSprite_setTexture(DT->Fgris, DT->fgris, sfTrue);
    DT->fond.r = 192;
    DT->fond.g = 192;
    DT->fond.b = 192;
    DT->fond.a = 200;
    DT->h = 1;
    init_struct3(partie, rst, DT);
}

void init_struct(mark *DT, game *partie, restart *rst)
{
    DT->video_mode.width = 800;
    DT->video_mode.height = 600;
    DT->video_mode.bitsPerPixel = 32;
    DT->Vtxt.x = 100;
    DT->Vtxt.y = 100;
    DT->font = sfFont_createFromFile("ressources/police.ttf");
    DT->Text = sfText_create();
    sfText_setString(DT->Text, "Score : ");
    sfText_setFont(DT->Text, DT->font);
    sfText_setCharacterSize(DT->Text, 20);
    DT->bg = sfTexture_createFromFile("ressources/background2.png", NULL);
    DT->Bg = sfSprite_create();
    sfSprite_setTexture(DT->Bg, DT->bg, sfTrue);
    DT->bird = sfTexture_createFromFile("ressources/fly.png", NULL);
    DT->Bird = sfSprite_create();
    sfSprite_setTexture(DT->Bird, DT->bird, sfTrue);
    DT->scale.x = 0.6;
    DT->scale.y = 0.6;
    sfSprite_setScale(DT->Bird, DT->scale);
    init_struct2(DT, partie, rst);
}

void init_game(game *partie, mark *DT)
{
    partie->lives = 3;
    partie->score = 0;
    partie->strk = 0;
    partie->lsk = 0;
    DT->window = sfRenderWindow_create(DT->video_mode,
    "My_Hunter", sfDefaultStyle, NULL);
}
