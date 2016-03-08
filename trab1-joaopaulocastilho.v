module plight(
	      input  clk,
	      output led);
   
   assign led = clk;
endmodule // plight

module test;
   reg clk;
   wire led;
  
   plight pled(clk, led);
   always #2 clk = ~clk;
   initial begin
      $dumpvars(0, pled);
      clk <= 1'b0;
      #500;
      $finish;
   end
endmodule // test

   
