module register_block_tb();

  wire [31:0] read_data1;
  wire [31:0] read_data2;
  reg byteOperations;
  reg [31:0] write_data;
  reg [4:0] read_reg1;  //address
  reg [4:0] read_reg2;
  reg [4:0] write_reg;
  reg regWrite;

  register_block _reg_block (
    .read_data1(read_data1),
    .read_data2(read_data2),
    .byteOperations(byteOperations),
    .write_data(write_data),
    .read_reg1(read_reg1),
    .read_reg2(read_reg2),
    .write_reg(write_reg),
    .regWrite(regWrite)
  );

  initial begin
		#10;
		read_reg1 = 0;
		#10;
		$display("%b",read_data1);
		#10;
		read_reg1 = 1;
		#10;
		$display("%b",read_data1);
		#10;
		read_reg1 = 3;
		#10;
		$display("%b",read_data1);
  end

endmodule
