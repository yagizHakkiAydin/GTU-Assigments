module SLT32(input [31:0] A,B,output [31:0] Y);


	wire [31:0] w1;

	SUBTRACTOR _subtractor(A,B,1'b1,w1);

	ONE_TO_THIRTYTWO_EXTENDER_WITH_LSB _extender(w1[31],Y);
	
	

	
	

endmodule


module ONE_TO_THIRTYTWO_EXTENDER_WITH_LSB(input lsb , output [31:0] out);

	ONE_TO_32_EXTENDER extender(1'b0,out[31:1]);

	
	and a0(out[0],lsb,lsb);
endmodule
