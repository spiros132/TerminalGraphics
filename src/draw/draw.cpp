#include <algorithm>
#include <draw.hpp>
#include <string>

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

void Draw::text(Menu *current_menu, int x, int y, std::string text, int max_width) {
    int text_length = text.length();
    int width = current_menu->get_width();

    // If the text is too long, shorten it
    if(max_width > 0 && text_length > max_width) {
        text = text.substr(0, max_width - 2);
        text += "..";
        
        // Update the text length for the next if
        text_length = text.length();
    }

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

void Draw::input_field(Menu *current_menu, int x, int y, input_field_settings settings) {
    // Max input of the input field is based on if the max_input_length is zero or not
    const int max_input_length = settings.max_input_length == 0 ? settings.current_input.length() : settings.max_input_length;

    // Draw the underscore first and then the current input
    current_menu->set_char(x - 1, y, '[');
    
    Draw::text(current_menu, x, y, std::string(max_input_length, '_'));
    Draw::text(current_menu, x, y, settings.current_input, max_input_length);
    
    current_menu->set_char(x + max_input_length, y, ']');
}