# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: C:\Users\chess\OneDrive\Documents\Stanford\EE272C\CGRA_IO_TEST\Vitis\cgra_test_system\_ide\scripts\systemdebugger_cgra_test_system_2_standalone.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source C:\Users\chess\OneDrive\Documents\Stanford\EE272C\CGRA_IO_TEST\Vitis\cgra_test_system\_ide\scripts\systemdebugger_cgra_test_system_2_standalone.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent Zed 210248AA3BD6" && level==0 && jtag_device_ctx=="jsn-Zed-210248AA3BD6-23727093-0"}
fpga -file C:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/Vitis/cgra_test/_ide/bitstream/cgra_test_design_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw C:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/Vitis/cgra_test_design_wrapper/export/cgra_test_design_wrapper/hw/cgra_test_design_wrapper.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source C:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/Vitis/cgra_test/_ide/psinit/ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow C:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/Vitis/cgra_test/Debug/cgra_test.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A9*#0"}
con
