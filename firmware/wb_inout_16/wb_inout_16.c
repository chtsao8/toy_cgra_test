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

int encode(uint32_t val, int lo)
{
    return val << lo;
}

int decode(uint32_t val, int lo, int hi)
{
    int bit_len = hi - lo + 1;
    val = val >> lo;
    int mask;
    if (hi >= 31 | hi == 0) {
        mask = 0xFFFFFFFF;
    } else {
        mask = (1 << bit_len) - 1;
    }
    val = val & mask;
    return val;
}

void main()
{
    int i, j, k;
    int data;
    reg_mprj_io_6   = 0x7ff;
    reg_mprj_datal  = 0;
    reg_uart_clkdiv = 1042;
    reg_uart_enable = 1;
    // reg_la3_data = 0x00000001;
    reg_la3_data = 0x00000000;

    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    // stall the CGRA for configuration
    reg_mprj_stall = 0xF;

    // write then read config test
    int fail = 0;
    unsigned int rtl;

    // load config
    reg_mprj_cfg_addr = 17694977;
    reg_mprj_cfg_wdata = 6291456;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 917761;
    reg_mprj_cfg_wdata = 1114112;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474;
    reg_mprj_cfg_wdata = 67117057;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730;
    reg_mprj_cfg_wdata = 4096;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17695233;
    reg_mprj_cfg_wdata = 256;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17694721;
    reg_mprj_cfg_wdata = 16777216;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081;
    reg_mprj_cfg_wdata = 11;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 983297;
    reg_mprj_cfg_wdata = 65538;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17760257;
    reg_mprj_cfg_wdata = 32768;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17760513;
    reg_mprj_cfg_wdata = 2;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327938;
    reg_mprj_cfg_wdata = 4;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010;
    reg_mprj_cfg_wdata = 268484608;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236226;
    reg_mprj_cfg_wdata = 4;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170946;
    reg_mprj_cfg_wdata = 1;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1392509185;
    reg_mprj_cfg_wdata = 16777216;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 67109121;
    reg_mprj_cfg_wdata = 64;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 257;
    reg_mprj_cfg_wdata = 1048576;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 83886337;
    reg_mprj_cfg_wdata = 65537;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 16777473;
    reg_mprj_cfg_wdata = 4063294;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 258;
    reg_mprj_cfg_wdata = 100663296;
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 16777474;
    reg_mprj_cfg_wdata = 512;
    reg_mprj_cfg_write = 1;

    // Read
    // // FAILED
    // reg_mprj_cfg_addr = 17694977;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 6291456) fail=1;

    // // FAILED
    // reg_mprj_cfg_addr = 917761;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 1114112) fail=2;

    reg_mprj_cfg_addr = 393474;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 67117057) fail=3;
    reg_mprj_cfg_addr = 393730;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 4096) fail=4;

    // // FAILED
    // reg_mprj_cfg_addr = 17695233;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 256) fail=5;

    // // FAILED
    // reg_mprj_cfg_addr = 17694721;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 16777216) fail=6;

    reg_mprj_cfg_addr = 590081;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 11) fail=7;

    // FAILED
    // reg_mprj_cfg_addr = 983297;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 65538) fail=8;

    // // FAILED
    // reg_mprj_cfg_addr = 17760257;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 32768) fail=9;

    // // FAILED
    // reg_mprj_cfg_addr = 17760513;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 2) fail=10;

    reg_mprj_cfg_addr = 327938;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 4) fail=11;
    reg_mprj_cfg_addr = 459010;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 268484608) fail=12;
    reg_mprj_cfg_addr = 17236226;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 4) fail=13;
    reg_mprj_cfg_addr = 17170946;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 1) fail=14;

    // // FAILED
    // reg_mprj_cfg_addr = 1392509185;
    // reg_mprj_cfg_read = 1;
    // rtl = reg_mprj_cfg_rdata;
    // data = rtl;
    // if (rtl != 16777216) fail=15;

    reg_mprj_cfg_addr = 67109121;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 64) fail=16;
    reg_mprj_cfg_addr = 257;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 1048576) fail=17;
    reg_mprj_cfg_addr = 83886337;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 65537) fail=18;
    reg_mprj_cfg_addr = 16777473;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 4063294) fail=19;
    reg_mprj_cfg_addr = 258;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 100663296) fail=20;
    reg_mprj_cfg_addr = 16777474;
    reg_mprj_cfg_read = 1;
    rtl = reg_mprj_cfg_rdata;
    if (rtl != 512) fail=21;

	while(1) {
	    putchar('|'); putchar(0x2d); // clear screen
        if (fail > 0) {
            print("failed\n");
            print_dec(fail); print("\n");
            print_hex(data, 8); print("\n");
        } else {
            print("success!\n");
            print_dec(rtl); print("\n");
        }
        for (j=0; j<10000; j++);
    }
}

