`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Author: Charles Tsao
// Create Date: 04/04/2022 11:20:50 PM
// Module Name: cgra_loader_tb
// Target Devices: Zedboard FPGA
// Tool Versions: Vivado 2021.2
//////////////////////////////////////////////////////////////////////////////////


module cgra_loader_tb();
    `define PERIOD 10
    `define HALF_PERIOD 5
    `define BUTTON_HOLD 1 // how long to hold a button for. 
    `define STATIC_STATE_LENGTH 2000 // how long to hold a state for. 

    `define CLEAR_BUTTONS 2'b00
    `define SET_RESET     2'b10
    `define SET_START     2'b01

    // module signals
    // input
    reg clk;
    reg [1:0] buttons;
    wire reset_btn, start_btn;
    assign {reset_btn, start_btn} = buttons;
    // output
    wire [3:0] gpio_out_4;
    wire gpio_out_1;
    wire io_rst;

    // modules
    cgra_loader dut(
        .clk(clk),
        .btn_r(reset_btn),
        .btn_s(start_btn),
        .gpio_out_16(gpio_out_4),
        .gpio_out_1(gpio_out_1),
        .io_rst(io_rst)
    );
   
    // tasks
    task press_button;
        input [1:0] PRESS;
        begin
            while(clk === 0)begin
                #1;
            end/**/
            buttons = PRESS;   // press button
            #(`BUTTON_HOLD *`PERIOD);
            buttons = `CLEAR_BUTTONS;
        end
    endtask
    
    task wait_cycles;
        input integer NUM_CYCLES;
        begin
            #(NUM_CYCLES *`PERIOD);
        end
    endtask

    // test signals
    reg case_passed = 1; 
    reg stop_clock = 0;
    
    // Clock with period of 10 units
    initial begin
        clk = 1'b1;
        while(stop_clock == 0) begin
            #`HALF_PERIOD;
            clk = ~clk;
        end
        $stop;
    end
    
    // Input stimuli
    initial begin
    // x state
        wait_cycles(1);
    // initial reset
        $display("[IDLE] Resetting IO.");
        press_button(`SET_RESET);
        
        wait_cycles(5);
        $display("[START] Start button pressed.");
        press_button(`SET_START);
        wait_cycles(1);
        $display("[SEND] FPGA should be sending to CGRA now.");
//        if(gpio_out_4 !== counter) begin
//            $display("[SEND] Error: FPGA is not sending to CGRA.");
//        end
        wait_cycles(`STATIC_STATE_LENGTH);
        
    /* END THE CLOCK LOOP */
        stop_clock = 1; 
        $stop;
    end
endmodule
