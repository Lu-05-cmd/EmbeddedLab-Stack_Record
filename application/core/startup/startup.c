/****************************************************************************************
 * @file    startup.c
 * @brief   Creates vector table, reset_handler, and other necessary functions executed 
 *          at MCU reset.
 * @author  lu-05-cmd
 * @date    November 1 2025
 * @version 1.0
 ****************************************************************************************/

/*      INCLUDE     */
#include <stdint.h>

/*****************************************************************************************
 *         Symboy from Linker script
 *****************************************************************************************/
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sidata;
extern uint32_t _estack;

// main
int main(void);

/*****************************************************************************************
 *            ALIAS FOR EXEPTIONS AND IRQs
 *****************************************************************************************/

void Reset_Handler(){
    uint32_t *src, *dst;
    src = &_sidata;
    dst = &_sdata;
    while(dst < &_edata){
        *dst++ = *src++;
    }

    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    main();

    while(1);
}
void Default_Handler(){ while(1); }

void NMI_Handler(void)                 __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler(void)           __attribute__((weak,alias("Default_Handler")));
void MemManage_Handler(void)           __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler(void)            __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler(void)          __attribute__((weak,alias("Default_Handler")));
void SVCall_Handler(void)              __attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler(void)            __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler(void)              __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler(void)             __attribute__((weak,alias("Default_Handler")));

void EXTI0_IRQHandler(void)          __attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler(void)          __attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler(void)          __attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler(void)          __attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler(void)          __attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)        __attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)      __attribute__((weak,alias("Default_Handler")));

void TIM2_IRQHandler(void)           __attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler(void)           __attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler(void)           __attribute__((weak,alias("Default_Handler")));

void USART1_IRQHandler(void)         __attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler(void)         __attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler(void)         __attribute__((weak,alias("Default_Handler")));

void I2C_CV_IRQHandler(void)         __attribute__((weak,alias("Default_Handler")));
void I2C_EV_IRQHandler(void)         __attribute__((weak,alias("Default_Handler")));

void SPI1_IRQHandler(void)           __attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler(void)           __attribute__((weak,alias("Default_Handler")));


/*****************************************************************************************
 *              VECTOR TABLE
 *****************************************************************************************/
__attribute__((section(".isr_vector")))
 void(* const g_pfnVector[]) = {
    (void (*)(void)) &_estack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,0,0,0,
    SVCall_Handler, 
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
 
    Default_Handler,  // 16 WWDG
    Default_Handler,  // 17 PVD
    Default_Handler,  // 18 TAMPER
    Default_Handler,  // 19 RTC
    Default_Handler,  // 20 FLASH
    Default_Handler,  // 21 RCC
    EXTI0_IRQHandler, // 22 EXTI0
    EXTI1_IRQHandler, // 23 EXTI1
    EXTI2_IRQHandler, // 24 EXTI2
    EXTI3_IRQHandler, // 25 EXTI3
    EXTI4_IRQHandler, // 26 EXTI4
    Default_Handler,  // 27 DMA1 CH1
    Default_Handler,  // 28 DMA1 CH2
    Default_Handler,  // 29 DMA1 CH3
    Default_Handler,  // 30 DMA1 CH4
    Default_Handler,  // 31 DMA1 CH5
    Default_Handler,  // 32 DMA1 CH6
    Default_Handler,  // 33 DMA1 CH7
    Default_Handler,  // 34 ADC1_2
    Default_Handler,  // 35 USB_HP
    Default_Handler,  // 36 USB_LP
    Default_Handler,  // 37 CAN_RX0
    Default_Handler,  // 38 CAN_RX1
    Default_Handler,  // 39 CAN_SCE
    EXTI9_5_IRQHandler,     // 40
    Default_Handler,         // 41 TIM1_BRK
    Default_Handler,         // 42 TIM1_UP
    Default_Handler,         // 43 TIM1_TRG_COM
    Default_Handler,         // 44 TIM1_CC
    TIM2_IRQHandler,         // 45
    TIM3_IRQHandler,         // 46
    TIM4_IRQHandler,         // 47
    I2C_EV_IRQHandler,       // 48 I2C1_EV
    I2C_CV_IRQHandler,       // 49 I2C1_ER
    Default_Handler,         // 50 I2C2_EV
    Default_Handler,         // 51 I2C2_ER
    SPI1_IRQHandler,         // 52
    SPI2_IRQHandler,         // 53
    USART1_IRQHandler,       // 54
    USART2_IRQHandler,       // 55
    USART3_IRQHandler,       // 56
};
