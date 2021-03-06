#include "../defs_mpw-two-mfix.h"
#include "../print_io.h"
// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

void set_gpio(int pin)
{
    (volatile uint32_t) ((reg_mprj_datal) |= pin);
}

void clear_gpio(int pin)
{
    (volatile uint32_t) ((reg_mprj_datal) &= ~(pin));
}

void main()
{
    int i, j, k;
    reg_mprj_io_6   = 0x7ff;
    reg_mprj_datal  = 0;
    reg_uart_clkdiv = 1042;
    reg_uart_enable = 1;

    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    char *msg[] = {
    " Woowzaaa!!         ",
    "                    ",
    " I'm Caravel !!     ",
    "      I'm Alive !!! "
    };

	while(1) {
	    putchar('|'); putchar(0x2d); // clear screen
	    for (i = 0; i < 4; i++) {
	        print(msg[i]);
	    }
        for (j=0; j<10000; j++);
    }
}

