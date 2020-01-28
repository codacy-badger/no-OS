/***************************************************************************//**
 *   @file   aducm3029/irq_extra.h
 *   @brief  Header file of IRQ driver for ADuCM302x
 *   @author Mihail Chindris (mihail.chindris@analog.com)
********************************************************************************
 * Copyright 2019(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef IRQ_EXTRA_H
# define IRQ_EXTRA_H

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include "gpio.h"
#include <drivers/xint/adi_xint.h>

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/

/** Number of available external interrupts */
#define NB_EXT_INTERRUPTS	4u

/** Map the interrupt ID to the GPIO associated number */
static const uint32_t id_map_gpio[NB_EXT_INTERRUPTS] = {
	15u, // ID 0 -> GPIO15
	16u, // ID 1 -> GPIO16
	13u, // ID 2 -> GPIO13
	33u  // ID 3 -> GPIO33
};

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

/**
 * @enum irq_mode
 * @brief Trigger condition for the external interrupt
 */
enum irq_mode {
	/** Rising edge */
	IRQ_RISING_EDGE		= ADI_XINT_IRQ_RISING_EDGE,
	/** Falling edge */
	IRQ_FALLING_EDGE	= ADI_XINT_IRQ_FALLING_EDGE,
	/** Either edge */
	IRQ_EITHER_EDGE		= ADI_XINT_IRQ_EITHER_EDGE,
	/** High level */
	IRQ_HIGH_LEVEL		= ADI_XINT_IRQ_HIGH_LEVEL,
	/** Low level */
	IRQ_LOW_LEVEL		= ADI_XINT_IRQ_LOW_LEVEL
};

/**
 * @struct aducm_irq_init_param
 * @brief Specific platform parameters to configure the IRQ
 */
struct aducm_irq_init_param {
	/** Trigger condition for the external interrupt */
	enum irq_mode mode;
};

/**
 * @struct aducm_irq_desc
 * @brief Stores specific platform parameters
 */
struct aducm_irq_desc {
	/** GPIO descriptor associated to the interrupt */
	struct gpio_desc	*gpio_desc;
	/** Trigger condition for the external interrupt */
	enum irq_mode		mode;
	/** Callback that will be called when the interrupt occurs*/
	void (*irq_handler)(void *param);
	/** Parameter passed to the \ref irq_handler when called */
	void *			param;

};

#endif // IRQ_EXTRA_H_
