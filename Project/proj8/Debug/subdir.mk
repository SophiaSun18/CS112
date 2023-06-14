################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ReversePoem.cpp \
../ReverseTester.cpp \
../StackTester.cpp \
../main.cpp \
../tester.cpp 

CPP_DEPS += \
./ReversePoem.d \
./ReverseTester.d \
./StackTester.d \
./main.d \
./tester.d 

OBJS += \
./ReversePoem.o \
./ReverseTester.o \
./StackTester.o \
./main.o \
./tester.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./ReversePoem.d ./ReversePoem.o ./ReverseTester.d ./ReverseTester.o ./StackTester.d ./StackTester.o ./main.d ./main.o ./tester.d ./tester.o

.PHONY: clean--2e-

