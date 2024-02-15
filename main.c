#include <stdio.h>
#include <unistd.h>

#define G_MAX_WIDTH 20
#define G_MAX_HEIGHT 20
#define G_MIN_WIDTH 0
#define G_MIN_HEIGHT 20

typedef struct
{
    int x_position;
    int y_position;
    int x_speed;
    int y_speed;
    char symbol;
}
ball;

void logic(ball *ball, int MAX_WIDTH, int MAX_HEIGHT, int MIN_WIDTH, int MIN_HEIGHT)
{
    if(ball->x_position <= 1)
    {
        ball->x_position = 1;
        ball->x_speed *= -1;
    }
    if(ball->x_position >= 18)
    {
        ball->x_position = 18;
        ball->x_speed *= -1;
    }
    if(ball->y_position <= 1)
    {
        ball->y_position = 1;
        ball->y_speed *= -1;
    }
    if(ball->y_position >= 18)
    {
        ball->y_position = 18;
        ball->y_speed *= -1;
    }

    ball->x_position += ball->x_speed;
    ball->y_position += ball->y_speed;
}

void draw(ball ball)
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(i == 0 || i == 19 || j == 0 || j == 19)
            {
                printf("#");
            }
            else if(i == ball.y_position && j == ball.x_position)
            {
                printf("%c", ball.symbol);
            }
            else
            {
                printf("-");
            }
        }

        printf("\n");
    }
}

int main()
{
    ball ball;
    ball.x_position = 1;
    ball.y_position = 8;
    ball.x_speed = 2;
    ball.y_speed = 1;
    ball.symbol = 'h';

    while(1)
    {
        printf("\033[2J\033[H");

        logic(&ball);
        draw(ball);

        usleep(50000);
    }


    return 0;
}
