
/*
    Modification Terminal aspt 
*/
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <termios.h>



int main(){
    int c;
    struct termios old_settings, new_settings;

    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);  // Mask

    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings)

    while ((c=getc(stdin)) != EOF){
        if(isalpha(c)){
            putc('@', stdout);
            continue;
        }
        if(isdigit(c)){
            putc('#', stdout);
            continue;
        }
        putc('.', stdout);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings)
}