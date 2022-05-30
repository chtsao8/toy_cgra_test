`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Author: Charles Tsao
// Create Date: 04/04/2022 11:20:50 PM
// Module Name: cgra_loader
// Target Devices: Zedboard FPGA
// Tool Versions: Vivado 2021.2
//////////////////////////////////////////////////////////////////////////////////

`define NUM_IO 4
`define IDLE 2'b00
`define START 2'b01
`define SEND 2'b10

module cgra_loader(
    input clk,
    input btn_r,
    input btn_s,
    output [`NUM_IO-1:0] gpio_out_16,
    output gpio_out_1,
    output io_rst
    );
    
    // BUTTONS
    
    assign io_rst = btn_r;

    wire io_start;
//  // Comment out this assignment for simulation
    button_press_unit start_btn(
        .clk(clk),
        .reset(io_rst),
        .in(btn_s),
        .out(io_start)
    );

//  // Comment out this assignment for synthesis
//    assign io_start = btn_s;
    
    // STATE REGISTER
    reg [1:0] next_state;
    wire [1:0] state;
    dffr #(2) state_reg (
        .clk(clk),
        .r(io_rst),
        .d(next_state),
        .q(state)
    );
    
    // CGRA LOADING COUNTER
    wire [11:0] count;
    wire max_count = count == 12'd4095;
    dffre #(12) counter (
        .clk(clk),
        .r(io_rst || max_count),
        .en(state == `SEND),
        .d(count + 12'b1),
        .q(count)
    );
    
    always @(*) begin
        case(state)
            `IDLE: next_state = (io_start) ? `START : `IDLE;
            `START: next_state = `SEND;
            `SEND: next_state = (max_count) ? `IDLE : `SEND;
            default: next_state = `IDLE;
        endcase
    end
    
    assign gpio_out_1 = (state == `START);
    assign gpio_out_16 = (state == `SEND)? count % 16 : 4'b0;
    
endmodule
