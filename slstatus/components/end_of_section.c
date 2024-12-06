#include "slstatus.h"
#include <stdio.h>
#include <string.h>

const char *end_of_section(const char *color) {
    static char buffer[64];
    if (color) {
        snprintf(buffer, sizeof(buffer), "%%{B%s}%%{B-}", color); // Format separator with color
    } else {
        snprintf(buffer, sizeof(buffer), ""); // Default separator without color
    }
    return buffer;
}
