# DWM configuration
dwm is an extremely fast, small, and dynamic window manager for X.

# Requirements
    sudo pacman -S base-devel libx11 libxft libxinerama freetype2 fontconfig xorg-xinit

# Build / compile
    sudo make clean install

# .xinitrc config

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm

# Configuration
The configuration of dwm is done by creating a custom config.h
and compiling the source code.
