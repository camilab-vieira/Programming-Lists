module cronometro(clk, botoes, led, dis0, dis1, dis2, dis3);

input clk;
input [0:3] botoes;
output [0:6] dis0, dis1, dis2, dis3;
output [0:3] led;

wire sinalContaTempo, sinalPausaDisplay, sinalZeraTempo;
wire [13:0] sinalNumber;

wire [0:6] sinalNumDis0;
wire [0:6] sinalNumDis1;
wire [0:6] sinalNumDis2;
wire [0:6] sinalNumDis3;

fsm(.clk(clk), .btn(botoes), .contaTempo(sinalContaTempo), .pausaDisplay(sinalPausaDisplay), .zeraTempo(sinalZeraTempo), .led(led));

contador(.clk(clk), .contaTempo(sinalContaTempo), .zeraTempo(sinalZeraTempo), .number(sinalNumber));

conversor(.number(sinalNumber), .pausaDis(sinalPausaDisplay), .num0(sinalNumDis0), .num1(sinalNumDis1), .num2(sinalNumDis2), .num3(sinalNumDis3));

decodificador(.number(sinalNumDis0), .display(dis0));
decodificador(.number(sinalNumDis1), .display(dis1));
decodificador(.number(sinalNumDis2), .display(dis2));
decodificador(.number(sinalNumDis3), .display(dis3));


endmodule