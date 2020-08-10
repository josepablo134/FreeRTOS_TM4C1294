# Project Zero (FreeRTOS for TivaC TM4C1294NCPDT)

## Build on Code Composer Studio

This is the project zero structure in order to configure and
build a FreeRTOS project for Tiva C on Code Composer Studio.

In order to build this project is necessary a proper code composer studio
configuration for: compiler version, driverlib version, etc.

The project structure is the following:

```
.
├── Board
│   ├── Board.c
│   └── Board.h
├── FreeRTOS
│   ├── (...) FreeRTOS Sources
│   ├── include
│   │   └── (...) FreeRTOS include headers
│   ├── portable
│   │   └── CCS
│   │       ├── ARM_CM4F
│   │       │   ├── portasm.asm
│   │       │   ├── port.c
│   │       │   └── portmacro.h
│   │       └── MemMang
│   │           └── heap_2.c
│   ├── queue.c
│   ├── readme.txt
│   ├── stream_buffer.c
│   ├── tasks.c
│   └── timers.c
├── FreeRTOSConfig.h
├── main.c
├── README.md
└── startup_ccs.c
```

In the _FreeRTOS_ directory are located all sources and headers of the FreeRTOS project.
In the _portable_ directory are the specific ARM Cortex M4F routines for the FreeRTOS port, while the
_Mem\_Mang_ directory includes the heap routines for malloc and free functions.
The latest FreeRTOS sources and ports can be downloaded from [FreeRTOS](https://www.freertos.org/),
as well as the FreeRTOS documentation.
The _Board_ file includes the routine to initialize the system clock to 120MHz before passing control
to FreeRTOS.

In order to create a new project from this template just select a new baremetal _blinky_ example
at _Code Composer Studio_ _Resource Explorer_ to create a new configurated project with
driverlib and compiler version, then reaplace the project with this template and build.

## Notes :

This template was tested on Arch Linux with Code Composer version 9 and version 10.

Original idea from : [Akobyl](https://github.com/akobyl/TM4C129_FreeRTOS_Demo)
