#!/bin/bash

/home/stipe/git/dwm/scripts/status &
/usr/bin/lxpolkit &
picom --config "/home/stipe/.config/picom.conf" &
xset s off -dpms #disabling things like turning off the monitor
xsetroot -cursor_name left_ptr
