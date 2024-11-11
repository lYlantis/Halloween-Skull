#include "mbed.h"
#include "rtos.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(p9,p10,p11); // serial tx, serial rx, reset pin;

Serial pc(USBTX, USBRX);


int main()
{
   
    uLCD.printf("\nHello uLCD World\n"); //Default Green on black text
    uLCD.printf("\n  Starting Demo...");
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    uLCD.color(RED);
    for (int i=3; i>=0; --i) {
        uLCD.locate(1,2);
        uLCD.printf("%2D",i);
        wait(.5);
    }
    uLCD.cls();
    uLCD.printf("Change baudrate......");
    uLCD.baudrate(3000000); //jack up baud rate to max for fast display

    //Load Image Demo
    uLCD.cls();
    //SD card needed with image and video files for last two demos
    uLCD.media_init();
    uLCD.printf("\n\nAn SD card is needed for image and video data");
    while(1) {
            uLCD.media_init();
            uLCD.set_sector_address(0x0000, 0x0000);
            uLCD.display_video(0,0);
        }

}