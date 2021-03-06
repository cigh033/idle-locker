#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/scrnsaver.h>

/* Report amount of X server idle time. */
/* Build with- */
/* cc xidle.c -o xidle -lX11 -lXext -lXss */


int main(int argc, char *argv[])
{
        Display *display;
        int event_base, error_base;
        XScreenSaverInfo info;
        unsigned int seconds;

        display = XOpenDisplay("");

        if(display) {
                if (XScreenSaverQueryExtension(display, &event_base, &error_base)) {
                        XScreenSaverQueryInfo(display, DefaultRootWindow(display), &info);

                        seconds = (unsigned int)info.idle;
                        printf("%lu\n",seconds);
                        return(0);
                }else{
                        fprintf(stderr,"Error: XScreenSaver Extension not present\n");
                        return(1);

                }
        }else {
                fprintf(stderr,"Error: Invalid Display\n");
                return(1);
        }
}