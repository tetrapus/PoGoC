#include <pebble.h>

static Window *s_main_window;

static void main_window_load(Window *window) {

}

static void main_window_unload(Window *window) {

}

static void init_window() {
    // Create main Window element and assign to pointer
    s_main_window = window_create();
    window_set_background_color(s_main_window, GColorFromHEX(0x0000ff));

    // Set handlers to manage the elements inside the Window
    window_set_window_handlers(s_main_window, (WindowHandlers) {
      .load = main_window_load,
      .unload = main_window_unload
    });

    // Show the Window on the watch, with animated=true
    window_stack_push(s_main_window, true);
}

static void deinit_window() {
    // Destroy Window
    window_destroy(s_main_window);
}

static void init() {
    init_window();
}

static void deinit() {
    deinit_window();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}