#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int amountofline = 0;

    while(1) {
    	unsigned char buffer = 0x00;

    	scanf("%c",&buffer);
    	if(amountofline < w.ws_col) {
    		printf("%c",buffer);
    		amountofline++;
    	} else if(buffer == '\n') {
    		amountofline = 0;
    		printf("\n");
    	}
    }

    return 0;  // make sure your main returns int
}
