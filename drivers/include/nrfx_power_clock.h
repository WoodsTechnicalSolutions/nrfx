/*
 * Copyright (c) 2015 - 2025, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_POWER_CLOCK_H__
#define NRFX_POWER_CLOCK_H__

#include <nrfx.h>

#ifdef __cplusplus
extern "C" {
#endif


__STATIC_INLINE void nrfx_power_clock_irq_init(void)
{
    uint8_t priority;
#if NRFX_CHECK(NRFX_POWER_ENABLED) && NRFX_CHECK(NRFX_CLOCK_ENABLED)
    #if NRFX_POWER_DEFAULT_CONFIG_IRQ_PRIORITY != NRFX_CLOCK_DEFAULT_CONFIG_IRQ_PRIORITY
    #error "IRQ priorities for POWER and CLOCK must be the same. Check <nrfx_config.h>."
    #endif
    priority = NRFX_POWER_DEFAULT_CONFIG_IRQ_PRIORITY;
#elif NRFX_CHECK(NRFX_POWER_ENABLED)
    priority = NRFX_POWER_DEFAULT_CONFIG_IRQ_PRIORITY;
#elif NRFX_CHECK(NRFX_CLOCK_ENABLED)
    priority = NRFX_CLOCK_DEFAULT_CONFIG_IRQ_PRIORITY;
#else
    #error "This code is not supposed to be compiled when neither POWER nor CLOCK is enabled."
#endif

#if defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    IRQn_Type irqn = CLOCK_POWER_IRQn;
#else
    IRQn_Type irqn = nrfx_get_irq_number(NRF_CLOCK);
#endif
    if (!NRFX_IRQ_IS_ENABLED(irqn))
    {
        NRFX_IRQ_PRIORITY_SET(irqn, priority);
        NRFX_IRQ_ENABLE(irqn);
    }
#if NRFX_CHECK(NRFX_CLOCK_CONFIG_USE_LFRC_CALIBRATION) && \
    NRFX_CHECK(NRFX_CLOCK_CONFIG_LF_CAL_ENABLED)
    if (!NRFX_IRQ_IS_ENABLED(LFRC_IRQn))
    {
        NRFX_IRQ_PRIORITY_SET(LFRC_IRQn, priority);
        NRFX_IRQ_ENABLE(LFRC_IRQn);
    }
#endif
}

#if NRFX_CHECK(NRFX_POWER_ENABLED) && NRFX_CHECK(NRFX_CLOCK_ENABLED)
void nrfx_power_clock_irq_handler(void);
#elif NRFX_CHECK(NRFX_POWER_ENABLED)
#define nrfx_power_irq_handler  nrfx_power_clock_irq_handler
#elif NRFX_CHECK(NRFX_CLOCK_ENABLED)
#define nrfx_clock_irq_handler  nrfx_power_clock_irq_handler
#endif


#ifdef __cplusplus
}
#endif

#endif // NRFX_POWER_CLOCK_H__
