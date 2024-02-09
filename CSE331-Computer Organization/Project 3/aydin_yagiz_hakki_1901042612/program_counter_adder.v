module program_counter_adder (
  output [31:0] out,
  input [31:0] inp
);



	 wire [31:0] wire_for_four;

    and a0(wire_for_four[0] , 1'b0 , 1'b0);
    and a1(wire_for_four[1] , 1'b0 , 1'b0);
    and a2(wire_for_four[2] , 1'b1 , 1'b1);
    and a3(wire_for_four[3] , 1'b0 , 1'b0);
    and a4(wire_for_four[4] , 1'b0 , 1'b0);
    and a5(wire_for_four[5] , 1'b0 , 1'b0);
    and a6(wire_for_four[6] , 1'b0 , 1'b0);
    and a7(wire_for_four[7] , 1'b0 , 1'b0);
    and a8(wire_for_four[8] , 1'b0 , 1'b0);
    and a9(wire_for_four[9] , 1'b0 , 1'b0);
    and a10(wire_for_four[10] , 1'b0 , 1'b0);
    and a11(wire_for_four[11] , 1'b0 , 1'b0);
    and a12(wire_for_four[12] , 1'b0 , 1'b0);
    and a13(wire_for_four[13] , 1'b0 , 1'b0);
    and a14(wire_for_four[14] , 1'b0 , 1'b0);
    and a15(wire_for_four[15] , 1'b0 , 1'b0);
    and a16(wire_for_four[16] , 1'b0 , 1'b0);
    and a17(wire_for_four[17] , 1'b0 , 1'b0);
    and a18(wire_for_four[18] , 1'b0 , 1'b0);
    and a19(wire_for_four[19] , 1'b0 , 1'b0);
    and a20(wire_for_four[20] , 1'b0 , 1'b0);
    and a21(wire_for_four[21] , 1'b0 , 1'b0);
    and a22(wire_for_four[22] , 1'b0 , 1'b0);
    and a23(wire_for_four[23] , 1'b0 , 1'b0);
    and a24(wire_for_four[24] , 1'b0 , 1'b0);
    and a25(wire_for_four[25] , 1'b0 , 1'b0);
    and a26(wire_for_four[26] , 1'b0 , 1'b0);
    and a27(wire_for_four[27] , 1'b0 , 1'b0);
    and a28(wire_for_four[28] , 1'b0 , 1'b0);
    and a29(wire_for_four[29] , 1'b0 , 1'b0);
    and a30(wire_for_four[30] , 1'b0 , 1'b0);
    and a31(wire_for_four[31] , 1'b0 , 1'b0);






  THIRTYTWO_BIT_ADDER _thirty_two_bit_adder (
    .a(wire_for_four),
    .b(inp),
    .cin(1'b0),
    .sum(out)
  );




endmodule
