################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PCT2075.cpp \
../PCT2075_setup.cpp \
../Serial.cpp \
../TestMode.cpp \
../buffer.cpp \
../external_board.cpp \
../misc.cpp 

S_UPPER_SRCS += \
../TestSignal.S 

LINK_OBJ += \
./PCT2075.cpp.o \
./PCT2075_setup.cpp.o \
./Serial.cpp.o \
./TestMode.cpp.o \
./TestSignal.S.o \
./buffer.cpp.o \
./external_board.cpp.o \
./misc.cpp.o 

S_UPPER_DEPS += \
./TestSignal.S.d 

CPP_DEPS += \
./PCT2075.cpp.d \
./PCT2075_setup.cpp.d \
./Serial.cpp.d \
./TestMode.cpp.d \
./buffer.cpp.d \
./external_board.cpp.d \
./misc.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
PCT2075.cpp.o: ../PCT2075.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

PCT2075_setup.cpp.o: ../PCT2075_setup.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Serial.cpp.o: ../Serial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

TestMode.cpp.o: ../TestMode.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

TestSignal.S.o: ../TestSignal.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-gcc" -c -g -x assembler-with-cpp -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

buffer.cpp.o: ../buffer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

external_board.cpp.o: ../external_board.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

misc.cpp.o: ../misc.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\standard" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire" -I"C:\Users\Rik van der Vlist\Downloads\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


