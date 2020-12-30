############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project gravity_AXI4_Lite
set_top myGravity
add_files ../source-code/core.cpp
add_files -tb ../source-code/test_core.cpp
add_files -tb ../source-code/test_core.h
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./gravity_AXI4_Lite/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
