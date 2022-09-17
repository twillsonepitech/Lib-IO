#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "io_stream.h"

void print_dbl_ptr(char **dbl_ptr)
{
    int32_t index_per_iteration;

    index_per_iteration = 0;
    while (dbl_ptr[index_per_iteration] != NULL)
    {
        fprintf(stdout, "[%s]\n", dbl_ptr[index_per_iteration]);
        index_per_iteration++;
    }
}

void free_dbl_ptr(char **dbl_ptr)
{
    int32_t index_per_iteration;

    index_per_iteration = 0;
    while (dbl_ptr[index_per_iteration] != NULL)
    {
        free(dbl_ptr[index_per_iteration]);
        index_per_iteration++;
    }
    free(dbl_ptr);
}

Test(tests_io_stream_open_and_close_success, test)
{
    char **dbl_ptr_container = NULL;
    int32_t return_from_function;

    return_from_function = io_stream_init(&dbl_ptr_container, "Makefile", "r+", &fopen, &fclose);
    if (EXIT_FAILURE_STREAM == return_from_function)
    {
        cr_log_error("Error in io_stream_init()");
    }
    print_dbl_ptr(dbl_ptr_container);
    free_dbl_ptr(dbl_ptr_container);
    cr_assert_eq(EXIT_SUCCESS, return_from_function);
    cr_log_warn("tests_io_stream_open_and_close_success: [SUCCESS]");
}

Test(tests_io_stream_open_and_close_failure, test_bad_mode)
{
    char **dbl_ptr_container;
    int32_t return_from_function;

    return_from_function = io_stream_init(&dbl_ptr_container, "ls -la", "bad_mode", &popen, &pclose);
    cr_assert_eq(EXIT_FAILURE_STREAM, return_from_function);
    cr_log_warn("tests_io_stream_open_and_close_failure: [SUCCESS]");
}
