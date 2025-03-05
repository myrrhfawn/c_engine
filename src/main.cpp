#include <iostream>
#include <chrono>
#include <thread>
#include "engine.h"
#include <unistd.h>
#include <functional>
#include <math.h>
#include <cstring>
#include <render/renderer.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
 
const float aspectRatio = SCREEN_WIDTH / SCREEN_HEIGHT;
const float pixelAspectRatio = 10.0f / 19.0f;
const char pixel = ' ';

char* grandient = " .:!/r(l1Z4H9W8$@";
int grandient_len = strlen(grandient);


char get_circle_char(float x, float y) {
    if (x * x + y * y < 0.50f)
        return '@';
    else
        return ' ';
}

char get_border(float x, float y) {
    float x_right = (2.0f - 1.0f) * aspectRatio * pixelAspectRatio;
    float y_bottom = (2.0f - 1.0f);
    float x_left = (- 1.0f) * aspectRatio * pixelAspectRatio;
    float y_top = (- 1.0f);

    if (x == x_right || x == x_left || y == y_top || y == y_bottom)
        return '@';
    else
        return ' ';
}



int main() {
    char* screen = new char[SCREEN_WIDTH * SCREEN_HEIGHT + 1];
    screen[SCREEN_WIDTH * SCREEN_HEIGHT] = '\0';
    void (*render)(char*) = nullptr;

    Renderer renderer("write", SCREEN_WIDTH, SCREEN_HEIGHT);


    for (int t = 0; t < 100000; t++) {
        // std::cout << "\x1B[2J\x1B[H";               //clear screen
        // std::cout << screen;
        // cout_render(screen);
        
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            for (int j = 0; j < SCREEN_HEIGHT; j++) {
                float x = (float)i / (SCREEN_WIDTH - 1) * 2.0f - 1.0f;
                float y = (float)j / (SCREEN_HEIGHT - 1) * 2.0f - 1.0f;
                x *= aspectRatio * pixelAspectRatio;
                x += sin(t * 0.00001f);
                screen[i + j * SCREEN_WIDTH] = get_circle_char(x, y);
                // screen[i + j * SCREEN_WIDTH] = get_border(x, y);
            }
        }
        renderer.render(screen);

        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    int i;
    std::cin >> i;
    
    delete[] screen;
    return 0;
}