#include "main.h"

/**
 * Utility function for string manipulation or various tasks
*/


int is_empty(const char *str)
{
    while (*str != '\0')
    {
        if (!isspace((unsigned char) *str))
        return (0);
        str++;
    }
    return (1);
}
