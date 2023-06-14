################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BST.cpp \
../BST_Tester.cpp \
../tester.cpp 

CPP_DEPS += \
./BST.d \
./BST_Tester.d \
./tester.d 

OBJS += \
./BST.o \
./BST_Tester.o \
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
	-$(RM) ./BST.d ./BST.o ./BST_Tester.d ./BST_Tester.o ./tester.d ./tester.o

.PHONY: clean--2e-

