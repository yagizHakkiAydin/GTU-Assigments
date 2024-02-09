module sign_extend (
  output [31:0] sign_ext_imm,
  input  [15:0] imm
);




    and a0(sign_ext_imm[0],imm[0],imm[0]);
    and a1(sign_ext_imm[1],imm[1],imm[1]);
    and a2(sign_ext_imm[2],imm[2],imm[2]);
    and a3(sign_ext_imm[3],imm[3],imm[3]);
    and a4(sign_ext_imm[4],imm[4],imm[4]);
    and a5(sign_ext_imm[5],imm[5],imm[5]);
    and a6(sign_ext_imm[6],imm[6],imm[6]);
    and a7(sign_ext_imm[7],imm[7],imm[7]);
    and a8(sign_ext_imm[8],imm[8],imm[8]);
    and a9(sign_ext_imm[9],imm[9],imm[9]);
    and a10(sign_ext_imm[10],imm[10],imm[10]);
    and a11(sign_ext_imm[11],imm[11],imm[11]);
    and a12(sign_ext_imm[12],imm[12],imm[12]);
    and a13(sign_ext_imm[13],imm[13],imm[13]);
    and a14(sign_ext_imm[14],imm[14],imm[14]);
    and a15(sign_ext_imm[15],imm[15],imm[15]);
    and a16(sign_ext_imm[16],imm[15],imm[15]);
    and a17(sign_ext_imm[17],imm[15],imm[15]);
    and a18(sign_ext_imm[18],imm[15],imm[15]);
    and a19(sign_ext_imm[19],imm[15],imm[15]);
    and a20(sign_ext_imm[20],imm[15],imm[15]);
    and a21(sign_ext_imm[21],imm[15],imm[15]);
    and a22(sign_ext_imm[22],imm[15],imm[15]);
    and a23(sign_ext_imm[23],imm[15],imm[15]);
    and a24(sign_ext_imm[24],imm[15],imm[15]);
    and a25(sign_ext_imm[25],imm[15],imm[15]);
    and a26(sign_ext_imm[26],imm[15],imm[15]);
    and a27(sign_ext_imm[27],imm[15],imm[15]);
    and a28(sign_ext_imm[28],imm[15],imm[15]);
    and a29(sign_ext_imm[29],imm[15],imm[15]);
    and a30(sign_ext_imm[30],imm[15],imm[15]);
	 and a31(sign_ext_imm[31],imm[15],imm[15]);



endmodule


