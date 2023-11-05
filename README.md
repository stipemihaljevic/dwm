# DWM configuration
dwm is an extremely fast, small, and dynamic window manager for X.

# Requirements
    ```bash
    sudo pacman -S base-devel libx11 libxft libxinerama freetype2 fontconfig xorg-xinit

# To clone the necessary configuration into the `/opt/git` directory, use the following command:
    ```bash
    git clone [URL_OF_CONFIGURATION_REPOSITORY] /opt/git

# Build / compile
    ```bash
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
