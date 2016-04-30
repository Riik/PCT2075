################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Rik\ van\ der\ Vlist/Downloads/eclipseArduino/arduinoPlugin/packages/arduino/hardware/avr/1.6.10/libraries/Wire/src/Wire.cpp 

LINK_OBJ += \
./libraries/Wire/src/Wire.cpp.o 

CPP_DEPS += \
./libraries/Wire/src/Wire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Wire/src/Wire.cpp.o: C:/Users/Rik\ van\ der\ Vlist/Downloads/eclipseArduino/arduinoPlugin/packages/arduino/hardware/avr/1.6.10/libraries/Wire/src/Wire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


