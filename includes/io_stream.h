/**
 * @file io_stream.h
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief IO stream header file is here to get the protos of
 * every function that allow an user to use wrapper, ...
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef IO_STREAM_H_
# define IO_STREAM_H_

#if !defined(EXIT_FAILURE_STREAM)
# define EXIT_FAILURE_STREAM    (-1)
#endif // EXIT_FAILURE_STREAM

typedef FILE *(*__io_stream_open_fn_t)(const char *, const char *);
typedef int (*__io_stream_close_fn_t)(FILE *);

/**
 * @brief IO function wrapper that take an open io stream function, getline all line in the FILE stream
 * and push it into __dbl_ptr_container.
 * The dbl ptr is reallocated in each loop, and add data.
 * It also takes an close io stream function, that close the FILE stream.
 * 
 * @param __dbl_ptr_container Double pointer that contains every line data
 * @param __ptr Can be a filename or commandname
 * @param __mode Mode like "r" "w" "a" "r+" "w+" "a+"...
 * @param __io_stream_open Function fopen or popen
 * @param __io_stream_close Function fclose or pclose
 * @return int32_t SUCCESS(0) or FAILURE(-1)
 */
int32_t io_stream_init(char ***__restrict __dbl_ptr_container, const char *__restrict __ptr, const char *__restrict __mode,
        __io_stream_open_fn_t __io_stream_open, __io_stream_close_fn_t __io_stream_close) __nonnull((1, 2, 3, 4, 5));

#endif /* !IO_STREAM_H_ */
