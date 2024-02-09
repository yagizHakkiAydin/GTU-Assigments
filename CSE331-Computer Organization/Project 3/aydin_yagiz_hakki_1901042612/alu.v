
module alu (
  output [31:0] alu_result,
  output zero_bit,
  input [31:0] alu_src1,
  input [31:0] alu_src2,
  input [2:0] alu_ctr
);
  
  
  wire [31:0] andWire;
  wire [31:0] orWire;
  wire [31:0] norWire;
  wire [31:0] xorWire;
  wire [31:0] adderWire;
  wire [31:0] subtractorWire;
  wire [31:0] sltWire;
  wire [31:0] null_wire;

  ADDER a1 (.a(alu_src1), .b(alu_src2), .cin(1'b0), .sum(adderWire));
  SUBTRACTOR a2 (.a(alu_src1), .b(alu_src2), .cin(1'b1), .result(subtractorWire));
  AND32 a3 (.A(alu_src1), .B(alu_src2), .Y(andWire));
  OR32 a4 (.A(alu_src1), .B(alu_src2), .Y(orWire));
  NOR32 a5 (.A(alu_src1), .B(alu_src2), .Y(norWire));
  XOR32 a6 (.A(alu_src1), .B(alu_src2), .Y(xorWire));
  SLT32 a7 (.A(alu_src1), .B(alu_src2), .Y(sltWire));
  
  MUX32 mux (
    .i0(andWire),
    .i1(orWire),
    .i2(xorWire),
    .i3(norWire),
    .i4(sltWire),
    .i5(adderWire),
    .i6(subtractorWire),
    .i7(null_wire),
    .ALUop(alu_ctr),
    .result(alu_result)
  );





  
  
  
  
    wire [15:0] or_32_to_16_wire;
  
    or or_32to16_0(or_32_to_16_wire[0] , alu_result[0] , alu_result[1]);
    or or_32to16_1(or_32_to_16_wire[1] , alu_result[2] , alu_result[3]);
    or or_32to16_2(or_32_to_16_wire[2] , alu_result[4] , alu_result[5]);
    or or_32to16_3(or_32_to_16_wire[3] , alu_result[6] , alu_result[7]);
    or or_32to16_4(or_32_to_16_wire[4] , alu_result[8] , alu_result[9]);
    or or_32to16_5(or_32_to_16_wire[5] , alu_result[10] , alu_result[11]);
    or or_32to16_6(or_32_to_16_wire[6] , alu_result[12] , alu_result[13]);
    or or_32to16_7(or_32_to_16_wire[7] , alu_result[14] , alu_result[15]);
    or or_32to16_8(or_32_to_16_wire[8] , alu_result[16] , alu_result[17]);
    or or_32to16_9(or_32_to_16_wire[9] , alu_result[18] , alu_result[19]);
    or or_32to16_10(or_32_to_16_wire[10] , alu_result[20] , alu_result[21]);
    or or_32to16_11(or_32_to_16_wire[11] , alu_result[22] , alu_result[23]);
    or or_32to16_12(or_32_to_16_wire[12] , alu_result[24] , alu_result[25]);
    or or_32to16_13(or_32_to_16_wire[13] , alu_result[26] , alu_result[27]);
    or or_32to16_14(or_32_to_16_wire[14] , alu_result[28] , alu_result[29]);
    or or_32to16_15(or_32_to_16_wire[15] , alu_result[30] , alu_result[31]);

  
  
  
    wire [7:0] or_16_to_8_wire;
    or or_16to8_0(or_16_to_8_wire[0] , or_32_to_16_wire[0] , or_32_to_16_wire[1]);
    or or_16to8_1(or_16_to_8_wire[1] , or_32_to_16_wire[2] , or_32_to_16_wire[3]);
    or or_16to8_2(or_16_to_8_wire[2] , or_32_to_16_wire[4] , or_32_to_16_wire[5]);
    or or_16to8_3(or_16_to_8_wire[3] , or_32_to_16_wire[6] , or_32_to_16_wire[7]);
    or or_16to8_4(or_16_to_8_wire[4] , or_32_to_16_wire[8] , or_32_to_16_wire[9]);
    or or_16to8_5(or_16_to_8_wire[5] , or_32_to_16_wire[10] , or_32_to_16_wire[11]);
    or or_16to8_6(or_16_to_8_wire[6] , or_32_to_16_wire[12] , or_32_to_16_wire[13]);
    or or_16to8_7(or_16_to_8_wire[7] , or_32_to_16_wire[14] , or_32_to_16_wire[15]);

   
   
    wire [3:0] or_8_to_4_wire;
    or or_8to4_0(or_8_to_4_wire[0] , or_16_to_8_wire[0] , or_16_to_8_wire[1]);
    or or_8to4_1(or_8_to_4_wire[1] , or_16_to_8_wire[2] , or_16_to_8_wire[3]);
    or or_8to4_2(or_8_to_4_wire[2] , or_16_to_8_wire[4] , or_16_to_8_wire[5]);
    or or_8to4_3(or_8_to_4_wire[3] , or_16_to_8_wire[6] , or_16_to_8_wire[7]);


    wire [1:0] or_4_to_2_wire;
    or or_4to2_0(or_4_to_2_wire[0] , or_8_to_4_wire[0] , or_8_to_4_wire[1]);
    or or_4to2_1(or_4_to_2_wire[1] , or_8_to_4_wire[2] , or_8_to_4_wire[3]);

  
  
  
  
    nor result_gate( zero_bit , or_4_to_2_wire[0],or_4_to_2_wire[1]);
  
  


endmodule
