#include "h/tty.h"
#include "h/CMOS.h"

void kernel_main(){
    t_init();
    t_print("#####   #####   ####   ###### ##   ##    ####    ##### \n");
    t_print("##  ##  ##  ##  ##  ##   ##   ###  ##  ##    ##  ##\n");
    t_print("#####   #####   ######   ##   ## # ##  ##    ##  ##\n");
    t_print("##  ##  ##  ##  ##  ##   ##   ##  ###  ##    ##  ##\n");
    t_print("#####   ##  ##  ##  ## ###### ##   ##    ####    #####\n");

    t_print("Company: Brain Software\nVersion: 1.0.1 (build 98)\nRelease: 30.09.2021\n");
    get_time();
    t_print("\nSelected Command: help, calc");
    
    while(1){

    }
}