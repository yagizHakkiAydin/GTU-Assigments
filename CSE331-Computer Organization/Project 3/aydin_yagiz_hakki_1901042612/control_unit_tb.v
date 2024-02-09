
module control_unit_tb;

  reg [5:0] opcode_reg;
  wire [5:0] opcode;
  wire regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move;
  wire [2:0] ALUop;

  // Instantiate control_unit module
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
    .opcode(opcode)
  );

  // Initial block to apply stimulus
  initial begin
    // Apply opcode values for testing
    opcode_reg = 6'b000000; // For R-type
    #10;
    $display("For opcode %b r-type, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b000010; // For addi
    #10;
    $display("For opcode %b addi, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b000011; // For subi
    #10;
    $display("For opcode %b subi, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b000100; // For andi
    #10;
    $display("For opcode %b andi, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b000101; // For ori
    #10;
    $display("For opcode %b ori, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b001000; // For lw
    #10;
    $display("For opcode %b lw, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b001001; // For lb
    #10;
    $display("For opcode %b lb, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b010000; // For sw
    #10;
    $display("For opcode %b sw, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b010001; // For sb
    #10;
    $display("For opcode %b sb, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b000111; // For slti
    #10;
    $display("For opcode %b slti, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b100011; // For beq
    #10;
    $display("For opcode %b beq, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b100111; // For bne
    #10;
    $display("For opcode %b bne, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b111000; // For jump
    #10;
    $display("For opcode %b j, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    opcode_reg = 6'b111001; // For jal
    #10;
    $display("For opcode %b jal, ALUop=%b, regDst=%b, branch=%b, memRead=%b, memWrite=%b, ALUsrc=%b, regWrite=%b, jump=%b, byteOperations=%b, move=%b", opcode_reg, ALUop, regDst, branch, memRead, memWrite, ALUsrc, regWrite, jump, byteOperations, move);

    // Terminate simulation
    $stop;
  end

  // Connect reg to wire
  assign opcode = opcode_reg;

endmodule
