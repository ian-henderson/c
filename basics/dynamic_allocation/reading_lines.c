#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *file_pointer);

int main(void) {
    FILE *file_pointer = fopen("foo.txt", "r");
    char *line;

    while ((line = readline(file_pointer)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(file_pointer);

    return 0;
}

// Read a line of arbitrary size from a file
//
// Returns a pointer to the line.
// Returns NULL on EOF or error.
//
// It's up to the caller to free this pointer when done with it.
//
// Note that this strips the newline from the result. If you need
// it in there, probably best to switch this to a do-while.
char *readline(FILE *file_pointer) {
    int buffer_size = 4, // Preferably power of 2 initial size
        c, offset = 0;

    char *buffer = malloc(buffer_size);

    if (buffer == NULL) {
        return NULL;
    }

    // Main loop; read until newline or EOF
    while (c = fgetc(file_pointer), c != '\n' && c != EOF) {
        // Check if we're out of room in the buffer accounting for the
        // extra byte for the NUL terminator
        if (offset == buffer_size - 1) // -1 for the NUL terminator
        {
            buffer_size *= 2; // 2x the space
            char *new_buffer = realloc(buffer, buffer_size);
            if (new_buffer == NULL) {
                free(buffer); // On error, free and bail
                return NULL;
            }
            buffer = new_buffer; // Successful realloc
        }

        buffer[offset++] = c; // Add the byte onto the buffer
    }

    // hit newline or EOF

    // If at EOF and we read no bytes, free the buffer and return NULL to
    // indicate we're at EOF:
    if (c == EOF && offset == 0) {
        free(buffer);
        return NULL;
    }

    // Shrink to fit
    if (offset < buffer_size - 1) // If we're short of the end
    {
        // +1 for the NUL terminator
        char *new_buffer = realloc(buffer, offset + 1);

        // If successful, point buffer to new_buffer
        if (new_buffer != NULL) {
            buffer = new_buffer;
        }
    }

    // Add the NUL terminator
    buffer[offset] = '\0';

    return buffer;
}
