
module tb_counter_pwm;

reg clk, rst, en;
wire pwm;
wire [3:0] count;

counter_pwm dut (
    .clk(clk),
    .rst(rst),
    .en(en),
    .pwm(pwm),
    .count(count)
);

initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

initial begin
    $dumpfile("counter_pwm.vcd");
    $dumpvars(0, tb_counter_pwm);

    rst = 1; en = 0;
    #20;
    // count up — pwm HIGH when count < 8
    rst = 0; en = 1;
    #500

    $finish;
end

endmodule