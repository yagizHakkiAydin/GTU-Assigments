module control_unit (
	output regDst,  //ok
	output branch,  //ok
	output memRead, //ok
	output memWrite, //ok
	output [2:0] ALUop,  //ok
	output ALUsrc,
	output regWrite, //ok
	output jump, //
	output byteOperations,
	output move,
	input [5:0] opcode
);




	
	wire [5:0] not_opcode;
	
	not n0(not_opcode[0] , opcode[0]);
	not n1(not_opcode[1] , opcode[1]);
	not n2(not_opcode[2] , opcode[2]);
	not n3(not_opcode[3] , opcode[3]);
	not n4(not_opcode[4] , opcode[4]);
	not n5(not_opcode[5] , opcode[5]);
	
	
	
// R-type  000000
wire r_type_out;
wire not_r_type_out;
not not_r_type_out_gate(not_r_type_out,r_type_out);
six_input_and is_r_type(
    .out(r_type_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);














// addi  000010
wire addi_out;
wire not_addi_out;
not not_addi_out_gate(not_addi_out,addi_out);
six_input_and is_addi(
    .out(addi_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(opcode[1]), 
    .inp6(not_opcode[0])  
);


// subi  000011
wire subi_out;
wire not_subi_out;
not not_subi_out_gate(not_subi_out,subi_out);
six_input_and is_subi(
    .out(subi_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(opcode[1]), 
    .inp6(opcode[0])  
);


// andi  000100
wire andi_out;
wire not_andi_out;
not not_andi_out_gate(not_andi_out,andi_out);
six_input_and is_andi(
    .out(andi_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);


// ori 000101
wire ori_out;
wire not_ori_out;
not not_ori_out_gate(not_ori_out,ori_out);
six_input_and is_ori(
    .out(ori_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(opcode[0])  
);


// lw  001000
wire lw_out;
wire not_lw_out;
not not_lw_out_gate(not_lw_out,lw_out);
six_input_and is_lw(
    .out(lw_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);


// sw   010000
wire sw_out;
wire not_sw_out;
not not_sw_out_gate(not_sw_out,sw_out);
six_input_and is_sw(
    .out(sw_out),
    .inp1(not_opcode[5]),
    .inp2(opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);


// lb  001001
wire lb_out;
wire not_lb_out;
not not_lb_out_gate(not_lb_out,lb_out);
six_input_and is_lb(
    .out(lb_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(opcode[0])  
);


// sb  010001
wire sb_out;
wire not_sb_out;
not not_sb_out_gate(not_sb_out,sb_out);
six_input_and is_sb(
    .out(sb_out),
    .inp1(not_opcode[5]),
    .inp2(opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(opcode[0])  
);


// slti  000111
wire slti_out;
wire not_slti_out;
not not_slti_out_gate(not_slti_out,slti_out);
six_input_and is_slti(
    .out(slti_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(opcode[2]),
    .inp5(opcode[1]), 
    .inp6(opcode[0])  
);


// beq  100011
wire beq_out;
wire not_beq_out;
not not_beq_out_gate(not_beq_out,beq_out);
six_input_and is_beq(
    .out(beq_out),
    .inp1(opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(opcode[1]), 
    .inp6(opcode[0])  
);


// bne 100111
wire bne_out;
wire not_bne_out;
not not_bne_out_gate(not_bne_out,bne_out);
six_input_and is_bne(
    .out(bne_out),
    .inp1(opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(opcode[2]),
    .inp5(opcode[1]), 
    .inp6(opcode[0])  
);


// j 000111
wire j_out;
wire not_j_out;
not not_j_out_gate(not_j_out,j_out);
six_input_and is_j(
    .out(j_out),
    .inp1(not_opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(opcode[2]),
    .inp5(opcode[1]), 
    .inp6(opcode[0])  
);


// jal  111001
wire jal_out;
wire not_jal_out;
not not_jal_out_gate(not_jal_out,jal_out);
six_input_and is_jal(
    .out(jal_out),
    .inp1(opcode[5]),
    .inp2(opcode[4]), 
    .inp3(opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(opcode[0])  
);






//move 100000
six_input_and is_move(
    .out(move),
    .inp1(opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);


//_________________________________________________________________________________________













//_____________________________________________________________________In this section,i will implement aluop signal


and aluop_a2(ALUop[2],not_andi_out,not_ori_out);





wire aluop_a1_w1;
wire aluop_a1_w2;
or aluop_a1_or1(aluop_a1_w1,subi_out,beq_out);
or aluop_a1_or2(aluop_a1_w2,r_type_out,bne_out);
or aluop_a1_or3(ALUop[1],aluop_a1_w2,aluop_a1_w1);







wire aluop_a0_w1; //ori or addi
wire aluop_a0_w2; //lb or sb
wire aluop_a0_w3; //lw or sw
wire aluop_a0_w4; //(ori or addi) or (lb or sb)
wire aluop_a0_w5;//(lw or sw) or r_type

or aluop_a0_or1(aluop_a0_w1,ori_out,addi_out);
or aluop_a0_or2(aluop_a0_w2,lb_out,sb_out);
or aluop_a0_or3(aluop_a0_w3,lw_out,sw_out);

or aluop_a0_or4(aluop_a0_w4,aluop_a0_w1,aluop_a0_w2);
or aluop_a0_or5(aluop_a0_w5,aluop_a0_w3,r_type_out);

or(ALUop[0],aluop_a0_w4,aluop_a0_w5);

//________________________________________________________________________________________



















//regDst
and regdst_result_gate(regDst,r_type_out,1'b1);



//Branch
or branch_result_gate(branch,beq_out,bne_out);



//memRead
or memread_result_gate(memRead,lw_out,lb_out);



//memWrite
or memwrite_result_gate(memWrite,sw_out,sb_out);







//regWrite signal
/*sw,sb,beq,bne,j,jr,jal instructions make regWrite 0*/

wire regwrite_wire1; // sw or sb
wire regwrite_wire2; // beq or bne
wire regwrite_wire3; // j or jal
wire regwrite_wire5;
wire regwrite_wire6;
wire regwrite_wire7;
wire regwrite_wire8;

// OR gates to combine conditions
or regwrite_or1(regwrite_wire1, sw_out, sb_out);
or regwrite_or2(regwrite_wire2, beq_out, bne_out);
or regwrite_or3(regwrite_wire3, j_out, jal_out);

// More OR gates to further combine conditions
or regwrite_or4(regwrite_wire4, regwrite_wire1, regwrite_wire2);
or regwrite_or5(regwrite_wire5, regwrite_wire3, 1'b0);

// Final OR gate to combine the last set of conditions
or regwrite_or6(regwrite_wire6, regwrite_wire4, regwrite_wire5);

// NOT gate to invert the final result
or regwrite_or7(regwrite_wire7 , regwrite_wire6 , slti_out);
not regwrite_not(regwrite_wire8, regwrite_wire7);
or regwrite_result(regWrite, regwrite_wire8 , move);







//ALUSrc
wire j_type_out;
or is_j_type_gate(j_type_out,j_out,jal_out);

wire alusrc_wire_1;
wire alusrc_wire_2;
wire alusrc_wire_3;
wire alusrc_wire_4;

or alusrc_or_1(alusrc_wire_1 , j_type_out , r_type_out);
or alusrc_or_2(alusrc_wire_2 , beq_out , bne_out);
or alusrc_or_3(alusrc_wire_3 , alusrc_wire_1 , alusrc_wire_2);
or alusrc_or_4(alusrc_wire_4 , alusrc_wire_3 , slti_out);

not alusrc_not(ALUsrc,alusrc_wire_4);















//byteOperations
or byteoperations_or(byteOperations,lb_out,sb_out);



//jump
or jump_or(jump,j_type_out,j_type_out);





//move
six_input_and is_r_type_gate(
    .out(move),
    .inp1(opcode[5]),
    .inp2(not_opcode[4]), 
    .inp3(not_opcode[3]),  
    .inp4(not_opcode[2]),
    .inp5(not_opcode[1]), 
    .inp6(not_opcode[0])  
);




endmodule




module six_input_and ( 
	output out,
	input inp1,
	input inp2,
	input inp3,
	input inp4,
	input inp5,
	input inp6
);


	wire w1;
	wire w2;
	wire w3;
	wire w4;
	wire w5;


	and a_1(w1,inp1,inp2);
	and a_2(w2,inp3,inp4);
	and a_3(w3,inp5,inp6);
	
	and a_4(w4,w1,w2);
	and a_5(out,w3,w4);
	
	
	
	
endmodule










