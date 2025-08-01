/*
 * Copyright (c) 2014 - 2025, Nordic Semiconductor ASA
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
#ifndef NRF_QDEC_H__
#define NRF_QDEC_H__

#include <nrfx.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(NRF_QDEC0) && defined(NRF_QDEC)
#define NRF_QDEC0 NRF_QDEC
#endif

/**
 * @defgroup nrf_qdec_hal QDEC HAL
 * @{
 * @ingroup nrf_qdec
 * @brief   Hardware access layer for managing the Quadrature Decoder (QDEC) peripheral.
 */

/**
 * @brief This value can be provided as a parameter for the @ref nrf_qdec_pins_set
 *        function call to specify that a LED signal shall not be use by the QDEC and
 *        connected to a physical pin.
 */
#define NRF_QDEC_PIN_NOT_CONNECTED 0xFFFFFFFF

#if defined(QDEC_TASKS_RDCLRACC_TASKS_RDCLRACC_Msk) || defined(__NRFX_DOXYGEN__)
/** @brief Presence of the RDCLRACC task. */
#define NRF_QDEC_HAS_TASK_RDCLRACC 1
#else
#define NRF_QDEC_HAS_TASK_RDCLRACC 0
#endif

#if defined(QDEC_TASKS_RDCLRDBL_TASKS_RDCLRDBL_Msk) || defined(__NRFX_DOXYGEN__)
/** @brief Presence of the RDCLRDBL task. */
#define NRF_QDEC_HAS_TASK_RDCLRDBL 1
#else
#define NRF_QDEC_HAS_TASK_RDCLRDBL 0
#endif

#if defined(QDEC_EVENTS_DBLRDY_EVENTS_DBLRDY_Msk) || defined(__NRFX_DOXYGEN__)
/** @brief Presence of the DBLRDY event. */
#define NRF_QDEC_HAS_EVENT_DBLRDY 1
#else
#define NRF_QDEC_HAS_EVENT_DBLRDY 0
#endif

#if defined(QDEC_EVENTS_STOPPED_EVENTS_STOPPED_Msk) || defined(__NRFX_DOXYGEN__)
/** @brief Presence of the STOPPED event. */
#define NRF_QDEC_HAS_EVENT_STOPPED 1
#else
#define NRF_QDEC_HAS_EVENT_STOPPED 0
#endif

/** @brief Reset value of LEDPRE register. */
#define NRF_QDEC_LEDPRE_DEFAULT 0x10

/** @brief QDEC tasks. */
typedef enum
{
    NRF_QDEC_TASK_START      = offsetof(NRF_QDEC_Type, TASKS_START),      /**< Starting the quadrature decoder. */
    NRF_QDEC_TASK_STOP       = offsetof(NRF_QDEC_Type, TASKS_STOP),       /**< Stopping the quadrature decoder. */
    NRF_QDEC_TASK_READCLRACC = offsetof(NRF_QDEC_Type, TASKS_READCLRACC), /**< Reading and clearing ACC and ACCDBL registers. */
#if NRF_QDEC_HAS_TASK_RDCLRACC
    NRF_QDEC_TASK_RDCLRACC   = offsetof(NRF_QDEC_Type, TASKS_RDCLRACC),   /**< Reading and clearing ACC register. */
#endif
#if NRF_QDEC_HAS_TASK_RDCLRDBL
    NRF_QDEC_TASK_RDCLRDBL   = offsetof(NRF_QDEC_Type, TASKS_RDCLRDBL)    /**< Reading and clearing ACCDBL register. */
#endif
} nrf_qdec_task_t;

/** @brief QDEC events. */
typedef enum
{
    NRF_QDEC_EVENT_SAMPLERDY = offsetof(NRF_QDEC_Type, EVENTS_SAMPLERDY), /**< Event generated for every new sample.  */
    NRF_QDEC_EVENT_REPORTRDY = offsetof(NRF_QDEC_Type, EVENTS_REPORTRDY), /**< Event generated for every new report.  */
    NRF_QDEC_EVENT_ACCOF     = offsetof(NRF_QDEC_Type, EVENTS_ACCOF),     /**< Event generated for every accumulator overflow. */
#if NRF_QDEC_HAS_EVENT_DBLRDY
    NRF_QDEC_EVENT_DBLRDY    = offsetof(NRF_QDEC_Type, EVENTS_DBLRDY),    /**< Event generated for every double displacement(s) detected. */
#endif
#if NRF_QDEC_HAS_EVENT_STOPPED
    NRF_QDEC_EVENT_STOPPED   = offsetof(NRF_QDEC_Type, EVENTS_STOPPED)    /**< Event generated for every QDEC stop. */
#endif
} nrf_qdec_event_t;

/** @brief QDEC shortcuts. */
typedef enum
{
    NRF_QDEC_SHORT_REPORTRDY_READCLRACC_MASK = QDEC_SHORTS_REPORTRDY_READCLRACC_Msk, /**< Shortcut between REPORTRDY event and READCLRACC task.  */
    NRF_QDEC_SHORT_SAMPLERDY_STOP_MASK       = QDEC_SHORTS_SAMPLERDY_STOP_Msk        /**< Shortcut between SAMPLERDY event and STOP task.  */
} nrf_qdec_short_mask_t;

/** @brief QDEC interrupts. */
typedef enum
{
    NRF_QDEC_INT_SAMPLERDY_MASK = QDEC_INTENSET_SAMPLERDY_Msk, /**< Mask for enabling or disabling an interrupt on SAMPLERDY event.  */
    NRF_QDEC_INT_REPORTRDY_MASK = QDEC_INTENSET_REPORTRDY_Msk, /**< Mask for enabling or disabling an interrupt on REPORTRDY event.  */
    NRF_QDEC_INT_ACCOF_MASK     = QDEC_INTENSET_ACCOF_Msk      /**< Mask for enabling or disabling an interrupt on ACCOF event.  */
} nrf_qdec_int_mask_t;

/** @brief States of the enable bit. */
typedef enum
{
    NRF_QDEC_DISABLE = QDEC_ENABLE_ENABLE_Disabled, /**< Mask for disabling the QDEC periperal. When disabled, the QDEC decoder pins are not active.  */
    NRF_QDEC_ENABLE  = QDEC_ENABLE_ENABLE_Enabled   /**< Mask for enabling the QDEC periperal. When enabled, the QDEC pins are active. */
} nrf_qdec_enable_t;

/** @brief States of the debounce filter enable bit. */
typedef enum
{
    NRF_QDEC_DBFEN_DISABLE = QDEC_DBFEN_DBFEN_Disabled, /**< Mask for disabling the debounce filter.  */
    NRF_QDEC_DBFEN_ENABLE  = QDEC_DBFEN_DBFEN_Enabled   /**< Mask for enabling the debounce filter.  */
} nrf_qdec_dbfen_t;

/** @brief Active LED polarity. */
typedef enum
{
    NRF_QDEC_LEPOL_ACTIVE_LOW  = QDEC_LEDPOL_LEDPOL_ActiveLow, /**< QDEC LED active on output pin low.  */
    NRF_QDEC_LEPOL_ACTIVE_HIGH = QDEC_LEDPOL_LEDPOL_ActiveHigh /**< QDEC LED active on output pin high.  */
} nrf_qdec_ledpol_t;

/** @brief Available sampling periods. */
typedef enum
{
    NRF_QDEC_SAMPLEPER_128US   = QDEC_SAMPLEPER_SAMPLEPER_128us,   /**< QDEC sampling period 128 microseconds.  */
    NRF_QDEC_SAMPLEPER_256US   = QDEC_SAMPLEPER_SAMPLEPER_256us,   /**< QDEC sampling period 256 microseconds.  */
    NRF_QDEC_SAMPLEPER_512US   = QDEC_SAMPLEPER_SAMPLEPER_512us,   /**< QDEC sampling period 512 microseconds.  */
    NRF_QDEC_SAMPLEPER_1024US  = QDEC_SAMPLEPER_SAMPLEPER_1024us,  /**< QDEC sampling period 1024 microseconds.  */
    NRF_QDEC_SAMPLEPER_2048US  = QDEC_SAMPLEPER_SAMPLEPER_2048us,  /**< QDEC sampling period 2048 microseconds.  */
    NRF_QDEC_SAMPLEPER_4096US  = QDEC_SAMPLEPER_SAMPLEPER_4096us,  /**< QDEC sampling period 4096 microseconds.  */
    NRF_QDEC_SAMPLEPER_8192US  = QDEC_SAMPLEPER_SAMPLEPER_8192us,  /**< QDEC sampling period 8192 microseconds.  */
    NRF_QDEC_SAMPLEPER_16384US = QDEC_SAMPLEPER_SAMPLEPER_16384us, /**< QDEC sampling period 16384 microseconds.  */
#if defined(QDEC_SAMPLEPER_SAMPLEPER_32ms) || defined(__NRFX_DOXYGEN__)
    NRF_QDEC_SAMPLEPER_32MS    = QDEC_SAMPLEPER_SAMPLEPER_32ms,    /**< QDEC sampling period 32768 microseconds. */
    NRF_QDEC_SAMPLEPER_65MS    = QDEC_SAMPLEPER_SAMPLEPER_65ms,    /**< QDEC sampling period 65536 microseconds. */
    NRF_QDEC_SAMPLEPER_131MS   = QDEC_SAMPLEPER_SAMPLEPER_131ms,   /**< QDEC sampling period 131072 microseconds. */
#endif
} nrf_qdec_sampleper_t;

/** @brief Available report periods. */
typedef enum
{
#if defined(QDEC_REPORTPER_REPORTPER_1Smpl) || defined(__NRFX_DOXYGEN__)
    NRF_QDEC_REPORTPER_1        = QDEC_REPORTPER_REPORTPER_1Smpl,                                    /**< QDEC report period 1 sample. */
#endif
    NRF_QDEC_REPORTPER_10       = QDEC_REPORTPER_REPORTPER_10Smpl,                                   /**< QDEC report period 10 samples. */
    NRF_QDEC_REPORTPER_40       = QDEC_REPORTPER_REPORTPER_40Smpl,                                   /**< QDEC report period 40 samples. */
    NRF_QDEC_REPORTPER_80       = QDEC_REPORTPER_REPORTPER_80Smpl,                                   /**< QDEC report period 80 samples. */
    NRF_QDEC_REPORTPER_120      = QDEC_REPORTPER_REPORTPER_120Smpl,                                  /**< QDEC report period 120 samples. */
    NRF_QDEC_REPORTPER_160      = QDEC_REPORTPER_REPORTPER_160Smpl,                                  /**< QDEC report period 160 samples. */
    NRF_QDEC_REPORTPER_200      = QDEC_REPORTPER_REPORTPER_200Smpl,                                  /**< QDEC report period 200 samples. */
    NRF_QDEC_REPORTPER_240      = QDEC_REPORTPER_REPORTPER_240Smpl,                                  /**< QDEC report period 240 samples. */
    NRF_QDEC_REPORTPER_280      = QDEC_REPORTPER_REPORTPER_280Smpl,                                  /**< QDEC report period 280 samples. */
} nrf_qdec_reportper_t;

/**
 * @brief Function for enabling QDEC.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 */
NRF_STATIC_INLINE void nrf_qdec_enable(NRF_QDEC_Type * p_reg);

/**
 * @brief Function for disabling QDEC.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 */
NRF_STATIC_INLINE void nrf_qdec_disable(NRF_QDEC_Type * p_reg);

/**
 * @brief Function for returning the enable state of QDEC.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return State of the register.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_enable_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for enabling QDEC interrupts by mask.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] mask  Mask of interrupts to be enabled.
 *                  Use @ref nrf_qdec_int_mask_t values for bit masking.
 */
NRF_STATIC_INLINE void nrf_qdec_int_enable(NRF_QDEC_Type * p_reg, uint32_t mask);

/**
 * @brief Function for disabling QDEC interrupts by mask.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] mask  Mask of interrupts to be disabled.
 *                  Use @ref nrf_qdec_int_mask_t values for bit masking.
 */
NRF_STATIC_INLINE void nrf_qdec_int_disable(NRF_QDEC_Type * p_reg, uint32_t mask);

/**
 * @brief Function for checking if the specified interrupts are enabled.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] mask  Mask of interrupts to be checked.
 *                  Use @ref nrf_qdec_int_mask_t values for bit masking.
 *
 * @return Mask of enabled interrupts.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_int_enable_check(NRF_QDEC_Type const * p_reg, uint32_t mask);

/**
 * @brief Function for enabling the QDEC debouncing filter.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 */
NRF_STATIC_INLINE void nrf_qdec_dbfen_enable(NRF_QDEC_Type * p_reg);

/**
 * @brief Function for disabling the QDEC debouncing filter.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 */
NRF_STATIC_INLINE void nrf_qdec_dbfen_disable(NRF_QDEC_Type * p_reg);

/**
 * @brief Function for getting the state of the QDEC debouncing filter.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @retval NRF_QDEC_DBFEN_DISABLE The debouncing filter is disabled.
 * @retval NRF_QDEC_DBFEN_ENABLE  The debouncing filter is enabled.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_dbfen_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for configuring QDEC pins.
 *
 * @param[in] p_reg       Pointer to the structure of registers of the peripheral.
 * @param[in] phase_a_pin Phase A pin number.
 * @param[in] phase_b_pin Phase B pin number.
 * @param[in] led_pin     LED pin number.
 */
NRF_STATIC_INLINE void nrf_qdec_pins_set(NRF_QDEC_Type * p_reg,
                                         uint32_t        phase_a_pin,
                                         uint32_t        phase_b_pin,
                                         uint32_t        led_pin);

/**
 * @brief Function for setting the Phase A pin.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] pin   Phase A pin number.
 */
NRF_STATIC_INLINE void nrf_qdec_phase_a_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin);

/**
 * @brief Function for setting the Phase B pin.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] pin   Phase B pin number.
 */
NRF_STATIC_INLINE void nrf_qdec_phase_b_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin);

/**
 * @brief Function for setting the LED pin.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] pin   LED pin number.
 */
NRF_STATIC_INLINE void nrf_qdec_led_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin);

/**
 * @brief Function for getting the Phase A pin selection.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Phase A pin selection.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_phase_a_pin_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for getting the Phase B pin selection.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Phase B pin selection.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_phase_b_pin_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for getting the LED pin selection.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return LED pin selection.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_led_pin_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for setting the specified QDEC task.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] task  QDEC task to be triggered.
 */
NRF_STATIC_INLINE void nrf_qdec_task_trigger(NRF_QDEC_Type * p_reg, nrf_qdec_task_t task);

/**
 * @brief Function for retrieving the address of a QDEC task register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] task  QDEC task to get its address.
 *
 * @return Address of the specified QDEC task.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_task_address_get(NRF_QDEC_Type const * p_reg,
                                                     nrf_qdec_task_t       task);

/**
 * @brief Function for clearing the specified QDEC event.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] event QDEC event to be cleared.
 */
NRF_STATIC_INLINE void nrf_qdec_event_clear(NRF_QDEC_Type * p_reg, nrf_qdec_event_t event);

/**
 * @brief Function for getting the state of the specified QDEC event.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] event QDEC event to be checked.
 *
 * @return State of the specified QDEC event.
 */
NRF_STATIC_INLINE bool nrf_qdec_event_check(NRF_QDEC_Type const * p_reg, nrf_qdec_event_t event);

/**
 * @brief Function for retrieving the address of the specified QDEC event register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] event QDEC event to get its address.
 *
 * @return Address of the specified QDEC event.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_event_address_get(NRF_QDEC_Type const * p_reg,
                                                      nrf_qdec_event_t      event);

/**
 * @brief Function for setting QDEC shortcuts.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] mask  Mask of QDEC shortcuts to be set.
 */
NRF_STATIC_INLINE void nrf_qdec_shorts_enable(NRF_QDEC_Type * p_reg, uint32_t mask);

/**
 * @brief Function for clearing shortcuts of the QDEC by mask.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] mask  Mask of QDEC shortcuts to be cleared.
 */
NRF_STATIC_INLINE void nrf_qdec_shorts_disable(NRF_QDEC_Type * p_reg, uint32_t mask);

/**
 * @brief Function for converting return value of the @ref nrf_qdec_sampleper_get function
 *        to microseconds.
 *
 * @param[in] sampleper The sampling period.
 *
 * @return Period in microseconds.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_sampleper_to_value(nrf_qdec_sampleper_t sampleper);

/**
 * @brief Function for setting value of the QDEC sampling period.
 *
 * @param[in] p_reg     Pointer to the structure of registers of the peripheral.
 * @param[in] sampleper The sampling period.
 */
NRF_STATIC_INLINE void nrf_qdec_sampleper_set(NRF_QDEC_Type *      p_reg,
                                              nrf_qdec_sampleper_t sampleper);

/**
 * @brief Function for retrieving value of the QDEC sampling period.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Sampling period.
 */
NRF_STATIC_INLINE nrf_qdec_sampleper_t nrf_qdec_sampleper_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving value of the QDEC SAMPLE register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Value of the SAMPLE register.
 */
NRF_STATIC_INLINE int32_t nrf_qdec_sample_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving value of the QDEC ACC register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Value of the ACC register.
 */
NRF_STATIC_INLINE int32_t nrf_qdec_acc_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving value of the QDEC ACCREAD register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Value of the ACCREAD register.
 */
NRF_STATIC_INLINE int32_t nrf_qdec_accread_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving value of the QDEC ACCDBL register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Value of the ACCDBL register.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_accdbl_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving value of the QDEC ACCDBLREAD register.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Value of the ACCDBLREAD register.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_accdblread_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for setting delay time between setting LED active state and start sampling.
 *
 * @param[in] p_reg   Pointer to the structure of registers of the peripheral.
 * @param[in] time_us Delay time (in microseconds) between setting LED active state
 *                    and start sampling.
 */
NRF_STATIC_INLINE void nrf_qdec_ledpre_set(NRF_QDEC_Type * p_reg, uint32_t time_us);

/**
 * @brief Function for retrieving how long the LED is switched on before sampling.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return The gap in time in microseconds between switched LED to active state and start sampling.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_ledpre_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for setting the report period (in samples).
 *
 * @param[in] p_reg     Pointer to the structure of registers of the peripheral.
 * @param[in] reportper The number of samples.
 */
NRF_STATIC_INLINE void nrf_qdec_reportper_set(NRF_QDEC_Type *      p_reg,
                                              nrf_qdec_reportper_t reportper);

/**
 * @brief Function for retrieving the report period.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return The report period.
 */
NRF_STATIC_INLINE nrf_qdec_reportper_t nrf_qdec_reportper_get(NRF_QDEC_Type const * p_reg);

/**
 * @brief Function for retrieving the value of QDEC SAMPLEPER register.
 *
 * @param[in] reportper Reportper to be converted to amount of samples per report.
 *
 * @return Number of samples per report.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_reportper_to_value(nrf_qdec_reportper_t reportper);

/**
 * @brief Function for setting the active level for the LED.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 * @param[in] pol   Level of the active signal of the LED.
 */
NRF_STATIC_INLINE void nrf_qdec_ledpol_set(NRF_QDEC_Type * p_reg, nrf_qdec_ledpol_t pol);

/**
 * @brief Function for retrieving the active level for the LED.
 *
 * @param[in] p_reg Pointer to the structure of registers of the peripheral.
 *
 * @return Level of the active signal of the LED.
 */
NRF_STATIC_INLINE uint32_t nrf_qdec_ledpol_get(NRF_QDEC_Type const * p_reg);


#ifndef NRF_DECLARE_ONLY

NRF_STATIC_INLINE void nrf_qdec_enable(NRF_QDEC_Type * p_reg)
{
    p_reg->ENABLE = NRF_QDEC_ENABLE;
}

NRF_STATIC_INLINE void nrf_qdec_disable(NRF_QDEC_Type * p_reg)
{
    p_reg->ENABLE = NRF_QDEC_DISABLE;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_enable_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->ENABLE;
}

NRF_STATIC_INLINE void nrf_qdec_int_enable(NRF_QDEC_Type * p_reg, uint32_t mask)
{
    p_reg->INTENSET = mask; // writing 0 has no effect
}

NRF_STATIC_INLINE void nrf_qdec_int_disable(NRF_QDEC_Type * p_reg, uint32_t mask)
{
    p_reg->INTENCLR = mask; // writing 0 has no effect
}

NRF_STATIC_INLINE uint32_t nrf_qdec_int_enable_check(NRF_QDEC_Type const * p_reg, uint32_t mask)
{
    return p_reg->INTENSET & mask; // when read this register will return the value of INTEN.
}

NRF_STATIC_INLINE void nrf_qdec_dbfen_enable(NRF_QDEC_Type * p_reg)
{
    p_reg->DBFEN = NRF_QDEC_DBFEN_ENABLE;
}

NRF_STATIC_INLINE void nrf_qdec_dbfen_disable(NRF_QDEC_Type * p_reg)
{
    p_reg->DBFEN = NRF_QDEC_DBFEN_DISABLE;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_dbfen_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->DBFEN;
}

NRF_STATIC_INLINE void nrf_qdec_pins_set(NRF_QDEC_Type * p_reg,
                                         uint32_t        phase_a_pin,
                                         uint32_t        phase_b_pin,
                                         uint32_t        led_pin)
{
#if defined(QDEC_PSEL_A_CONNECT_Pos)
    p_reg->PSEL.A = phase_a_pin;
#else
    p_reg->PSELA = phase_a_pin;
#endif

#if defined(QDEC_PSEL_B_CONNECT_Pos)
    p_reg->PSEL.B = phase_b_pin;
#else
    p_reg->PSELB = phase_b_pin;
#endif

#if defined(QDEC_PSEL_LED_CONNECT_Pos)
    p_reg->PSEL.LED = led_pin;
#else
    p_reg->PSELLED = led_pin;
#endif
}

NRF_STATIC_INLINE void nrf_qdec_phase_a_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin)
{
#if defined(QDEC_PSEL_A_CONNECT_Pos)
    p_reg->PSEL.A = pin;
#else
    p_reg->PSELA = pin;
#endif
}

NRF_STATIC_INLINE void nrf_qdec_phase_b_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin)
{
#if defined(QDEC_PSEL_B_CONNECT_Pos)
    p_reg->PSEL.B = pin;
#else
    p_reg->PSELB = pin;
#endif
}

NRF_STATIC_INLINE void nrf_qdec_led_pin_set(NRF_QDEC_Type * p_reg, uint32_t pin)
{
#if defined(QDEC_PSEL_LED_CONNECT_Pos)
    p_reg->PSEL.LED = pin;
#else
    p_reg->PSELLED = pin;
#endif
}

NRF_STATIC_INLINE uint32_t nrf_qdec_phase_a_pin_get(NRF_QDEC_Type const * p_reg)
{
#if defined(QDEC_PSEL_A_CONNECT_Pos)
    return p_reg->PSEL.A;
#else
    return p_reg->PSELA;
#endif
}

NRF_STATIC_INLINE uint32_t nrf_qdec_phase_b_pin_get(NRF_QDEC_Type const * p_reg)
{
#if defined(QDEC_PSEL_B_CONNECT_Pos)
    return p_reg->PSEL.B;
#else
    return p_reg->PSELB;
#endif
}

NRF_STATIC_INLINE uint32_t nrf_qdec_led_pin_get(NRF_QDEC_Type const * p_reg)
{
#if defined(QDEC_PSEL_LED_CONNECT_Pos)
    return p_reg->PSEL.LED;
#else
    return p_reg->PSELLED;
#endif
}

NRF_STATIC_INLINE void nrf_qdec_task_trigger(NRF_QDEC_Type * p_reg, nrf_qdec_task_t task)
{
    *( (volatile uint32_t *)( (uint8_t *)p_reg + (uint32_t)task) ) = 1;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_task_address_get(NRF_QDEC_Type const * p_reg,
                                                     nrf_qdec_task_t       task)
{
    return nrf_task_event_address_get(p_reg, task);
}

NRF_STATIC_INLINE void nrf_qdec_event_clear(NRF_QDEC_Type * p_reg, nrf_qdec_event_t event)
{
    *( (volatile uint32_t *)( (uint8_t *)p_reg + (uint32_t)event) ) = 0;
    nrf_event_readback((uint8_t *)p_reg + (uint32_t)event);
}

NRF_STATIC_INLINE bool nrf_qdec_event_check(NRF_QDEC_Type const * p_reg, nrf_qdec_event_t event)
{
    return nrf_event_check(p_reg, event);
}

NRF_STATIC_INLINE uint32_t nrf_qdec_event_address_get(NRF_QDEC_Type const * p_reg,
                                                      nrf_qdec_event_t      event)
{
    return nrf_task_event_address_get(p_reg, event);
}

NRF_STATIC_INLINE void nrf_qdec_shorts_enable(NRF_QDEC_Type * p_reg, uint32_t mask)
{
    p_reg->SHORTS |= mask;
}

NRF_STATIC_INLINE void nrf_qdec_shorts_disable(NRF_QDEC_Type * p_reg, uint32_t mask)
{
    p_reg->SHORTS &= ~mask;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_sampleper_to_value(nrf_qdec_sampleper_t sampleper)
{
    return (1 << (7 + sampleper));
}

NRF_STATIC_INLINE void nrf_qdec_sampleper_set(NRF_QDEC_Type *      p_reg,
                                              nrf_qdec_sampleper_t sampleper)
{
    p_reg->SAMPLEPER = sampleper;
}

NRF_STATIC_INLINE nrf_qdec_sampleper_t nrf_qdec_sampleper_get(NRF_QDEC_Type const * p_reg)
{
    return (nrf_qdec_sampleper_t)(p_reg->SAMPLEPER);
}

NRF_STATIC_INLINE int32_t nrf_qdec_sample_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->SAMPLE;
}

NRF_STATIC_INLINE int32_t nrf_qdec_acc_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->ACC;
}

NRF_STATIC_INLINE int32_t nrf_qdec_accread_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->ACCREAD;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_accdbl_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->ACCDBL;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_accdblread_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->ACCDBLREAD;
}

NRF_STATIC_INLINE void nrf_qdec_ledpre_set(NRF_QDEC_Type * p_reg, uint32_t time_us)
{
    p_reg->LEDPRE = time_us;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_ledpre_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->LEDPRE;
}

NRF_STATIC_INLINE void nrf_qdec_reportper_set(NRF_QDEC_Type *      p_reg,
                                              nrf_qdec_reportper_t reportper)
{
    p_reg->REPORTPER = reportper;
}

NRF_STATIC_INLINE nrf_qdec_reportper_t nrf_qdec_reportper_get(NRF_QDEC_Type const * p_reg)
{
    return (nrf_qdec_reportper_t)(p_reg->REPORTPER);
}

NRF_STATIC_INLINE uint32_t nrf_qdec_reportper_to_value(nrf_qdec_reportper_t reportper)
{
    return (reportper == NRF_QDEC_REPORTPER_10) ? 10 : reportper * 40;
}

NRF_STATIC_INLINE void nrf_qdec_ledpol_set(NRF_QDEC_Type * p_reg, nrf_qdec_ledpol_t pol)
{
    p_reg->LEDPOL = pol;
}

NRF_STATIC_INLINE uint32_t nrf_qdec_ledpol_get(NRF_QDEC_Type const * p_reg)
{
    return p_reg->LEDPOL;
}

#endif // NRF_DECLARE_ONLY

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NRF_QDEC_H__
