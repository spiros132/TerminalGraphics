#include <window.hpp>
#include <menu.hpp>
#include <conio.h>
#include <draw.hpp>

class TestMenu: public Menu {
    public:
    std::string a = "";
    TestMenu(Window* window, MenuSettings settings = {}): Menu(window, settings) { }
    void start() override {

    }

    void update() override {
        clear_buffer();

        // Blah blah blah update the buffer
        Draw::empty_checkbox(this, 2, 1);
        Draw::filled_checkbox(this, 2, 3);
        Draw::text(this, 1, 5, "Normal Text");
        Draw::checkbox_text(this, 2, 7, true, "Checkbox Text");
        Draw::text_checkbox(this, 1, 9, "Text Checkbox", false);
        
        Draw::input_field(this, 2, 11, {
            a,
            15
        });

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

        switch (c)
        {
            case 'q':
                window.quit();
                break;
            case 0x08:
                // If a backspace character has been pressed, remove the last character from the 'a' string
                if(menu.a.length() > 0)
                    menu.a.pop_back();
                break;
            default:
            // Only add big and small letters as well as numbers!
            if( (48 <= c && c <= 57) || 
                (65 <= c && c <= 90) || 
                (97 <= c && c <= 122))
                menu.a += c;
                break;
        }
    }

    return 0;
}