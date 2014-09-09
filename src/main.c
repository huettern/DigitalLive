#include <pebble.h>
#include "mainwindow.h"

Window *my_window;
TextLayer *text_layer;

char timeBuf[] = "00:00";
char dateBuf[] = "Tue, 09.09.2014";


/*****************************************************************************************
Handle Time Layer
*****************************************************************************************/ 
void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
  //Get Time
  strftime(timeBuf, sizeof("00:00"),           "%H:%M",        tick_time);
  strftime(dateBuf, sizeof("Tue, 09.09.2014"), "%a, %x", tick_time); //%d.%m.%G
  
  set_time(timeBuf);
  set_date(dateBuf);
} 





void handle_init(void) {
  
  tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler); //MINUTE_UNIT SECOND_UNIT
  
  show_mainwindow();
  
  
}

void handle_deinit(void) {
  text_layer_destroy(text_layer);
  window_destroy(my_window);
}

int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
