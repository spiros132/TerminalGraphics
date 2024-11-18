add_library(TerminalGraphics
window/window.cpp   window/window.hpp
menu/menu.cpp       menu/menu.hpp
draw/draw.cpp       draw/draw.hpp
)

target_include_directories(TerminalGraphics 
PUBLIC menu 
PUBLIC window
PUBLIC draw
)