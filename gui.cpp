#include "raylib.h"

extern void autoclicker(int h, int v);
extern void getDesktopResolution(int &horizontal, int &vertical);
extern void registerHotkey();
extern void hotkeyUpdate(bool &isAutoClicking);

int main()
{
    InitWindow(480, 360, "MuttonAutoClicker");
    float clickTimer = 0.0f;
    const float clickInterval = 0.1f; // seconds
    bool isAutoClicking = false;
    registerHotkey();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press \"ESCAPE\" to close program.", 5, 40, 28, BLACK);
        DrawRectangle(130, 160, 220, 40, BLACK);
        DrawText("Start Autoclicker", 135, 170, 24, WHITE);
        DrawText("By Mutton9558", 135, 300, 24, BLACK);
        EndDrawing();

        if (IsKeyReleased(KEY_ESCAPE))
        {
            CloseWindow();
        }

        hotkeyUpdate(isAutoClicking);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            int x = GetMouseX(), y = GetMouseY();
            if ((x >= 130 && x <= 250) && (y >= 160 && y <= 200))
            {
                isAutoClicking = !isAutoClicking; // toggle
            }
        }

        if (isAutoClicking)
        {
            clickTimer += GetFrameTime();
            if (clickTimer >= clickInterval)
            {
                int h, v;
                getDesktopResolution(h, v);
                autoclicker(h, v);
                clickTimer = 0.0f;
            }
        }
    }
}