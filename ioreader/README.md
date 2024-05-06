*IoReader* is a simple device for measuring and providing signals on data bus of 8bit computer.

# Functionalities
- Supports 16 bit wide buses (16 wires)
- Displays 16 bits as 16 leds (grouped by 8)
- Displays 16 bits as 4 hex digits on 7-segment display
- Allows to connect any of 16 bits to VCC, effectively providing set value on bus
- Uses powerbank module with one 18650 li-ion cell to power device (the modlue allows recharging via USB-C port)
- Main PCB contains simple circuit which uses NPN transistor to pulse 100mA of current from VCC to GND in order to keep powerbank module power alive (powerbank module stops providing power after 30s of lack of high current draw >100mA)