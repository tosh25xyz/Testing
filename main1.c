#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    Music music;

    InitWindow(screenWidth, screenHeight, "Pokemon Style Character - raylib (C)");
    SetTargetFPS(140);

    // Load texture
    Texture2D texture = LoadTexture("player.png");
    InitAudioDevice();
    music=LoadMusicStream("poke.mp3");
    int frameWidth = texture.width / 4;
    int frameHeight = texture.height / 4;

    Rectangle frameRec = { 0, 0, frameWidth, frameHeight };
    Vector2 position = { 400, 300 };

    int currentFrame = 0;
    int currentRow = 0; // 0=down,1=left,2=right,3=up

    float frameTime = 0.0f;
    float frameSpeed = 0.15f;
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        // Movement + direction
        if (IsKeyDown(KEY_RIGHT))
        {
            position.x += 2;
            currentRow = 3;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            position.x -= 2;
            currentRow = 2;
        }
        else if (IsKeyDown(KEY_UP))
        {
            position.y -= 1;
            currentRow = 1;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            position.y += 2;
            currentRow = 0;
        }

        // Animation timing
        frameTime += GetFrameTime();
        if (frameTime >= frameSpeed)
        {
            frameTime = 0.0f;
            currentFrame++;
            if (currentFrame > 3) currentFrame = 0;
        }
        //dadakajfhkfj

        // Update frame rectangle
        frameRec.x = currentFrame * frameWidth;
        frameRec.y = currentRow * frameHeight;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextureRec(texture, frameRec, position, WHITE);

        EndDrawing();
        DrawFPS(10,10);
    }
    UnloadMusicStream(music);
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}