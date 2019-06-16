#define USINGPORT2








#ifdef USINGPORT2

#include "mbed.h"


extern serial_t stdio_uart;
Serial * pc2;

int main()
{
        serial_free(&stdio_uart);

        /* You have to init the new serial after the deinit of the old one */
        pc2 = new Serial(PB_3, NC);

        int i = 1;
        pc2->baud(230400);
        pc2->printf("Hello World Serial PORT2 !\n");

        while(1) {
                pc2->printf("PORT2 program runs since %d seconds.\n", i++);
                wait(1.0);
        }
}


#else



#include "mbed.h"
Serial pc(USBTX,NC);
DigitalOut led(D13,0);
int main() {
        pc.baud(230400);
        while(1) {
                led = !led;
                pc.printf("TEST!!\r\n");
                wait_ms(650);
        }
}
#endif
