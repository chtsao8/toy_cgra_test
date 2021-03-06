//////////////////////////////////////////////////////////////////////////////////
// Author: Charles Tsao
// Create Date: 04/05/2022
// Module Name: CGRA_IO_test
// Target Devices: Zynq7 Processor on Zedboard FPGA
// Tool Versions: Vivado 2021.2
//////////////////////////////////////////////////////////////////////////////////


#define CGRA_ID XPAR_AXI_GPIO_CGRA_DEVICE_ID
#define LED_ID XPAR_AXI_GPIO_LED_DEVICE_ID
#define LED_MASK 0b1111
#define READ_16 0b1111 // 4 bits for now
#define READ_1 1
#define WRITE 0

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xil_types.h"

XGpio_Config *cfg_ptr;
XGpio led_device, cgra_device;
u32 data_16;
u32 data_1;
u32 led;

//int main() {
//	XGpio_Config *cfg_ptr;
//	XGpio led_device, btn_device;
//	u32 data;
//
//	xil_printf("Entered function main\r\n");
//}

void initDrivers()
{
	int status;

	// Initialize CGRA Device
	cfg_ptr = XGpio_LookupConfig(CGRA_ID);
	status = XGpio_CfgInitialize(&cgra_device, cfg_ptr, cfg_ptr->BaseAddress);
	if (status != XST_SUCCESS) {
		xil_printf("ERROR: CGRA GPIO Initialization Failed\n\r");
	} else {
		xil_printf("CGRA GPIO Initialization Successful\n\r");
	}

	// Initialize LED Device
	cfg_ptr = XGpio_LookupConfig(LED_ID);
	status = XGpio_CfgInitialize(&led_device, cfg_ptr, cfg_ptr->BaseAddress);
	if (status != XST_SUCCESS) {
		print("ERROR: LED GPIO Initialization Failed\n\r");
	} else {
		print("LED GPIO Initialization Successful\n\r");
	}
}

void configGPIO()
{
	// Set CGRA Tristate
	print("Entered configGPIO");
	XGpio_SetDataDirection(&cgra_device, 1, READ_16); 	// gpio_in_16
	XGpio_SetDataDirection(&cgra_device, 2, READ_1);  // gpio_in_1
	print("CGRA GPIO set to READ\n\r");

	// Set Led Tristate
	XGpio_SetDataDirection(&led_device, 1, WRITE);
	print("LED GPIO set to WRITE\n\r");
}

void readFromCGRA()
{
	xil_printf("Reading data from CGRA...\n\r");
	while (1) {
		xil_printf("1 Reading data from CGRA...\n\r");
		data_16 = XGpio_DiscreteRead(&cgra_device, 1);
		data_1 = XGpio_DiscreteRead(&cgra_device, 2);
		xil_printf("2 Reading data from CGRA...\n\r");
		led = LED_MASK;

		xil_printf("%d\n\r", data_16);
		xil_printf("%d\n\r", data_1);

		XGpio_DiscreteWrite(&led_device, 1, led);
	}
}

int main()
{
//	init_platform();
    xil_printf("Hello World!\n\r");
    xil_printf("Zynq7 Processor Active\n\r");

	initDrivers();
	xil_printf("got here\n\r");
	configGPIO();
//	xil_printf("got here\n\r");
	readFromCGRA();
//	cleanup_platform();

}
