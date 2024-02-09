transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/mips.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/control_unit.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/alu.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/alu_control.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/sign_extend.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/shift_left_2.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/program_counter_adder.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/mux2x1.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/ins_to_reg_mux.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/reg_to_alu_mux.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/mem_mux.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/pc_mux.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/move_mux.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/ADDER.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/SUBTRACTOR.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/ONE_TO_32_EXTENDER.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/XOR32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/AND32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/OR32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/NOR32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/SLT32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/MUX32.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/register_block.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/instruction_block.v}
vlog -vlog01compat -work work +incdir+/home/yagz/Desktop/project {/home/yagz/Desktop/project/memory_block.v}
