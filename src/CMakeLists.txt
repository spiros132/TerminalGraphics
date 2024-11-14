add_library(TerminalGraphics
window/window.cpp
menu/menu.cpp
)

target_include_directories(TerminalGraphics 
PUBLIC menu 
PUBLIC window
)