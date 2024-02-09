module mod_cu(
  input clk,
  input reset,
  input start,
  input [31:0] temp,
  input done,
  output reg [1:0] state,
  output reg next_state
);

  localparam IDLE = 2'b00,
             SUBTRACT = 2'b01,
             RESULT = 2'b10;

  always @(posedge clk or posedge reset) begin
  
    if (reset) begin
      state <= IDLE;
      next_state <= IDLE;
		
		
    end else begin
	 
      state <= next_state;
		
      case (state)
		
        IDLE: begin
          if (start) begin
            next_state <= SUBTRACT;
          end else begin
            next_state <= IDLE;
          end
        end
		  
        SUBTRACT: begin
          if (temp >= 32'b0) begin
            next_state <= SUBTRACT;
          end else begin
            next_state <= RESULT;
          end
        end
		  
        RESULT: begin
          next_state <= IDLE;
        end
		  
      endcase
		
		
    end 
	 
	 
  end
endmodule
