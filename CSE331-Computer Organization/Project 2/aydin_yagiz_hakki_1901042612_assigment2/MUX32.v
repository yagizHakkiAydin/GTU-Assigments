module MUX32(input [31:0] i0,i1,i2,i3,i4,i5,i6,i7,input [2:0] ALUop,output [31:0] result);

	 EIGHT_BIT_MUX m0( ALUop[0],ALUop[1],ALUop[2],i0[0],i1[0],i2[0],i3[0],i4[0],i5[0],i6[0],i7[0],result[0] );
	 EIGHT_BIT_MUX m1( ALUop[0],ALUop[1],ALUop[2],i0[1],i1[1],i2[1],i3[1],i4[1],i5[1],i6[1],i7[1],result[1] );
	 EIGHT_BIT_MUX m2( ALUop[0],ALUop[1],ALUop[2],i0[2],i1[2],i2[2],i3[2],i4[2],i5[2],i6[2],i7[2],result[2] );
	 EIGHT_BIT_MUX m3( ALUop[0],ALUop[1],ALUop[2],i0[3],i1[3],i2[3],i3[3],i4[3],i5[3],i6[3],i7[3],result[3] );
	 EIGHT_BIT_MUX m4( ALUop[0],ALUop[1],ALUop[2],i0[4],i1[4],i2[4],i3[4],i4[4],i5[4],i6[4],i7[4],result[4] );
	 EIGHT_BIT_MUX m5( ALUop[0],ALUop[1],ALUop[2],i0[5],i1[5],i2[5],i3[5],i4[5],i5[5],i6[5],i7[5],result[5] );
	 EIGHT_BIT_MUX m6( ALUop[0],ALUop[1],ALUop[2],i0[6],i1[6],i2[6],i3[6],i4[6],i5[6],i6[6],i7[6],result[6] );
	 EIGHT_BIT_MUX m7( ALUop[0],ALUop[1],ALUop[2],i0[7],i1[7],i2[7],i3[7],i4[7],i5[7],i6[7],i7[7],result[7] );
	 EIGHT_BIT_MUX m8( ALUop[0],ALUop[1],ALUop[2],i0[8],i1[8],i2[8],i3[8],i4[8],i5[8],i6[8],i7[8],result[8] );
	 EIGHT_BIT_MUX m9( ALUop[0],ALUop[1],ALUop[2],i0[9],i1[9],i2[9],i3[9],i4[9],i5[9],i6[9],i7[9],result[9] );
	 EIGHT_BIT_MUX m10( ALUop[0],ALUop[1],ALUop[2],i0[10],i1[10],i2[10],i3[10],i4[10],i5[10],i6[10],i7[10],result[10] );
	 EIGHT_BIT_MUX m11( ALUop[0],ALUop[1],ALUop[2],i0[11],i1[11],i2[11],i3[11],i4[11],i5[11],i6[11],i7[11],result[11] );
	 EIGHT_BIT_MUX m12( ALUop[0],ALUop[1],ALUop[2],i0[12],i1[12],i2[12],i3[12],i4[12],i5[12],i6[12],i7[12],result[12] );
	 EIGHT_BIT_MUX m13( ALUop[0],ALUop[1],ALUop[2],i0[13],i1[13],i2[13],i3[13],i4[13],i5[13],i6[13],i7[13],result[13] );
	 EIGHT_BIT_MUX m14( ALUop[0],ALUop[1],ALUop[2],i0[14],i1[14],i2[14],i3[14],i4[14],i5[14],i6[14],i7[14],result[14] );
	 EIGHT_BIT_MUX m15( ALUop[0],ALUop[1],ALUop[2],i0[15],i1[15],i2[15],i3[15],i4[15],i5[15],i6[15],i7[15],result[15] );
	 EIGHT_BIT_MUX m16( ALUop[0],ALUop[1],ALUop[2],i0[16],i1[16],i2[16],i3[16],i4[16],i5[16],i6[16],i7[16],result[16] );
	 EIGHT_BIT_MUX m17( ALUop[0],ALUop[1],ALUop[2],i0[17],i1[17],i2[17],i3[17],i4[17],i5[17],i6[17],i7[17],result[17] );
	 EIGHT_BIT_MUX m18( ALUop[0],ALUop[1],ALUop[2],i0[18],i1[18],i2[18],i3[18],i4[18],i5[18],i6[18],i7[18],result[18] );
	 EIGHT_BIT_MUX m19( ALUop[0],ALUop[1],ALUop[2],i0[19],i1[19],i2[19],i3[19],i4[19],i5[19],i6[19],i7[19],result[19] );
	 EIGHT_BIT_MUX m20( ALUop[0],ALUop[1],ALUop[2],i0[20],i1[20],i2[20],i3[20],i4[20],i5[20],i6[20],i7[20],result[20] );
	 EIGHT_BIT_MUX m21( ALUop[0],ALUop[1],ALUop[2],i0[21],i1[21],i2[21],i3[21],i4[21],i5[21],i6[21],i7[21],result[21] );
	 EIGHT_BIT_MUX m22( ALUop[0],ALUop[1],ALUop[2],i0[22],i1[22],i2[22],i3[22],i4[22],i5[22],i6[22],i7[22],result[22] );
	 EIGHT_BIT_MUX m23( ALUop[0],ALUop[1],ALUop[2],i0[23],i1[23],i2[23],i3[23],i4[23],i5[23],i6[23],i7[23],result[23] );
	 EIGHT_BIT_MUX m24( ALUop[0],ALUop[1],ALUop[2],i0[24],i1[24],i2[24],i3[24],i4[24],i5[24],i6[24],i7[24],result[24] );
	 EIGHT_BIT_MUX m25( ALUop[0],ALUop[1],ALUop[2],i0[25],i1[25],i2[25],i3[25],i4[25],i5[25],i6[25],i7[25],result[25] );
	 EIGHT_BIT_MUX m26( ALUop[0],ALUop[1],ALUop[2],i0[26],i1[26],i2[26],i3[26],i4[26],i5[26],i6[26],i7[26],result[26] );
	 EIGHT_BIT_MUX m27( ALUop[0],ALUop[1],ALUop[2],i0[27],i1[27],i2[27],i3[27],i4[27],i5[27],i6[27],i7[27],result[27] );
	 EIGHT_BIT_MUX m28( ALUop[0],ALUop[1],ALUop[2],i0[28],i1[28],i2[28],i3[28],i4[28],i5[28],i6[28],i7[28],result[28] );
	 EIGHT_BIT_MUX m29( ALUop[0],ALUop[1],ALUop[2],i0[29],i1[29],i2[29],i3[29],i4[29],i5[29],i6[29],i7[29],result[29] );
	 EIGHT_BIT_MUX m30( ALUop[0],ALUop[1],ALUop[2],i0[30],i1[30],i2[30],i3[30],i4[30],i5[30],i6[30],i7[30],result[30] );
	 EIGHT_BIT_MUX m31( ALUop[0],ALUop[1],ALUop[2],i0[31],i1[31],i2[31],i3[31],i4[31],i5[31],i6[31],i7[31],result[31] );
endmodule






module EIGHT_BIT_MUX(input _s2,_s1,_s0, _o0,_o1,_o2,_o3,_o4,_o5,_o6,_o7,output y);

	wire not_s0;
	wire not_s1;
	wire not_s2;
	
	wire exp0;
	wire exp1;
	wire exp2;
	wire exp3;
	wire exp4;
	wire exp5;
	wire exp6;
	wire exp7;
	
	
	
	
	
	not n0(not_s0,_s0);
	not n1(not_s1,_s1);
	not n2(not_s2,_s2);
	



	wire w0_0;
	wire w0_1;
	and exp0_and1(w0_0,not_s0,not_s1);
	and exp0_and2(w0_1,not_s2,_o0);
	and exp0_and3(exp0,w0_0,w0_1);
	


	
	wire w1_0;
	wire w1_1;
	and exp1_and1(w1_0,not_s0,not_s1);
	and exp1_and2(w1_1,_s2,_o1);
	and exp1_and3(exp1,w1_0,w1_1);


	
	wire w2_0;
	wire w2_1;
	and exp2_and1(w2_0,not_s0,_s1);
	and exp2_and2(w2_1,not_s2,_o2);
	and exp2_and3(exp2,w2_0,w2_1);


	
	
	wire w3_0;
	wire w3_1;
	and exp3_and1(w3_0,not_s0,_s1);
	and exp3_and2(w3_1,_s2,_o3);
	and exp3_and3(exp3,w3_0,w3_1);

	
	
	wire w4_0;
	wire w4_1;
	and exp4_and1(w4_0,_s0,not_s1);
	and exp4_and2(w4_1,not_s2,_o4);
	and exp4_and3(exp4,w4_0,w4_1);

	
	
	
	wire w5_0;
	wire w5_1;
	and exp5_and1(w5_0,_s0,not_s1);
	and exp5_and2(w5_1,_s2,_o5);
	and exp5_and3(exp5,w5_0,w5_1);

	
	
	wire w6_0;
	wire w6_1;
	and exp6_and1(w6_0,_s0,_s1);
	and exp6_and2(w6_1,not_s2,_o6);
	and exp6_and3(exp6,w6_0,w6_1);
	
	
	
	
	wire w7_0;
	wire w7_1;
	and exp7_and1(w7_0,_s0,_s1);
	and exp7_and2(w7_1,_s2,_o7);
	and exp7_and3(exp7,w7_0,w7_1);
	
	
	
	
	
	
	wire or_wire0;
	wire or_wire1;
	wire or_wire2;
	wire or_wire3;
	wire or_wire4;
	wire or_wire5;
	
	
	or or0(or_wire0,exp0,exp1);
	or or1(or_wire1,exp2,exp3);
	or or2(or_wire2,exp4,exp5);
	or or3(or_wire3,exp6,exp7);
	
	
	
	
	or or4(or_wire4,or_wire0,or_wire1);
	or or5(or_wire5,or_wire2,or_wire3);
	or or6(y,or_wire4,or_wire5);
	
	


endmodule
