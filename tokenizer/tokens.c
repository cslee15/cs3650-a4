#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"

/** Helper function to ask if the given character is one of the special single-character tokens. */
static int is_special(char ch) {
    return ch == '(' || ch == ')' || ch == '<' || ch == '>' || ch == ';' || ch == '|';
}

/** Helper function to ask if the given character is whitespace. */
static int is_whitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n';
}

/** Read a word from the start of input into output.
 *  Returns the number of characters read. */
static int read_word(const char *input, char *output) {
    int i = 0;
    while (input[i] != '\0' && !is_whitespace(input[i]) && !is_special(input[i]) && input[i] != '"') {
        output[i] = input[i];
        i++;
    }
    output[i] = '\0';
    return i;
}

/** Read the inside of a quoted string into output, starting just after the
 *  opening quote. Stops at the closing quote or the end of input.
 *  Returns the number of characters read. */
static int read_quoted(const char *input, char *output) {
    int i = 0;
    while (input[i] != '\0' && input[i] != '"') {
        output[i] = input[i];
        i++;
    }
    output[i] = '\0';
    return i;
}

/** Split the given line into shell tokens and return them in a vector. */
vect_t *tokenize(const char *input) {
    assert(input != NULL);

    vect_t *tokens = vect_new();
    char *buf = malloc(strlen(input) +1);
    assert(buf != NULL);
    int i = 0;

    while (input[i] != '\0') {
        if (is_whitespace(input[i])) {
            i++;
            continue;
        }

        if (is_special(input[i])) {
            char tok[2] = {input[i], '\0'};
            vect_add(tokens, tok);
            i++;
            continue;
        }

        if (input[i] == '"') {
            i++;
            i += read_quoted(&input[i], buf);
            vect_add(tokens, buf);
            if (input[i] == '"') {
                i++;
            }
            continue;
        }
        
        i += read_word(&input[i], buf);
        vect_add(tokens, buf);
    }

    free(buf);
    return tokens;
}