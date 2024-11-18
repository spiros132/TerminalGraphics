#pragma once
#include <cstdlib>
#include <string>
#include <window.hpp>

class Window;

/**
 * @brief Some common menu settings when drawing this particular menu
 * 
 */
struct MenuSettings {
    /**
     * @brief The default title of this menu
     * 
     */
    std::string title = "Title";

    /**
     * @brief The custom width, if this is zero use the window width instead
     * 
     */
    int custom_width = 0;
    
    /**
     * @brief The custom height, if this is zero use the window height instead
     * 
     */
    int custom_height = 0;

    /**
     * @brief The character to display in 'empty' spaces
     * 
     */
    char empty_space_char = ' ';

    /**
     * @brief The top border character
     * 
     */
    char top_border = '-';

    /**
     * @brief The left border character
     * 
     */
    char left_border = '|';

    /**
     * @brief The bottom border character
     * 
     */
    char bottom_border = '-';

    /**
     * @brief The right border character
     * 
     */
    char right_border = '|';

    /**
     * @brief The one diagonal top left border character
     * 
     */
    char top_left_border = '|';

    /**
     * @brief The one diagonal top right border character
     * 
     */
    char top_right_border = '|';

    /**
     * @brief The one diagonal bottom left border character
     * 
     */
    char bottom_left_border = '|';

    /**
     * @brief The one diagonal bottom right border character
     * 
     */
    char bottom_right_border = '|';
};

class Menu {
    private:
    Window* window;
    char* display;
    MenuSettings settings;
    int current_width = 0;
    int current_height = 0;

    public:
    /**
     * @brief Abstract constructor for the Menu class
     * 
     * @param window The window which this menu will be displayed on
     * @param settings The settings that this menu will use
     */
    Menu(Window* window, MenuSettings settings = {})
    :   window(window),
        settings(settings)
    {
        display = (char*)malloc(get_width() * get_height());

        clear_buffer();
    }
    ~Menu() {
        free(display);
    }


    /**
     * @brief Get the width of this menu
     * 
     * @return the width
     */
    int get_width();

    /**
     * @brief Get the height of this menu
     * 
     * @return the height
     */
    int get_height();

    /**
     * @brief Function called at the start of this menu's lifecycle
     * 
     */
    virtual void start() = 0;

    /**
     * @brief Function called when the Window wants to update
     * 
     */
    virtual void update() = 0;

    /**
     * @brief Function called at the end of this menu's lifecycle
     * 
     */
    virtual void end() = 0;


    /**
     * @brief Set a character in the buffer 
     * 
     * @param x The x position of the character, counting from 0
     * @param y The y position of the character, counting from 0
     * @param c The character itself
     */
    virtual void set_char(int x, int y, char c);


    /**
     * @brief Display the buffer based on the current stream variable of the window
     * 
     */
    virtual void display_buffer_to_screen();

    /**
     * @brief Clear the buffer replacing the whole buffer with the default_char
     * 
     */
    virtual void clear_buffer();

    /**
     * @brief Clears the current terminal by using ASCII escape codes 
     * to rewrite the whole screen to empty
     * 
     */
    virtual void clear_screen();
};