module mod_dp(
  input clk,
  input reset,
  input [31:0] A,
  input [31:0] B,
  input start,
  output reg [31:0] temp,
  output reg done
);

always @(posedge clk or posedge reset) begin
    if (reset) begin
        temp <= 32'b0;
        done <= 1'b0;
    end else if (start) begin
        temp <= A;
        if (temp >= B) begin
            done <= 1'b0;
        end else begin
            done <= 1'b1;
        end
        if (done == 1'b0) begin
				$display("temp %d", temp);
            temp <= temp - B;
        end
    end
end

endmodule
