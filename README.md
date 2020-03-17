# Wash Timer

![](media/washtimer.gif)

This is an easy-to-build timer to use while washing your hands which doesn't
involve trying to sing a song in your head. Just wave your hand in front of it
and wait for the LEDs to go off.

Here are the modules I used to build it, but honestly, you could replace any of
them with whatever you have in your parts box. The display could be a 7-segment
display, or even a handful of LEDs instead. The proximity sensor could be replaced 
with an ultrasonic rangefinder, or a light-break setup but it's best to avoid a
physical switch _that people would have to press before washing!_

Display module: 
* https://www.banggood.com/MAX7219-Dot-Matrix-Module-4-in-1-LED-Display-Module-p-1072083.html

Proximity sensor:
* https://www.pololu.com/product/1134

Arduino:
* Use any Arduino or Arduino-compatible board. I used an Arduino Micro because it was small and
I had one handy but anything will work.

A bit of perfboard is also useful to hold everything together. I 3D-printed a case for it but
it could also be placed in a translucent food container (with a cutout for the proximity sensor).

## Wiring it up

Hook up the signal wires as follows (again, not critical, the pins are configurable in software):
* D2 - display SCLK
* D3 - display CS
* D4 - display DATA
* D5 - sensor OUT

## Modifying / Running the softare

The project uses the PlatformIO environment (https://platformio.org). If you install that, you
should be able to open this folder, and then Build and Upload. If you prefer a different IDE,
then simply copying the code in `src/main.cpp` should be enough (don't forget to install the 
MD libraries).

Libraries: 
* https://github.com/MajicDesigns/MD_Parola
* https://github.com/MajicDesigns/MD_MAX72XX

License: CC Attribution-NonCommercial https://creativecommons.org/licenses/by-nc/4.0/
