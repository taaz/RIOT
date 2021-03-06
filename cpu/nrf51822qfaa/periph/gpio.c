/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License.
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     driver_periph
 * @{
 *
 * @file        gpio.c
 * @brief       Low-level GPIO driver implementation
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 *
 * @}
 */

#include "cpu.h"
#include "periph/gpio.h"
#include "periph_conf.h"

typedef struct {
    void (*cb)(void);
} gpio_state_t;

static gpio_state_t config[GPIO_NUMOF];

int gpio_init_out(gpio_t dev, gpio_pp_t pullup)
{
    return -1;
}

int gpio_init_in(gpio_t dev, gpio_pp_t pullup)
{
    return -1;
}

int gpio_init_int(gpio_t dev, gpio_pp_t pullup, gpio_flank_t flank, void (*cb)(void))
{
    return -1;
}

int gpio_read(gpio_t dev)
{
    return -1;
}

int gpio_set(gpio_t dev)
{
    return -1;
}

int gpio_clear(gpio_t dev)
{
    return -1;
}


int gpio_toggle(gpio_t dev)
{
    if (gpio_read(dev)) {
        return gpio_clear(dev);
    } else {
        return gpio_set(dev);
    }
}

int gpio_write(gpio_t dev, int value)
{
    if (value) {
        return gpio_set(dev);
    } else {
        return gpio_clear(dev);
    }
}
