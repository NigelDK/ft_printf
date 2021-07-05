# ft_printf
Validated on 17-01-2021.

I had to recode printf. I will be allowed to reuse this function in my future projects. The main focus is how to use variadic arguments.

- With the Makefile you will compile the library called "libftprintf.a"
- The prototype is: int ft_printf(const char *, ...);
- Following coversions can be handled: cspdiuxX%
- It manages any combination of the following flags: '-0.*' and minimum field width with all conversions
