#include <stdio.h>
#include <string.h>

// define line size and word size
#define LINE 256
#define WORD 30

int get_word(char w[]);
int substring(char *str1, char *str2);
int similar(char *large, char *small, int n);
void print_lines(char *str);
void print_similar_words(char *str);


int main() {
    char find_word[WORD] = "";
    // Get the search word
    get_word(find_word);
    // Get the option (a or b)
    char c = fgetc(stdin);
    char option = c;
    // Removes the \n\n in the start of the text
    fgetc(stdin);
    fgetc(stdin);
    if (option == 'a') {
        print_lines(find_word);
    }
    else {
        print_similar_words(find_word);
    }
    return 0;
}


int get_word(char w[]) {
    w[0] = '\0';
    // Get input from buffer
    char c = fgetc(stdin);
    int index = 0;
    // While the next char in buffer is a letter, concatenate to the word
    while (c != EOF && c != '\t' && c != ' ' && c != '\n' && c != '\r') {
        strncat(w, &c, 1);
        index++;
        c = fgetc(stdin);
    }
    return index;
}

int substring(char *str1, char *str2) {
    int i = 0;
    int j = 0;
    // Loop over the word in the text
    while (i < strlen(str2)) {
        // Loop over the word we search
        while (j < strlen(str1)) {
            // If the chars are equal, increment i and j
            if (str1[j] == str2[i]) {
                i++;
                j++;
            }
            // If the chars are different and j is above 0, got back to the starting point of i, reset j and break the loop.
            else if (str1[j] != str2[i] && j > 0) {
                i = i - j + 1;
                j = 0;
                break;
            }
            // If the chars are different and j == 0 , increment i only and break the loop.
            else {
                i++;
                break;
            }
            // If we reach the end of the search word we exit
            if (j == strlen(str1)) {
                return 1;
            }
        }
    }
    return 0;
}

int similar(char *large, char *small, int n) {
    int counter = 0;
    int i = 0;
    int j = 0;
    // Loop over the word in the text and the search word, see if we can change the word in the text n or less time to get the search word
    while (i < strlen(large) && j < strlen(small)) {
        if (large[i] != small[j]) {
            counter++;
            i++;
        }
        else if (large[i] == small[j]) {
            i++;
            j++;
        }
        // If text word is not finished, loop over and finish it
        while (j == strlen(small) && i < strlen(large)){
            counter++;
            i++;
        }
    }
    // If we need to change only n times the word in the text and we reach to the end of the search word, return 1
    if (counter <= n && j == strlen(small)) {
        return 1;
    }
    return 0;
}

void print_lines(char *str) {
    char line[LINE] = "";
    // Loop while buffer still has lines
    while (fgets(line,LINE,stdin) != NULL) {
        // If str is a substring of line, we print the line
        if (substring(str, line)) {
            printf("%s", line);
        }
    }
}

void print_similar_words(char *str) {
    char word[WORD] = "";
    int size = get_word(word);
    // Loop while size of the word is over 0
    while (size > 0) {
        // If text word is smaller than search word, dont continue
        if (strlen(word) >= strlen(str)) {
            // If text word and search word are similar, print text word
            if (similar(word, str, 1) == 1) {
                printf("%s\n", word);
            }
        }
        // Get new text word
        size = get_word(word);
    }
}
