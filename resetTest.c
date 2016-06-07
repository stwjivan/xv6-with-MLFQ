#include "types.h"
#include "date.h"
#include "user.h"

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        getpri();
        sleep(1);
    }
    exit();
}