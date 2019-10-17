#include <stdio.h>
#include <signal.h>
#include <time.h>


void myCtrlCHandler (int signum) {
    printf("You pressed ctrl+c, but I don't care\n");
}

int main() {
    
    clock_t clk;

    signal(SIGINT, myCtrlCHandler);

    while (1) {
        printf("Welcome, to the Jungle... (first CTRL-C can not break me)\n");

        clk = CLOCKS_PER_SEC / 2 + clock();

        while (clk > clock())
            ;
    }
}


