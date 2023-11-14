#include "main.h"
#include <stdarg.h>
/**
 * @_printf - prints output according to format
 *
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{

	va_list ag;
	if(format == NULL)
	{
		return(-1);
	}
	va_start(ag, format);
	int count = 0;
	while(*format != 0)
	{
		if(*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			switch(*++format)
			{
				case 'd':
					count += fprintf(stdout, "%d", va_arg(ag, int));
                			break;
            			case 'c':
                			count += fprintf(stdout, "%c", va_arg(ag, char));
                			break;
            			case 's':
                			count += fprintf(stdout, "%s", va_arg(ag, char *));
                			break;
				default:
					putchar('%');
               	 			putchar(*format);
                			count += 2;
                			break;
            		}
   	     	}
        	format++;	
    	}

    	va_end(ag);
    	return count;
}
