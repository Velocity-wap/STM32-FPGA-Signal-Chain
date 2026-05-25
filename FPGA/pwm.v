module counter_pwm(
    input clk,
    input rst,
    input en,
    output reg pwm,
    output reg [3:0] count
);

always @(posedge clk)
    if(rst)
        count <= 0;
    else if (en) begin
            count <= count + 1;
    end

always @(posedge clk)
    if(count < 4'd8 && count != 0)
    pwm <= 1;
    else
    pwm <= 0;
    
endmodule