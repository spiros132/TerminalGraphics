#pragma once
#include <cstdlib>
#include <menu.hpp>

class Menu;

/**
 * @brief Uses standard output to write to the console
 * 
 */
class Window {
    private:
    Menu* current_menu = nullptr;
    int width, height;
    bool run = false;

    public:
    Window(int width, int height)
    :width(width), height(height) {}
    ~Window() {}


    /**
     * @brief Set the current menu that is displaying in this window
     * 
     * @param new_menu The new menu to be displayed
     */
    void set_menu(Menu* new_menu);

    /**
     * @brief Get the current menu that is displaying in this window
     * 
     * @return The menu currently displayed
     */
    Menu* get_menu();


    /**
     * @brief Update the current window
     * 
     */
    void update();

    /**
     * @brief Tell the window to close itself
     * 
     */
    void quit();

    bool is_running();

    /**
     * @brief Get the width of the window
     * 
     * @return the width
     */
    int get_width();

    /**
     * @brief Get the height of the window
     * 
     * @return the height
     */
    int get_height();
};