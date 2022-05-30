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
    int mask;
    if (hi >= 31 | hi == 0) {
        mask = 0xFFFFFFFF;
    } else {
        mask = (1 << hi+1) - 1;
    }
    val = val & mask;
    return val >> lo;
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

    // regtest_wr_0.c
    group = 0;

    // write then read config test
    int fail = 0;
    int lo, hi;
    unsigned int rtl;
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131073; // flush 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131073; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=1; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 458753; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458753; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=2; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524289; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524289; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=3; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196609; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196609; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=4; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262145; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262145; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=5; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327681; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327681; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=6; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393217; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393217; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=7; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 589825; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=8; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 589825; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=9; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 589825; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=10; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 589825; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=11; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 589825; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=12; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367041; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=13; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 589825; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=14; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367041; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=15; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367041; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=16; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367041; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=17; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367041; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=18; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367041; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367041; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=19; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=20; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=21; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=22; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=23; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=24; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=25; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=26; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=27; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=28; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=29; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=30; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589825; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=31; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655361; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=32; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655361; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=33; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655361; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=34; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655361; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=35; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655361; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=36; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17432577; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=37; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655361; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=38; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17432577; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=39; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17432577; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=40; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17432577; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=41; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17432577; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=42; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17432577; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432577; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=43; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=44; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=45; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=46; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=47; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=48; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=49; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=50; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=51; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=52; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=53; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=54; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655361; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=55; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65538; // bit0 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65538; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=56; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131074; // bit1 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131074; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=57; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196610; // bit2 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196610; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=58; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262146; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262146; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=59; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327682; // data1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327682; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=60; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393218; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=61; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393218; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=62; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393218; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=63; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393218; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=64; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393218; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=65; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393218; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=66; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393218; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=67; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393218; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=68; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393218; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=69; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170434; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170434; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=70; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393218; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=71; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170434; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170434; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=72; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=73; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=74; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=75; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=76; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=77; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=78; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=79; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=80; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=81; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=82; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=83; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393218; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=84; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458754; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=85; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458754; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=86; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458754; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=87; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458754; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=88; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458754; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=89; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458754; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=90; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458754; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=91; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458754; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=92; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458754; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=93; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235970; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235970; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=94; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458754; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=95; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235970; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235970; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=96; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=97; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=98; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=99; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=100; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=101; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=102; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=103; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=104; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=105; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=106; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=107; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458754; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=108; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65539; // bit0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65539; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=109; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131075; // bit1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131075; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=110; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196611; // bit2 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196611; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=111; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262147; // data0 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262147; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=112; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327683; // data1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327683; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=113; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393219; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=114; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393219; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=115; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393219; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=116; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393219; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=117; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393219; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=118; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393219; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=119; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393219; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=120; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393219; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=121; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393219; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=122; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170435; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170435; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=123; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393219; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=124; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170435; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170435; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=125; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=126; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=127; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=128; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=129; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=130; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=131; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=132; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=133; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=134; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=135; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=136; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393219; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=137; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458755; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=138; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458755; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=139; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458755; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=140; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458755; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=141; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458755; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=142; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458755; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=143; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458755; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=144; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458755; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=145; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458755; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=146; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235971; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235971; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=147; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458755; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=148; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235971; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235971; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=149; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=150; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=151; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=152; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=153; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=154; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=155; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=156; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=157; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=158; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=159; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=160; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458755; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=161; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65540; // bit0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65540; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=162; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131076; // bit1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131076; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=163; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196612; // bit2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196612; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=164; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262148; // data0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262148; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=165; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327684; // data1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327684; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=166; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393220; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=167; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393220; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=168; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393220; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=169; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393220; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=170; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393220; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=171; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393220; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=172; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393220; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=173; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393220; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=174; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393220; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=175; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170436; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170436; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=176; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393220; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=177; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170436; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170436; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=178; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=179; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=180; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=181; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=182; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=183; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=184; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=185; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=186; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=187; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=188; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=189; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393220; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=190; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458756; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=191; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458756; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=192; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458756; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=193; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458756; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=194; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458756; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=195; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458756; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=196; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458756; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=197; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458756; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=198; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458756; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=199; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235972; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235972; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=200; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458756; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=201; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235972; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235972; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=202; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=203; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=204; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=205; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=206; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=207; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=208; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=209; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=210; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=211; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=212; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=213; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458756; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=214; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131077; // flush 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131077; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=215; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 458757; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458757; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=216; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524293; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524293; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=217; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196613; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196613; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=218; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262149; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262149; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=219; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327685; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327685; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=220; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393221; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393221; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=221; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 589829; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=222; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 589829; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=223; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 589829; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=224; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 589829; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=225; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 589829; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=226; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367045; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=227; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 589829; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=228; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367045; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=229; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367045; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=230; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367045; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=231; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367045; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=232; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367045; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367045; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=233; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=234; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=235; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=236; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=237; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=238; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=239; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=240; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=241; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=242; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=243; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=244; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 589829; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=245; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655365; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=246; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655365; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=247; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655365; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=248; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655365; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=249; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655365; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=250; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17432581; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=251; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655365; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=252; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17432581; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=253; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17432581; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=254; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17432581; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=255; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17432581; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=256; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17432581; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432581; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=257; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=258; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=259; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=260; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=261; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=262; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=263; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=264; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=265; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=266; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=267; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=268; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655365; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=269; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65542; // bit0 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65542; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=270; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131078; // bit1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131078; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=271; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196614; // bit2 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196614; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=272; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262150; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262150; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=273; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327686; // data1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327686; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=274; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393222; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=275; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393222; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=276; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393222; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=277; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393222; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=278; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393222; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=279; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393222; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=280; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393222; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=281; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393222; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=282; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393222; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=283; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170438; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170438; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=284; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393222; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=285; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170438; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170438; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=286; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=287; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=288; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=289; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=290; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=291; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=292; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=293; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=294; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=295; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=296; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=297; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393222; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=298; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458758; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=299; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458758; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=300; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458758; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=301; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458758; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=302; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458758; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=303; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458758; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=304; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458758; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=305; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458758; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=306; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458758; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=307; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235974; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235974; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=308; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458758; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=309; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235974; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235974; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=310; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=311; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=312; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=313; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=314; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=315; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=316; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=317; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=318; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=319; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=320; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=321; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458758; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=322; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65543; // bit0 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65543; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=323; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131079; // bit1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131079; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=324; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196615; // bit2 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196615; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=325; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262151; // data0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262151; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=326; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327687; // data1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327687; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=327; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393223; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=328; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393223; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=329; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393223; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=330; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393223; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=331; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393223; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=332; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393223; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=333; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393223; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=334; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393223; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=335; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393223; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=336; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170439; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170439; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=337; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393223; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=338; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170439; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170439; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=339; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=340; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=341; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=342; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=343; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=344; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=345; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=346; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=347; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=348; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=349; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=350; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393223; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=351; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458759; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=352; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458759; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=353; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458759; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=354; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458759; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=355; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458759; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=356; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458759; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=357; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458759; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=358; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458759; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=359; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458759; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=360; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235975; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235975; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=361; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458759; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=362; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235975; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235975; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=363; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=364; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=365; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=366; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=367; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=368; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=369; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=370; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=371; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=372; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=373; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=374; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458759; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=375; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65544; // bit0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65544; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=376; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131080; // bit1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131080; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=377; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196616; // bit2 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196616; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=378; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262152; // data0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262152; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=379; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327688; // data1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327688; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=380; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393224; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=381; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393224; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=382; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393224; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=383; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393224; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=384; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393224; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=385; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393224; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=386; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393224; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=387; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393224; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=388; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393224; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=389; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170440; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170440; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=390; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393224; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=391; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170440; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170440; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=392; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=393; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=394; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=395; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=396; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=397; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=398; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=399; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=400; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=401; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=402; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=403; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393224; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=404; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 458760; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=405; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 458760; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=406; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 458760; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=407; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 458760; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=408; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 458760; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=409; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 458760; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=410; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 458760; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=411; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 458760; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=412; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 458760; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=413; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17235976; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235976; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=414; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 458760; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=415; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17235976; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17235976; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=416; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=417; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=418; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=419; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=420; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=421; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=422; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=423; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=424; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=425; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=426; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=427; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 458760; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=428; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131329; // flush 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131329; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=429; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459009; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459009; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=430; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524545; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524545; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=431; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196865; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196865; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=432; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262401; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262401; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=433; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327937; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327937; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=434; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393473; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393473; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=435; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590081; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=436; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590081; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=437; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590081; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=438; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590081; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=439; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590081; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=440; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367297; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=441; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590081; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=442; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367297; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=443; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367297; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=444; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367297; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=445; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367297; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=446; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367297; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367297; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=447; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=448; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=449; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=450; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=451; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=452; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=453; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=454; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=455; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=456; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=457; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=458; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590081; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=459; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655617; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=460; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655617; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=461; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655617; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=462; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655617; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=463; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655617; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=464; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17432833; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=465; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655617; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=466; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17432833; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=467; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17432833; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=468; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17432833; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=469; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17432833; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=470; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17432833; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432833; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=471; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=472; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=473; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=474; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=475; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=476; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=477; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=478; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=479; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=480; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=481; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=482; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655617; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=483; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65794; // bit0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65794; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=484; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131330; // bit1 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131330; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=485; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196866; // bit2 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196866; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=486; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262402; // data0 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262402; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=487; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327938; // data1 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327938; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=488; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393474; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=489; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393474; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=490; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393474; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=491; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393474; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=492; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393474; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=493; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393474; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=494; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393474; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=495; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393474; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=496; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393474; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=497; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170690; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170690; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=498; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393474; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=499; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170690; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170690; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=500; // 3


    // regtest_wr_1.c
    group = 1;
    
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=1; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=2; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=3; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=4; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=5; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=6; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=7; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=8; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=9; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=10; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=11; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393474; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=12; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459010; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=13; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459010; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=14; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459010; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=15; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459010; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=16; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459010; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=17; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459010; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=18; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459010; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=19; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459010; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=20; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459010; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=21; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236226; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236226; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=22; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459010; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=23; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236226; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236226; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=24; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=25; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=26; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=27; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=28; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=29; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=30; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=31; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=32; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=33; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=34; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=35; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459010; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=36; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65795; // bit0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65795; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=37; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131331; // bit1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131331; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=38; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196867; // bit2 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196867; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=39; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262403; // data0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262403; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=40; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327939; // data1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327939; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=41; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393475; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=42; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393475; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=43; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393475; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=44; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393475; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=45; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393475; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=46; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393475; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=47; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393475; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=48; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393475; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=49; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393475; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=50; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170691; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170691; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=51; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393475; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=52; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170691; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170691; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=53; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=54; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=55; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=56; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=57; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=58; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=59; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=60; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=61; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=62; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=63; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=64; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393475; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=65; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459011; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=66; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459011; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=67; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459011; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=68; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459011; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=69; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459011; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=70; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459011; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=71; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459011; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=72; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459011; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=73; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459011; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=74; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236227; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236227; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=75; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459011; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=76; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236227; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236227; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=77; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=78; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=79; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=80; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=81; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=82; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=83; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=84; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=85; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=86; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=87; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=88; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459011; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=89; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65796; // bit0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65796; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=90; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131332; // bit1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131332; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=91; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196868; // bit2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196868; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=92; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262404; // data0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262404; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=93; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327940; // data1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327940; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=94; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393476; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=95; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393476; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=96; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393476; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=97; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393476; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=98; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393476; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=99; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393476; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=100; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393476; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=101; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393476; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=102; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393476; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=103; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170692; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170692; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=104; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393476; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=105; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170692; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170692; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=106; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=107; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=108; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=109; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=110; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=111; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=112; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=113; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=114; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=115; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=116; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=117; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393476; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=118; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459012; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=119; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459012; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=120; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459012; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=121; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459012; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=122; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459012; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=123; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459012; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=124; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459012; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=125; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459012; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=126; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459012; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=127; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236228; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236228; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=128; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459012; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=129; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236228; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236228; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=130; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=131; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=132; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=133; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=134; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=135; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=136; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=137; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=138; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=139; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=140; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=141; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459012; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=142; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131333; // flush 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131333; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=143; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459013; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459013; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=144; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524549; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524549; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=145; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196869; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196869; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=146; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262405; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262405; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=147; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327941; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327941; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=148; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393477; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393477; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=149; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590085; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=150; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590085; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=151; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590085; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=152; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590085; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=153; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590085; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=154; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367301; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=155; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590085; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=156; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367301; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=157; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367301; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=158; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367301; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=159; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367301; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=160; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367301; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367301; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=161; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=162; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=163; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=164; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=165; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=166; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=167; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=168; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=169; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=170; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=171; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=172; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590085; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=173; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655621; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=174; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655621; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=175; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655621; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=176; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655621; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=177; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655621; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=178; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17432837; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=179; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655621; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=180; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17432837; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=181; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17432837; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=182; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17432837; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=183; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17432837; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=184; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17432837; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17432837; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=185; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=186; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=187; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=188; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=189; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=190; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=191; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=192; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=193; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=194; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=195; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=196; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655621; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=197; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65798; // bit0 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65798; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=198; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131334; // bit1 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131334; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=199; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196870; // bit2 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196870; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=200; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262406; // data0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262406; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=201; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327942; // data1 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327942; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=202; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393478; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=203; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393478; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=204; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393478; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=205; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393478; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=206; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393478; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=207; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393478; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=208; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393478; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=209; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393478; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=210; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393478; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=211; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170694; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170694; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=212; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393478; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=213; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170694; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170694; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=214; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=215; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=216; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=217; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=218; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=219; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=220; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=221; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=222; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=223; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=224; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=225; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393478; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=226; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459014; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=227; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459014; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=228; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459014; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=229; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459014; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=230; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459014; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=231; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459014; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=232; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459014; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=233; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459014; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=234; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459014; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=235; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236230; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236230; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=236; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459014; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=237; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236230; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236230; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=238; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=239; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=240; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=241; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=242; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=243; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=244; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=245; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=246; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=247; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=248; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=249; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459014; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=250; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65799; // bit0 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65799; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=251; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131335; // bit1 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131335; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=252; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196871; // bit2 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196871; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=253; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262407; // data0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262407; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=254; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327943; // data1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327943; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=255; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393479; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=256; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393479; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=257; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393479; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=258; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393479; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=259; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393479; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=260; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393479; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=261; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393479; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=262; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393479; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=263; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393479; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=264; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170695; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170695; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=265; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393479; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=266; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170695; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170695; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=267; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=268; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=269; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=270; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=271; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=272; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=273; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=274; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=275; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=276; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=277; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=278; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393479; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=279; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459015; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=280; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459015; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=281; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459015; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=282; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459015; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=283; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459015; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=284; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459015; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=285; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459015; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=286; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459015; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=287; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459015; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=288; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236231; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236231; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=289; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459015; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=290; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236231; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236231; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=291; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=292; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=293; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=294; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=295; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=296; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=297; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=298; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=299; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=300; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=301; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=302; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459015; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=303; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 65800; // bit0 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 65800; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=304; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131336; // bit1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131336; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=305; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 196872; // bit2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 196872; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=306; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262408; // data0 
    reg_mprj_cfg_wdata = encode(4, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262408; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=307; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 327944; // data1 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 327944; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=308; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393480; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=309; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393480; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=310; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393480; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=311; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393480; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=312; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393480; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=313; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393480; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=314; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393480; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=315; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393480; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=316; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393480; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=317; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170696; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170696; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=318; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393480; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=319; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170696; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170696; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=320; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=321; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=322; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=323; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=324; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=325; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=326; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=327; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=328; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=329; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=330; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=331; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393480; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=332; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459016; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=333; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459016; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=334; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459016; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=335; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459016; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=336; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459016; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=337; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459016; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=338; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459016; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=339; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459016; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=340; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459016; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=341; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236232; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236232; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=342; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459016; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=343; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236232; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236232; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=344; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=345; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=346; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=347; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=348; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=349; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=350; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=351; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=352; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=353; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=354; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=355; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459016; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=356; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131585; // flush 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131585; // flush
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=357; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 459265; // input_width_1_num_0 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459265; // input_width_1_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=358; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 524801; // input_width_1_num_1 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 524801; // input_width_1_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=359; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197121; // input_width_16_num_0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197121; // input_width_16_num_0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=360; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262657; // input_width_16_num_1 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262657; // input_width_16_num_1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=361; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328193; // input_width_16_num_2 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328193; // input_width_16_num_2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=362; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 393729; // input_width_16_num_3 
    reg_mprj_cfg_wdata = encode(5, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393729; // input_width_16_num_3
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 5) fail=363; // 11
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 590337; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=364; // 5
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 590337; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=365; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 590337; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(3, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=366; // 5
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 590337; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=367; // 5
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 590337; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=368; // 5
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17367553; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=369; // 5
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 590337; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=370; // 5
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17367553; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=371; // 5
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17367553; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=372; // 5
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17367553; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=373; // 5
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17367553; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(4, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 4) fail=374; // 5
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17367553; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 5
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17367553; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=375; // 5
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=376; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=377; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=378; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=379; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=380; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=381; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=382; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=383; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=384; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=385; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=386; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 590337; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=387; // 1
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 655873; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=388; // 4
    lo = 18;
    hi = 21;
    reg_mprj_cfg_addr = 655873; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=389; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 655873; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=390; // 4
    lo = 21;
    hi = 24;
    reg_mprj_cfg_addr = 655873; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=391; // 4
    lo = 27;
    hi = 30;
    reg_mprj_cfg_addr = 655873; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=392; // 4
    lo = 0;
    hi = 3;
    reg_mprj_cfg_addr = 17433089; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=393; // 4
    lo = 24;
    hi = 27;
    reg_mprj_cfg_addr = 655873; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=394; // 4
    lo = 3;
    hi = 6;
    reg_mprj_cfg_addr = 17433089; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=395; // 4
    lo = 9;
    hi = 12;
    reg_mprj_cfg_addr = 17433089; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=396; // 4
    lo = 12;
    hi = 15;
    reg_mprj_cfg_addr = 17433089; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=397; // 4
    lo = 6;
    hi = 9;
    reg_mprj_cfg_addr = 17433089; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=398; // 4
    lo = 15;
    hi = 18;
    reg_mprj_cfg_addr = 17433089; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(3, lo); // 4
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17433089; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=399; // 4
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=400; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=401; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=402; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=403; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=404; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=405; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=406; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=407; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=408; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=409; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=410; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 655873; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=411; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66050; // bit0 
    reg_mprj_cfg_wdata = encode(3, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66050; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 3) fail=412; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131586; // bit1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131586; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=413; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197122; // bit2 
    reg_mprj_cfg_wdata = encode(8, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197122; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 8) fail=414; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262658; // data0 
    reg_mprj_cfg_wdata = encode(10, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262658; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 10) fail=415; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328194; // data1 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328194; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=416; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393730; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=417; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393730; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=418; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393730; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=419; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393730; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=420; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393730; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=421; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393730; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=422; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393730; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=423; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393730; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=424; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393730; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=425; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170946; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170946; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=426; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393730; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=427; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170946; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170946; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=428; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=429; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=430; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=431; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=432; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=433; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=434; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=435; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=436; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=437; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=438; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=439; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393730; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=440; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459266; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=441; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459266; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=442; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459266; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=443; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459266; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=444; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459266; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=445; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459266; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=446; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459266; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=447; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 459266; // SB_T1_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T1_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=448; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 459266; // SB_T2_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T2_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=449; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17236482; // SB_T2_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236482; // SB_T2_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=450; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 459266; // SB_T2_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // SB_T2_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=451; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17236482; // SB_T2_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17236482; // SB_T2_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=452; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=453; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=454; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=455; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T0_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=456; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=457; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=458; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=459; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T1_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=460; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_NORTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_NORTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=461; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_SOUTH_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_SOUTH_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=462; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_EAST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_EAST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=463; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_WEST_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459266; // RMUX_T2_WEST_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=464; // 1
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 66051; // bit0 
    reg_mprj_cfg_wdata = encode(6, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 66051; // bit0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 6) fail=465; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 131587; // bit1 
    reg_mprj_cfg_wdata = encode(2, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 131587; // bit1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=466; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 197123; // bit2 
    reg_mprj_cfg_wdata = encode(7, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 197123; // bit2
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 7) fail=467; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 262659; // data0 
    reg_mprj_cfg_wdata = encode(9, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 262659; // data0
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 9) fail=468; // 11
    lo = 0;
    hi = 4;
    reg_mprj_cfg_addr = 328195; // data1 
    reg_mprj_cfg_wdata = encode(1, lo); // 11
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 328195; // data1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=469; // 11
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 393731; // SB_T0_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T0_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=470; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 393731; // SB_T0_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T0_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=471; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 393731; // SB_T0_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T0_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=472; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 393731; // SB_T0_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T0_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=473; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 393731; // SB_T1_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T1_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=474; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 393731; // SB_T1_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T1_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=475; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 393731; // SB_T1_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T1_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=476; // 3
    lo = 26;
    hi = 28;
    reg_mprj_cfg_addr = 393731; // SB_T1_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T1_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=477; // 3
    lo = 30;
    hi = 31;
    reg_mprj_cfg_addr = 393731; // SB_T2_NORTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T2_NORTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=478; // 3
    lo = 0;
    hi = 2;
    reg_mprj_cfg_addr = 17170947; // SB_T2_SOUTH_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170947; // SB_T2_SOUTH_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=479; // 3
    lo = 28;
    hi = 30;
    reg_mprj_cfg_addr = 393731; // SB_T2_EAST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // SB_T2_EAST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=480; // 3
    lo = 2;
    hi = 4;
    reg_mprj_cfg_addr = 17170947; // SB_T2_WEST_SB_OUT_B1 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 17170947; // SB_T2_WEST_SB_OUT_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=481; // 3
    lo = 1;
    hi = 2;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=482; // 1
    lo = 2;
    hi = 3;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=483; // 1
    lo = 0;
    hi = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=484; // 1
    lo = 3;
    hi = 4;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T0_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=485; // 1
    lo = 5;
    hi = 6;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=486; // 1
    lo = 6;
    hi = 7;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=487; // 1
    lo = 4;
    hi = 5;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=488; // 1
    lo = 7;
    hi = 8;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T1_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=489; // 1
    lo = 9;
    hi = 10;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_NORTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_NORTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=490; // 1
    lo = 10;
    hi = 11;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_SOUTH_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_SOUTH_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=491; // 1
    lo = 8;
    hi = 9;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_EAST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_EAST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=492; // 1
    lo = 11;
    hi = 12;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_WEST_B1 
    reg_mprj_cfg_wdata = encode(1, lo); // 1
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 393731; // RMUX_T2_WEST_B1
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=493; // 1
    lo = 14;
    hi = 16;
    reg_mprj_cfg_addr = 459267; // SB_T0_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T0_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=494; // 3
    lo = 16;
    hi = 18;
    reg_mprj_cfg_addr = 459267; // SB_T0_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T0_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=495; // 3
    lo = 12;
    hi = 14;
    reg_mprj_cfg_addr = 459267; // SB_T0_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T0_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=496; // 3
    lo = 18;
    hi = 20;
    reg_mprj_cfg_addr = 459267; // SB_T0_WEST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T0_WEST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=497; // 3
    lo = 22;
    hi = 24;
    reg_mprj_cfg_addr = 459267; // SB_T1_NORTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T1_NORTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=498; // 3
    lo = 24;
    hi = 26;
    reg_mprj_cfg_addr = 459267; // SB_T1_SOUTH_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(2, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T1_SOUTH_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 2) fail=499; // 3
    lo = 20;
    hi = 22;
    reg_mprj_cfg_addr = 459267; // SB_T1_EAST_SB_OUT_B16 
    reg_mprj_cfg_wdata = encode(1, lo); // 3
    reg_mprj_cfg_write = 1;
    reg_mprj_cfg_addr = 459267; // SB_T1_EAST_SB_OUT_B16
    reg_mprj_cfg_read = 1;
    rtl = decode(reg_mprj_cfg_rdata, lo, hi);
    if (rtl != 1) fail=500; // 3



	while(1) {
	    putchar('|'); putchar(0x2d); // clear screen
        if (fail > 0) {
            print("failed\n");
            print_dec(group); print("\n");
            print_dec(fail); print("\n");
            // print_hex(data, 8); print("\n");
        } else {
            print("success!\n");
            print_dec(rtl); print("\n");
        }
        for (j=0; j<10000; j++);
    }
}

