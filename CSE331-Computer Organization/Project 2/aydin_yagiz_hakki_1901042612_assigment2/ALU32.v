`timescale 1ns/1ns

module ALU32(
  input [31:0] a,
  input [31:0] b,
  input [2:0] ALUop,
  output wire [31:0] result,
  input wire clk,
  input wire reset
);

  wire [31:0] andWire;
  wire [31:0] orWire;
  wire [31:0] norWire;
  wire [31:0] xorWire;
  wire [31:0] adderWire;
  wire [31:0] subtractorWire;
  wire [31:0] sltWire;
  wire [31:0] modWire;

  ADDER a1 (.a(a), .b(b), .cin(1'b0), .sum(adderWire));
  SUBTRACTOR a2 (.a(a), .b(b), .cin(1'b1), .result(subtractorWire));
  AND32 a3 (.A(a), .B(b), .Y(andWire));
  OR32 a4 (.A(a), .B(b), .Y(orWire));
  NOR32 a5 (.A(a), .B(b), .Y(norWire));
  XOR32 a6 (.A(a), .B(b), .Y(xorWire));
  SLT32 a7 (.A(a), .B(b), .Y(sltWire));
  mod a8 (.a(a), .b(b), .result(modWire), .clk(clk), .reset(reset));

  MUX32 mux (
    .i0(adderWire),
    .i1(subtractorWire),
    .i2(modWire),
    .i3(xorWire),
    .i4(andWire),
    .i5(orWire),
    .i6(sltWire),
    .i7(norWire),
    .ALUop(ALUop),
    .result(result)
  );

endmodule


















`timescale 1ns/1ns

module tb;
  reg [31:0] a;
  reg [31:0] b;
  reg [2:0] ALUop;  // Add ALUop as an input
  reg clk;
  reg reset;
  wire [31:0] result;

  ALU32 alu (
    .a(a),
    .b(b),
    .ALUop(ALUop),  // Connect ALUop
	 .result(result),
	 .clk(clk),
    .reset(reset)
  );

  // Clock generation
  always #5 clk = ~clk;

  initial begin
    clk = 1'b0;
    reset = 1'b1;
    a = 32'd50;
    b = 32'd9;
    ALUop = 3'b010;  // Mod operation





    // Add some simulation steps to observe the result
    #50;

    $display("a: %d", a);
    $display("b: %d", b);
    $display("a mod b: %d", result);

    // Add a delay before stopping the simulation
    #100;

    #10 $stop;
  end

endmodule
