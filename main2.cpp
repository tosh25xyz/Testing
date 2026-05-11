#include "raylib.h"

int main()
{
    InitWindow(800, 450, "raylib C++");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Raylib in C++", 220, 200, 30, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}