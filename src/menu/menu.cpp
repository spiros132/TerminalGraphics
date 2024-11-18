#include <cmath>
#include <menu.hpp>
#include <window.hpp>

#include <string>
#include <iostream>

using namespace std;

int Menu::get_width() {
    if(settings.custom_width == 0)
        return window->get_width();
    else
        return settings.custom_width;
}

int Menu::get_height() {
    if(settings.custom_height == 0)
        return window->get_height();
    else
        return settings.custom_height;
}

void Menu::set_char(int x, int y, char c) {
    // Only add this character if it's within the width / height range
    if( (0 <= x && x < get_width()) &&
        (0 <= y && y < get_height())
    ) {
        display[x + y * get_width()] = c;
    }
}

void Menu::display_buffer_to_screen() {
    // Clear the screen first
    clear_screen();

    const int width = this->get_width();
    const int height = this->get_height();
    
    // Top border
    const int title_width = settings.title.length() + 2;
    const int left_size = floor((width - title_width) / 2.0);
    const int right_size = ceil((width - title_width) / 2.0);

    string border = "";
    border += settings.top_left_border;
    border.append(left_size, settings.top_border);
    border += ' ' + settings.title + ' ';
    border.append(right_size, settings.top_border);
    border += settings.top_right_border;

    // Print the top border
    cout << border << endl;

    // Local Variables for the menu itself
    current_width = border.length();
    current_height++;

    // The buffer itself
    for (size_t row = 0; row < height; row++)
    {
        string s = "";
        s += settings.left_border;

        for (size_t column = 0; column < width; column++) {
            s += display[column + row * width];
        }

        s += settings.right_border;
        cout << s << endl;

        // Local Variable
        current_height++;
    }

    // The bottom border
    border = "";
    border += settings.bottom_left_border;
    border.append(width, settings.bottom_border);
    border += settings.bottom_right_border;

    cout << border;

    // Local variable
    current_height++;
}

void Menu::clear_buffer() {
    for (size_t i = 0; i < sizeof(char) * get_width() * get_height(); i++)
    {
        this->display[i] = settings.empty_space_char;
    }
}

void Menu::clear_screen() {
    if(current_height > 0) {
        // Remove the first line
        cout << "\e[2K";

        // Remove the rest of the lines
        for (size_t i = 1; i < current_height; i++)
        {
            // ASCII Code for first moving up a line and then erasing the entire line
            std::cout << "\e[A" << "\e[2K";
        }

        // Put cursor to the beginning of this line
        std::cout << '\r';

        // Reset local variables
        current_height = 0;
        current_width = 0;
    }
}