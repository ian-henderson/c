#include <stdio.h>

struct cabin_information {
    int window_count;
    int o2level;
};

struct spaceship {
    char *manufacturer;
    struct cabin_information ci;
};

int main(void) {
    struct spaceship s = {
        .manufacturer = "General Products",
        .ci.window_count = 9,
        .ci.o2level = 23,
    };
    /*
      also valid:
      struct spaceship s = {
              .manufacturer = "General Products",
            .ci={
                     window_count = 9,
                     o2level = 23,
             }
      };
    */

    printf("%s: %d seats, %d%% oxygen\n", s.manufacturer, s.ci.window_count,
           s.ci.o2level);
}
