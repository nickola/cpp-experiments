#include <unistd.h>

int wait(int period) {
    sleep(period);
    return period;
}
