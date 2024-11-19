#pragma once

#include <string>
#include <menu.hpp>

struct input_field_settings {
    /**
        * @brief The current input of the field
        * 
        */
    std::string current_input = "";

    /**
        * @brief If max_input_length is zero then the border of the field will be automatic and change based on the current input
        * 
        */
    int max_input_length = 0;
};

class Draw {
    public:
    /**
     * @brief Draw an empty checkbox on the menu, with a specific x and y
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     */
    static void empty_checkbox(Menu* current_menu, int x, int y);
    
    /**
     * @brief Draw a filled checkbox on the menu, with a specific x and y
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     */
    static void filled_checkbox(Menu* current_menu, int x, int y);

    /**
     * @brief Draw a checkbox on the menu, with a specific x and y, and it's filled based on the boolean filled
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     * @param filled Should this checkbox be filled or not?
     */
    static void checkbox(Menu* current_menu, int x, int y, bool filled);

    /**
     * @brief Draw a certain string on the menu, with a specific x and y
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     * @param text The text that should be displayed
     * @param max_width The max width the text can take, if zero the max width is till the end of the border
     */
    static void text(Menu* current_menu, int x, int y, std::string text, int max_width = 0);

    /**
     * @brief Draw a checkbox followed by a string, with a specific x and y
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     * @param filled Should this checkbox be filled or not?
     * @param text The text that should be displayed
     */
    static void checkbox_text(Menu* current_menu, int x, int y, bool filled, std::string text);
    
    /**
     * @brief Draw a text followed by a checkbox, with a specific x and y
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     * @param text The text that should be displayed
     * @param filled Should this checkbox be filled or not?
     */
    static void text_checkbox(Menu* current_menu, int x, int y, std::string text, bool filled);

    /**
     * @brief Draw an input field for inputting a certain length of a string 
     * 
     * @param current_menu The menu to draw this on
     * @param x The x position
     * @param y The y position
     * @param input_length The length of the input field
     * @param current_input The current input
     */
    static void input_field(Menu* current_menu, int x, int y, input_field_settings settings = {});
};