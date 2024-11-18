#include <window.hpp>
#include <menu.hpp>
#include <conio.h>
#include <draw.hpp>

class TestMenu: public Menu {
    public:
    TestMenu(Window* window, MenuSettings settings = {}): Menu(window, settings) { }
    void start() override {

    }

    void update() override {
        // Blah blah blah update the buffer
        Draw::empty_checkbox(this, 2, 1);
        Draw::filled_checkbox(this, 2, 3);
        Draw::text(this, 1, 5, "Normal Text");
        Draw::checkbox_text(this, 2, 7, true, "Checkbox Text");
        Draw::text_checkbox(this, 1, 9, "Text Checkbox", false);
        
        // Show the buffer to the screen
        display_buffer_to_screen();
    }

    void end() override {}
};

int main() {
    Window window(30, 15);
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