################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AccountManager.cpp \
../AccountManagerTester.cpp \
../Menu.cpp \
../MenuTester.cpp \
../manageUserAccounts.cpp \
../tester.cpp 

CPP_DEPS += \
./AccountManager.d \
./AccountManagerTester.d \
./Menu.d \
./MenuTester.d \
./manageUserAccounts.d \
./tester.d 

OBJS += \
./AccountManager.o \
./AccountManagerTester.o \
./Menu.o \
./MenuTester.o \
./manageUserAccounts.o \
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
	-$(RM) ./AccountManager.d ./AccountManager.o ./AccountManagerTester.d ./AccountManagerTester.o ./Menu.d ./Menu.o ./MenuTester.d ./MenuTester.o ./manageUserAccounts.d ./manageUserAccounts.o ./tester.d ./tester.o

.PHONY: clean--2e-

