/*
 * Copyright (c) 2019 - 2025, Nordic Semiconductor ASA
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

#ifndef NRFX_IRQS_NRF5340_NETWORK_H__
#define NRFX_IRQS_NRF5340_NETWORK_H__

#ifdef __cplusplus
extern "C" {
#endif

// CLOCK_POWER_IRQn
#define nrfx_power_clock_irq_handler    CLOCK_POWER_IRQHandler

// RADIO_IRQn

// RNG_IRQn
#define nrfx_rng_irq_handler        RNG_IRQHandler

// GPIOTE_IRQn
#define nrfx_gpiote_0_irq_handler   GPIOTE_IRQHandler

// WDT_IRQn
#define nrfx_wdt_0_irq_handler      WDT_IRQHandler

// TIMER0_IRQn
#define nrfx_timer_0_irq_handler    TIMER0_IRQHandler

// ECB_IRQn

// AAR_CCM_IRQn

// TEMP_IRQn
#define nrfx_temp_irq_handler       TEMP_IRQHandler

// RTC0_IRQn
#define nrfx_rtc_0_irq_handler      RTC0_IRQHandler

// IPC_IRQn
#define nrfx_ipc_irq_handler        IPC_IRQHandler

// SERIAL0_IRQn
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_0_ENABLED)
#define nrfx_prs_box_0_irq_handler  SERIAL0_IRQHandler
#else
#define nrfx_spim_0_irq_handler     SERIAL0_IRQHandler
#define nrfx_spis_0_irq_handler     SERIAL0_IRQHandler
#define nrfx_twim_0_irq_handler     SERIAL0_IRQHandler
#define nrfx_twis_0_irq_handler     SERIAL0_IRQHandler
#define nrfx_uarte_0_irq_handler    SERIAL0_IRQHandler
#endif

// EGU0_IRQn
#define nrfx_egu_0_irq_handler      EGU0_IRQHandler

// RTC1_IRQn
#define nrfx_rtc_1_irq_handler      RTC1_IRQHandler

// TIMER1_IRQn
#define nrfx_timer_1_irq_handler    TIMER1_IRQHandler

// TIMER2_IRQn
#define nrfx_timer_2_irq_handler    TIMER2_IRQHandler

// SWI0_IRQn

// SWI1_IRQn

// SWI2_IRQn

// SWI3_IRQn

#ifdef __cplusplus
}
#endif

#endif // NRFX_IRQS_NRF5340_NETWORK_H__
