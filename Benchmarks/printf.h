#ifndef __PRINTF_H__
#define __PRINTF_H__

#include <stdarg.h>

/** putchar used by vprintf */
extern void (*putchar_func)(char);

int printf(const char *format, ...);
int vprintf(const char *format, va_list args);


#endif
