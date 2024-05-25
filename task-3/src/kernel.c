#include "kernel.h"
#include "std_lib.h"
int main() {
    char buf[128];
    clearScreen();
    printString("Welcome to MengOS\n");

    while (true) {
        printString("$ ");
        readString(buf);
        printString(buf);
        printString("\n");
    }
}
void printString(char* str) {
    int i=0;
    while (*str != 0) {
        if(*str == '\n')
        {
            interrupt(0x10, 0x0E00 | '\r',0,0,0);
        }
        interrupt(0x10, 0x0E00 | *str, 0, 0, 0);
        str++;
    }
}

void readString(char* buf) {
    int index = 0;
    char c = 0;
    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0) & 0xFF;
        if (c == 0x0D) {  // Enter key
            buf[index] = 0;
            printString("\r\n");
            break;
        } else if (c == 0x08) {  // Backspace
            if (index > 0) {
                index--;
                printString("\b \b");  // Handle backspace on screen
            }
        } else {
            buf[index] = c;
            index++;
            interrupt(0x10, 0x0E00 | c, 0, 0, 0);  // Echo character
        }
    }
}

void clearScreen() {
    int i;
    for (i = 0; i < 80 * 25; i++) {
        putInMemory(0xB800, i * 2, ' ');
        putInMemory(0xB800, i * 2 + 1, 0x07);
    }
    interrupt(0x10, 0x0200, 0, 0, 0);  // Move cursor to top-left
}



