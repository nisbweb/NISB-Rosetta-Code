`timescale 1ns/1ns

module mod10(input clk, rst,
             output reg [3:0] out);
    
    always @(posedge clk) begin
        if (!rst)
            out <= 0;
        else begin
            if (out == 10)
                out <= 0;
            else
                out <= out + 1; 
        end
    end
endmodule


module mod10_tb;
    reg clk, rst;
    wire [3:0] out;

    mod10 uut(.clk(clk), .rst(rst), .out(out));
    

    always #10 clk = ~clk;

    initial begin
        $monitor("%b    %b    %b\n", rst, clk, out);
        $dumpfile("dump.vcd");
        $dumpvars(0, mod10_tb);
    end

    initial begin
        {clk, rst} <= 0;
        #10 rst <= 1;
        #300 $finish;
    end
endmodule