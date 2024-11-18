#include <window.hpp>
#include <menu.hpp>
#include <conio.h>


class TestMenu: public Menu {
    public:
    TestMenu(Window* window, MenuSettings settings = {}): Menu(window, settings) { }
    void start() override {

    }

    void update() override {
        // Blah blah blah update the buffer

        // Show the buffer to the screen
        display_buffer_to_screen();
    }

    void end() override {}
};

int main() {
    Window window(30, 5);
    TestMenu menu(&window, { .title =  "Test Menu" });

    window.set_menu(&menu);

    char c;

    while (window.is_running())
    {
        window.update();
        c = _getch();

        if(c == 'q')
            window.quit();
    }

    return 0;
}