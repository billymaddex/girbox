# girbox - PS3IR-1000 for GNOME
Linux Utility for the PS3IR-1000 box

The PS3IR-1000 is a pretty slick IR to Bluetooth interface box for the PS3! Sadly, no longer manufactured or really supported. They never got around to making  linux program to interface with the box, and I'm done dual booting to run just 1 program. So I threw this little GNOME interface together. Uses hidraw for usb interaction. It does what I need, but is a bit short of feature complete. All the same, thought I might share it with the world. 

PS. You can still check out the what's left of the company website for more info: 

http://ps3ir.com/forum/


Build Dependencies:
GTK+-3
Glade
Systemd

Should be able to build by just running make, assuming build time dependencies are met.
