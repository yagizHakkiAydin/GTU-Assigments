module mux2x1 (
  output wire out,
  input wire inp0,
  input wire inp1,
  input wire select
);

  wire w0, w1;
	
  wire not_wire;
  
  not not_gate(not_wire,select);
  
  
  // Implementing AND gates for input selection
  and gate0(w0, inp0, not_wire);
  and gate1(w1, inp1, select);

  // Implementing OR gate for output
  or gate2(out, w0, w1);

endmodule
