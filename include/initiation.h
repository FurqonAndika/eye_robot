#include "touch.h"
#include "display.h"
#include "customwatch.h"


void system_init(){
    touch_init();
    display_init();
    watch_init();
}
