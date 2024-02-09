module instruction_block (
	output reg [31:0] instruction,
	input [31:0] pc
);
	
	reg [7:0] instruction_memory[4095:0];
	
	
	always @(pc) begin
		$readmemb("instructions.mem", instruction_memory);
	 
      instruction[31:24] = instruction_memory[pc];
		instruction[23:16] = instruction_memory[pc+1];
		instruction[15:8] = instruction_memory[pc+2];
		instruction[7:0] = instruction_memory[pc+3];
		
		$writememb("instructions.mem", instruction_memory);
        
    end
	
	
endmodule


