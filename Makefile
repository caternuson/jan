#==============================================================================
# These are the basic steps:
#
# avr-gcc -g -Wall -O2 -mmcu=attiny85 -c -o demo.o demo.c
# avr-gcc -g -Wall -O2 -mmcu=attiny85 -Wl,-Map,demo.map -o demo.elf demo.o
# avr-objcopy -j .text -j .data -O ihex demo.elf demo.hex
#==============================================================================

#------------------------------------------------------------------------------
# Defines
#------------------------------------------------------------------------------
PROJECT = jan

MCU_TARGET = attiny85
F_CPU = 16000000

TOOLCHAIN   = avr
CC          = $(TOOLCHAIN)-gcc
OBJCOPY     = $(TOOLCHAIN)-objcopy

CFLAGS = -g2 -mmcu=$(MCU_TARGET) -DF_CPU=$(F_CPU)
CFLAGS+= -Os -std=c99 -ffunction-sections -fdata-sections -fpack-struct -fno-move-loop-invariants -fno-tree-scev-cprop -fno-inline-small-functions
CFLAGS+= -Wall -Wno-pointer-to-int-cast

ifeq ($(DEBUG), 1)
  CFLAGS += -ggdb
endif

LDFLAGS = -Wl,--relax,--section-start=.text=0,-Map=$(PROJECT).map

SRC = 	$(PROJECT).c \
		adc.c \
		init.c \
		neopixels.c \
		speaker.c \
		light.c \
		temperature.c \
		light_ws2812.c

OBJS = $(SRC:.c=.o)

#------------------------------------------------------------------------------
# Rules
#------------------------------------------------------------------------------
all: $(OBJS) $(PROJECT).elf $(PROJECT).hex

$(PROJECT).hex : $(PROJECT).elf
	$(OBJCOPY) -j .text -j .data -O ihex $(PROJECT).elf $(PROJECT).hex

$(PROJECT).elf : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROJECT).elf $(OBJS)

%o : %c
	$(CC) -c $(CFLAGS) $< -o $@ 
	
clean:
	rm -rf *.o *.elf *.hex

program:
	avrdude -P usb -c dragon_isp -p $(MCU_TARGET) -U flash:w:$(PROJECT).hex