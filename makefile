all: serial-conv

serial-conv:
	gcc -Wall -Wextra -o out/s_conv src/serial_main.c src/convolution.c src/image.c src/kernel_sample.c

test-s-1: serial-conv
	cd out; ./s_conv fubuki.sis
