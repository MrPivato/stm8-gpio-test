.PHONY: all clean

#Compiler
CC = sdcc
OBJCOPY = stm8-objcopy
SIZE = stm8-size

#Platform
PLATFORM = stm8

#Product name
PNAME = main

#Directory for helpers
IDIR = StdPeriphLib/inc
SDIR = StdPeriphLib/src

# In case you ever want a different name for the main source file
MAINSRC = $(PNAME).c

ELF_SECTIONS_TO_REMOVE = #-R SSEG -R DATA -R INITIALIZED  -R .debug_line -R .debug_loc -R .debug_abbrev -R .debug_info -R .debug_pubnames -R .debug_frame

# These are the sources that must be compiled to .rel files:
EXTRASRCS = \
	$(SDIR)/stm8s_gpio.c \
	$(SDIR)/stm8s_tim1.c \
	$(SDIR)/stm8s_tim2.c \
	$(SDIR)/stm8s_adc1.c \
	state.c \
	# all of the stm8 features, add as needed 
	#$(SDIR)/stm8s_adc1.c \
	$(SDIR)/stm8s_adc1.c \
	$(SDIR)/stm8s_adc2.c \
	$(SDIR)/stm8s_awu.c \
	$(SDIR)/stm8s_beep.c \
	$(SDIR)/stm8s_can.c \
	$(SDIR)/stm8s_clk.c \
	$(SDIR)/stm8s_exti.c \
	$(SDIR)/stm8s_flash.c \
	$(SDIR)/stm8s_gpio.c \
	$(SDIR)/stm8s_i2c.c \
	$(SDIR)/stm8s_it.c \
	$(SDIR)/stm8s_itc.c \
	$(SDIR)/stm8s_iwdg.c \
	$(SDIR)/stm8s_rst.c \
	$(SDIR)/stm8s_spi.c \
	$(SDIR)/stm8s_tim1.c \
	$(SDIR)/stm8s_tim2.c \
	$(SDIR)/stm8s_tim3.c \
	$(SDIR)/stm8s_tim4.c \
	$(SDIR)/stm8s_tim5.c \
	$(SDIR)/stm8s_tim6.c \
	$(SDIR)/stm8s_uart1.c \
	$(SDIR)/stm8s_uart2.c \
	$(SDIR)/stm8s_uart3.c \
	$(SDIR)/stm8s_uart4.c \
	$(SDIR)/stm8s_wwdg.c \

HEADERS = state.h

# The list of .rel files can be derived from the list of their source files
RELS = $(EXTRASRCS:.c=.rel)

INCLUDES = -I$(IDIR) -I. 
CFLAGS   = -m$(PLATFORM) -Ddouble=float --std-c99
ELF_FLAGS = --out-fmt-elf --debug -mstm8 --opt-code-size 
LIBS     = 
#CFLAGS   = -m$(PLATFORM) -Ddouble=float --std-c99 --nolospre
#ELF_FLAGS = --out-fmt-elf --nogcse --all-callee-saves --debug --verbose --stack-auto --fverbose-asm --float-reent --no-peep -mstm8

# This just provides the conventional target name "all"; it is optional
# Note: I assume you set PNAME via some means not exhibited in your original file
all: $(PNAME)

# How to build the overall program
$(PNAME): $(MAINSRC) $(RELS)
	$(CC) $(INCLUDES) $(CFLAGS) $(ELF_FLAGS) $(LIBS) $(MAINSRC) $(RELS)
	$(SIZE) $(PNAME).elf
	$(OBJCOPY) $(ELF_SECTIONS_TO_REMOVE) $(PNAME).elf $(PNAME).elf
#	$(OBJCOPY) -O binary $(ELF_SECTIONS_TO_REMOVE) $(PNAME).elf $(PNAME).bin
#	$(OBJCOPY) -O ihex $(ELF_SECTIONS_TO_REMOVE) $(PNAME).elf $(PNAME).hex

# How to build any .rel file from its corresponding .c file
# GNU would have you use a pattern rule for this, but that's GNU-specific
%.rel: %.c $(HEADERS)
	$(CC) -c $(INCLUDES) $(CFLAGS) $(ELF_FLAGS) $(LIBS) -o$< $<

# Suffixes appearing in suffix rules we care about.
# Necessary because .rel is not one of the standard suffixes.
.SUFFIXES: .c .rel

hex:
	$(OBJCOPY) -O ihex $(ELF_SECTIONS_TO_REMOVE) $(PNAME).elf $(PNAME).hex
#hex:
#	$(OBJCOPY) --remove-section SSEG $(PNAME).elf $(PNAME).hex

# flash:
#	stm8flash -cstlinkv2 -pstm8s105?6 -w$(PNAME).ihx

ENTF = cmd /C del

clean:
	@echo "Cleaning files..."
	@clean.bat
	@$(ENTF) *.asm 
	@$(ENTF) *.rel
	@$(ENTF) *.lk
	@$(ENTF) *.lst
	@$(ENTF) *.rst
	@$(ENTF) *.sym
	@$(ENTF) *.cdb
	@$(ENTF) *.map
	@$(ENTF) *.elf
	@$(ENTF) *.adb 
	@echo "Done."

