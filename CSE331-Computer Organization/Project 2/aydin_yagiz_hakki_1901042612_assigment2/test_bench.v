`timescale 1ns/1ps

module tb_ALU32;

  // Inputs
  reg clk;
  reg rst;
  reg [31:0] A;
  reg [31:0] B;

  // Outputs
  wire [31:0] result;
  wire done;

  // Instantiate the ALU32 module
  ALU32 uut (
    .clk(clk),
    .rst(rst),
    .A(A),
    .B(B),
    .result(result),
    .done(done)
  );

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  // Initial stimulus
  initial begin
    // Initialize inputs
    rst = 1;
    A = 8'b10101010;
    B = 8'b01010101;

    // Apply reset
    #10 rst = 0;

    // Apply operations
    #10 A = 32'b11001100110011001100110011001100;
    #10 B = 32'b00110011001100110011001100110011;

    // Wait for the result
    #100 $stop;
  end

  // Monitor output
  always @(posedge clk) begin
    $display("Result = %h, Done = %b", result, done);
  end

endmodule
