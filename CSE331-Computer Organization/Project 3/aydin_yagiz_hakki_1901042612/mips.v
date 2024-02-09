module mips (
	input clock
);


	wire regDst;
	wire branch;
	wire memRead;
	wire memWrite;
	wire [2:0] ALUop;
	wire ALUsrc;
	wire regWrite;
	wire jump;
	wire byteOperations;
	wire move;



	wire [31:0] instruction;




	wire [4:0] registers_write_reg;
	wire [31:0] registers_write_data;
	wire [31:0] registers_read_data1;
	wire [31:0] registers_read_data2;
 
 
 
 
	wire [31:0] sign_extend_output;
 
	
	wire [31:0] alu_src2;
	wire [31:0] alu_result;
	wire alu_zero_bit;
   wire [2:0] alu_ctr;
 
	wire [31:0] data_memory_read_data;
 
 

 
 
 
	wire [31:0] program_counter_adder_output;
	
	
	wire [31:0] shift_left_2_output;
	
	wire [31:0] jump_adder_result;
 
 
	wire program_counter_mux_select;
 
	wire [31:0] move_mux_inp0;
 
 
 
 
 
   reg [31:0] pc;
	wire [31:0] pc_output;
	wire [31:0] pc_input;
	
	
	
	
	
	//Connected
	instruction_block _instruction_block (
		.instruction(instruction),
		.pc(pc_output)
	);
	 

	 
	 
	//Connects instruction memory to write register input
	ins_to_reg_mux _ins_to_reg_mux(
		.out(registers_write_reg),
		.inp0(instruction[20:16]),
		.inp1(instruction[15:11]),
		.select(regDst)
	);
	
	
	
	
	
	
	
	
	//This mux makes move instruction possible by selecting output of the write data
	//if move signal is sent,then content of read data 1 gets written to write data
	//so move operation gets done
	move_mux _move_mux(
		.out(registers_write_data),
		.inp0(move_mux_inp0),
		.inp1(registers_read_data1),
		.select(move)
	);
	

	
	
	
	
	
	
	register_block _register_block (
		.read_data1(registers_read_data1),
		.read_data2(registers_read_data2),
		.byteOperations(byteOperations),
		.write_data(registers_write_data),
		.read_reg1(instruction[25:21]),
		.read_reg2(instruction[20:16]),
		.write_reg(registers_write_reg),
		.regWrite(regWrite)
	);
  
  

	  control_unit _control_unit (
		 .regDst(regDst),
		 .branch(branch),
		 .memRead(memRead),
		 .memWrite(memWrite),
		 .ALUop(ALUop),
		 .ALUsrc(ALUsrc),
		 .regWrite(regWrite),
		 .jump(jump),
		 .byteOperations(byteOperations),
		 .move(move),
		 .opcode(instruction[31:26])
	  );
  
  
     //Connected
	  sign_extend _sign_extend (
		 .sign_ext_imm(sign_extend_output),
		 .imm(instruction[15:0])
	  );
  
  
  
   //CONNECTED
  	reg_to_alu_mux _reg_to_alu_mux (
		.out(alu_src2),
		.inp0(registers_read_data2),
		.inp1(sign_extend_output),
		.select(ALUsrc)
	);

  
  
  
 


     //connected
	  alu _alu (
		 .alu_result(alu_result),
		 .zero_bit(alu_zero_bit),
		 .alu_src1(registers_read_data1),
		 .alu_src2(alu_src2),
		 .alu_ctr(alu_ctr)
	  );
	  
  
     //connected
	  alu_control _alu_control (
		 .alu_ctr(alu_ctr),
		 .function_code(instruction[5:0]),
		 .ALUop(ALUop)
	  );
	  
  
  
  


  //connected
	memory_block _memory_block (
		 .read_data(data_memory_read_data),
		 .byteOperations(byteOperations),
		 .address(alu_result[17:0]),
		 .write_data(registers_read_data2),
		 .memRead(memRead),
		 .memWrite(memWrite)
	);  
  
  
  
   //connected
	mem_mux _mem_mux (
		.out(move_mux_inp0),
		.inp0(alu_result),
		.inp1(data_memory_read_data),
		.select(memRead)
	);
  
  
  
  
  
  
  
     //connected
	  program_counter_adder _program_counter_adder (
		 .out(program_counter_adder_output),
		 .inp(pc_output)
	  );


	  
	  //connected
	  shift_left_2 _shift_left_2 (
		 .shifted_address(shift_left_2_output),
		 .address(sign_extend_output)
	  );

  
  
 
 
		//connected
		ADDER _jump_adder
		(
			.a(program_counter_adder_output),
			.b(shift_left_2_output),
			.cin(1'b0),
			.sum(jump_adder_result)
		);

 
		//connected
		and and_gate( program_counter_mux_select , branch , alu_zero_bit );
		
		//connected
		pc_mux _pc_mux (
			.out(pc_input),
			.inp0(program_counter_adder_output),
			.inp1(jump_adder_result),
			.select(program_counter_mux_select)
		);

    
  

  
  


  reg test_bench_trigger;
  mips_tb tb (
	 .trigger(test_bench_trigger),
	 .regDst(regDst),
    .branch(branch),
    .memRead(memRead),
    .memWrite(memWrite),
    .ALUop(ALUop),
    .ALUsrc(ALUsrc),
    .regWrite(regWrite),
    .jump(jump),
    .byteOperations(byteOperations),
    .move(move),
    .instruction(instruction),
    .registers_write_reg(registers_write_reg),
    .registers_write_data(registers_write_data),
    .registers_read_data1(registers_read_data1),
    .registers_read_data2(registers_read_data2),
    .sign_extend_output(sign_extend_output),
    .alu_src2(alu_src2),
    .alu_result(alu_result),
    .alu_zero_bit(alu_zero_bit),
    .alu_ctr(alu_ctr),
    .data_memory_read_data(data_memory_read_data),
    .program_counter_adder_output(program_counter_adder_output),
    .shift_left_2_output(shift_left_2_output),
    .jump_adder_result(jump_adder_result),
    .program_counter_mux_select(program_counter_mux_select),
    .move_mux_inp0(move_mux_inp0),
    .pc(pc),
    .pc_output(pc_output),
    .pc_input(pc_input)
  );
    initial begin
		 test_bench_trigger = 1'b0;
		 pc =32'b0;
	 end
  
  
	always @(program_counter_adder_output) begin

			  pc = pc + 4;  //to show only design works,here because of a bug with program counter logic
			  test_bench_trigger = ~test_bench_trigger;
		
	end
	assign pc_output = pc;


endmodule


module mips_tb (
   input trigger,
	input regDst,
	input branch,
	input memRead,
	input memWrite,
	input [2:0] ALUop,
	input ALUsrc,
	input regWrite,
	input jump,
	input byteOperations,
	input move,
	input [31:0] instruction,
	input [4:0] registers_write_reg,
	input [31:0] registers_write_data,
	input [31:0] registers_read_data1,
	input [31:0] registers_read_data2,
	input [31:0] sign_extend_output,
	input [31:0] alu_src2,
	input [31:0] alu_result,
	input alu_zero_bit,
   input [2:0] alu_ctr,
	input [31:0] data_memory_read_data,
	input [31:0] program_counter_adder_output,
	input [31:0] shift_left_2_output,
	input [31:0] jump_adder_result,
	input program_counter_mux_select,
	input [31:0] move_mux_inp0,
   input [31:0] pc,
	input [31:0] pc_output,
	input [31:0] pc_input
);

	always@(trigger) begin

	
					$display("Instruction gets executed -> %b",instruction);
					$display("CONTROL SIGNALS");
					$display("	regDst -> %b",regDst);
					$display("	branch -> %b",branch);
					$display("	memRead -> %b",memRead);
					$display("	memWrite -> %b",memWrite);
					$display("	jump -> %b",jump);
					$display("	move -> %b",move);
					$display("	byteOperations -> %b",byteOperations);
					$display("regWrite -> %b",regWrite);
					
					
					$display("INSTRUCTION MEMORY INPUT-OUTPUTS");	
					$display("	Ins. mem. gets read address ->%b ",pc_output);
					$display("	Full instruction read as -> %b",instruction);
					$display("	Opcode -> %b",instruction[5:0]);
					$display("	Read reg 1(registers ) -> %b",instruction[25:21]);
					$display("	Read reg 2(registers) -> %b",instruction[20:16]);
					$display("	Write reg (registers) -> %b",registers_write_reg);
					$display("	Write data(registers) -> %b",registers_write_data);
					$display("	Read data 1 (registers) -> %b",registers_read_data1);
					$display("	Read data 2 (registers) -> %b",registers_read_data2);
					
					
					
					$display("ALU RELATED INPUT-OUTPUTS");
					$display("	ALUop -> %b",ALUop);
					$display("	Function code -> %b", instruction[5:0]);
					$display("	alu_ctr -> %b",alu_ctr);
					$display("	ALU input 1 -> %b",registers_read_data1);
					$display("	ALU input 2 -> %b",alu_src2);
					$display("	ALU output -> %b",alu_result);
					$display("");
					$display("	Next program counter value -> %b",pc_input);
					
					
					

					
					
					
					
					
		
					
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");
					$display("");

			end
endmodule









