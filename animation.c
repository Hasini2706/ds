#include <stdio.h>
#include <unistd.h>  // for sleep (on UNIX)
#include <stdlib.h>

void clearScreen() {
    // Clears the console screen (works on Unix-based)
    printf("\e[1;1H\e[2J");
}

void drawFrame(int frame) {
    clearScreen();
    if (frame % 2 == 0) {
        printf("   o  \n"); // head
        printf("  /|\\ \n"); // arms
        printf("  / \\ \n"); // legs
        printf(" Girl is walking... (step left)\n");
    } else {
        printf("   o  \n");
        printf("  \\|/ \n");
        printf("  / \\ \n");
        printf(" Girl is walking... (step right)\n");
    }
}

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        drawFrame(i);
        usleep(300000); // 0.3 seconds
    }
    return 0;
}

