`timescale 1ns/1ns

module tb;
  reg [31:0] a;
  reg [31:0] b;
  reg clk;
  reg reset;
  wire [31:0] result;

  ALU32 i0(
    .a(a),
    .b(b),
    .reset(reset),
    .clk(clk),
    .result(result)
  );

  // Clock generation
  always #5 clk = ~clk;

  initial begin
    clk = 1'b0;
    reset = 1'b1;
    a = 32'd250;
    b = 32'd251;

    #5 reset = 1'b0;

    #10 reset = 1'b1;
    b = 32'd200;

    #5 reset = 1'b0;

    // Add some simulation steps to observe the result
    #100;

    $display("Result: %h", result);

    #10 $stop;
  end

endmodule

