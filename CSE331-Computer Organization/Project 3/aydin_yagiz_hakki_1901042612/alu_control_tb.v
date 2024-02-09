module alu_control_tb;

  reg [5:0] function_code;
  reg [2:0] ALUop;
  wire [2:0] alu_ctr;

  // Instantiate alu_control module
  alu_control alu_ctrl_inst (
    .alu_ctr(alu_ctr),
    .function_code(function_code),
    .ALUop(ALUop)
  );

  // Initial block to apply stimulus
  initial begin
    // Test case 1: R-type, ALUop = 000 (Addition)
    function_code = 6'b000010;
    ALUop = 3'b111;
    #10;
    $display("Test Case 1: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);

    // Test case 2: R-type, ALUop = 010 (Subtraction)
    function_code = 6'b000011;
    ALUop = 3'b111;
    #10;
    $display("Test Case 2: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);

    // Test case 3: AND operation
    function_code = 6'b000100;
    ALUop = 3'b111;
    #10;
    $display("Test Case 3: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);

    // Test case 4: OR operation
    function_code = 6'b000101;
    ALUop = 3'b111;
    #10;
    $display("Test Case 4: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);

    // Test case 5: Set on Less Than (SLT)
    function_code = 6'b000111;
    ALUop = 3'b111;
    #10;
    $display("Test Case 5: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);

    
	  // Test case 6: andi
    function_code = 6'b000010;
    ALUop = 3'b110;
    #10;
    $display("Test Case 5: For function_code %b and ALUop %b, result alu_ctr=%b", function_code, ALUop, alu_ctr);


    // Terminate simulation
    $stop;
  end

endmodule
