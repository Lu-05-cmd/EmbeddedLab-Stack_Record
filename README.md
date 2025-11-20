
# ========================

# PROJEC TREE DIAGRAM   =

# ========================




bluepill-baremetal-framework/
│
├── application/
|   ├── core/
│   │   ├── startup/
│   │   │   └── startup_stm32f103.s
│   │   ├── system/
│   │   │   ├── system.c
│   │   │   └── system.h
│   │   ├── linker/
│   │   │   └── stm32f103c8.ld
│   │   ├── main.c
│   │   └── README.md
│   │
|   ├── driver/
│   │   ├── rcc/
│   │   │   ├── rcc.c
│   │   │   └── rcc.h
│   │   ├── gpio/
│   │   │   ├── gpio.c
│   │   │   └── gpio.h
│   │   ├── uart/
│   │   │   ├── uart.c
│   │   │   └── uart.h
│   │   ├── spi/
│   │   ├── i2c/
│   │   ├── adc/
│   │   ├── timers/
│   │   ├── exti/
│   │   └── systick/
│   │       ├── systick.c
│   │       └── systick.h
│   │
│   ├── middleware/
│   │   ├── scheduler/
│   │   │   ├── scheduler.c
│   │   │   └── scheduler.h
│   │   ├── protocol/
│   │   │   └── parser.c/h
│   │   ├── cli/
│   │   │   └── cli.c/h
│   │   └── log/
│   │       └── log.c/h
│   │
│   ├── services/
│   │   ├── led_service/
│   │   ├── sensor_service/
│   │   └── system_monitor/
│   │
│   ├── utils/
│   │   ├── ring_buffer/
│   │   ├── delay/
│   │   ├── memory/
│   │   └── debug/
│   │
│   ├── config/
│   │   ├── board.h
│   │   ├── pinout.h
│   │   ├── clocks.h
│   │   ├── macros/        
│   │   │   ├── bit_ops.h
│   │   │   ├── utils.h
│   │   │   └── system_macros.h
│   │   └── all_driver_config.h  
│   │
│   └── README.md
│
├── bootloader/
│   ├── inc/
│   ├── src/
│   ├── linker/
│   └── README.md
│
├── tools/
│   ├── flash/
│   ├── build/     
│   ├── python_tools/
│   └── README.md
|
├── tests/
│   ├── unit/
│   ├── integration/
│   └── hw_test/
│
├── examples/   
│   ├── blink/
│   ├── uart_echo/
│   ├── scheduler_demo/
│   └── sensor_demo/
│
├── docs/        
│   ├── architecture/
│   ├── drivers/
│   ├── scheduler/
│   ├── bootloader/
│   └── protocol/
│
├── .gitignore
├── LICENSE













