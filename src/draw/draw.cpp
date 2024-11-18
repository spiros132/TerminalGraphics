#include <draw.hpp>

void Draw::empty_checkbox(Menu* current_menu, int x, int y) {
    current_menu->set_char(x + 1, y, ']'); // Right border
    current_menu->set_char(x - 1, y, '['); // Left border
}

void Draw::filled_checkbox(Menu *current_menu, int x, int y) {
    Draw::empty_checkbox(current_menu, x, y);

    current_menu->set_char(x, y, 'x');
}

void Draw::checkbox(Menu *current_menu, int x, int y, bool filled) {
    // Show a filled or empty checkbox based on the filled boolean
    if(filled)
        Draw::filled_checkbox(current_menu, x, y);
    else
        Draw::empty_checkbox(current_menu, x, y);
}

void Draw::text(Menu *current_menu, int x, int y, std::string text) {
    int text_length = text.length();
    int width = current_menu->get_width();

    // If the text is too long, shorten it
    if (x + text_length >= width) {
        text = text.substr(0, width - x - 2);
        text += "..";
    }

    for (int i = 0; i < text.length(); ++i)
        current_menu->set_char(x + i, y, text[i]);
}

void Draw::checkbox_text(Menu *current_menu, int x, int y, bool filled, std::string text) {
    // Draw the checkbox first and then the text
    Draw::checkbox(current_menu, x, y, filled);
    Draw::text(current_menu, x + 3, y, text);
}

void Draw::text_checkbox(Menu *current_menu, int x, int y, std::string text, bool filled) {
    // Draw the text first and then the checkbox
    Draw::text(current_menu, x, y, text);
    Draw::checkbox(current_menu, x + 2 + text.length(), y, filled);
}