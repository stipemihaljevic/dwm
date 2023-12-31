# DWM configuration
DWM is a highly efficient, lean, and adaptable window manager for Xorg, designed by suckless.org for those who appreciate the art of personalizing their computing experience.

# Requirements
    $ sudo pacman -S base-devel libx11 libxft libxinerama freetype2 fontconfig xorg-xinit xorg-xsetroot dunst picom feh

# AUR requirements
Install AUR helper (yay,paru...):

    $ git clone https://aur.archlinux.org/yay-bin /opt/git/yay-bin
    $ cd /opt/git/yay-bin
    $ makepkg -si

Install required packages from aur:

    $ yay -S lxpolkit-git

# Clone
Clone the necessary configuration into the `/opt/git` directory:

    $ git clone https://github.com/stipemihaljevic/dwm /opt/git/dwm

# Build / compile
    $ sudo make clean install

# Make DWM appear on display manager (lightdm, ly, sddm, gdm...)
Copy dwm.desktop file to xsessions directory:

    $ sudo cp -r /opt/git/dwm/dwm.desktop /usr/share/xsessions


If the `/usr/share/xsessions` directory does not exist, run the following command:

    $ sudo mkdir -p /usr/share/xsessions

# .xinitrc config

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm

# Configuration
The configuration of dwm is done by creating a custom config.h
and compiling the source code.

# Credit
The code base is sourced from @ChrisTitusTech, available at https://github.com/ChrisTitusTech/dwm-titus.
