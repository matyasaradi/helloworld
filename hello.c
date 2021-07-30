#include <stdio.h>
#include <string.h>

#define HEIGHT_OF_LETTERS 7
#define WIDTH_OF_LETTERS 5
#define WIDTH_OF_SPACES 2
#define C "\e[107m\e[30mC"
#define SPACE "\e[107m "
#define NEWLINE "\e[107m\n\e[49m"

void print_sector_with_full_c() {
    int i;
    for (i = 0; i < WIDTH_OF_LETTERS; ++i){
        printf(C);
    }
}

void print_sector_with_full_c_but_no_right_c() {
    int i;
    for (i = 0; i < WIDTH_OF_LETTERS-1; ++i){
        printf(C);
    }
    printf(SPACE);
}

void print_empty_sector() {
    int i;
    for (i = 0; i < WIDTH_OF_LETTERS; ++i){
        printf(SPACE);
    }
}

void print_sector_with_left_c() {
    int i;
    printf(C);
    for (i = 1; i < WIDTH_OF_LETTERS; ++i){
        printf(SPACE);
    }
}

void print_sector_with_left_and_right_c() {
    int i;
    printf(C);
    for (i = 1; i < WIDTH_OF_LETTERS-1; ++i){
        printf(SPACE);
    }
    printf(C);
}

void print_letter(char letter, int line) {
    int i, j;
    switch (letter) {
        case 'D':
            switch (line) {
                case 0:
                case HEIGHT_OF_LETTERS-1:
                    print_sector_with_full_c_but_no_right_c();
                    break;
                default:
                    print_sector_with_left_and_right_c();
            }
            break;
        case 'E':
            switch (line) {
                case 0:
                case HEIGHT_OF_LETTERS/2:
                case HEIGHT_OF_LETTERS-1:
                    print_sector_with_full_c();
                    break;
                default:
                    print_sector_with_left_c();
            }
            break;
        case 'H':
            switch (line) {
                case HEIGHT_OF_LETTERS/2:
                    print_sector_with_full_c();
                    break;
                default:
                    print_sector_with_left_and_right_c();
            }
            break;
        case 'L':
            switch (line) {
                case HEIGHT_OF_LETTERS-1:
                    print_sector_with_full_c();
                    break;
                default:
                    print_sector_with_left_c();
            }
            break;
        case 'O':
            switch (line) {
                case 0:
                case HEIGHT_OF_LETTERS-1:
                    print_sector_with_full_c();
                    break;
                default:
                    print_sector_with_left_and_right_c();
            }
            break;
        case 'R':
            i = line-HEIGHT_OF_LETTERS+WIDTH_OF_LETTERS;
            if ((line == 0) || (line == HEIGHT_OF_LETTERS/2-1)) {
                print_sector_with_full_c();
            } else if (line < HEIGHT_OF_LETTERS/2-1) {
                print_sector_with_left_and_right_c();
            } else if (i > 0) {
                printf(C);
                for (j = 1; j<i; ++j) {
                    printf(SPACE);
                }
                printf(C);
                for (j = i+1; j<WIDTH_OF_LETTERS; ++j) {
                    printf(SPACE);
                }
            } else {
                print_sector_with_left_c();
            }
            break;
        case 'W':
            i = line-WIDTH_OF_LETTERS/2+1;
            j = (WIDTH_OF_LETTERS+1)/2;
            if ((i > 0) && (i < j)) {
                printf(C);
                for (j = 1; j < WIDTH_OF_LETTERS-line-1; ++j) {
                    printf(SPACE);
                }
                printf(C);
                for (j = WIDTH_OF_LETTERS-line-1; j < line-1; ++j) {
                    printf(SPACE);
                }
                if ((i > 1) || (WIDTH_OF_LETTERS%2==0)) {
                    printf(C);
                }
                for (j = line+1; j<WIDTH_OF_LETTERS-1; ++j) {
                    printf(SPACE);
                }
                printf(C);
            } else {
                print_sector_with_left_and_right_c();
            }
            break;
        default:
            print_empty_sector();
    }
}

void print_space() {
    int i;
    for (i = 0; i < WIDTH_OF_SPACES; ++i){
        printf(SPACE);
    }
}

void print_line(char* string) {
    int number_of_characters, i, j;
    number_of_characters = strlen(string);

    for (i = 0; i < HEIGHT_OF_LETTERS; ++i) {
        for (j = 0; j < number_of_characters; ++j) {
            print_letter(string[j], i);
            if (j < number_of_characters-1) {
                print_space();
            }
        }
        printf(NEWLINE);
    }
    printf(NEWLINE);
}

int main() {
    print_line("HELLO");
    print_line("WORLD");
    return 0;
}
