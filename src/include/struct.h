/*
** EPITECH PROJECT, 2020
** structures
** File description:
** structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>

typedef struct mark mark;
struct mark
{
    sfVector2f Vtxt;
    sfText *Text;
    sfFont *font;
    sfVector2f Vscr;
    sfText *score;
    char *scr;
    sfVector2f stk;
    sfText *streak;
    sfVector2f Nstk;
    sfText *Nstreak;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *Bg;
    sfTexture *bg;
    sfSprite *Bird;
    sfTexture *bird;
    sfVector2f scale;
    sfIntRect Rsp;
    sfClock *clock;
    sfTime time;
    sfVector2f pos;
    sfVector2f decal;
    sfSprite *Fgris;
    sfTexture *fgris;
    sfVector2f posgris;
    sfColor fond;
    sfEvent *Event;
    int h;
};

typedef struct game game;
struct game
{
    int lives;
    int score;
    int strk;
    int lsk;
    sfSprite *Vie;
    sfTexture *vie;
    sfIntRect Rpv;
    sfVector2f posvie;
};

typedef struct restart restart;
struct restart
{
    sfSprite *Btn;
    sfTexture *btn;
    sfVector2f posbtn;
};

#endif /* !STRUCT_H_ */