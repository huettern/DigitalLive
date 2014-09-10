#include "mainwindow.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_bitham_42_bold;
static TextLayer *s_clock_layer;
static TextLayer *s_date_layer;

static void initialise_ui(void) {
  //Load font
  //ResHandle font_handle = resource_get_handle(RESOURCE_ID_FONT_EXO2_BOLD_42);
  
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, 1);
  
  //s_res_bitham_42_bold = fonts_get_system_font("FONT_KEY_BITHAM_30_BLACK"); //FONT_EXO2_BOLD_42 FONT_KEY_BITHAM_42_BOLD
  // s_clock_layer
  s_clock_layer = text_layer_create(GRect(0, 0, 144, 55));
  text_layer_set_background_color(s_clock_layer, GColorWhite);
  text_layer_set_text_color(s_clock_layer, GColorBlack);
  text_layer_set_text(s_clock_layer, "     ");
  text_layer_set_text_alignment(s_clock_layer, GTextAlignmentCenter);
  text_layer_set_font(s_clock_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DIGITAL_MONO_55))); //FONT_IMAGINE_42 RESOURCE_ID_FONT_EXO2_BOLD_42 FONT_GRUPO3_42
  //text_layer_set_font(s_clock_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK)); //FONT_IMAGINE_42 RESOURCE_ID_FONT_EXO2_BOLD_42 FONT_GRUPO3_42
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_clock_layer);
  
  
   // s_date_layer
  s_date_layer = text_layer_create(GRect(0, 83, 144, 22));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, GColorWhite);
  text_layer_set_text(s_date_layer, "          ");
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);
  text_layer_set_font(s_date_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DIGITAL_STRAIGHT_20))); //FONT_IMAGINE_42 RESOURCE_ID_FONT_EXO2_BOLD_42 FONT_GRUPO3_42
  //text_layer_set_font(s_clock_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK)); //FONT_IMAGINE_42 RESOURCE_ID_FONT_EXO2_BOLD_42 FONT_GRUPO3_42
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_clock_layer);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_mainwindow(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_mainwindow(void) {
  window_stack_remove(s_window, true);
}

void set_time (char* time_data)
  {
  text_layer_set_text(s_clock_layer, time_data);
}

void set_date (char* date_data)
  {
  text_layer_set_text(s_date_layer, date_data);
}
