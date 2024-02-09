 module mod(
  input [31:0] a,
  input [31:0] b,
  output wire [31:0] result,
  input clk,
  input reset
  
);

  reg start;
  
  always @(posedge clk or posedge reset) begin
    if (reset) begin
      start <= 1'b0;
    end else if (start) begin
      start <= 1'b0;
    end else begin
      start <= 1'b1;
    end
  end

  // Instantiate other modules
  mod_dp mod_dp(
    .clk(clk),
    .reset(reset),
    .A(a),
    .B(b),
    .start(start),
    .temp(result),
    .done(done)
  );

endmodule




















