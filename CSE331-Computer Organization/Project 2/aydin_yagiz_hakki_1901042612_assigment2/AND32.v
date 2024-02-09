module AND32(input [31:0] A,B,output[31:0] Y);
	THIRTYTWO_BIT_AND t_and(A,B,Y);
endmodule





module FOUR_BIT_AND( input[3:0] A,B, output[3:0] Y);

	and and3(Y[3],A[3],B[3]);
	and and2(Y[2],A[2],B[2]);
	and and1(Y[1],A[1],B[1]);
	and and0(Y[0],A[0],B[0]);
	

	
endmodule



module THIRTYTWO_BIT_AND(input [31:0] A,B,output [31:0] Y);

	
	FOUR_BIT_AND and0(A[3:0],B[3:0],Y[3:0]);
	FOUR_BIT_AND and1(A[7:4],B[7:4],Y[7:4]);
	FOUR_BIT_AND and2(A[11:8],B[11:8],Y[11:8]);
	FOUR_BIT_AND and3(A[15:12],B[15:12],Y[15:12]);
	
	FOUR_BIT_AND and4(A[19:16],B[19:16],Y[19:16]);
	FOUR_BIT_AND and5(A[23:20],B[23:20],Y[23:20]);
	FOUR_BIT_AND and6(A[27:24],B[27:24],Y[27:24]);
	FOUR_BIT_AND and7(A[31:28],B[31:28],Y[31:28]);
	
	
endmodule
