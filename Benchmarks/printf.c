#include <stdarg.h>
#include <stdint.h>
#include "printf.h"


/** Needed by printf, make sure is is provided somewhere */
extern void putchar(char c);

/** By default, use putchar, but can be changed */
void (*putchar_func)(char) = putchar;

#define PUTCHAR(c) do { ++count; putchar_func((c)); } while(0)
#define PUTS(s) do {const char *str=s; while (*str) PUTCHAR(*str++);}while(0)


#define PUT_HEXA_DIGIT(d,a_letter) do {         \
      if ((d) <= 9)			\
         PUTCHAR('0' + (d));                    \
      else                                      \
         PUTCHAR((a_letter) + ((d) - 0xA));     \
   } while (0)

#define PUT_HEXA_BYTE(b, a_letter) do {         \
      PUT_HEXA_DIGIT(((b)>>4), (a_letter));     \
      PUT_HEXA_DIGIT(((b) & 0xF), (a_letter));  \
   } while (0)

#define PUT_HEXA_VAL(val,a_letter,bits, print_zero) do {        \
      int b = (bits) - 4;                                       \
      if (!(print_zero)) {                                      \
         while ((b > 0) && (((val) >> b) & 0xF) == 0)		\
            b -=4;                                              \
      }								\
      for ( ; b >= 0 ; b -= 4)					\
         PUT_HEXA_DIGIT(((val) >> b) & 0xF, (a_letter));        \
   } while(0)


#define PUT_INT_DIGIT(i) do {			\
      PUTCHAR('0' + (i));			\
   } while(0);

#define PUT_INT_NUMBER(i) do {                          \
      unsigned int max_pow = 1;				\
      unsigned int val = i;                             \
      while ((val) / (max_pow) >= 10) max_pow*=10;      \
      for ( ; max_pow >= 1; max_pow /= 10)              \
      {							\
         PUT_INT_DIGIT((val)/max_pow);			\
         val = val % max_pow;				\
      }							\
   } while(0);

int vprintf(const char *format, va_list args)
{
   int count = 0; /* number of char printed */
   int print_zero = 0;
   int ccount = sizeof(unsigned int);

   while (*format)
   {
      switch (*format)
      {
         case '%':
            ++format;
            if (*format == '0')
            {
               print_zero = 1;
               ++format;
            }
            if (*format >= '2' && *format <= '4')
            {
               ccount = (*format - '0') / 2;
               ++format;
            }
            switch(*format)
            {
               case 'd':
               case 'i':
               {
                  int i = (int) va_arg(args,int);
                  if (i < 0)
                  {
                     i = -i;
                     PUTCHAR('-');
                  }
                  PUT_INT_NUMBER(i);
               }
               break;
               case 'u':
               {
                  unsigned int i = (unsigned int) va_arg(args,unsigned int);
                  PUT_INT_NUMBER(i);
               }
               break;
               case 'p':
               case 'P':
               {
                  void *p = (void *)va_arg(args,void*);
                  PUTCHAR('0');
                  PUTCHAR('x');
                  PUT_HEXA_VAL((uint32_t)p,(*format - ('p' - 'a')), sizeof(void*)<<3, 1);
               }
               break;
               case 'x':
               case 'X':
               {
                  unsigned int val = (unsigned int) va_arg(args, unsigned int);
                  /* print the hexa val using lower case letter or upper
                   * case letter depending on 'x' or 'X' */
                  PUT_HEXA_VAL(val,(*format - ('x' - 'a')),ccount<<3, print_zero);
                  print_zero = 0;
               }
               break;
               case 'c':
               {
                  char c = (char) va_arg(args, int);
                  PUTCHAR(c);
                  break;
               }
               case 's':
               {
                  const char *s = (const char*) va_arg(args, const char*);
                  PUTS(s);
                  break;
               }
               case '%':
                  PUTCHAR('%');
                  break;

               default:
               {
                  /* not handled arg, assume int and get next */
                  (int) va_arg(args, int);
                  PUTS("!Not handled format char: '");
                  PUTCHAR(*format);
                  PUTS("', treated as int!");
               }
               break;
            }
            break;
         default:
            PUTCHAR(*format);
            break;
      }
      ++format;
   }
   return count;
}

int printf(const char *format, ...)
{
   va_list args;
   int count;
   va_start(args, format);
   count = vprintf(format, args);
   va_end(args);
   return count;
}
