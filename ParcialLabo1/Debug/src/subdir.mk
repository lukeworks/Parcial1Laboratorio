################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ParcialLabo1.c \
../src/clientes.c \
../src/inputs.c \
../src/menu.c \
../src/nexo.c \
../src/pedidos.c 

OBJS += \
./src/ParcialLabo1.o \
./src/clientes.o \
./src/inputs.o \
./src/menu.o \
./src/nexo.o \
./src/pedidos.o 

C_DEPS += \
./src/ParcialLabo1.d \
./src/clientes.d \
./src/inputs.d \
./src/menu.d \
./src/nexo.d \
./src/pedidos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


