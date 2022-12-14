#include <stdio.h>
#include "pico/stdlib.h"

int main() 
{

    const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();

    while (true) 
    {
        printf("Led! ON\r\n");
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        printf("Led! Test OFF\r\n");        
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }


    return 0;

}
