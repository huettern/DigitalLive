#include <pebble.h>
#include "mainwindow.h"

char timeBuf[] = "     ";
char dateBuf[] = "               ";
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


/*****************************************************************************************
Init routines
*****************************************************************************************/ 
void handle_init(void) {
  tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler); //MINUTE_UNIT SECOND_UNIT
  
  show_mainwindow();
}

void handle_deinit(void) {
  hide_mainwindow();
}

int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
