module register_block (
    output reg [31:0] read_data1,
    output reg [31:0] read_data2,
    input byteOperations,
    input [31:0] write_data,
    input [4:0] read_reg1,
    input [4:0] read_reg2,
    input [4:0] write_reg,
    input regWrite
);

    // Registers in file "registers.mem"
    reg [31:0] registers[31:0];


    always @(write_data,read_reg1, read_reg2, write_reg,regWrite,byteOperations) begin
        $readmemb("registers.mem", registers);

        // Read data from registers
        read_data1 = registers[read_reg1];
        read_data2 = registers[read_reg2];

        // Write data to register
        if (regWrite) begin
            if (byteOperations) begin
                // Byte Write Operation
                case (write_reg[1:0])
                    2'b00: registers[write_reg] = write_data[7:0];
                    2'b01: registers[write_reg] = {registers[write_reg][31:8], write_data[7:0]};
                    2'b10: registers[write_reg] = {registers[write_reg][31:16], write_data[15:0]};
                    2'b11: registers[write_reg] = {registers[write_reg][31:24], write_data[23:0]};
                endcase
            end else begin
                if (write_data !== 32'hxxxx_xxxx) begin
                    registers[write_reg] = write_data;
                end
            end
        end
        $writememb("registers.mem", registers);
    end
endmodule
