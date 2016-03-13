module counter32bits(input clk, input reset, output [31:0] num);
   reg[31:0] numb;
   
   assign num = numb;

   always @(posedge clk or posedge reset)
     if(reset) numb <= 0;
     else numb <= numb + 1;
endmodule // counter32bits

module verifica_num(input clk, input [31:0] num, output reset, output [7:0] led);
   reg [7:0] ledR = 8'b01010101;
   reg resetR;
	
   assign reset = resetR;
   assign led = ledR;

   always @(clk)
     if(num == 50000000)
       begin
	  resetR <= 1;
	  ledR <= ~ledR;
       end
     else
       begin
	  resetR <= 0;
       end
endmodule // verifica_num

module trab2(input CLOCK_50, output [7:0] LEDG);
   wire rstins;
   wire [31: 0] numins;
   wire [7:0]	ledins;
   
   counter32bits contador(CLOCK_50, rstins, numins);
   verifica_num verifica(CLOCK_50, numins, rstins, ledins);
   
   assign LEDG = ledins;   
endmodule // trab2

/*module test;
   reg clk;
   wire [7:0] led;

   trab2 teste(clk, led);
   always #1 clk = ~clk;
   
   initial
     begin
	$dumpvars(0, teste);
	clk = 0;
	#500
	$finish;
     end
endmodule // test
*/

   
