module counter_pwm(
    input clk,
    input rst,
    input en,
    input dir,
    output reg pwm,
    output reg [3:0] count
);

always @(posedge clk)
    if(rst)
        count <= 0;
    else if (en) begin
        if(dir)
            count <= count + 1;
        else
            count <= count - 1;
    
    end

always @(posedge clk)
    if(count < 4'd8)
    pwm <= 1;
    else
    pwm <= 0;
    
endmodule