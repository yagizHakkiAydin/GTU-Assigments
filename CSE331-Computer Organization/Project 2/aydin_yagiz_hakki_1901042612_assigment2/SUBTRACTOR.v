module SUBTRACTOR(input [31:0] a,b,input cin, output [31:0] result);
	 THIRTYTWO_BIT_SUBTRACTOR subtractor(a,b,cin,result);
endmodule




module THIRTYTWO_BIT_SUBTRACTOR(input [31:0] a,b,input cin, output [31:0] result);

	wire [31:0] w1;
	wire [31:0] w2;
	
	
	ONE_TO_32_EXTENDER extender(cin,w2);
	
	
	XOR32 t_xor(b,w2,w1);
	ADDER t_adder(a,w1,cin,result);
	

endmodule
