#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int amountofline = 0;
    unsigned char buffer;

    do {
        buffer = 0;
        scanf("%c",&buffer);

        if(amountofline < w.ws_col) {
            printf("%c",buffer);
            amountofline++;
        } else if(buffer == '\n') {
            amountofline = 0;
            printf("\n");
        }
    } while(buffer != EOF && buffer != 0);

    return 0;
}