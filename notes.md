Hardware layout
---------------
`[attiny85]---SPI---[dragon]---USB---[linux host]`

Software layout (debug)
---------------
`[dragon]---[avarice]---TCP---[avr-gdb]`

Software layout (program)
---------------
`[dragon]---[avrdude]`

Command Line
------------
* read fuses
    `avrdude -P usb -c dragon_isp -p attiny85 -U hfuse:r:-:h`
* set fuses for debugWIRE (set WEN)
    `avrdude -P usb -c dragon_isp -p attiny85 -U hfuse:w:0x9f:m`
* set fuses for SPI programming (unset WEN)
    `avrdude -P usb -c dragon_isp -p attiny85 -U hfuse:w:0xdf:m`
* launch avarice on port 4242
    `avarice -P attiny85 -j usb -g -w :4242`
* connect with gdb
```
    avr-gdb program.elf
    (gdb) target extended-remote :4242
    (gdb) load
    (gdb) monitor reset
    etc
```

VS Code debugger setup
----------------------
* setup in file `.vscode/launch.json`