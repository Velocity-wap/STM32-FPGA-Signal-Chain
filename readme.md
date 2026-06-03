# STM32-FPGA-Signal-Chain

## Overview
Two-hardware signal chain demonstrating FPGA-to-STM32 analog signal communication. FPGA generates PWM signal through RC filter, STM32 reads it via ADC triggered by timer, streams results over UART to PC.

## 01 - FPGA PWM Generator (Verilog)

Generates variable DC voltage output via PWM and RC low-pass filter.

### What it does
- 4-bit up counter in Verilog increments on every clock cycle
- Compare value (8 bits) determines PWM duty cycle
- Output HIGH while counter < compare value, LOW after
- PWM pin connects through RC filter (10kΩ, 100nF) to smooth into analog voltage
- Change compare value in code to change output voltage

### Files
- counter_pwm.v — PWM generator module
- tb_counter_pwm.v — testbench for GTKWave simulation

### How to use
iverilog -o sim counter_pwm.v tb_counter_pwm.v
vvp sim
gtkwave counter_pwm.vcd

---

## 02 - STM32 Signal Reader

Reads FPGA-generated analog signal via ADC, triggered by timer at fixed intervals, outputs to UART.

### What it does
- Timer (TIM2) fires at fixed interval, triggers ADC conversion automatically
- ADC converts FPGA voltage (0-3.3V) to 12-bit digital value (0-4095)
- UART transmits ADC reading to PC terminal (PuTTY) in real time
- Change FPGA compare value, voltage changes, ADC reading changes, visible on screen

### Hardware Connection
FPGA GPIO (pwm_out) connected through RC Filter to STM32 PA0 (ADC input).
RC Filter: 10kΩ resistor plus 100nF capacitor, low-pass cutoff around 160Hz.
Ground wire shared between FPGA and STM32.

### Registers used (ADC)
- RCC APB2ENR (0x40021018) — enable ADC1, GPIOA clocks
- RCC CFGR (0x40021004) — set ADC prescaler to /2 (4MHz ADC clock)
- GPIOA CRL (0x40010800) — configure PA0 as analog input
- ADC1 CR2 (0x40012408) — enable ADC, trigger SWSTART
- ADC1 CR1 (0x40012404) — configure resolution, scan mode
- ADC1 SMPR2 (0x40012410) — set sampling time for CH0
- ADC1 SQR3 (0x40012434) — select channel 0 for conversion
- ADC1 SR (0x40012400) — poll EOC flag
- ADC1 DR (0x4001244C) — read conversion result

### Registers used (Timer)
- TIM2 PSC (0x40000028) — prescaler divides 8MHz to 1MHz
- TIM2 ARR (0x4000002C) — period sets conversion frequency
- TIM2 CR1 (0x40000000) — enable timer

### Registers used (UART)
- RCC APB2ENR (0x40021018) — enable USART1 clock, bit 4
- GPIOA CRH (0x40010804) — configure PA9 (TX) as alternate function push-pull, PA10 (RX) as floating input
- USART1 CR1 (0x4001380C) — enable transmitter, receiver, USART
- USART1 BRR (0x40013808) — set baud rate to 9600 (value 0x271 at 8MHz clock)
- USART1 SR (0x40013800) — check TXE flag (bit 7) before sending, check RXNE flag (bit 5) before receiving
- USART1 DR (0x40013804) — write character to send, read character received
---

## Full Signal Chain
Verilog Code generates FPGA Hardware PWM Signal through RC Filter to Analog Voltage input on STM32 ADC. Timer triggers ADC conversion. ADC result transmitted via UART to PuTTY Terminal on PC.

---

## Toolchain
- FPGA: Quartus (Altera) or Vivado (Xilinx) for synthesis and flashing
- STM32: arm-none-eabi-gcc, make, ST-Link V2 plus OpenOCD
- Simulation: iverilog plus GTKWave
- Terminal: PuTTY or minicom for UART output

## Key Learning
- FPGA generates real analog signals via PWM
- STM32 timer-triggered ADC (no CPU polling)
- Multi-peripheral coordination (Timer plus ADC plus UART)
- Cross-platform hardware communication

## No HAL, no libraries — direct register access only