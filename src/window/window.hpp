#pragma once
#include <menu.hpp>

class Menu;

class Window {
    private:
    Menu* current_menu;

    public:
    Window(Menu* starting_menu);
    ~Window();

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
};