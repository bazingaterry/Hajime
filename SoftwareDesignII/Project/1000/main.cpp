#include "Game.h"

int main(int argc, char const *argv[])
{
    printf("Input N: ");
    int N;
    scanf("%d", &N);
    Game game(N);
    game.start();
    return 0;
}
