#include <stddef.h>
#include <stdint.h>
 
volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;

void print_uart0(const char *s)
{
    while (*s != '\0')
	{
	  *UART0DR = (unsigned int)(*s);
	  s++;
	}
}
 
#if defined(__cplusplus)
extern "C"
#endif
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	// Declare as unused
	(void) r0;
	(void) r1;
	(void) atags;
 
	while (1)
		print_uart0("heloo world!\n");
}
