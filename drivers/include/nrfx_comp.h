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

#ifndef NRFX_COMP_H__
#define NRFX_COMP_H__

#include <nrfx.h>
#include <haly/nrfy_comp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_comp COMP driver
 * @{
 * @ingroup nrf_comp
 * @brief   Comparator (COMP) peripheral driver.
 */

/**
 * @brief Macro for converting the threshold voltage to an integer value
 *        (needed by the COMP_TH register).
 *
 * @param[in] vol Voltage to be changed to COMP_TH register value. This value
 *                must not be smaller than reference voltage divided by 64.
 * @param[in] ref Reference voltage.
 */
#define NRFX_COMP_VOLTAGE_THRESHOLD_TO_INT(vol, ref) \
    (uint8_t)(((vol) > ((ref) / 64)) ? (NRFX_ROUNDED_DIV((vol) * 64,(ref)) - 1) : 0)

/**
 * @brief COMP event handler function type.
 *
 * @param[in] event COMP event.
 */
typedef void (* nrfx_comp_event_handler_t)(nrf_comp_event_t event);

/**
 * @brief COMP shortcut masks.
 *
 * @deprecated Use @ref nrf_comp_short_mask_t instead.
*/
typedef enum
{
    NRFX_COMP_SHORT_STOP_AFTER_CROSS_EVT = NRF_COMP_SHORT_STOP_CROSS_MASK, ///< Shortcut between the CROSS event and the STOP task.
    NRFX_COMP_SHORT_STOP_AFTER_UP_EVT    = NRF_COMP_SHORT_STOP_UP_MASK,    ///< Shortcut between the UP event and the STOP task.
    NRFX_COMP_SHORT_STOP_AFTER_DOWN_EVT  = NRF_COMP_SHORT_STOP_DOWN_MASK   ///< Shortcut between the DOWN event and the STOP task.
} nrfx_comp_short_mask_t;

/**
 * @brief COMP events masks.
 *
 * @deprecated Use @ref nrf_comp_int_mask_t instead.
*/
typedef enum
{
    NRFX_COMP_EVT_EN_CROSS_MASK = NRF_COMP_INT_CROSS_MASK, ///< CROSS event (generated after VIN+ == VIN-).
    NRFX_COMP_EVT_EN_UP_MASK    = NRF_COMP_INT_UP_MASK,    ///< UP event (generated when VIN+ crosses VIN- while increasing).
    NRFX_COMP_EVT_EN_DOWN_MASK  = NRF_COMP_INT_DOWN_MASK,  ///< DOWN event (generated when VIN+ crosses VIN- while decreasing).
    NRFX_COMP_EVT_EN_READY_MASK = NRF_COMP_INT_READY_MASK  ///< READY event (generated when the module is ready).
} nrfx_comp_evt_en_mask_t;

/** @brief COMP configuration. */
typedef struct
{
    nrf_comp_ref_t       reference;          ///< Reference selection.
    nrf_comp_ext_ref_t   ext_ref;            ///< External analog reference selection.
    nrf_comp_main_mode_t main_mode;          ///< Main operation mode.
    nrf_comp_th_t        threshold;          ///< Structure holding THDOWN and THUP values needed by the COMP_TH register.
    nrf_comp_sp_mode_t   speed_mode;         ///< Speed and power mode.
    nrf_comp_hyst_t      hyst;               ///< Comparator hysteresis.
#if NRF_COMP_HAS_ISOURCE
    nrf_isource_t        isource;            ///< Current source selected on analog input.
#endif
    nrf_comp_input_t     input;              ///< Input to be monitored.
    uint8_t              interrupt_priority; ///< Interrupt priority.
} nrfx_comp_config_t;

/** @brief COMP threshold default configuration. */
#define NRFX_COMP_CONFIG_TH                                  \
{                                                            \
    .th_down = NRFX_COMP_VOLTAGE_THRESHOLD_TO_INT(0.5, 1.2), \
    .th_up   = NRFX_COMP_VOLTAGE_THRESHOLD_TO_INT(1.0, 1.2)  \
}

/**
 * @brief COMP driver default configuration.
 *
 * This configuration sets up COMP with the following options:
 * - single-ended mode
 * - reference voltage: internal 1.2 V
 * - lower threshold: 0.5 V
 * - upper threshold: 1.0 V
 * - high speed mode
 * - hysteresis disabled
 * - current source disabled
 *
 * @param[in] _input Analog input.
 */
#define NRFX_COMP_DEFAULT_CONFIG(_input)                                           \
{                                                                                  \
    .reference          = NRF_COMP_REF_INT_1V2,                                    \
    .main_mode          = NRF_COMP_MAIN_MODE_SE,                                   \
    .threshold          = NRFX_COMP_CONFIG_TH,                                     \
    .speed_mode         = NRF_COMP_SP_MODE_HIGH,                                   \
    .hyst               = NRF_COMP_HYST_NO_HYST,                                   \
    NRFX_COND_CODE_1(NRF_COMP_HAS_ISOURCE, (.isource = NRF_COMP_ISOURCE_OFF,), ()) \
    .input              = (nrf_comp_input_t)_input,                                \
    .interrupt_priority = NRFX_COMP_DEFAULT_CONFIG_IRQ_PRIORITY                    \
}

/**
 * @brief Function for initializing the COMP driver.
 *
 * This function initializes the COMP driver, but does not enable the peripheral or any interrupts.
 * To start the driver, call the function @ref nrfx_comp_start() after initialization.
 *
 * @param[in] p_config      Pointer to the structure with the initial configuration.
 * @param[in] event_handler Event handler provided by the user.
 *                          Must not be NULL.
 *
 * @retval NRFX_SUCCESS             Initialization was successful.
 * @retval NRFX_ERROR_ALREADY       The driver is already initialized.
 * @retval NRFX_ERROR_INVALID_STATE The driver is already initialized.
 *                                  Deprecated - use @ref NRFX_ERROR_ALREADY instead.
 * @retval NRFX_ERROR_BUSY          The LPCOMP peripheral is already in use.
 *                                  This is possible only if @ref nrfx_prs module
 *                                  is enabled.
 */
nrfx_err_t nrfx_comp_init(nrfx_comp_config_t const * p_config,
                          nrfx_comp_event_handler_t  event_handler);

/**
 * @brief Function for reconfiguring the COMP driver.
 *
 * @param[in] p_config Pointer to the structure with the configuration.
 *
 * @retval NRFX_SUCCESS             Reconfiguration was successful.
 * @retval NRFX_ERROR_BUSY          The driver is running and cannot be reconfigured.
 * @retval NRFX_ERROR_INVALID_STATE The driver is uninitialized.
 */
nrfx_err_t nrfx_comp_reconfigure(nrfx_comp_config_t const * p_config);

/**
 * @brief Function for uninitializing the COMP driver.
 *
 * This function uninitializes the COMP driver. The COMP peripheral and
 * its interrupts are disabled, and local variables are cleaned. After this call, you must
 * initialize the driver again by calling nrfx_comp_init() if you want to use it.
 *
 * @sa nrfx_comp_stop
 */
void nrfx_comp_uninit(void);

/**
 * @brief Function for checking if the COMP driver is initialized.
 *
 * @retval true  Driver is already initialized.
 * @retval false Driver is not initialized.
 */
bool nrfx_comp_init_check(void);

/**
 * @brief Function for setting the analog input.
 *
 * @param[in] psel COMP analog pin selection.
 */
void nrfx_comp_pin_select(nrf_comp_input_t psel);

/**
 * @brief Function for starting the COMP peripheral and interrupts.
 *
 * Before calling this function, the driver must be initialized. This function
 * enables the COMP peripheral and its interrupts.
 *
 * @param[in] comp_evt_en_mask Mask of events to be enabled. This parameter is to be built as
 *                             an OR of elements from @ref nrf_comp_int_mask_t.
 * @param[in] comp_shorts_mask Mask of shortcuts to be enabled. This parameter is to be built as
 *                             an OR of elements from @ref nrf_comp_short_mask_t.
 *
 * @sa nrfx_comp_init
 */
void nrfx_comp_start(uint32_t comp_evt_en_mask, uint32_t comp_shorts_mask);

/**
 * @brief Function for stopping the COMP peripheral.
 *
 * Before calling this function, the driver must be enabled. This function disables the COMP
 * peripheral and its interrupts.
 *
 * @sa nrfx_comp_uninit
 */
void nrfx_comp_stop(void);

/**
 * @brief Function for copying the current state of the comparator result to the RESULT register.
 *
 * @retval 0 The input voltage is below the threshold (VIN+ < VIN-).
 * @retval 1 The input voltage is above the threshold (VIN+ > VIN-).
 */
uint32_t nrfx_comp_sample(void);

/**
 * @brief Function for getting the address of a COMP task.
 *
 * @param[in] task COMP task.
 *
 * @return Address of the given COMP task.
 */
NRFX_STATIC_INLINE uint32_t nrfx_comp_task_address_get(nrf_comp_task_t task);

/**
 * @brief Function for getting the address of a COMP event.
 *
 * @param[in] event COMP event.
 *
 * @return Address of the given COMP event.
 */
NRFX_STATIC_INLINE uint32_t nrfx_comp_event_address_get(nrf_comp_event_t event);

#ifndef NRFX_DECLARE_ONLY
NRFX_STATIC_INLINE uint32_t nrfx_comp_task_address_get(nrf_comp_task_t task)
{
    return nrfy_comp_task_address_get(NRF_COMP, task);
}

NRFX_STATIC_INLINE uint32_t nrfx_comp_event_address_get(nrf_comp_event_t event)
{
    return nrfy_comp_event_address_get(NRF_COMP, event);
}
#endif // NRFX_DECLARE_ONLY

/** @} */


void nrfx_comp_irq_handler(void);


#ifdef __cplusplus
}
#endif

#endif // NRFX_COMP_H__
