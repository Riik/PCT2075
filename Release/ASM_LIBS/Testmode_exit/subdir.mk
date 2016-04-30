################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../ASM_LIBS/Testmode_exit/exit_testmode.S 

LINK_OBJ += \
./ASM_LIBS/Testmode_exit/exit_testmode.S.o 

S_UPPER_DEPS += \
./ASM_LIBS/Testmode_exit/exit_testmode.S.d 


# Each subdirectory must supply rules for building sources it contributes
ASM_LIBS/Testmode_exit/exit_testmode.S.o: ../ASM_LIBS/Testmode_exit/exit_testmode.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-gcc" -c -g -x assembler-with-cpp -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


