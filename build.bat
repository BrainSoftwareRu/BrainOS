:: Сценарий сборки

@Echo off

i686-elf-gcc -O2 -std=gnu99 -Wall -Wextra -ffreestanding -g -c src/modules-c/tty.c -o bin/tty.o
i686-elf-gcc -O2 -std=gnu99 -Wall -Wextra -ffreestanding -g -c src/modules-c/ports.c -o bin/ports.o
i686-elf-gcc -O2 -std=gnu99 -Wall -Wextra -ffreestanding -g -c src/modules-c/CMOS.c -o bin/CMOS.o


i686-elf-gcc -O2 -std=gnu99 -Wall -Wextra -ffreestanding -g -c src/start.s -o bin/start.o
i686-elf-gcc -O2 -std=gnu99 -Wall -Wextra -ffreestanding -g -c src/kernel.c -o bin/kernel.o
i686-elf-gcc -ffreestanding -nostdlib -g -T src/linker.ld bin/start.o bin/tty.o bin/ports.o bin/CMOS.o bin/kernel.o -o bin/mykernel.elf -lgcc


pause
