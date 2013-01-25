UsbPanicButton
==============

This is a software to use the usb panic button by GADGETREE on linux.

Url panic button product URL : http://www.thesource.ca/estore/product.aspx?language=en-CA&product=8003038&catalog=Online&tab=1

This appliation uses HIDAPI (https://github.com/signal11/hidapi.git) to work on any OS (Linux, OS X, ...)

Compiling
---------

        # autoreconf --force --install
        # ./configure
        # make
    
Installing
----------

        # sudo make install
    
Configuring to run as normal user
---------------------------------

        # sudo bash -c 'echo "SUBSYSTEM==usb, SYSFS{idVendor}==1d43, MODE=0666" > /etc/udev/rules.d/99-panicbutton.rules'
        # sudo /etc/init.d/udev reload

Usage: panicbutton _'the command to run'_
-----------------------------------------

The following example run the tests in IntelliJ IDEA when pressing the button
        
        # sudo apt-get install xautomation
        # panicbutton 'xte "keydown Shift_L" "keydown F10" "keyup F10" "keyup Shift_L"' &

Same thing on OS X
        
        # panicbutton "osascript -e 'tell application \"System Events\"
        > key code 109 using {shift down}
        > end tell'" &

