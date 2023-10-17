module contador(clk, contaTempo, zeraTempo, number);

input clk;
input contaTempo;
input zeraTempo;

output reg[13:0] number = 0;


parameter decsegundo = 5000000; //numero de pulsos para formar um ds

reg[0:30] i = 0; 

always @ (posedge clk) begin
	if(i + 1 == decsegundo)begin
		number <= number+1;
		if(number == 10000) number <= 0; 
		i <= 0;
	end
	else if(contaTempo == 1 && zeraTempo == 0) i <= i+1;
	else if(zeraTempo == 1)begin
		i <= 0;
		number <= 0;
	end
	
end

endmodule