#pragma once

#include <string>
#include <menu.hpp>

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
     */
    static void text(Menu* current_menu, int x, int y, std::string text);

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

};