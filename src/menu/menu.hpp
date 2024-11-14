#pragma once
#include <window.hpp>

class Window;

class Menu {
    private:
    Window* window;

    public:
    Menu(Window* window);
    ~Menu();

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
};