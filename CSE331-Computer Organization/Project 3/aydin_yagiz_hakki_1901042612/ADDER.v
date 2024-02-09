module ADDER(input [31:0] a,b,input cin, output [31:0] sum);
	 THIRTYTWO_BIT_ADDER adder(a,b,cin,sum);
endmodule





module ONE_BIT_ADDER(input A,B,Cin,output Sum,Cout);
	wire w1;
	wire w2;
	wire w3;
	xor first_xor(w1,A,B);
	xor sec_xor(Sum,w1,Cin);
	and first_and(w2,w1,Cin);
	and sec_and(w3,A,B);
	or first_or(Cout,w2,w3);
endmodule


module FOUR_BIT_ADDER( input[3:0] a,b,input cin, output[3:0] sum, output cout );

	wire w1;
	wire w2;
	wire w3;
	wire w4;

	ONE_BIT_ADDER adder0(a[0],b[0],cin,sum[0],w1);
	ONE_BIT_ADDER adder1(a[1],b[1],w1,sum[1],w2);
	ONE_BIT_ADDER adder2(a[2],b[2],w2,sum[2],w3);
	ONE_BIT_ADDER adder3(a[3],b[3],w3,sum[3],cout);
	
endmodule



module THIRTYTWO_BIT_ADDER(input [31:0] a,b,input cin, output [31:0] sum);

	wire w1;
	wire w2;
	wire w3;
	wire w4;
	wire w5;
	wire w6;
	wire w7;
	wire emptyWire;
	
	FOUR_BIT_ADDER adder0(a[3:0],b[3:0],cin,sum[3:0],w1);
	FOUR_BIT_ADDER adder1(a[7:4],b[7:4],w1,sum[7:4],w2);
	FOUR_BIT_ADDER adder2(a[11:8],b[11:8],w2,sum[11:8],w3);
	FOUR_BIT_ADDER adder3(a[15:12],b[15:12],w3,sum[15:12],w4);
	
	FOUR_BIT_ADDER adder4(a[19:16],b[19:16],w4,sum[19:16],w5);
	FOUR_BIT_ADDER adder5(a[23:20],b[23:20],w5,sum[23:20],w6);
	FOUR_BIT_ADDER adder6(a[27:24],b[27:24],w6,sum[27:24],w7);
	FOUR_BIT_ADDER adder7(a[31:28],b[31:28],w7,sum[31:28],emptyWire);
	
	
endmodule
