module main(number, pausaDis, dis0, dis1, dis2, dis3);

input [13:0] number;
input [1:0] pausaDis;
output [0:6] dis0, dis1, dis2, dis3;

reg [3:0] num0, num1, num2, num3;

always @ (number) begin
	if(pausaDis != 1) begin
		num0 <= number % 10;
		num1 <= (number / 10)%10;
		num2 <= (number / 100)%10;
		num3 <= (number / 1000)%10;
	end
end

decodificador dec0(num0, dis0); 
decodificador dec1(num1, dis1);
decodificador dec2(num2, dis2);
decodificador dec3(num3, dis3);

endmodule