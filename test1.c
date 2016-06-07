#include "types.h"
#include "date.h"
#include "user.h"

int main() {
    int pid = fork();
    if (pid > 0) {
        nice(2);
        sleep(1);
        getpri();
    	wait();
    } else {
    	nice(0);
        sleep(1);
        getpri();
    }
    exit();
}