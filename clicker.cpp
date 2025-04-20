#include <iostream>
#include <windows.h>
#include "wtypes.h"

void getDesktopResolution(int &horizontal, int &vertical)
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    horizontal = desktop.right / 2;
    vertical = desktop.bottom / 2;
}

void autoclicker(int h, int v)
{
    INPUT input[2] = {};

    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SetCursorPos(h, v);
    SendInput(2, input, sizeof(INPUT));
}

void registerHotkey()
{
    RegisterHotKey(NULL, 1, MOD_CONTROL, 0x58);
}

void hotkeyUpdate(bool &isAutoClicking)
{
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_HOTKEY && msg.wParam == 1)
        {
            isAutoClicking = !isAutoClicking; // Toggle the state
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}