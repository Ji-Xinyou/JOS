#ifndef __LOGGER_H
#define __LOGGER_H

/**
 * @file logger.h
 * @author Ji-Xinyou (jerryji0414@outlook.com)
 * @brief The logger implementation of J-i-OS, the logger uses a macro approach
 *        for utilizing builtin macros line __FILE__, __LINE__ and letting them
 *        show correct message.
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "defs.h"

#if !defined(__FUNCTION__) && !defined(__GNUC__)
#define __FUNCTION__ ""
#endif

#define LOG_INFO(...)  LOG("[INFO]: ", __VA_ARGS__)
#define LOG_DEBUG(...) LOG("[DEBUG]: ", __VA_ARGS__)
#define LOG_ERROR(...) LOG("[ERROR]: ", __VA_ARGS__)

#define __LOG_PREFIX() \
do { \
    uart_printf(__FILE__); \
    uart_printf(":"); \
    char buf[32]; \
    itoa(__LINE__, buf, 10); \
    uart_printf(buf); \
    uart_printf("  "); \
} while (0)

#define LOG(prefix, ...) \
do { \
    __LOG_PREFIX(); \
    uart_printf(prefix); \
    uart_printf(__VA_ARGS__); \
    uart_printf("\n"); \
} while(0)

#endif
