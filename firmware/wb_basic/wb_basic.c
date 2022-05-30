#include "../defs_mpw-two-mfix.h"
#include "../print_io.h"


// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------
#define reg_mprj_cfg_addr  (*(volatile uint32_t*)0x30000000)
#define reg_mprj_cfg_wdata (*(volatile uint32_t*)0x30000004)
#define reg_mprj_cfg_rdata (*(volatile uint32_t*)0x30000008)
#define reg_mprj_cfg_write (*(volatile uint32_t*)0x3000000C)
#define reg_mprj_cfg_read  (*(volatile uint32_t*)0x30000010)
#define reg_mprj_stall     (*(volatile uint32_t*)0x30000014)
#define reg_mprj_message   (*(volatile uint32_t*)0x30000018)

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
    // reg_la3_data = 0x00000001;
    reg_la3_data = 0x00000000;

    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    char *msg[] = {
    " Woowzaaa!!         ",
    "                    ",
    " I'm Caravel !!     ",
    "      I'm Alive !!! "
    };

    char *msg_pre[] = {
    " Test               ",
    "                    ",
    " I'm Caravel !!     ",
    "      I'm Pre   !!! "
    };

    // int repeat = 3;

    // while(1) {
	//     putchar('|'); putchar(0x2d); // clear screen
    //     for (i = 0; i < 4; i++) {
	//         print(msg_pre[i]);
	//     }
    //     for (j=0; j<10000; j++);
    //     if (--repeat == 0)
    //         break;
    // }

    // message=1, indicate start config
    // reg_mprj_message = 1;

    // stall the CGRA for configuration
    reg_mprj_stall = 0xF;

    // load config
    reg_mprj_cfg_addr = 17367297;
    reg_mprj_cfg_wdata = 0x888;
    reg_mprj_cfg_write = 1;

    // read config
    int rtl;
    reg_mprj_cfg_addr = 17367297;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;

	while(1) {
	    putchar('|'); putchar(0x2d); // clear screen
        // for (i = 0; i < 4; i++) {
	    //     print(msg[i]);
	    // }
        print_hex(rtl, 3);
        for (j=0; j<10000; j++);
    }
}

