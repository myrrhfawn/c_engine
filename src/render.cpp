#include <render/renderer.h>
#include <iostream>
#include <cstring>
#include <unistd.h>


Renderer::Renderer(char* render_type, int width, int height) {
    // Renderer constructor implementation
    this->render_type = render_type;
    this->screen_width = width;
    this->screen_height = height;
}

void Renderer::render(char* screen) {
    if (strcmp(this->render_type, "write") == 0)
        this->render_with_write(screen);
    else if (strcmp(this->render_type, "cout") == 0)
        this->render_with_cout(screen);
    else
        std::cout << "Invalid render type" << std::endl;
}


void Renderer::render_with_cout(char* screen) {
    // render_with_cout method implementation
    std::cout << "\033[H"; // Move cursor to the top left corner
    for (int j = 0; j < this->screen_height; ++j) {
        for (int i = 0; i < this->screen_width; ++i) {
            std::cout << screen[i + j * this->screen_width];
        }
        std::cout << '\n';
    }
    std::cout.flush(); // Flush the buffer

}

void Renderer::render_with_write(char* screen) {
    // render_with_write method implementation
    write(STDOUT_FILENO, "\033[H", 3); // Clear the screen ANSI escape code
    write(STDOUT_FILENO, screen, this->screen_width * this->screen_height);

}
