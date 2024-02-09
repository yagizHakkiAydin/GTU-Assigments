module pc_mux (
	output [31:0] out,
	input [31:0] inp0,
	input [31:0] inp1,
	input select
);




mux2x1 mux2x1_pc_1 (
    .out(out[31]),
    .inp0(inp0[31]),
    .inp1(inp1[31]),
    .select(select)
);

mux2x1 mux2x1_pc_2 (
    .out(out[30]),
    .inp0(inp0[30]),
    .inp1(inp1[30]),
    .select(select)
);

mux2x1 mux2x1_pc_3 (
    .out(out[29]),
    .inp0(inp0[29]),
    .inp1(inp1[29]),
    .select(select)
);

mux2x1 mux2x1_pc_4 (
    .out(out[28]),
    .inp0(inp0[28]),
    .inp1(inp1[28]),
    .select(select)
);

mux2x1 mux2x1_pc_5 (
    .out(out[27]),
    .inp0(inp0[27]),
    .inp1(inp1[27]),
    .select(select)
);

mux2x1 mux2x1_pc_6 (
    .out(out[26]),
    .inp0(inp0[26]),
    .inp1(inp1[26]),
    .select(select)
);

mux2x1 mux2x1_pc_7 (
    .out(out[25]),
    .inp0(inp0[25]),
    .inp1(inp1[25]),
    .select(select)
);

mux2x1 mux2x1_pc_8 (
    .out(out[24]),
    .inp0(inp0[24]),
    .inp1(inp1[24]),
    .select(select)
);

mux2x1 mux2x1_pc_9 (
    .out(out[23]),
    .inp0(inp0[23]),
    .inp1(inp1[23]),
    .select(select)
);

mux2x1 mux2x1_pc_10 (
    .out(out[22]),
    .inp0(inp0[22]),
    .inp1(inp1[22]),
    .select(select)
);

mux2x1 mux2x1_pc_11 (
    .out(out[21]),
    .inp0(inp0[21]),
    .inp1(inp1[21]),
    .select(select)
);

mux2x1 mux2x1_pc_12 (
    .out(out[20]),
    .inp0(inp0[20]),
    .inp1(inp1[20]),
    .select(select)
);

mux2x1 mux2x1_pc_13 (
    .out(out[19]),
    .inp0(inp0[19]),
    .inp1(inp1[19]),
    .select(select)
);

mux2x1 mux2x1_pc_14 (
    .out(out[18]),
    .inp0(inp0[18]),
    .inp1(inp1[18]),
    .select(select)
);

mux2x1 mux2x1_pc_15 (
    .out(out[17]),
    .inp0(inp0[17]),
    .inp1(inp1[17]),
    .select(select)
);

mux2x1 mux2x1_pc_16 (
    .out(out[16]),
    .inp0(inp0[16]),
    .inp1(inp1[16]),
    .select(select)
);

mux2x1 mux2x1_pc_17 (
    .out(out[15]),
    .inp0(inp0[15]),
    .inp1(inp1[15]),
    .select(select)
);

mux2x1 mux2x1_pc_18 (
    .out(out[14]),
    .inp0(inp0[14]),
    .inp1(inp1[14]),
    .select(select)
);

mux2x1 mux2x1_pc_19 (
    .out(out[13]),
    .inp0(inp0[13]),
    .inp1(inp1[13]),
    .select(select)
);

mux2x1 mux2x1_pc_20 (
    .out(out[12]),
    .inp0(inp0[12]),
    .inp1(inp1[12]),
    .select(select)
);

mux2x1 mux2x1_pc_21 (
    .out(out[11]),
    .inp0(inp0[11]),
    .inp1(inp1[11]),
    .select(select)
);

mux2x1 mux2x1_pc_22 (
    .out(out[10]),
    .inp0(inp0[10]),
    .inp1(inp1[10]),
    .select(select)
);

mux2x1 mux2x1_pc_23 (
    .out(out[9]),
    .inp0(inp0[9]),
    .inp1(inp1[9]),
    .select(select)
);

mux2x1 mux2x1_pc_24 (
    .out(out[8]),
    .inp0(inp0[8]),
    .inp1(inp1[8]),
    .select(select)
);

mux2x1 mux2x1_pc_25 (
    .out(out[7]),
    .inp0(inp0[7]),
    .inp1(inp1[7]),
    .select(select)
);

mux2x1 mux2x1_pc_26 (
    .out(out[6]),
    .inp0(inp0[6]),
    .inp1(inp1[6]),
    .select(select)
);

mux2x1 mux2x1_pc_27 (
    .out(out[5]),
    .inp0(inp0[5]),
    .inp1(inp1[5]),
    .select(select)
);

mux2x1 mux2x1_pc_28 (
    .out(out[4]),
    .inp0(inp0[4]),
    .inp1(inp1[4]),
    .select(select)
);

mux2x1 mux2x1_pc_29 (
    .out(out[3]),
    .inp0(inp0[3]),
    .inp1(inp1[3]),
    .select(select)
);

mux2x1 mux2x1_pc_30 (
    .out(out[2]),
    .inp0(inp0[2]),
    .inp1(inp1[2]),
    .select(select)
);

mux2x1 mux2x1_pc_31 (
    .out(out[1]),
    .inp0(inp0[1]),
    .inp1(inp1[1]),
    .select(select)
);

mux2x1 mux2x1_pc_32 (
    .out(out[0]),
    .inp0(inp0[0]),
    .inp1(inp1[0]),
    .select(select)
);





endmodule