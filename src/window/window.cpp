#include <window.hpp>
#include <menu.hpp>

void Window::set_menu(Menu* menu) {
    if(this->current_menu != nullptr)
        this->current_menu->end();
        
    this->current_menu = menu;
    this->current_menu->start();

    this->run = true;
}

Menu* Window::get_menu() {
    return this->current_menu;
}

void Window::update() {
    this->current_menu->update();
}

void Window::quit() {
    this->run = false;
}

bool Window::is_running() {
    return this->run;
}

int Window::get_width() {
    return this->width;
}

int Window::get_height() {
    return this->height;
}