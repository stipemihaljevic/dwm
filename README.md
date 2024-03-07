# Requirements
    $ sudo pacman -S base-devel libx11 libxft libxinerama freetype2 fontconfig xorg-xinit xorg-xsetroot dunst picom feh dmenu

# AUR requirements
Install AUR helper(yay):

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

# Make DWM appear on display manager (ly)
Install ly
    $ sudo pacman -S ly

Make xsessions directory

    $ sudo mkdir -p /usr/share/xsessions

Copy dwm.desktop file to xsessions directory:

    $ sudo cp -r /opt/git/dwm/dwm.desktop /usr/share/xsessions
