#include <stdio.h>
#include <unistd.h>

#define ROWS 40
#define COLUMNS 20

typedef struct 
{
    int posx;
    int posy;
    int speedx;
    int speedy;
    char character;
} object;

void screen_clear()
{
    printf("\033[H\033[2J");
}

void object_detection_and_border(object object, int i, int j) // oh god Im bad at making function
{
    if(j == object.posx && i == object.posy)
    {
        printf("%c", object.character);
    }
    else if(j == 0 || j == ROWS - 1 || i == 0 || i == COLUMNS - 1)
    {
        printf("#");
    }
    else
    {
        printf("-");
    }
}

void draw(object object)
{
    screen_clear();

    for(int i = 0; i < COLUMNS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            object_detection_and_border(object, i, j);
        }

        printf("\n");
    }
}

void logic(object *object)
{
    if(object->posx >= ROWS - 2)
    {
        object->posx = ROWS - 2; // if the object goes out of bound
        object->speedx *= -1;
    }
    if(object->posx <= 1)
    {
        object->posx = 1;
        object->speedx *=-1;
    }

    if(object->posy >= COLUMNS - 2)
    {
        object->posy = COLUMNS - 2;
        object->speedy *= -1;
    }
    if(object->posy <= 1)
    {
        object->posy = 1;
        object->speedy *=-1;
    }

    object->posx += object->speedx;
    object->posy += object->speedy;
}

int main()
{
    object ball;
    ball.posx = ROWS / 2;
    ball.posy = COLUMNS / 2;
    ball.speedx = 1;
    ball.speedy = 1;
    ball.character = '@';

    while(1)
    {
        logic(&ball);
        draw(ball);

        sleep(1);
    }

    return 0;
}
