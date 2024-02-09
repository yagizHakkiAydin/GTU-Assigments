module memory_block (
    output reg [31:0] read_data,
    input byteOperations,
    input [17:0] address,
    input [31:0] write_data,
    input memRead,
    input memWrite
);

    //reg [7:0] memory[262143:0];
	 reg [7:0] memory[1023:0];
	
    always @(address ,memWrite , memRead,write_data,byteOperations) begin
		 $readmemb("memory.mem", memory);
        // Read data from memory based on the address
        if (byteOperations) begin
            read_data = (address[0] == 1) ? {8'h00, memory[address[17:1]][7:0]} : {memory[address[17:1]], 8'h00};
        end else begin
            read_data = memory[address];
        end


        // Write data to memory
        if (memWrite) begin
            if (byteOperations) begin
                // Byte Write Operation
                if (address[0] == 1)
                    memory[address[17:1]][7:0] = write_data[7:0];
                else
                    memory[address[17:1]] = write_data[31:8];
            end else begin
                // Word Write Operation
                memory[address] = write_data;
            end
				 $writememb("memory.mem", memory);
        end
    end

endmodule
