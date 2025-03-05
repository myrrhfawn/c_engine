class Renderer {
    public:
        Renderer(char* render_type, int width, int height);
        ~Renderer() {};
        void render(char* screen);
    private:
        void render_with_cout(char* screen);
        void render_with_write(char* screen);
        char* render_type;
        int screen_width;
        int screen_height;

};