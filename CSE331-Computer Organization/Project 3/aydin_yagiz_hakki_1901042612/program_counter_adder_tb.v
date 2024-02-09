`timescale 1ns / 1ps

module program_counter_adder_tb;

  // Inputs
  reg [31:0] address;
  
  // Outputs
  wire [31:0] next_address;

  // Instantiate the program_counter_adder module
  program_counter_adder uut (
    .address(address),
    .next_address(next_address)
  );

  // Clock generation
  reg clk = 0;
  always #5 clk = ~clk;

  // Testbench stimulus
  initial begin
    // Test case 1
    address = 32'h00000000;
    #10;
    $display("Test case 1: Address = %h, Next Address = %h", address, next_address);
    
    // Test case 2
    address = 32'h12345678;
    #10;
    $display("Test case 2: Address = %h, Next Address = %h", address, next_address);

    // Add more test cases as needed

    $finish;
  end

  // Clock generation
  always #2 clk = ~clk;

endmodule