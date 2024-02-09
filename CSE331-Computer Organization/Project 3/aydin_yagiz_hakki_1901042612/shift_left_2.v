module shift_left_2 (
  output [31:0] shifted_address,
  input [31:0] address
);
	
	
	 and a0(shifted_address[0],1'b0,1'b0);
	 and a1(shifted_address[1],1'b0,1'b0);
    and a2(shifted_address[2],address[0],address[0]);
    and a3(shifted_address[3],address[1],address[1]);
    and a4(shifted_address[4],address[2],address[2]);
    and a5(shifted_address[5],address[3],address[3]);
    and a6(shifted_address[6],address[4],address[4]);
    and a7(shifted_address[7],address[5],address[5]);
    and a8(shifted_address[8],address[6],address[6]);
    and a9(shifted_address[9],address[7],address[7]);
    and a10(shifted_address[10],address[8],address[8]);
    and a11(shifted_address[11],address[9],address[9]);
    and a12(shifted_address[12],address[10],address[10]);
    and a13(shifted_address[13],address[11],address[11]);
    and a14(shifted_address[14],address[12],address[12]);
    and a15(shifted_address[15],address[13],address[13]);
    and a16(shifted_address[16],address[14],address[14]);
    and a17(shifted_address[17],address[15],address[15]);
    and a18(shifted_address[18],address[16],address[16]);
    and a19(shifted_address[19],address[17],address[17]);
    and a20(shifted_address[20],address[18],address[18]);
    and a21(shifted_address[21],address[19],address[19]);
    and a22(shifted_address[22],address[20],address[20]);
    and a23(shifted_address[23],address[21],address[21]);
    and a24(shifted_address[24],address[22],address[22]);
    and a25(shifted_address[25],address[23],address[23]);
    and a26(shifted_address[26],address[24],address[24]);
    and a27(shifted_address[27],address[25],address[25]);
    and a28(shifted_address[28],address[26],address[26]);
    and a29(shifted_address[29],address[27],address[27]);
    and a30(shifted_address[30],address[28],address[28]);
    and a31(shifted_address[31],address[29],address[29]);
	
	
endmodule