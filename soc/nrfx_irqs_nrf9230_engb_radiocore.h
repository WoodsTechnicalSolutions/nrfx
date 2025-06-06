/*
 * Copyright (c) 2024 - 2025, Nordic Semiconductor ASA
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

#ifndef NRFX_IRQS_NRF9230_ENGB_RADIOCORE_H__
#define NRFX_IRQS_NRF9230_ENGB_RADIOCORE_H__

#ifdef __cplusplus
extern "C" {
#endif

// SPU000_IRQHandler

// MPC_IRQHandler

// MVDMA_IRQHandler
#define nrfx_mvdma_irq_handler          MVDMA_IRQHandler

// SPU010_IRQHandler

// WDT010_IRQHandler
#define nrfx_wdt_010_irq_handler        WDT0_IRQHandler

// WDT011_IRQHandler
#define nrfx_wdt_011_irq_handler        WDT1_IRQHandler

// SPU020_IRQHandler

// EGU020_IRQHandler
#define nrfx_egu_020_irq_handler        EGU020_IRQHandler

// AAR020_CCM020_IRQHandler

// ECB020_IRQHandler

// TIMER020_IRQHandler
#define nrfx_timer_020_irq_handler      TIMER020_IRQHandler

// TIMER021_IRQHandler
#define nrfx_timer_021_irq_handler      TIMER021_IRQHandler

// TIMER022_IRQHandler
#define nrfx_timer_022_irq_handler      TIMER022_IRQHandler

// RTC_IRQHandler
#define nrfx_rtc_0_irq_handler          RTC_IRQHandler

// RADIO_0_IRQHandler
// RADIO_1_IRQHandler

// SPU030_IRQHandler

// VPR_IRQHandler

// AAR030_CCM030_IRQHandler

// ECB030_IRQHandler

// IPCT_0_IRQHandler

// IPCT_1_IRQHandler

// BELLBOARD_0_IRQHandler
#define nrfx_bellboard_0_irq_handler    BELLBOARD_0_IRQHandler

// BELLBOARD_1_IRQHandler
#define nrfx_bellboard_1_irq_handler    BELLBOARD_1_IRQHandler

// BELLBOARD_2_IRQHandler
#define nrfx_bellboard_2_irq_handler    BELLBOARD_2_IRQHandler

// BELLBOARD_3_IRQHandler
#define nrfx_bellboard_3_irq_handler    BELLBOARD_3_IRQHandler

// GPIOTE130_0_IRQHandler
// GPIOTE130_1_IRQHandler
#define nrfx_gpiote_130_irq_handler     GPIOTE130_IRQHandler

// GRTC_0_IRQHandler
// GRTC_1_IRQHandler
#define nrfx_grtc_irq_handler           GRTC_IRQHandler

// TBM_IRQHandler
#define nrfx_tbm_irq_handler            TBM_IRQHandler

// EXMIF_IRQHandler

// IPCT120_0_IRQHandler

// I3C120_IRQHandler

// VPR121_IRQHandler

// CAN_IRQHandler

// I3C121_IRQHandler

// TIMER120_IRQHandler
#define nrfx_timer_120_irq_handler      TIMER120_IRQHandler

// TIMER121_IRQHandler
#define nrfx_timer_121_irq_handler      TIMER121_IRQHandler

// PWM120_IRQHandler
#define nrfx_pwm_120_irq_handler        PWM120_IRQHandler

// SPIS120_UARTE120_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_8_ENABLED)
#define nrfx_prs_box_8_irq_handler      SPIS120_UARTE120_IRQHandler
#else
#define nrfx_spis_120_irq_handler       SPIS120_UARTE120_IRQHandler
#define nrfx_uarte_120_irq_handler      SPIS120_UARTE120_IRQHandler
#endif

// SPIM120_IRQHandler
#define nrfx_spim_120_irq_handler       SPIM120_IRQHandler

// SPIM121_IRQHandler
#define nrfx_spim_121_irq_handler       SPIM121_IRQHandler

// VPR130_IRQHandler
// IPCT130_0_IRQHandler
// RTC130_IRQHandler
#define nrfx_rtc_130_irq_handler        RTC130_IRQHandler

// RTC131_IRQHandler
#define nrfx_rtc_131_irq_handler        RTC131_IRQHandler

// WDT131_IRQHandler
#define nrfx_wdt_131_irq_handler        WDT131_IRQHandler

// WDT132_IRQHandler
#define nrfx_wdt_132_irq_handler        WDT132_IRQHandler

// SAADC_IRQHandler
#define nrfx_saadc_irq_handler          SAADC_IRQHandler

// COMP_LPCOMP_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_9_ENABLED)
#define nrfx_prs_box_9_irq_handler      COMP_LPCOMP_IRQHandler
#else
#define nrfx_comp_irq_handler           COMP_LPCOMP_IRQHandler
#define nrfx_lpcomp_irq_handler         COMP_LPCOMP_IRQHandler
#endif

// TEMP_IRQHandler
#define nrfx_temp_irq_handler           TEMP_IRQHandler

// NFCT_IRQHandler
#define nrfx_nfct_irq_handler           NFCT_IRQHandler

// I2S130_IRQHandler
#define nrfx_i2s_130_irq_handler        I2S130_IRQHandler

// PDM_IRQHandler
#define nrfx_pdm_0_irq_handler          PDM_IRQHandler

// QDEC130_IRQHandler
#define nrfx_qdec_130_irq_handler       QDEC130_IRQHandler

// QDEC131_IRQHandler
#define nrfx_qdec_131_irq_handler       QDEC131_IRQHandler

// I2S131_IRQHandler
#define nrfx_i2s_131_irq_handler        I2S131_IRQHandler

// TIMER130_IRQHandler
#define nrfx_timer_130_irq_handler      TIMER130_IRQHandler

// TIMER131_IRQHandler
#define nrfx_timer_131_irq_handler      TIMER131_IRQHandler

// PWM130_IRQHandler
#define nrfx_pwm_130_irq_handler        PWM130_IRQHandler

// SERIAL0_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_0_ENABLED)
#define nrfx_prs_box_0_irq_handler      SERIAL0_IRQHandler
#else
#define nrfx_spim_130_irq_handler       SERIAL0_IRQHandler
#define nrfx_spis_130_irq_handler       SERIAL0_IRQHandler
#define nrfx_twim_130_irq_handler       SERIAL0_IRQHandler
#define nrfx_twis_130_irq_handler       SERIAL0_IRQHandler
#define nrfx_uarte_130_irq_handler      SERIAL0_IRQHandler
#endif

// SERIAL1_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_1_ENABLED)
#define nrfx_prs_box_1_irq_handler      SERIAL1_IRQHandler
#else
#define nrfx_spim_131_irq_handler       SERIAL1_IRQHandler
#define nrfx_spis_131_irq_handler       SERIAL1_IRQHandler
#define nrfx_twim_131_irq_handler       SERIAL1_IRQHandler
#define nrfx_twis_131_irq_handler       SERIAL1_IRQHandler
#define nrfx_uarte_131_irq_handler      SERIAL1_IRQHandler
#endif

// TIMER132_IRQHandler
#define nrfx_timer_132_irq_handler      TIMER132_IRQHandler

// TIMER133_IRQHandler
#define nrfx_timer_133_irq_handler      TIMER133_IRQHandler

// PWM131_IRQHandler
#define nrfx_pwm_131_irq_handler        PWM131_IRQHandler

// SERIAL2_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_2_ENABLED)
#define nrfx_prs_box_2_irq_handler      SERIAL2_IRQHandler
#else
#define nrfx_spim_132_irq_handler       SERIAL2_IRQHandler
#define nrfx_spis_132_irq_handler       SERIAL2_IRQHandler
#define nrfx_twim_132_irq_handler       SERIAL2_IRQHandler
#define nrfx_twis_132_irq_handler       SERIAL2_IRQHandler
#define nrfx_uarte_132_irq_handler      SERIAL2_IRQHandler
#endif

// SERIAL3_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_3_ENABLED)
#define nrfx_prs_box_3_irq_handler      SERIAL3_IRQHandler
#else
#define nrfx_spim_133_irq_handler       SERIAL3_IRQHandler
#define nrfx_spis_133_irq_handler       SERIAL3_IRQHandler
#define nrfx_twim_133_irq_handler       SERIAL3_IRQHandler
#define nrfx_twis_133_irq_handler       SERIAL3_IRQHandler
#define nrfx_uarte_133_irq_handler      SERIAL3_IRQHandler
#endif

// TIMER134_IRQHandler
#define nrfx_timer_134_irq_handler      TIMER134_IRQHandler

// TIMER135_IRQHandler
#define nrfx_timer_135_irq_handler      TIMER135_IRQHandler

// PWM132_IRQHandler
#define nrfx_pwm_132_irq_handler        PWM132_IRQHandler

// SERIAL4_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_4_ENABLED)
#define nrfx_prs_box_4_irq_handler      SERIAL4_IRQHandler
#else
#define nrfx_spim_134_irq_handler       SERIAL4_IRQHandler
#define nrfx_spis_134_irq_handler       SERIAL4_IRQHandler
#define nrfx_twim_134_irq_handler       SERIAL4_IRQHandler
#define nrfx_twis_134_irq_handler       SERIAL4_IRQHandler
#define nrfx_uarte_134_irq_handler      SERIAL4_IRQHandler
#endif

// SERIAL5_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_5_ENABLED)
#define nrfx_prs_box_5_irq_handler      SERIAL5_IRQHandler
#else
#define nrfx_spim_135_irq_handler       SERIAL5_IRQHandler
#define nrfx_spis_135_irq_handler       SERIAL5_IRQHandler
#define nrfx_twim_135_irq_handler       SERIAL5_IRQHandler
#define nrfx_twis_135_irq_handler       SERIAL5_IRQHandler
#define nrfx_uarte_135_irq_handler      SERIAL5_IRQHandler
#endif

// TIMER136_IRQHandler
#define nrfx_timer_136_irq_handler      TIMER136_IRQHandler

// TIMER137_IRQHandler
#define nrfx_timer_137_irq_handler      TIMER137_IRQHandler

// PWM133_IRQHandler
#define nrfx_pwm_133_irq_handler        PWM133_IRQHandler

// SERIAL6_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_6_ENABLED)
#define nrfx_prs_box_6_irq_handler      SERIAL6_IRQHandler
#else
#define nrfx_spim_136_irq_handler       SERIAL6_IRQHandler
#define nrfx_spis_136_irq_handler       SERIAL6_IRQHandler
#define nrfx_twim_136_irq_handler       SERIAL6_IRQHandler
#define nrfx_twis_136_irq_handler       SERIAL6_IRQHandler
#define nrfx_uarte_136_irq_handler      SERIAL6_IRQHandler
#endif

// SERIAL7_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_7_ENABLED)
#define nrfx_prs_box_7_irq_handler      SERIAL7_IRQHandler
#else
#define nrfx_spim_137_irq_handler       SERIAL7_IRQHandler
#define nrfx_spis_137_irq_handler       SERIAL7_IRQHandler
#define nrfx_twim_137_irq_handler       SERIAL7_IRQHandler
#define nrfx_twis_137_irq_handler       SERIAL7_IRQHandler
#define nrfx_uarte_137_irq_handler      SERIAL7_IRQHandler
#endif

#ifdef __cplusplus
}
#endif

#endif // NRFX_IRQS_NRF9230_ENGB_RADIOCORE_H__
