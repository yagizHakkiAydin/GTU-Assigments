module alu_control (
  output [2:0] alu_ctr,
  input [5:0] function_code,
  input [2:0] ALUop
);

	wire [5:0] not_function_code;
	
	not n0(not_function_code[0] , function_code[0]);
	not n1(not_function_code[1] , function_code[1]);
	not n2(not_function_code[2] , function_code[2]);
	not n3(not_function_code[3] , function_code[3]);
	not n4(not_function_code[4] , function_code[4]);
	not n5(not_function_code[5] , function_code[5]);


	wire is_r_type;
	
	six_input_and is_r_type_gate(
		 .out(is_r_type),
		 .inp1(ALUop[2]),
		 .inp2(ALUop[1]), 
		 .inp3(ALUop[0]),  
		 .inp4(1'b1),
		 .inp5(1'b1), 
		 .inp6(1'b1)  
	);




	wire is_add;
	six_input_and is_add_gate (  //add , 000010
		 .out(is_add),
		 .inp1(not_function_code[5]),
		 .inp2(not_function_code[4]), 
		 .inp3(not_function_code[3]),  
		 .inp4(not_function_code[2]),
		 .inp5(function_code[1]), 
		 .inp6(not_function_code[0])  
	);
	




	wire is_sub;
	six_input_and is_sub_gate (  //sub , 000011
		 .out(is_sub),
		 .inp1(not_function_code[5]),
		 .inp2(not_function_code[4]), 
		 .inp3(not_function_code[3]),  
		 .inp4(not_function_code[2]),
		 .inp5(function_code[1]), 
		 .inp6(function_code[0])  
	);
	


	
	wire is_and;
	six_input_and is_and_gate (  //and , 000100
		 .out(is_and),
		 .inp1(not_function_code[5]),
		 .inp2(not_function_code[4]), 
		 .inp3(not_function_code[3]),  
		 .inp4(function_code[2]),
		 .inp5(not_function_code[1]), 
		 .inp6(not_function_code[0])  
	);
	

	
	
	
	
	
	wire is_or;
	six_input_and is_or_gate (  //or , 000101
		 .out(is_or),
		 .inp1(not_function_code[5]),
		 .inp2(not_function_code[4]), 
		 .inp3(not_function_code[3]),  
		 .inp4(function_code[2]),
		 .inp5(not_function_code[1]), 
		 .inp6(function_code[0])  
	);
	
	
	
	wire is_slt;
	six_input_and is_slt_gate (  //or , 000111
		 .out(is_slt),
		 .inp1(not_function_code[5]),
		 .inp2(not_function_code[4]), 
		 .inp3(not_function_code[3]),  
		 .inp4(function_code[2]),
		 .inp5(function_code[1]), 
		 .inp6(function_code[0])  
	);

	
	
	
	
	
	
	
	
	
	//alu_ctr[2]
	//eğer r type değilse ALUop[2]
	//eğer r typesa is
	//if add or sub or slt or ALUop[2]
	
	wire is_add_or_is_sub;  //is_add or is_sub
	or o1(is_add_or_is_sub,is_add,is_sub);
	
	wire is_add_or_is_sub_or_is_slt;  //is_add or is_sub
	or o2(is_add_or_is_sub_or_is_slt,is_slt,is_add_or_is_sub);

	mux2x1 aluctr_2_select (
	  .out(alu_ctr[2]),
	  .inp0(ALUop[2]),
	  .inp1(is_add_or_is_sub_or_is_slt),
	  .select(is_r_type)
	);
	
	
	
	
	//alu_ctr[1]
	wire is_sub_or_is_slt; //is_sub or is_slt
	or o3(is_sub_or_is_slt,is_sub,is_slt);
	mux2x1 aluctr_1_select (
	  .out(alu_ctr[1]),
	  .inp0(ALUop[1]),
	  .inp1(is_sub_or_is_slt),
	  .select(is_r_type)
	);

	
	

	wire is_add_or_is_or;
	or o4(is_add_or_is_or,is_add,is_or);
	mux2x1 aluctr_0_select (
	  .out(alu_ctr[0]),
	  .inp0(ALUop[0]),
	  .inp1(is_add_or_is_or),
	  .select(is_r_type)
	);

	

endmodule
