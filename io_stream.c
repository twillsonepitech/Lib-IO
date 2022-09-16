/**
 * @file io_file.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Wrapper of IO FILE function that open, close, etc...
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
#include "io_stream.h"

int32_t io_stream_init(char ***__restrict __dbl_ptr_container, const char *__restrict __ptr, const char *__restrict __mode,
    __io_stream_open_fn_t __io_stream_open, __io_stream_close_fn_t __io_stream_close)
{
    char *lineptr = NULL;
    FILE *stream = NULL;
    int32_t return_from_function = 0;
    int32_t index_per_iteration = 0;
    int64_t readline = 0;
    uint64_t n = 0;

    *__dbl_ptr_container = NULL;
    stream = __io_stream_open(__ptr, __mode);
    if (NULL == stream)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE_STREAM;
    }
    while (true)
    {
        readline = getline(&lineptr, &n, stream);
        if (readline == EXIT_FAILURE_STREAM)
        {
            break;
        }
        lineptr[readline - 1] = '\0';
        *__dbl_ptr_container = realloc(*__dbl_ptr_container, sizeof(char *) * (strlen(lineptr) + 1));
        if (NULL == *__dbl_ptr_container)
        {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return EXIT_FAILURE_STREAM;
        }
        (*__dbl_ptr_container)[index_per_iteration] = strdup(lineptr);
        index_per_iteration++;
    }
    (*__dbl_ptr_container)[index_per_iteration] = NULL;
    free(lineptr);
    return_from_function = __io_stream_close(stream);
    if (EXIT_FAILURE_STREAM == return_from_function)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE_STREAM;
    }
    return EXIT_SUCCESS;
}
