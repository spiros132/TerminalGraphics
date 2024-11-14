#include <cstdlib>
#include <window.hpp>

Window::Window(Menu* starting_menu) {
    this->current_menu = starting_menu;

    // Start the current menu
    this->current_menu->start();
}

Window::~Window() {
    this->current_menu->end();

    free(this->current_menu);

}

void Window::set_menu(Menu* menu) {
    this->current_menu->end();

    this->current_menu = menu;
    this->current_menu->start();
}

Menu* Window::get_menu() {
    return this->current_menu;
}

void Window::update() {
    this->current_menu->update();
}