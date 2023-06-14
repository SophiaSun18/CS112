################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lab4/Vec.cpp \
../lab4/VecTester.cpp \
../lab4/tester.cpp 

CPP_DEPS += \
./lab4/Vec.d \
./lab4/VecTester.d \
./lab4/tester.d 

OBJS += \
./lab4/Vec.o \
./lab4/VecTester.o \
./lab4/tester.o 


# Each subdirectory must supply rules for building sources it contributes
lab4/%.o: ../lab4/%.cpp lab4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lab4

clean-lab4:
	-$(RM) ./lab4/Vec.d ./lab4/Vec.o ./lab4/VecTester.d ./lab4/VecTester.o ./lab4/tester.d ./lab4/tester.o

.PHONY: clean-lab4

