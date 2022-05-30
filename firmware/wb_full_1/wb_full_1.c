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
    int data, group;
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
    int lo, hi;
    unsigned int rtl;
    
    // regtest_wr_2.c
    group = 2;

    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459267; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=1; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459267; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=2; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236483; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236483; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=3; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459267; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=4; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236483; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236483; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=5; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=6; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=7; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=8; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=9; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=10; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=11; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=12; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=13; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=14; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=15; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=16; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=17; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66052; // bit0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66052; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=18; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131588; // bit1 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131588; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=19; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197124; // bit2 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197124; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=20; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262660; // data0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262660; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=21; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328196; // data1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328196; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=22; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393732; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=23; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393732; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=24; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393732; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=25; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393732; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=26; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393732; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=27; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393732; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=28; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393732; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=29; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393732; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=30; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393732; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=31; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170948; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170948; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=32; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393732; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=33; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170948; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170948; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=34; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=35; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=36; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=37; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=38; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=39; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=40; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=41; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=42; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=43; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=44; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=45; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393732; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=46; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459268; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=47; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459268; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=48; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459268; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=49; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459268; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=50; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459268; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=51; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459268; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=52; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459268; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=53; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459268; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=54; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459268; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=55; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236484; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236484; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=56; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459268; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=57; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236484; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236484; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=58; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=59; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=60; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=61; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=62; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=63; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=64; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=65; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=66; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=67; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=68; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=69; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459268; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=70; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131589; // flush 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131589; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=71; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459269; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459269; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=72; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524805; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524805; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=73; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197125; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197125; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=74; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262661; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262661; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=75; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328197; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328197; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=76; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393733; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393733; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=77; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590341; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=78; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590341; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=79; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590341; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=80; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590341; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=81; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590341; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=82; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367557; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=83; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590341; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=84; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367557; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=85; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367557; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=86; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367557; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=87; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367557; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=88; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367557; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367557; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=89; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=90; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=91; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=92; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=93; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=94; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=95; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=96; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=97; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=98; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=99; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=100; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590341; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=101; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655877; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=102; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655877; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=103; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655877; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=104; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655877; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=105; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655877; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=106; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17433093; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=107; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655877; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=108; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17433093; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=109; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17433093; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=110; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17433093; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=111; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17433093; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=112; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17433093; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433093; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=113; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=114; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=115; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=116; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=117; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=118; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=119; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=120; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=121; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=122; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=123; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=124; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655877; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=125; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66054; // bit0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66054; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=126; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131590; // bit1 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131590; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=127; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197126; // bit2 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197126; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=128; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262662; // data0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262662; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=129; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328198; // data1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328198; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=130; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393734; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=131; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393734; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=132; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393734; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=133; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393734; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=134; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393734; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=135; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393734; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=136; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393734; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=137; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393734; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=138; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393734; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=139; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170950; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170950; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=140; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393734; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=141; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170950; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170950; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=142; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=143; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=144; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=145; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=146; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=147; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=148; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=149; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=150; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=151; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=152; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=153; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393734; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=154; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459270; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=155; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459270; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=156; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459270; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=157; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459270; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=158; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459270; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=159; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459270; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=160; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459270; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=161; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459270; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=162; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459270; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=163; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236486; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236486; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=164; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459270; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=165; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236486; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236486; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=166; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=167; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=168; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=169; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=170; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=171; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=172; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=173; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=174; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=175; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=176; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=177; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459270; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=178; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66055; // bit0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66055; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=179; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131591; // bit1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131591; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=180; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197127; // bit2 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197127; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=181; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262663; // data0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262663; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=182; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328199; // data1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328199; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=183; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393735; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=184; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393735; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=185; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393735; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=186; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393735; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=187; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393735; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=188; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393735; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=189; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393735; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=190; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393735; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=191; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393735; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=192; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170951; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170951; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=193; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393735; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=194; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170951; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170951; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=195; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=196; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=197; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=198; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=199; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=200; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=201; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=202; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=203; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=204; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=205; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=206; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393735; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=207; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459271; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=208; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459271; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=209; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459271; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=210; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459271; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=211; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459271; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=212; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459271; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=213; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459271; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=214; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459271; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=215; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459271; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=216; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236487; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236487; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=217; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459271; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=218; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236487; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236487; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=219; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=220; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=221; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=222; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=223; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=224; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=225; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=226; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=227; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=228; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=229; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=230; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459271; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=231; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66056; // bit0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66056; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=232; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131592; // bit1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131592; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=233; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197128; // bit2 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197128; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=234; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262664; // data0 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262664; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=235; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328200; // data1 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328200; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=236; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393736; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=237; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393736; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=238; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393736; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=239; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393736; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=240; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393736; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=241; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393736; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=242; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393736; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=243; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393736; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=244; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393736; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=245; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170952; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170952; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=246; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393736; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=247; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170952; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170952; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=248; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=249; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=250; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=251; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=252; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=253; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=254; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=255; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=256; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=257; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=258; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=259; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393736; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=260; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459272; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=261; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459272; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=262; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459272; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=263; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459272; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=264; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459272; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=265; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459272; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=266; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459272; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=267; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459272; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=268; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459272; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=269; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236488; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236488; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=270; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459272; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=271; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236488; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236488; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=272; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=273; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=274; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=275; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=276; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=277; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=278; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=279; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=280; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=281; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=282; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=283; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459272; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=284; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131841; // flush 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131841; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=285; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459521; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459521; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=286; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 525057; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 525057; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=287; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197377; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197377; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=288; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262913; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262913; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=289; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328449; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328449; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=290; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393985; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393985; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=291; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590593; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=292; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590593; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=293; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590593; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=294; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590593; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=295; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590593; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=296; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367809; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=297; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590593; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=298; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367809; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=299; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367809; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=300; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367809; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=301; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367809; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=302; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367809; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367809; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=303; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=304; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=305; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=306; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=307; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=308; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=309; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=310; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=311; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=312; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=313; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=314; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590593; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=315; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 656129; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=316; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 656129; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=317; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 656129; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=318; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 656129; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=319; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 656129; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=320; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17433345; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=321; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 656129; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=322; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17433345; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=323; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17433345; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=324; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17433345; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=325; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17433345; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=326; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17433345; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433345; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=327; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=328; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=329; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=330; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=331; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=332; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=333; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=334; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=335; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=336; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=337; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=338; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656129; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=339; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66306; // bit0 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66306; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=340; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131842; // bit1 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131842; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=341; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197378; // bit2 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197378; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=342; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262914; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262914; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=343; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328450; // data1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328450; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=344; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393986; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=345; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393986; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=346; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393986; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=347; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393986; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=348; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393986; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=349; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393986; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=350; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393986; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=351; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393986; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=352; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393986; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=353; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171202; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171202; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=354; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393986; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=355; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171202; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171202; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=356; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=357; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=358; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=359; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=360; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=361; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=362; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=363; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=364; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=365; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=366; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=367; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393986; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=368; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459522; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=369; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459522; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=370; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459522; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=371; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459522; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=372; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459522; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=373; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459522; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=374; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459522; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=375; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459522; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=376; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459522; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=377; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236738; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236738; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=378; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459522; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=379; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236738; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236738; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=380; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=381; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=382; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=383; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=384; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=385; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=386; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=387; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=388; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=389; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=390; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=391; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459522; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=392; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66307; // bit0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66307; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=393; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131843; // bit1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131843; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=394; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197379; // bit2 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197379; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=395; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262915; // data0 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262915; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=396; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328451; // data1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328451; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=397; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393987; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=398; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393987; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=399; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393987; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=400; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393987; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=401; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393987; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=402; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393987; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=403; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393987; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=404; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393987; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=405; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393987; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=406; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171203; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171203; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=407; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393987; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=408; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171203; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171203; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=409; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=410; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=411; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=412; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=413; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=414; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=415; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=416; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=417; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=418; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=419; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=420; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393987; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=421; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459523; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=422; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459523; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=423; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459523; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=424; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459523; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=425; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459523; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=426; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459523; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=427; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459523; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=428; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459523; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=429; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459523; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=430; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236739; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236739; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=431; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459523; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=432; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236739; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236739; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=433; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=434; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=435; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=436; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=437; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=438; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=439; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=440; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=441; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=442; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=443; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=444; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459523; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=445; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66308; // bit0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66308; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=446; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131844; // bit1 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131844; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=447; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197380; // bit2 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197380; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=448; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262916; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262916; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=449; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328452; // data1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328452; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=450; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393988; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=451; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393988; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=452; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393988; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=453; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393988; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=454; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393988; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=455; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393988; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=456; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393988; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=457; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393988; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=458; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393988; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=459; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171204; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171204; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=460; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393988; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=461; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171204; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171204; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=462; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=463; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=464; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=465; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=466; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=467; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=468; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=469; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=470; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=471; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=472; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=473; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393988; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=474; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459524; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=475; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459524; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=476; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459524; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=477; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459524; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=478; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459524; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=479; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459524; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=480; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459524; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=481; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459524; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=482; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459524; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=483; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236740; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236740; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=484; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459524; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=485; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236740; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236740; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=486; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=487; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=488; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=489; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=490; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=491; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=492; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=493; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=494; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=495; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=496; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=497; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459524; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=498; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131845; // flush 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131845; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=499; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459525; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459525; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=500; // 11


    // regtest_wr_3.c
    group = 3;

    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 525061; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 525061; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=1; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197381; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197381; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=2; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262917; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262917; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=3; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328453; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328453; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=4; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393989; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393989; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=5; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590597; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=6; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590597; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=7; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590597; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=8; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590597; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=9; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590597; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=10; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367813; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=11; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590597; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=12; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367813; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=13; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367813; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=14; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367813; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=15; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367813; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=16; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367813; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367813; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=17; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=18; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=19; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=20; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=21; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=22; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=23; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=24; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=25; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=26; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=27; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=28; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590597; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=29; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 656133; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=30; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 656133; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=31; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 656133; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=32; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 656133; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=33; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 656133; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=34; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17433349; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=35; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 656133; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=36; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17433349; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=37; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17433349; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=38; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17433349; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=39; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17433349; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=40; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17433349; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433349; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=41; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=42; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=43; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=44; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=45; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=46; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=47; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=48; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=49; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=50; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=51; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=52; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 656133; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=53; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66310; // bit0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66310; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=54; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131846; // bit1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131846; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=55; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197382; // bit2 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197382; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=56; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262918; // data0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262918; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=57; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328454; // data1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328454; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=58; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393990; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=59; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393990; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=60; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393990; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=61; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393990; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=62; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393990; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=63; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393990; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=64; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393990; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=65; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393990; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=66; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393990; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=67; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171206; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171206; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=68; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393990; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=69; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171206; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171206; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=70; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=71; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=72; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=73; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=74; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=75; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=76; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=77; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=78; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=79; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=80; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=81; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393990; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=82; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459526; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=83; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459526; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=84; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459526; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=85; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459526; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=86; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459526; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=87; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459526; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=88; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459526; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=89; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459526; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=90; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459526; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=91; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236742; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236742; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=92; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459526; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=93; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236742; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236742; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=94; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=95; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=96; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=97; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=98; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=99; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=100; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=101; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=102; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=103; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=104; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=105; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459526; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=106; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66311; // bit0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66311; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=107; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131847; // bit1 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131847; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=108; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197383; // bit2 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197383; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=109; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262919; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262919; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=110; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328455; // data1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328455; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=111; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393991; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=112; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393991; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=113; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393991; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=114; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393991; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=115; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393991; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=116; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393991; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=117; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393991; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=118; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393991; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=119; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393991; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=120; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171207; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171207; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=121; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393991; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=122; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171207; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171207; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=123; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=124; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=125; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=126; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=127; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=128; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=129; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=130; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=131; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=132; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=133; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=134; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393991; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=135; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459527; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=136; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459527; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=137; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459527; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=138; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459527; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=139; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459527; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=140; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459527; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=141; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459527; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=142; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459527; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=143; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459527; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=144; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236743; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236743; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=145; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459527; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=146; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236743; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236743; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=147; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=148; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=149; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=150; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=151; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=152; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=153; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=154; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=155; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=156; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=157; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=158; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459527; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=159; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66312; // bit0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66312; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=160; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131848; // bit1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131848; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=161; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197384; // bit2 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197384; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=162; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262920; // data0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262920; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=163; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328456; // data1 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328456; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=164; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393992; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=165; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393992; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=166; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393992; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=167; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393992; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=168; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393992; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=169; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393992; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=170; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393992; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=171; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393992; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=172; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393992; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=173; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17171208; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171208; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=174; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393992; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=175; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17171208; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17171208; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=176; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=177; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=178; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=179; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=180; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=181; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=182; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=183; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=184; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=185; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=186; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=187; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393992; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=188; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459528; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=189; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459528; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=190; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459528; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=191; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459528; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=192; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459528; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=193; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459528; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=194; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459528; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=195; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459528; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=196; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459528; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=197; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236744; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236744; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=198; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459528; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=199; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236744; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236744; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=200; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=201; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=202; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=203; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=204; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=205; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=206; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=207; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=208; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=209; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=210; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=211; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459528; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=212; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 1; // input_width_1_num_0_reg_value 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // input_width_1_num_0_reg_value
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=213; // 2
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 1; // input_width_1_num_0_reg_sel 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // input_width_1_num_0_reg_sel
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=214; // 2
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 1; // input_width_1_num_1_reg_value 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // input_width_1_num_1_reg_value
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=215; // 2
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 1; // input_width_1_num_1_reg_sel 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // input_width_1_num_1_reg_sel
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=216; // 2
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 1; // flush_reg_value 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // flush_reg_value
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=217; // 2
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 1; // flush_reg_sel 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // flush_reg_sel
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=218; // 2
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(71, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 71) fail=219; // 256
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 989855745; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 989855745; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=220; // 2
    lo = 8;
    hi = 10;
    reg_mprj_cfg_addr = 1358954497; // mode 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1358954497; // mode
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=221; // 4
    lo = 12;
    hi = 28;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_0 
    reg_mprj_cfg_wdata = encode(14390, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14390) fail=222; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 822083585; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_1 
    reg_mprj_cfg_wdata = encode(5381, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 822083585; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5381) fail=223; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 822083585; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_2 
    reg_mprj_cfg_wdata = encode(30822, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 822083585; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30822) fail=224; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 838860801; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_3 
    reg_mprj_cfg_wdata = encode(62678, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 838860801; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 62678) fail=225; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 838860801; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_4 
    reg_mprj_cfg_wdata = encode(57899, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 838860801; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57899) fail=226; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 855638017; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_5 
    reg_mprj_cfg_wdata = encode(17553, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 855638017; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 17553) fail=227; // 65536
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 369098753; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 369098753; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=228; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 570425345; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_dimensionality 
    reg_mprj_cfg_wdata = encode(3, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 570425345; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=229; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1275068417; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(38279, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1275068417; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 38279) fail=230; // 65536
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 503316481; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(22675, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 503316481; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 22675) fail=231; // 65536
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(14, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14) fail=232; // 16
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(8, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=233; // 16
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=234; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=235; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=236; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(9, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=237; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 939524097; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(49530, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 939524097; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 49530) fail=238; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 939524097; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(51538, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 939524097; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 51538) fail=239; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 956301313; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(41685, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 956301313; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 41685) fail=240; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 956301313; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(14215, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 956301313; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14215) fail=241; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 973078529; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(5188, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 973078529; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5188) fail=242; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 973078529; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(5695, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 973078529; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5695) fail=243; // 65536
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(8, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=244; // 16
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=245; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(4, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=246; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=247; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=248; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=249; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 452984833; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(21614, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 452984833; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 21614) fail=250; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 452984833; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(50983, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 452984833; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 50983) fail=251; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 469762049; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(64252, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 469762049; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 64252) fail=252; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 469762049; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(16205, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 469762049; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 16205) fail=253; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 486539265; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(13614, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 486539265; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 13614) fail=254; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 486539265; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(13012, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 486539265; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 13012) fail=255; // 65536
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 1358954497; // tile_en 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1358954497; // tile_en
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=256; // 2
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=257; // 16
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(189, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 189) fail=258; // 256
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(43, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 43) fail=259; // 256
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(94, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 94) fail=260; // 256
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(127, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 754974721; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 127) fail=261; // 256
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(62, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 62) fail=262; // 256
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(180, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 180) fail=263; // 256
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 436207617; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 436207617; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=264; // 2
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1207959553; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(15178, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1207959553; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15178) fail=265; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1224736769; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(1170, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1224736769; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1170) fail=266; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1224736769; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(12807, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1224736769; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12807) fail=267; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1241513985; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(35821, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1241513985; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 35821) fail=268; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1241513985; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(34931, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1241513985; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 34931) fail=269; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1258291201; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(53895, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1258291201; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 53895) fail=270; // 65536
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(14, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14) fail=271; // 16
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(29, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 29) fail=272; // 256
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 922746881; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(33603, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 922746881; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 33603) fail=273; // 65536
    lo = 24;
    hi = 25;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=274; // 2
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 318767105; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality 
    reg_mprj_cfg_wdata = encode(13, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 318767105; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 13) fail=275; // 16
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 251658241; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 251658241; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=276; // 2
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=277; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(7, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=278; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(5, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=279; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=280; // 16
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(5, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=281; // 16
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(14, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14) fail=282; // 16
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 503316481; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 503316481; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=283; // 2
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 1107296257; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1107296257; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=284; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(9, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=285; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1006632961; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(32498, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1006632961; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32498) fail=286; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1006632961; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(25228, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1006632961; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 25228) fail=287; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1023410177; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(57558, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1023410177; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57558) fail=288; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1023410177; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(30164, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1023410177; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30164) fail=289; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1040187393; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(62095, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1040187393; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 62095) fail=290; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1040187393; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(16968, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1040187393; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 16968) fail=291; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1124073473; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_0 
    reg_mprj_cfg_wdata = encode(1501, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1124073473; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1501) fail=292; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1124073473; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_1 
    reg_mprj_cfg_wdata = encode(16303, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1124073473; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 16303) fail=293; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1140850689; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_2 
    reg_mprj_cfg_wdata = encode(36430, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1140850689; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 36430) fail=294; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1140850689; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_3 
    reg_mprj_cfg_wdata = encode(27599, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1140850689; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 27599) fail=295; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1157627905; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_4 
    reg_mprj_cfg_wdata = encode(32809, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1157627905; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32809) fail=296; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1157627905; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_5 
    reg_mprj_cfg_wdata = encode(32853, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1157627905; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_1_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32853) fail=297; // 65536
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(205, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 205) fail=298; // 256
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(210, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 210) fail=299; // 256
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(1, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 721420289; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=300; // 256
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=301; // 256
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(205, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 205) fail=302; // 256
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(203, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 738197505; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 203) fail=303; // 256
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(3, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=304; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=305; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(7, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=306; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=307; // 16
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(1, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=308; // 16
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(9, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=309; // 16
    lo = 10;
    hi = 26;
    reg_mprj_cfg_addr = 1; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_0 
    reg_mprj_cfg_wdata = encode(23875, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 23875) fail=310; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 16777217; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_1 
    reg_mprj_cfg_wdata = encode(19619, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 16777217; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 19619) fail=311; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 16777217; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_2 
    reg_mprj_cfg_wdata = encode(40144, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 16777217; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40144) fail=312; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 33554433; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_3 
    reg_mprj_cfg_wdata = encode(29748, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 33554433; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 29748) fail=313; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 33554433; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_4 
    reg_mprj_cfg_wdata = encode(57227, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 33554433; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57227) fail=314; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 50331649; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_5 
    reg_mprj_cfg_wdata = encode(6216, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 50331649; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6216) fail=315; // 65536
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_chain_chain_en
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=316; // 2
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 620756993; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_dimensionality 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 620756993; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=317; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=318; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=319; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=320; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=321; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 1358954497; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(7, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1358954497; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=322; // 16
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 1358954497; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1358954497; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=323; // 16
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=324; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 201326593; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(33044, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 201326593; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 33044) fail=325; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 201326593; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(42762, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 201326593; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 42762) fail=326; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 218103809; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(49056, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 218103809; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 49056) fail=327; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 218103809; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(4725, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 218103809; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4725) fail=328; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 234881025; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(5992, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 234881025; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5992) fail=329; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 234881025; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(4932, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 234881025; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4932) fail=330; // 65536
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_0_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=331; // 16
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 436207617; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(23677, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 436207617; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_0_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 23677) fail=332; // 65536
    lo = 9;
    hi = 17;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(202, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 202) fail=333; // 256
    lo = 17;
    hi = 25;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(13, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 13) fail=334; // 256
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(129, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 129) fail=335; // 256
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(71, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 71) fail=336; // 256
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(25, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 25) fail=337; // 256
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(113, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 704643073; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 113) fail=338; // 256
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(40, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40) fail=339; // 256
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(212, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 212) fail=340; // 256
    lo = 8;
    hi = 16;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(188, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 188) fail=341; // 256
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(47, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 47) fail=342; // 256
    lo = 24;
    hi = 31;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(82, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 788529153; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 82) fail=343; // 256
    lo = 0;
    hi = 8;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(179, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 805306369; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 179) fail=344; // 256
    lo = 4;
    hi = 20;
    reg_mprj_cfg_addr = 570425345; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_0 
    reg_mprj_cfg_wdata = encode(59867, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 570425345; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 59867) fail=345; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 587202561; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_1 
    reg_mprj_cfg_wdata = encode(59535, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 587202561; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 59535) fail=346; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 587202561; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_2 
    reg_mprj_cfg_wdata = encode(34627, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 587202561; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 34627) fail=347; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 603979777; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_3 
    reg_mprj_cfg_wdata = encode(35114, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 603979777; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 35114) fail=348; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 603979777; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_4 
    reg_mprj_cfg_wdata = encode(2979, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 603979777; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2979) fail=349; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 620756993; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_5 
    reg_mprj_cfg_wdata = encode(31667, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 620756993; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_0_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 31667) fail=350; // 65536
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 922746881; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 922746881; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_0_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=351; // 2
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(4, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1342177281; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_write_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=352; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(1, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1174405121; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=353; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 268435457; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(59638, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 268435457; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 59638) fail=354; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 268435457; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(62195, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 268435457; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 62195) fail=355; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 285212673; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(15479, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 285212673; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15479) fail=356; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 285212673; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(50213, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 285212673; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 50213) fail=357; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 301989889; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(30414, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 301989889; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30414) fail=358; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 301989889; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(57359, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 301989889; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57359) fail=359; // 65536
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=360; // 16
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(3, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=361; // 16
    lo = 8;
    hi = 12;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(8, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=362; // 16
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=363; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(1, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=364; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1191182337; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=365; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 637534209; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_0 
    reg_mprj_cfg_wdata = encode(12603, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 637534209; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12603) fail=366; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 637534209; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_1 
    reg_mprj_cfg_wdata = encode(20347, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 637534209; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 20347) fail=367; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 654311425; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_2 
    reg_mprj_cfg_wdata = encode(53026, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 654311425; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 53026) fail=368; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 654311425; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_3 
    reg_mprj_cfg_wdata = encode(7691, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 654311425; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7691) fail=369; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 671088641; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_4 
    reg_mprj_cfg_wdata = encode(17288, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 671088641; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 17288) fail=370; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 671088641; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_5 
    reg_mprj_cfg_wdata = encode(43268, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 671088641; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_loops_in2buf_autovec_write_1_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 43268) fail=371; // 65536
    lo = 4;
    hi = 20;
    reg_mprj_cfg_addr = 318767105; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_0 
    reg_mprj_cfg_wdata = encode(54179, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 318767105; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 54179) fail=372; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 335544321; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_1 
    reg_mprj_cfg_wdata = encode(14982, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 335544321; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14982) fail=373; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 335544321; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_2 
    reg_mprj_cfg_wdata = encode(48218, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 335544321; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 48218) fail=374; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 352321537; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_3 
    reg_mprj_cfg_wdata = encode(63820, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 352321537; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 63820) fail=375; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 352321537; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_4 
    reg_mprj_cfg_wdata = encode(51165, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 352321537; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 51165) fail=376; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 369098753; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_5 
    reg_mprj_cfg_wdata = encode(63295, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 369098753; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_0_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 63295) fail=377; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 67108865; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(37291, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 67108865; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 37291) fail=378; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 83886081; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(43199, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 83886081; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 43199) fail=379; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 83886081; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(37737, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 83886081; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 37737) fail=380; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 100663297; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(6899, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 100663297; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6899) fail=381; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 100663297; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(60313, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 100663297; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 60313) fail=382; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(38099, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 38099) fail=383; // 65536
    lo = 1;
    hi = 9;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_starting_addr 
    reg_mprj_cfg_wdata = encode(16, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 687865857; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_input_addr_gen_0_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 16) fail=384; // 256
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 872415233; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_0 
    reg_mprj_cfg_wdata = encode(17108, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 872415233; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 17108) fail=385; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 872415233; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_1 
    reg_mprj_cfg_wdata = encode(49815, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 872415233; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 49815) fail=386; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 889192449; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_2 
    reg_mprj_cfg_wdata = encode(14505, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 889192449; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14505) fail=387; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 889192449; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_3 
    reg_mprj_cfg_wdata = encode(1971, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 889192449; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1971) fail=388; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 905969665; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_4 
    reg_mprj_cfg_wdata = encode(28234, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 905969665; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 28234) fail=389; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 905969665; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_5 
    reg_mprj_cfg_wdata = encode(63112, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 905969665; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 63112) fail=390; // 65536
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=391; // 16
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1207959553; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(51125, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1207959553; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_0_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 51125) fail=392; // 65536
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(14, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14) fail=393; // 16
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 184549377; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 184549377; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=394; // 2
    lo = 6;
    hi = 10;
    reg_mprj_cfg_addr = 1; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality 
    reg_mprj_cfg_wdata = encode(6, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_loops_stencil_valid_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=395; // 16
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 251658241; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(40576, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 251658241; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_1_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40576) fail=396; // 65536
    lo = 16;
    hi = 24;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr 
    reg_mprj_cfg_wdata = encode(31, lo); // 256
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 771751937; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_only_output_addr_gen_1_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 31) fail=397; // 256
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 385875969; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_0 
    reg_mprj_cfg_wdata = encode(59016, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 385875969; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 59016) fail=398; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 385875969; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_1 
    reg_mprj_cfg_wdata = encode(6051, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 385875969; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6051) fail=399; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 402653185; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_2 
    reg_mprj_cfg_wdata = encode(48891, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 402653185; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 48891) fail=400; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 402653185; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_3 
    reg_mprj_cfg_wdata = encode(38192, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 402653185; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 38192) fail=401; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 419430401; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_4 
    reg_mprj_cfg_wdata = encode(10738, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 419430401; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10738) fail=402; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 419430401; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_5 
    reg_mprj_cfg_wdata = encode(9054, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 419430401; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_loops_in2buf_1_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9054) fail=403; // 65536
    lo = 12;
    hi = 16;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_0 
    reg_mprj_cfg_wdata = encode(14, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 14) fail=404; // 16
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_1 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=405; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_2 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=406; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_3 
    reg_mprj_cfg_wdata = encode(7, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=407; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_4 
    reg_mprj_cfg_wdata = encode(15, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 15) fail=408; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_5 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_addr_gen_0_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=409; // 16
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 989855745; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(30393, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 989855745; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_output_sched_gen_1_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30393) fail=410; // 65536
    lo = 4;
    hi = 20;
    reg_mprj_cfg_addr = 1056964609; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_0 
    reg_mprj_cfg_wdata = encode(8884, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1056964609; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8884) fail=411; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1073741825; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_1 
    reg_mprj_cfg_wdata = encode(28945, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1073741825; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 28945) fail=412; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1073741825; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_2 
    reg_mprj_cfg_wdata = encode(29466, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1073741825; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 29466) fail=413; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1090519041; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_3 
    reg_mprj_cfg_wdata = encode(36725, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1090519041; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 36725) fail=414; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1090519041; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_4 
    reg_mprj_cfg_wdata = encode(30863, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1090519041; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30863) fail=415; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1107296257; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_5 
    reg_mprj_cfg_wdata = encode(33429, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1107296257; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_ranges_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 33429) fail=416; // 65536
    lo = 16;
    hi = 17;
    reg_mprj_cfg_addr = 50331649; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 50331649; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=417; // 2
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 67108865; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(40475, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 67108865; // mem_ctrl_stencil_valid_flat_stencil_valid_inst_stencil_valid_sched_gen_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40475) fail=418; // 65536
    lo = 16;
    hi = 17;
    reg_mprj_cfg_addr = 1258291201; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable 
    reg_mprj_cfg_wdata = encode(1, lo); // 2
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1258291201; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_enable
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=419; // 2
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 855638017; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 855638017; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_sram_tb_shared_loops_buf2out_autovec_read_1_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=420; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 1056964609; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality 
    reg_mprj_cfg_wdata = encode(11, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1056964609; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_loops_buf2out_read_0_dimensionality
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11) fail=421; // 16
    lo = 1;
    hi = 17;
    reg_mprj_cfg_addr = 184549377; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr 
    reg_mprj_cfg_wdata = encode(56406, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 184549377; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_write_sched_gen_0_sched_addr_gen_starting_addr
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 56406) fail=422; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 520093697; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(48875, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 520093697; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 48875) fail=423; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 520093697; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(31285, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 520093697; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 31285) fail=424; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 536870913; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(47275, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 536870913; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 47275) fail=425; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 536870913; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(50226, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 536870913; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 50226) fail=426; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 553648129; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(62097, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 553648129; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 62097) fail=427; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 553648129; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(32846, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 553648129; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_sram_shared_agg_read_sched_gen_1_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32846) fail=428; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1275068417; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_0 
    reg_mprj_cfg_wdata = encode(46184, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1275068417; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 46184) fail=429; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1291845633; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_1 
    reg_mprj_cfg_wdata = encode(35032, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1291845633; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 35032) fail=430; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1291845633; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_2 
    reg_mprj_cfg_wdata = encode(25032, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1291845633; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 25032) fail=431; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1308622849; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_3 
    reg_mprj_cfg_wdata = encode(53975, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1308622849; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 53975) fail=432; // 65536
    lo = 16;
    hi = 31;
    reg_mprj_cfg_addr = 1308622849; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_4 
    reg_mprj_cfg_wdata = encode(18333, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1308622849; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 18333) fail=433; // 65536
    lo = 0;
    hi = 16;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_5 
    reg_mprj_cfg_wdata = encode(18051, lo); // 65536
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1325400065; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_tb_only_tb_read_sched_gen_1_sched_addr_gen_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 18051) fail=434; // 65536
    lo = 16;
    hi = 20;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_0 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=435; // 16
    lo = 20;
    hi = 24;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_1 
    reg_mprj_cfg_wdata = encode(10, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=436; // 16
    lo = 24;
    hi = 28;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_2 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=437; // 16
    lo = 28;
    hi = 31;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_3 
    reg_mprj_cfg_wdata = encode(2, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=438; // 16
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_4 
    reg_mprj_cfg_wdata = encode(3, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=439; // 16
    lo = 4;
    hi = 8;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_5 
    reg_mprj_cfg_wdata = encode(12, lo); // 16
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // mem_ctrl_strg_ub_vec_flat_strg_ub_vec_inst_agg_only_agg_read_addr_gen_1_strides_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 12) fail=440; // 16
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 1; // SRAM_0_0 
    reg_mprj_cfg_wdata = encode(40015, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 1; // SRAM_0_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40015) fail=441; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 16777217; // SRAM_0_1 
    reg_mprj_cfg_wdata = encode(31337, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 16777217; // SRAM_0_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 31337) fail=442; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 33554433; // SRAM_0_2 
    reg_mprj_cfg_wdata = encode(25068, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 33554433; // SRAM_0_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 25068) fail=443; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 50331649; // SRAM_0_3 
    reg_mprj_cfg_wdata = encode(26361, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 50331649; // SRAM_0_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 26361) fail=444; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 67108865; // SRAM_0_4 
    reg_mprj_cfg_wdata = encode(139, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 67108865; // SRAM_0_4
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 139) fail=445; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 83886081; // SRAM_0_5 
    reg_mprj_cfg_wdata = encode(13923, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 83886081; // SRAM_0_5
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 13923) fail=446; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 100663297; // SRAM_0_6 
    reg_mprj_cfg_wdata = encode(63492, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 100663297; // SRAM_0_6
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 63492) fail=447; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 117440513; // SRAM_0_7 
    reg_mprj_cfg_wdata = encode(45546, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 117440513; // SRAM_0_7
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 45546) fail=448; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 134217729; // SRAM_0_8 
    reg_mprj_cfg_wdata = encode(64709, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 134217729; // SRAM_0_8
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 64709) fail=449; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 150994945; // SRAM_0_9 
    reg_mprj_cfg_wdata = encode(28673, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 150994945; // SRAM_0_9
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 28673) fail=450; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 167772161; // SRAM_0_10 
    reg_mprj_cfg_wdata = encode(18907, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 167772161; // SRAM_0_10
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 18907) fail=451; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 184549377; // SRAM_0_11 
    reg_mprj_cfg_wdata = encode(19923, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 184549377; // SRAM_0_11
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 19923) fail=452; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 201326593; // SRAM_0_12 
    reg_mprj_cfg_wdata = encode(8289, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 201326593; // SRAM_0_12
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8289) fail=453; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 218103809; // SRAM_0_13 
    reg_mprj_cfg_wdata = encode(24851, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 218103809; // SRAM_0_13
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 24851) fail=454; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 234881025; // SRAM_0_14 
    reg_mprj_cfg_wdata = encode(29063, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 234881025; // SRAM_0_14
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 29063) fail=455; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 251658241; // SRAM_0_15 
    reg_mprj_cfg_wdata = encode(26016, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 251658241; // SRAM_0_15
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 26016) fail=456; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 268435457; // SRAM_0_16 
    reg_mprj_cfg_wdata = encode(1090, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 268435457; // SRAM_0_16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1090) fail=457; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 285212673; // SRAM_0_17 
    reg_mprj_cfg_wdata = encode(41601, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 285212673; // SRAM_0_17
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 41601) fail=458; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 301989889; // SRAM_0_18 
    reg_mprj_cfg_wdata = encode(47848, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 301989889; // SRAM_0_18
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 47848) fail=459; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 318767105; // SRAM_0_19 
    reg_mprj_cfg_wdata = encode(48331, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 318767105; // SRAM_0_19
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 48331) fail=460; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 335544321; // SRAM_0_20 
    reg_mprj_cfg_wdata = encode(56611, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 335544321; // SRAM_0_20
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 56611) fail=461; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 352321537; // SRAM_0_21 
    reg_mprj_cfg_wdata = encode(32461, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 352321537; // SRAM_0_21
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32461) fail=462; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 369098753; // SRAM_0_22 
    reg_mprj_cfg_wdata = encode(33918, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 369098753; // SRAM_0_22
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 33918) fail=463; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 385875969; // SRAM_0_23 
    reg_mprj_cfg_wdata = encode(57892, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 385875969; // SRAM_0_23
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57892) fail=464; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 402653185; // SRAM_0_24 
    reg_mprj_cfg_wdata = encode(45557, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 402653185; // SRAM_0_24
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 45557) fail=465; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 419430401; // SRAM_0_25 
    reg_mprj_cfg_wdata = encode(45989, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 419430401; // SRAM_0_25
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 45989) fail=466; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 436207617; // SRAM_0_26 
    reg_mprj_cfg_wdata = encode(30870, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 436207617; // SRAM_0_26
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30870) fail=467; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 452984833; // SRAM_0_27 
    reg_mprj_cfg_wdata = encode(11930, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 452984833; // SRAM_0_27
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 11930) fail=468; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 469762049; // SRAM_0_28 
    reg_mprj_cfg_wdata = encode(32381, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 469762049; // SRAM_0_28
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32381) fail=469; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 486539265; // SRAM_0_29 
    reg_mprj_cfg_wdata = encode(57959, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 486539265; // SRAM_0_29
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 57959) fail=470; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 503316481; // SRAM_0_30 
    reg_mprj_cfg_wdata = encode(28435, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 503316481; // SRAM_0_30
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 28435) fail=471; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 520093697; // SRAM_0_31 
    reg_mprj_cfg_wdata = encode(7856, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 520093697; // SRAM_0_31
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7856) fail=472; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 536870913; // SRAM_0_32 
    reg_mprj_cfg_wdata = encode(30685, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 536870913; // SRAM_0_32
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 30685) fail=473; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 553648129; // SRAM_0_33 
    reg_mprj_cfg_wdata = encode(19390, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 553648129; // SRAM_0_33
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 19390) fail=474; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 570425345; // SRAM_0_34 
    reg_mprj_cfg_wdata = encode(2389, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 570425345; // SRAM_0_34
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2389) fail=475; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 587202561; // SRAM_0_35 
    reg_mprj_cfg_wdata = encode(21200, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 587202561; // SRAM_0_35
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 21200) fail=476; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 603979777; // SRAM_0_36 
    reg_mprj_cfg_wdata = encode(6173, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 603979777; // SRAM_0_36
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6173) fail=477; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 620756993; // SRAM_0_37 
    reg_mprj_cfg_wdata = encode(40534, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 620756993; // SRAM_0_37
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40534) fail=478; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 637534209; // SRAM_0_38 
    reg_mprj_cfg_wdata = encode(3248, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 637534209; // SRAM_0_38
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3248) fail=479; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 654311425; // SRAM_0_39 
    reg_mprj_cfg_wdata = encode(43621, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 654311425; // SRAM_0_39
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 43621) fail=480; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 671088641; // SRAM_0_40 
    reg_mprj_cfg_wdata = encode(45816, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 671088641; // SRAM_0_40
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 45816) fail=481; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 687865857; // SRAM_0_41 
    reg_mprj_cfg_wdata = encode(23012, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 687865857; // SRAM_0_41
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 23012) fail=482; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 704643073; // SRAM_0_42 
    reg_mprj_cfg_wdata = encode(21415, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 704643073; // SRAM_0_42
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 21415) fail=483; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 721420289; // SRAM_0_43 
    reg_mprj_cfg_wdata = encode(4346, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 721420289; // SRAM_0_43
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4346) fail=484; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 738197505; // SRAM_0_44 
    reg_mprj_cfg_wdata = encode(17628, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 738197505; // SRAM_0_44
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 17628) fail=485; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 754974721; // SRAM_0_45 
    reg_mprj_cfg_wdata = encode(9512, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 754974721; // SRAM_0_45
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9512) fail=486; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 771751937; // SRAM_0_46 
    reg_mprj_cfg_wdata = encode(60632, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 771751937; // SRAM_0_46
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 60632) fail=487; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 788529153; // SRAM_0_47 
    reg_mprj_cfg_wdata = encode(58350, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 788529153; // SRAM_0_47
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 58350) fail=488; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 805306369; // SRAM_0_48 
    reg_mprj_cfg_wdata = encode(35258, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 805306369; // SRAM_0_48
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 35258) fail=489; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 822083585; // SRAM_0_49 
    reg_mprj_cfg_wdata = encode(51965, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 822083585; // SRAM_0_49
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 51965) fail=490; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 838860801; // SRAM_0_50 
    reg_mprj_cfg_wdata = encode(40454, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 838860801; // SRAM_0_50
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40454) fail=491; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 855638017; // SRAM_0_51 
    reg_mprj_cfg_wdata = encode(20191, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 855638017; // SRAM_0_51
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 20191) fail=492; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 872415233; // SRAM_0_52 
    reg_mprj_cfg_wdata = encode(56947, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 872415233; // SRAM_0_52
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 56947) fail=493; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 889192449; // SRAM_0_53 
    reg_mprj_cfg_wdata = encode(35644, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 889192449; // SRAM_0_53
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 35644) fail=494; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 905969665; // SRAM_0_54 
    reg_mprj_cfg_wdata = encode(64276, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 905969665; // SRAM_0_54
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 64276) fail=495; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 922746881; // SRAM_0_55 
    reg_mprj_cfg_wdata = encode(19973, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 922746881; // SRAM_0_55
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 19973) fail=496; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 939524097; // SRAM_0_56 
    reg_mprj_cfg_wdata = encode(7285, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 939524097; // SRAM_0_56
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7285) fail=497; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 956301313; // SRAM_0_57 
    reg_mprj_cfg_wdata = encode(17582, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 956301313; // SRAM_0_57
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 17582) fail=498; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 973078529; // SRAM_0_58 
    reg_mprj_cfg_wdata = encode(40505, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 973078529; // SRAM_0_58
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 40505) fail=499; // 65535
    lo = 0;
    hi = 31;
    reg_mprj_cfg_addr = 989855745; // SRAM_0_59 
    reg_mprj_cfg_wdata = encode(32721, lo); // 65535
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 989855745; // SRAM_0_59
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 32721) fail=500; // 65535


	while(1) {
	    putchar('|'); putchar(0x2d); // clear screen
        if (fail > 0) {
            print("failed\n");
            print_dec(group); print("\n");
            print_dec(fail); print("\n");
            // print_hex(data, 8); print("\n");
        } else {
            print("success!\n");
            // print_hex(data, 8); print("\n");
        }
        for (j=0; j<10000; j++);
    }
}

