module clock(clk,btn,dis0,dis1,dis2,dis3, led);

input clk;
input [3:0] btn;
reg [3:0] pressed = 0;
output [0:6] dis0,dis1,dis2,dis3;
output reg [3:0] led;
reg[0:30] i = 0;
parameter decsegundo = 5000000;
parameter parado = 0, contando = 1, pausado = 2, reset = 3;
reg [13:0] number = 0;
reg [1:0] state = reset;
reg [1:0] pausaDis = 0;

initial begin
	led = 4'b1000;
end

always @ (posedge clk) begin
	if(i + 1 == decsegundo)begin
		number <= number+1;
		if(number == 10000) number <= 0; 
		i <= 0;
	end
	else i <= i+1;
	//else if(state != parado && state != reset)i <= i+1;
	/*else if(state == reset)begin
		i <= 0;
		number <= 0;
	end*/
end
/*
always @ (negedge clk) begin
	if(!btn[0]) pressed[0] <= 1;
	if(!btn[1]) pressed[1] <= 1;
	if(!btn[2]) pressed[2] <= 1;
	if(!btn[3]) pressed[3] <= 1;
	if(btn[0] && pressed[0]) begin
		state <= parado;
		led[3] <= 0;
		led[2] <= 0;
		led[1] <= 0;
		led[0] <= 1;
		pressed[0] <= 0;
		pausaDis <= 0;
	end
	if(btn[1] && pressed[1]) begin
		if(state == contando) begin
			state <= pausado;
			led[3] <= 0;
			led[2] <= 0;
			led[1] <= 1;
			led[0] <= 0;
			pausaDis <= 1;
		end
		pressed[1] <= 0;
	end
	if(btn[2] && pressed[2]) begin
		state <= contando;
		led[3] <= 0;
		led[2] <= 1;
		led[1] <= 0;
		led[0] <= 0;
		pressed[2] <= 0;
		pausaDis <= 0;
	end
	if(btn[3] && pressed[3]) begin
		state <= reset;
		led[3] <= 1;
		led[2] <= 0;
		led[1] <= 0;
		led[0] <= 0;
		pressed[3] <= 0;
		pausaDis <= 0;
	end
end*/
main(number,pausaDis,dis0,dis1,dis2,dis3);	

endmodule