
#ifndef __AML_PMU_COMMOM_H__
#define __AML_PMU_COMMOM_H__

#include <amlogic/battery_parameter.h>

struct aml_pmu_driver {
    int  (*pmu_init)(void);                                                     // initialize PMU board
    int  (*pmu_get_battery_capacity)(void);                                     // return battery percent
    int  (*pmu_get_extern_power_status)(void);                                  // return extern power is online
    int  (*pmu_set_gpio)(int gpio, int value);                                  // export for other driver 
    int  (*pmu_get_gpio)(int gpio, int *value);                                 // export for other driver
    int  (*pmu_reg_read)  (int addr, unsigned char *buf);                       // single register read
    int  (*pmu_reg_write) (int addr, unsigned char value);                      // single register write
    int  (*pmu_reg_reads) (int addr, unsigned char *buf, int count);            // large amount registers reads
    int  (*pmu_reg_writes)(int addr, unsigned char *buf, int count);            // large amount registers writes
    int  (*pmu_set_bits)  (int addr, unsigned char bits, unsigned char mask);   // set bits in mask
    int  (*pmu_set_usb_current_limit)(int curr);                                // set usb current limit
    int  (*pmu_set_charge_current)(int curr);                                   // set charge current
    int  (*pmu_init_para)(struct battery_parameter *battery);                   // init pmu by battery parameter
    void (*pmu_power_off)(void);                                                // power off system
    void (*pmu_do_battery_calibrate)(void);                                     // calibrate battery curve
};

extern struct aml_pmu_driver* aml_pmu_get_driver(void);

#endif  /* __AML_PMU_COMMOM_H__ */