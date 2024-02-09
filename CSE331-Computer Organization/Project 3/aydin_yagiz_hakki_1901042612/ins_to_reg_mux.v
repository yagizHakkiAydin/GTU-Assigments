module ins_to_reg_mux (
	output [4:0] out,
	input [4:0] inp0,
	input [4:0] inp1,
	input select
);





mux2x1 mux2x1_ins_to_reg_1 (
	.out(out[4]),
	.inp0(inp0[4]),
	.inp1(inp1[4]),
	.select(select)
);
  

mux2x1 mux2x1_ins_to_reg_2 (
	.out(out[3]),
	.inp0(inp0[3]),
	.inp1(inp1[3]),
	.select(select)
);


mux2x1 mux2x1_ins_to_reg_3 (
	.out(out[2]),
	.inp0(inp0[2]),
	.inp1(inp1[2]),
	.select(select)
);


mux2x1 mux2x1_ins_to_reg_4 (
	.out(out[1]),
	.inp0(inp0[1]),
	.inp1(inp1[1]),
	.select(select)
);


mux2x1 mux2x1_ins_to_reg_5 (
	.out(out[0]),
	.inp0(inp0[0]),
	.inp1(inp1[0]),
	.select(select)
);

endmodule