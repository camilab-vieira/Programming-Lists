module conversor(number, pausaDis, num0, num1, num2, num3);

input [13:0] number;
input pausaDis;

output reg [3:0] num0, num1, num2, num3;

always @ (number) begin
	if(pausaDis != 1) begin
		num0 <= number % 10;
		num1 <= (number / 10)%10;
		num2 <= (number / 100)%10;
		num3 <= (number / 1000)%10;
	end
end

endmodule