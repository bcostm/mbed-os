/**
  ******************************************************************************
  * @file    stm32h7xx_ll_bdma.h
  * @author  MCD Application Team
  * @brief   Header file of BDMA LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H7xx_LL_BDMA_H
#define STM32H7xx_LL_BDMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"
#include "stm32h7xx_ll_dmamux.h"

/** @addtogroup STM32H7xx_LL_Driver
  * @{
  */

#if defined (BDMA)

/** @defgroup BDMA_LL BDMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup BDMA_LL_Private_Variables BDMA Private Variables
  * @{
  */
/* Array used to get the BDMA channel register offset versus channel index LL_BDMA_CHANNEL_x */
static const uint8_t CHANNEL_OFFSET_TAB[] =
{
  (uint8_t)(BDMA_Channel0_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel1_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel2_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel3_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel4_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel5_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel6_BASE - BDMA_BASE),
  (uint8_t)(BDMA_Channel7_BASE - BDMA_BASE)
};
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup BDMA_LL_ES_INIT BDMA Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t PeriphOrM2MSrcAddress;  /*!< Specifies the peripheral base address for BDMA transfer
                                        or as Source base address in case of memory to memory transfer direction.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t MemoryOrM2MDstAddress;  /*!< Specifies the memory base address for DMA transfer
                                        or as Destination base address in case of memory to memory transfer direction.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t Direction;              /*!< Specifies if the data will be transferred from memory to peripheral,
                                        from memory to memory or from peripheral to memory.
                                        This parameter can be a value of @ref BDMA_LL_EC_DIRECTION

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetDataTransferDirection(). */

  uint32_t Mode;                   /*!< Specifies the normal or circular operation mode.
                                        This parameter can be a value of @ref BDMA_LL_EC_MODE
                                        @note: The circular buffer mode cannot be used if the memory to memory
                                               data transfer direction is configured on the selected Channel

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetMode(). */

  uint32_t PeriphOrM2MSrcIncMode;  /*!< Specifies whether the Peripheral address or Source address in case of memory to memory transfer direction
                                        is incremented or not.
                                        This parameter can be a value of @ref BDMA_LL_EC_PERIPH

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetPeriphIncMode(). */

  uint32_t MemoryOrM2MDstIncMode;  /*!< Specifies whether the Memory address or Destination address in case of memory to memory transfer direction
                                        is incremented or not.
                                        This parameter can be a value of @ref BDMA_LL_EC_MEMORY

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetMemoryIncMode(). */

  uint32_t PeriphOrM2MSrcDataSize; /*!< Specifies the Peripheral data size alignment or Source data size alignment (byte, half word, word)
                                        in case of memory to memory transfer direction.
                                        This parameter can be a value of @ref BDMA_LL_EC_PDATAALIGN

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetPeriphSize(). */

  uint32_t MemoryOrM2MDstDataSize; /*!< Specifies the Memory data size alignment or Destination data size alignment (byte, half word, word)
                                        in case of memory to memory transfer direction.
                                        This parameter can be a value of @ref BDMA_LL_EC_MDATAALIGN

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetMemorySize(). */

  uint32_t NbData;                 /*!< Specifies the number of data to transfer, in data unit.
                                        The data unit is equal to the source buffer configuration set in PeripheralSize
                                        or MemorySize parameters depending in the transfer direction.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0x0000FFFF

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetDataLength(). */

  uint32_t PeriphRequest;          /*!< Specifies the peripheral request.
                                        This parameter can be a value of @ref DMAMUX_LL_EC_REQUEST

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetPeriphRequest(). */

  uint32_t Priority;               /*!< Specifies the channel priority level.
                                        This parameter can be a value of @ref BDMA_LL_EC_PRIORITY

                                        This feature can be modified afterwards using unitary function @ref LL_BDMA_SetChannelPriorityLevel(). */

} LL_BDMA_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup BDMA_LL_Exported_Constants BDMA Exported Constants
  * @{
  */
/** @defgroup BDMA_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_BDMA_WriteReg function
  * @{
  */
#define LL_BDMA_IFCR_CGIF1                 BDMA_IFCR_CGIF1        /*!< Channel 1 global flag            */
#define LL_BDMA_IFCR_CTCIF1                BDMA_IFCR_CTCIF1       /*!< Channel 1 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF1                BDMA_IFCR_CHTIF1       /*!< Channel 1 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF1                BDMA_IFCR_CTEIF1       /*!< Channel 1 transfer error flag    */
#define LL_BDMA_IFCR_CGIF2                 BDMA_IFCR_CGIF2        /*!< Channel 2 global flag            */
#define LL_BDMA_IFCR_CTCIF2                BDMA_IFCR_CTCIF2       /*!< Channel 2 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF2                BDMA_IFCR_CHTIF2       /*!< Channel 2 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF2                BDMA_IFCR_CTEIF2       /*!< Channel 2 transfer error flag    */
#define LL_BDMA_IFCR_CGIF3                 BDMA_IFCR_CGIF3        /*!< Channel 3 global flag            */
#define LL_BDMA_IFCR_CTCIF3                BDMA_IFCR_CTCIF3       /*!< Channel 3 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF3                BDMA_IFCR_CHTIF3       /*!< Channel 3 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF3                BDMA_IFCR_CTEIF3       /*!< Channel 3 transfer error flag    */
#define LL_BDMA_IFCR_CGIF4                 BDMA_IFCR_CGIF4        /*!< Channel 4 global flag            */
#define LL_BDMA_IFCR_CTCIF4                BDMA_IFCR_CTCIF4       /*!< Channel 4 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF4                BDMA_IFCR_CHTIF4       /*!< Channel 4 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF4                BDMA_IFCR_CTEIF4       /*!< Channel 4 transfer error flag    */
#define LL_BDMA_IFCR_CGIF5                 BDMA_IFCR_CGIF5        /*!< Channel 5 global flag            */
#define LL_BDMA_IFCR_CTCIF5                BDMA_IFCR_CTCIF5       /*!< Channel 5 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF5                BDMA_IFCR_CHTIF5       /*!< Channel 5 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF5                BDMA_IFCR_CTEIF5       /*!< Channel 5 transfer error flag    */
#define LL_BDMA_IFCR_CGIF6                 BDMA_IFCR_CGIF6        /*!< Channel 6 global flag            */
#define LL_BDMA_IFCR_CTCIF6                BDMA_IFCR_CTCIF6       /*!< Channel 6 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF6                BDMA_IFCR_CHTIF6       /*!< Channel 6 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF6                BDMA_IFCR_CTEIF6       /*!< Channel 6 transfer error flag    */
#define LL_BDMA_IFCR_CGIF7                 BDMA_IFCR_CGIF7        /*!< Channel 7 global flag            */
#define LL_BDMA_IFCR_CTCIF7                BDMA_IFCR_CTCIF7       /*!< Channel 7 transfer complete flag */
#define LL_BDMA_IFCR_CHTIF7                BDMA_IFCR_CHTIF7       /*!< Channel 7 half transfer flag     */
#define LL_BDMA_IFCR_CTEIF7                BDMA_IFCR_CTEIF7       /*!< Channel 7 transfer error flag    */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_BDMA_ReadReg function
  * @{
  */
#define LL_BDMA_ISR_GIF0                   BDMA_ISR_GIF0          /*!< Channel 1 global flag            */
#define LL_BDMA_ISR_TCIF0                  BDMA_ISR_TCIF0         /*!< Channel 1 transfer complete flag */
#define LL_BDMA_ISR_HTIF0                  BDMA_ISR_HTIF0         /*!< Channel 1 half transfer flag     */
#define LL_BDMA_ISR_TEIF0                  BDMA_ISR_TEIF0         /*!< Channel 1 transfer error flag    */
#define LL_BDMA_ISR_GIF1                   BDMA_ISR_GIF1          /*!< Channel 1 global flag            */
#define LL_BDMA_ISR_TCIF1                  BDMA_ISR_TCIF1         /*!< Channel 1 transfer complete flag */
#define LL_BDMA_ISR_HTIF1                  BDMA_ISR_HTIF1         /*!< Channel 1 half transfer flag     */
#define LL_BDMA_ISR_TEIF1                  BDMA_ISR_TEIF1         /*!< Channel 1 transfer error flag    */
#define LL_BDMA_ISR_GIF2                   BDMA_ISR_GIF2          /*!< Channel 2 global flag            */
#define LL_BDMA_ISR_TCIF2                  BDMA_ISR_TCIF2         /*!< Channel 2 transfer complete flag */
#define LL_BDMA_ISR_HTIF2                  BDMA_ISR_HTIF2         /*!< Channel 2 half transfer flag     */
#define LL_BDMA_ISR_TEIF2                  BDMA_ISR_TEIF2         /*!< Channel 2 transfer error flag    */
#define LL_BDMA_ISR_GIF3                   BDMA_ISR_GIF3          /*!< Channel 3 global flag            */
#define LL_BDMA_ISR_TCIF3                  BDMA_ISR_TCIF3         /*!< Channel 3 transfer complete flag */
#define LL_BDMA_ISR_HTIF3                  BDMA_ISR_HTIF3         /*!< Channel 3 half transfer flag     */
#define LL_BDMA_ISR_TEIF3                  BDMA_ISR_TEIF3         /*!< Channel 3 transfer error flag    */
#define LL_BDMA_ISR_GIF4                   BDMA_ISR_GIF4          /*!< Channel 4 global flag            */
#define LL_BDMA_ISR_TCIF4                  BDMA_ISR_TCIF4         /*!< Channel 4 transfer complete flag */
#define LL_BDMA_ISR_HTIF4                  BDMA_ISR_HTIF4         /*!< Channel 4 half transfer flag     */
#define LL_BDMA_ISR_TEIF4                  BDMA_ISR_TEIF4         /*!< Channel 4 transfer error flag    */
#define LL_BDMA_ISR_GIF5                   BDMA_ISR_GIF5          /*!< Channel 5 global flag            */
#define LL_BDMA_ISR_TCIF5                  BDMA_ISR_TCIF5         /*!< Channel 5 transfer complete flag */
#define LL_BDMA_ISR_HTIF5                  BDMA_ISR_HTIF5         /*!< Channel 5 half transfer flag     */
#define LL_BDMA_ISR_TEIF5                  BDMA_ISR_TEIF5         /*!< Channel 5 transfer error flag    */
#define LL_BDMA_ISR_GIF6                   BDMA_ISR_GIF6          /*!< Channel 6 global flag            */
#define LL_BDMA_ISR_TCIF6                  BDMA_ISR_TCIF6         /*!< Channel 6 transfer complete flag */
#define LL_BDMA_ISR_HTIF6                  BDMA_ISR_HTIF6         /*!< Channel 6 half transfer flag     */
#define LL_BDMA_ISR_TEIF6                  BDMA_ISR_TEIF6         /*!< Channel 6 transfer error flag    */
#define LL_BDMA_ISR_GIF7                   BDMA_ISR_GIF7          /*!< Channel 7 global flag            */
#define LL_BDMA_ISR_TCIF7                  BDMA_ISR_TCIF7         /*!< Channel 7 transfer complete flag */
#define LL_BDMA_ISR_HTIF7                  BDMA_ISR_HTIF7         /*!< Channel 7 half transfer flag     */
#define LL_BDMA_ISR_TEIF7                  BDMA_ISR_TEIF7         /*!< Channel 7 transfer error flag    */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_BDMA_ReadReg and  LL_BDMA_WriteReg functions
  * @{
  */
#define LL_BDMA_CCR_TCIE                   BDMA_CCR_TCIE          /*!< Transfer complete interrupt */
#define LL_BDMA_CCR_HTIE                   BDMA_CCR_HTIE          /*!< Half Transfer interrupt     */
#define LL_BDMA_CCR_TEIE                   BDMA_CCR_TEIE          /*!< Transfer error interrupt    */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_CHANNEL CHANNEL
  * @{
  */
#define LL_BDMA_CHANNEL_0                  0x00000000U /*!< DMA Channel 0 */
#define LL_BDMA_CHANNEL_1                  0x00000001U /*!< BDMA Channel 1 */
#define LL_BDMA_CHANNEL_2                  0x00000002U /*!< BDMA Channel 2 */
#define LL_BDMA_CHANNEL_3                  0x00000003U /*!< BDMA Channel 3 */
#define LL_BDMA_CHANNEL_4                  0x00000004U /*!< BDMA Channel 4 */
#define LL_BDMA_CHANNEL_5                  0x00000005U /*!< BDMA Channel 5 */
#define LL_BDMA_CHANNEL_6                  0x00000006U /*!< BDMA Channel 6 */
#define LL_BDMA_CHANNEL_7                  0x00000007U /*!< BDMA Channel 7 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_BDMA_CHANNEL_ALL                0xFFFF0000U /*!< BDMA Channel all (used only for function @ref LL_BDMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_DIRECTION Transfer Direction
  * @{
  */
#define LL_BDMA_DIRECTION_PERIPH_TO_MEMORY 0x00000000U             /*!< Peripheral to memory direction */
#define LL_BDMA_DIRECTION_MEMORY_TO_PERIPH BDMA_CCR_DIR             /*!< Memory to peripheral direction */
#define LL_BDMA_DIRECTION_MEMORY_TO_MEMORY BDMA_CCR_MEM2MEM         /*!< Memory to memory direction     */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_MODE Transfer mode
  * @{
  */
#define LL_BDMA_MODE_NORMAL                0x00000000U             /*!< Normal Mode                  */
#define LL_BDMA_MODE_CIRCULAR              BDMA_CCR_CIRC            /*!< Circular Mode                */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_PERIPH Peripheral increment mode
  * @{
  */
#define LL_BDMA_PERIPH_INCREMENT           BDMA_CCR_PINC            /*!< Peripheral increment mode Enable */
#define LL_BDMA_PERIPH_NOINCREMENT         0x00000000U             /*!< Peripheral increment mode Disable */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_MEMORY Memory increment mode
  * @{
  */
#define LL_BDMA_MEMORY_INCREMENT           BDMA_CCR_MINC            /*!< Memory increment mode Enable  */
#define LL_BDMA_MEMORY_NOINCREMENT         0x00000000U             /*!< Memory increment mode Disable */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_PDATAALIGN Peripheral data alignment
  * @{
  */
#define LL_BDMA_PDATAALIGN_BYTE            0x00000000U             /*!< Peripheral data alignment : Byte     */
#define LL_BDMA_PDATAALIGN_HALFWORD        BDMA_CCR_PSIZE_0         /*!< Peripheral data alignment : HalfWord */
#define LL_BDMA_PDATAALIGN_WORD            BDMA_CCR_PSIZE_1         /*!< Peripheral data alignment : Word     */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_MDATAALIGN Memory data alignment
  * @{
  */
#define LL_BDMA_MDATAALIGN_BYTE            0x00000000U             /*!< Memory data alignment : Byte     */
#define LL_BDMA_MDATAALIGN_HALFWORD        BDMA_CCR_MSIZE_0         /*!< Memory data alignment : HalfWord */
#define LL_BDMA_MDATAALIGN_WORD            BDMA_CCR_MSIZE_1         /*!< Memory data alignment : Word     */
/**
  * @}
  */

/** @defgroup BDMA_LL_EC_PRIORITY Transfer Priority level
  * @{
  */
#define LL_BDMA_PRIORITY_LOW               0x00000000U             /*!< Priority level : Low       */
#define LL_BDMA_PRIORITY_MEDIUM            BDMA_CCR_PL_0            /*!< Priority level : Medium    */
#define LL_BDMA_PRIORITY_HIGH              BDMA_CCR_PL_1            /*!< Priority level : High      */
#define LL_BDMA_PRIORITY_VERYHIGH          BDMA_CCR_PL              /*!< Priority level : Very_High */
/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup BDMA_LL_Exported_Macros BDMA Exported Macros
  * @{
  */

/** @defgroup BDMA_LL_EM_WRITE_READ Common Write and read registers macros
  * @{
  */
/**
  * @brief  Write a value in BDMA register
  * @param  __INSTANCE__ BDMA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_BDMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in BDMA register
  * @param  __INSTANCE__ BDMA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_BDMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup BDMA_LL_EM_CONVERT_DMAxCHANNELy Convert BDMAxChannely
  * @{
  */
/**
  * @brief  Convert BDMAx_Channely into BDMAx
  * @param  __CHANNEL_INSTANCE__ BDMAx_Channely
  * @retval BDMAx
  */
#define __LL_BDMA_GET_INSTANCE(__CHANNEL_INSTANCE__)  (BDMA)

/**
  * @brief  Convert BDMAx_Channely into LL_BDMA_CHANNEL_y
  * @param  __CHANNEL_INSTANCE__ BDMAx_Channely
  * @retval LL_BDMA_CHANNEL_y
  */
#define __LL_BDMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel0)) ? LL_BDMA_CHANNEL_0 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel1)) ? LL_BDMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel2)) ? LL_BDMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel3)) ? LL_BDMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel4)) ? LL_BDMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel5)) ? LL_BDMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)BDMA_Channel6)) ? LL_BDMA_CHANNEL_6 : \
 LL_BDMA_CHANNEL_7)

/**
  * @brief  Convert BDMA Instance BDMAx and LL_BDMA_CHANNEL_y into BDMAx_Channely
  * @param  __BDMA_INSTANCE__ BDMAx
  * @param  __CHANNEL__ LL_BDMA_CHANNEL_y
  * @retval BDMAx_Channely
  */
#define __LL_BDMA_GET_CHANNEL_INSTANCE(__BDMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_0))) ? BDMA_Channel0 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_1))) ? BDMA_Channel1 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_2))) ? BDMA_Channel2 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_3))) ? BDMA_Channel3 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_4))) ? BDMA_Channel4 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_5))) ? BDMA_Channel5 : \
 (((uint32_t)(__BDMA_INSTANCE__) == ((uint32_t)BDMA)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_BDMA_CHANNEL_6))) ? BDMA_Channel6 : \
 BDMA_Channel7)


/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup BDMA_LL_Exported_Functions BDMA Exported Functions
 * @{
 */

/** @defgroup BDMA_LL_EF_Configuration Configuration
  * @{
  */
/**
  * @brief  Enable BDMA channel.
  * @rmtoll CCR          EN            LL_BDMA_EnableChannel
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_EnableChannel(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  SET_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_EN);
}

/**
  * @brief  Disable BDMA channel.
  * @rmtoll CCR          EN            LL_BDMA_DisableChannel
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_DisableChannel(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  CLEAR_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_EN);
}

/**
  * @brief  Check if BDMA channel is enabled or disabled.
  * @rmtoll CCR          EN            LL_BDMA_IsEnabledChannel
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsEnabledChannel(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                             BDMA_CCR_EN) == (BDMA_CCR_EN));
}

/**
  * @brief  Configure all parameters link to BDMA transfer.
  * @rmtoll CCR          DIR           LL_BDMA_ConfigTransfer\n
  *         CCR          MEM2MEM       LL_BDMA_ConfigTransfer\n
  *         CCR          CIRC          LL_BDMA_ConfigTransfer\n
  *         CCR          PINC          LL_BDMA_ConfigTransfer\n
  *         CCR          MINC          LL_BDMA_ConfigTransfer\n
  *         CCR          PSIZE         LL_BDMA_ConfigTransfer\n
  *         CCR          MSIZE         LL_BDMA_ConfigTransfer\n
  *         CCR          PL            LL_BDMA_ConfigTransfer
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  Configuration This parameter must be a combination of all the following values:
  *         @arg @ref LL_BDMA_DIRECTION_PERIPH_TO_MEMORY or @ref LL_BDMA_DIRECTION_MEMORY_TO_PERIPH or @ref LL_BDMA_DIRECTION_MEMORY_TO_MEMORY
  *         @arg @ref LL_BDMA_MODE_NORMAL or @ref LL_BDMA_MODE_CIRCULAR
  *         @arg @ref LL_BDMA_PERIPH_INCREMENT or @ref LL_BDMA_PERIPH_NOINCREMENT
  *         @arg @ref LL_BDMA_MEMORY_INCREMENT or @ref LL_BDMA_MEMORY_NOINCREMENT
  *         @arg @ref LL_BDMA_PDATAALIGN_BYTE or @ref LL_BDMA_PDATAALIGN_HALFWORD or @ref LL_BDMA_PDATAALIGN_WORD
  *         @arg @ref LL_BDMA_MDATAALIGN_BYTE or @ref LL_BDMA_MDATAALIGN_HALFWORD or @ref LL_BDMA_MDATAALIGN_WORD
  *         @arg @ref LL_BDMA_PRIORITY_LOW or @ref LL_BDMA_PRIORITY_MEDIUM or @ref LL_BDMA_PRIORITY_HIGH or @ref LL_BDMA_PRIORITY_VERYHIGH
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ConfigTransfer(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t Configuration)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
             BDMA_CCR_DIR | BDMA_CCR_MEM2MEM | BDMA_CCR_CIRC | BDMA_CCR_PINC | BDMA_CCR_MINC | BDMA_CCR_PSIZE | BDMA_CCR_MSIZE | BDMA_CCR_PL,
             Configuration);
}

/**
  * @brief  Set Data transfer direction (read from peripheral or from memory).
  * @rmtoll CCR          DIR           LL_BDMA_SetDataTransferDirection\n
  *         CCR          MEM2MEM       LL_BDMA_SetDataTransferDirection
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_MEMORY
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetDataTransferDirection(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t Direction)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
             BDMA_CCR_DIR | BDMA_CCR_MEM2MEM, Direction);
}

/**
  * @brief  Get Data transfer direction (read from peripheral or from memory).
  * @rmtoll CCR          DIR           LL_BDMA_GetDataTransferDirection\n
  *         CCR          MEM2MEM       LL_BDMA_GetDataTransferDirection
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_MEMORY
  */
__STATIC_INLINE uint32_t LL_BDMA_GetDataTransferDirection(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_DIR | BDMA_CCR_MEM2MEM));
}

/**
  * @brief  Set BDMA mode circular or normal.
  * @note The circular buffer mode cannot be used if the memory-to-memory
  * data transfer is configured on the selected Channel.
  * @rmtoll CCR          CIRC          LL_BDMA_SetMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_MODE_NORMAL
  *         @arg @ref LL_BDMA_MODE_CIRCULAR
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetMode(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t Mode)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_CIRC,
             Mode);
}

/**
  * @brief  Get BDMA mode circular or normal.
  * @rmtoll CCR          CIRC          LL_BDMA_GetMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_MODE_NORMAL
  *         @arg @ref LL_BDMA_MODE_CIRCULAR
  */
__STATIC_INLINE uint32_t LL_BDMA_GetMode(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_CIRC));
}

/**
  * @brief  Set Peripheral increment mode.
  * @rmtoll CCR          PINC          LL_BDMA_SetPeriphIncMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  PeriphOrM2MSrcIncMode This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_PERIPH_INCREMENT
  *         @arg @ref LL_BDMA_PERIPH_NOINCREMENT
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetPeriphIncMode(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcIncMode)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_PINC,
             PeriphOrM2MSrcIncMode);
}

/**
  * @brief  Get Peripheral increment mode.
  * @rmtoll CCR          PINC          LL_BDMA_GetPeriphIncMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_PERIPH_INCREMENT
  *         @arg @ref LL_BDMA_PERIPH_NOINCREMENT
  */
__STATIC_INLINE uint32_t LL_BDMA_GetPeriphIncMode(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_PINC));
}

/**
  * @brief  Set Memory increment mode.
  * @rmtoll CCR          MINC          LL_BDMA_SetMemoryIncMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  MemoryOrM2MDstIncMode This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_MEMORY_INCREMENT
  *         @arg @ref LL_BDMA_MEMORY_NOINCREMENT
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetMemoryIncMode(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t MemoryOrM2MDstIncMode)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_MINC,
             MemoryOrM2MDstIncMode);
}

/**
  * @brief  Get Memory increment mode.
  * @rmtoll CCR          MINC          LL_BDMA_GetMemoryIncMode
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_MEMORY_INCREMENT
  *         @arg @ref LL_BDMA_MEMORY_NOINCREMENT
  */
__STATIC_INLINE uint32_t LL_BDMA_GetMemoryIncMode(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_MINC));
}

/**
  * @brief  Set Peripheral size.
  * @rmtoll CCR          PSIZE         LL_BDMA_SetPeriphSize
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  PeriphOrM2MSrcDataSize This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_PDATAALIGN_BYTE
  *         @arg @ref LL_BDMA_PDATAALIGN_HALFWORD
  *         @arg @ref LL_BDMA_PDATAALIGN_WORD
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetPeriphSize(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcDataSize)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_PSIZE,
             PeriphOrM2MSrcDataSize);
}

/**
  * @brief  Get Peripheral size.
  * @rmtoll CCR          PSIZE         LL_BDMA_GetPeriphSize
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_PDATAALIGN_BYTE
  *         @arg @ref LL_BDMA_PDATAALIGN_HALFWORD
  *         @arg @ref LL_BDMA_PDATAALIGN_WORD
  */
__STATIC_INLINE uint32_t LL_BDMA_GetPeriphSize(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_PSIZE));
}

/**
  * @brief  Set Memory size.
  * @rmtoll CCR          MSIZE         LL_BDMA_SetMemorySize
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  MemoryOrM2MDstDataSize This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_MDATAALIGN_BYTE
  *         @arg @ref LL_BDMA_MDATAALIGN_HALFWORD
  *         @arg @ref LL_BDMA_MDATAALIGN_WORD
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetMemorySize(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t MemoryOrM2MDstDataSize)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_MSIZE,
             MemoryOrM2MDstDataSize);
}

/**
  * @brief  Get Memory size.
  * @rmtoll CCR          MSIZE         LL_BDMA_GetMemorySize
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_MDATAALIGN_BYTE
  *         @arg @ref LL_BDMA_MDATAALIGN_HALFWORD
  *         @arg @ref LL_BDMA_MDATAALIGN_WORD
  */
__STATIC_INLINE uint32_t LL_BDMA_GetMemorySize(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_MSIZE));
}

/**
  * @brief  Set Channel priority level.
  * @rmtoll CCR          PL            LL_BDMA_SetChannelPriorityLevel
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  Priority This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_PRIORITY_LOW
  *         @arg @ref LL_BDMA_PRIORITY_MEDIUM
  *         @arg @ref LL_BDMA_PRIORITY_HIGH
  *         @arg @ref LL_BDMA_PRIORITY_VERYHIGH
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetChannelPriorityLevel(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t Priority)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_PL,
             Priority);
}

/**
  * @brief  Get Channel priority level.
  * @rmtoll CCR          PL            LL_BDMA_GetChannelPriorityLevel
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_BDMA_PRIORITY_LOW
  *         @arg @ref LL_BDMA_PRIORITY_MEDIUM
  *         @arg @ref LL_BDMA_PRIORITY_HIGH
  *         @arg @ref LL_BDMA_PRIORITY_VERYHIGH
  */
__STATIC_INLINE uint32_t LL_BDMA_GetChannelPriorityLevel(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                   BDMA_CCR_PL));
}

/**
  * @brief  Set Number of data to transfer.
  * @note   This action has no effect if
  *         channel is enabled.
  * @rmtoll CNDTR        NDT           LL_BDMA_SetDataLength
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  NbData Between Min_Data = 0 and Max_Data = 0x0000FFFF
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetDataLength(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t NbData)
{
  MODIFY_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CNDTR,
             BDMA_CNDTR_NDT, NbData);
}

/**
  * @brief  Get Number of data to transfer.
  * @note   Once the channel is enabled, the return value indicate the
  *         remaining bytes to be transmitted.
  * @rmtoll CNDTR        NDT           LL_BDMA_GetDataLength
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_BDMA_GetDataLength(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CNDTR,
                   BDMA_CNDTR_NDT));
}

/**
  * @brief  Configure the Source and Destination addresses.
  * @note   This API must not be called when the BDMA channel is enabled.
  * @note   Each IP using BDMA provides an API to get directly the register adress (LL_PPP_BDMA_GetRegAddr).
  * @rmtoll CPAR         PA            LL_BDMA_ConfigAddresses\n
  *         CMAR         MA            LL_BDMA_ConfigAddresses
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  SrcAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_BDMA_DIRECTION_MEMORY_TO_MEMORY
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ConfigAddresses(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t SrcAddress,
                                             uint32_t DstAddress, uint32_t Direction)
{
  /* Direction Memory to Periph */
  if (Direction == LL_BDMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR, SrcAddress);
    WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR, DstAddress);
  }
  /* Direction Periph to Memory and Memory to Memory */
  else
  {
    WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR, SrcAddress);
    WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR, DstAddress);
  }
}

/**
  * @brief  Set the Memory address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_PERIPH_TO_MEMORY or LL_BDMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @note   This API must not be called when the BDMA channel is enabled.
  * @rmtoll CMAR         MA            LL_BDMA_SetMemoryAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetMemoryAddress(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR, MemoryAddress);
}

/**
  * @brief  Set the Peripheral address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_PERIPH_TO_MEMORY or LL_BDMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @note   This API must not be called when the BDMA channel is enabled.
  * @rmtoll CPAR         PA            LL_BDMA_SetPeriphAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  PeriphAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetPeriphAddress(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t PeriphAddress)
{
  WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR, PeriphAddress);
}

/**
  * @brief  Get Memory address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_PERIPH_TO_MEMORY or LL_BDMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @rmtoll CMAR         MA            LL_BDMA_GetMemoryAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_BDMA_GetMemoryAddress(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR));
}

/**
  * @brief  Get Peripheral address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_PERIPH_TO_MEMORY or LL_BDMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @rmtoll CPAR         PA            LL_BDMA_GetPeriphAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_BDMA_GetPeriphAddress(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR));
}

/**
  * @brief  Set the Memory to Memory Source address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @note   This API must not be called when the BDMA channel is enabled.
  * @rmtoll CPAR         PA            LL_BDMA_SetM2MSrcAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetM2MSrcAddress(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR, MemoryAddress);
}

/**
  * @brief  Set the Memory to Memory Destination address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @note   This API must not be called when the BDMA channel is enabled.
  * @rmtoll CMAR         MA            LL_BDMA_SetM2MDstAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetM2MDstAddress(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR, MemoryAddress);
}

/**
  * @brief  Get the Memory to Memory Source address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @rmtoll CPAR         PA            LL_BDMA_GetM2MSrcAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_BDMA_GetM2MSrcAddress(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CPAR));
}

/**
  * @brief  Get the Memory to Memory Destination address.
  * @note   Interface used for direction LL_BDMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @rmtoll CMAR         MA            LL_BDMA_GetM2MDstAddress
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_BDMA_GetM2MDstAddress(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_REG(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CMAR));
}

/**
  * @brief  Set BDMA request for BDMA Channels on DMAMUX Channel x.
  * @note   DMAMUX2 channel 0 to 7 are mapped to BDMA channel 0 to 7.
  * @rmtoll CxCR         DMAREQ_ID     LL_BDMA_SetPeriphRequest
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMAMUX2_REQ_MEM2MEM
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR0
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR1
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR2
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR3
  *         @arg @ref LL_DMAMUX2_REQ_ADC1
  *         @arg @ref LL_DMAMUX2_REQ_DAC1_CH1
  *         @arg @ref LL_DMAMUX2_REQ_DAC1_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM6_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM7_UP
  *         @arg @ref LL_DMAMUX2_REQ_SPI1_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI1_TX
  *         @arg @ref LL_DMAMUX2_REQ_SPI2_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI2_TX
  *         @arg @ref LL_DMAMUX2_REQ_SPI3_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI3_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C1_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C1_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C2_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C2_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C3_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C3_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C4_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C4_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART1_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART1_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART2_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART2_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART3_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART3_TX
  *         @arg @ref LL_DMAMUX2_REQ_UART4_RX
  *         @arg @ref LL_DMAMUX2_REQ_UART4_TX
  *         @arg @ref LL_DMAMUX2_REQ_UART5_RX
  *         @arg @ref LL_DMAMUX2_REQ_UART5_TX
  *         @arg @ref LL_DMAMUX2_REQ_LPUART1_RX
  *         @arg @ref LL_DMAMUX2_REQ_LPUART1_TX
  *         @arg @ref LL_DMAMUX2_REQ_SAI1_A
  *         @arg @ref LL_DMAMUX2_REQ_SAI1_B
  *         @arg @ref LL_DMAMUX2_REQ_SAI2_A
  *         @arg @ref LL_DMAMUX2_REQ_SAI2_B
  *         @arg @ref LL_DMAMUX2_REQ_OSPI1
  *         @arg @ref LL_DMAMUX2_REQ_OSPI2
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM16_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM16_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM17_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM17_UP
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT0
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT1
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT2
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT3
  *         @arg @ref LL_DMAMUX2_REQ_DCMI
  *         @arg @ref LL_DMAMUX2_REQ_AES_IN
  *         @arg @ref LL_DMAMUX2_REQ_AES_OUT
  *         @arg @ref LL_DMAMUX2_REQ_HASH_IN
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_SetPeriphRequest(BDMA_TypeDef *BDMAx, uint32_t Channel, uint32_t Request)
{
  MODIFY_REG(((DMAMUX_Channel_TypeDef *)(uint32_t)((uint32_t)DMAMUX2_Channel0 + (DMAMUX_CCR_SIZE * (Channel))))->CCR, DMAMUX_CxCR_DMAREQ_ID, Request);
}

/**
  * @brief  Get BDMA request for BDMA Channels on DMAMUX Channel x.
  * @note   DMAMUX channel 0 to 7 are mapped to BDMA channel 0 to 7.
  * @rmtoll CxCR         DMAREQ_ID     LL_BDMA_GetPeriphRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMAMUX2_REQ_MEM2MEM
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR0
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR1
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR2
  *         @arg @ref LL_DMAMUX2_REQ_GENERATOR3
  *         @arg @ref LL_DMAMUX2_REQ_ADC1
  *         @arg @ref LL_DMAMUX2_REQ_DAC1_CH1
  *         @arg @ref LL_DMAMUX2_REQ_DAC1_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM6_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM7_UP
  *         @arg @ref LL_DMAMUX2_REQ_SPI1_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI1_TX
  *         @arg @ref LL_DMAMUX2_REQ_SPI2_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI2_TX
  *         @arg @ref LL_DMAMUX2_REQ_SPI3_RX
  *         @arg @ref LL_DMAMUX2_REQ_SPI3_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C1_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C1_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C2_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C2_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C3_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C3_TX
  *         @arg @ref LL_DMAMUX2_REQ_I2C4_RX
  *         @arg @ref LL_DMAMUX2_REQ_I2C4_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART1_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART1_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART2_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART2_TX
  *         @arg @ref LL_DMAMUX2_REQ_USART3_RX
  *         @arg @ref LL_DMAMUX2_REQ_USART3_TX
  *         @arg @ref LL_DMAMUX2_REQ_UART4_RX
  *         @arg @ref LL_DMAMUX2_REQ_UART4_TX
  *         @arg @ref LL_DMAMUX2_REQ_UART5_RX
  *         @arg @ref LL_DMAMUX2_REQ_UART5_TX
  *         @arg @ref LL_DMAMUX2_REQ_LPUART1_RX
  *         @arg @ref LL_DMAMUX2_REQ_LPUART1_TX
  *         @arg @ref LL_DMAMUX2_REQ_SAI1_A
  *         @arg @ref LL_DMAMUX2_REQ_SAI1_B
  *         @arg @ref LL_DMAMUX2_REQ_SAI2_A
  *         @arg @ref LL_DMAMUX2_REQ_SAI2_B
  *         @arg @ref LL_DMAMUX2_REQ_OSPI1
  *         @arg @ref LL_DMAMUX2_REQ_OSPI2
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM1_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM8_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM2_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM3_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM4_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH2
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH3
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_CH4
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM5_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_TRIG
  *         @arg @ref LL_DMAMUX2_REQ_TIM15_COM
  *         @arg @ref LL_DMAMUX2_REQ_TIM16_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM16_UP
  *         @arg @ref LL_DMAMUX2_REQ_TIM17_CH1
  *         @arg @ref LL_DMAMUX2_REQ_TIM17_UP
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT0
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT1
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT2
  *         @arg @ref LL_DMAMUX2_REQ_DFSDM1_FLT3
  *         @arg @ref LL_DMAMUX2_REQ_DCMI
  *         @arg @ref LL_DMAMUX2_REQ_AES_IN
  *         @arg @ref LL_DMAMUX2_REQ_AES_OUT
  *         @arg @ref LL_DMAMUX2_REQ_HASH_IN
  */
__STATIC_INLINE uint32_t LL_BDMA_GetPeriphRequest(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (READ_BIT(((DMAMUX_Channel_TypeDef *)((uint32_t)((uint32_t)DMAMUX2_Channel0 + (DMAMUX_CCR_SIZE * (Channel)))))->CCR, DMAMUX_CxCR_DMAREQ_ID));
}

/**
  * @}
  */


/** @defgroup BDMA_LL_EF_FLAG_Management FLAG_Management
  * @{
  */
/**
  * @brief  Get Channel 0 global interrupt flag.
  * @rmtoll ISR          GIF0          LL_BDMA_IsActiveFlag_GI0
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI0(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF0) == (BDMA_ISR_GIF0));
}

/**
  * @brief  Get Channel 1 global interrupt flag.
  * @rmtoll ISR          GIF1          LL_BDMA_IsActiveFlag_GI1
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI1(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF1) == (BDMA_ISR_GIF1));
}

/**
  * @brief  Get Channel 2 global interrupt flag.
  * @rmtoll ISR          GIF2          LL_BDMA_IsActiveFlag_GI2
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI2(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF2) == (BDMA_ISR_GIF2));
}

/**
  * @brief  Get Channel 3 global interrupt flag.
  * @rmtoll ISR          GIF3          LL_BDMA_IsActiveFlag_GI3
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI3(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF3) == (BDMA_ISR_GIF3));
}

/**
  * @brief  Get Channel 4 global interrupt flag.
  * @rmtoll ISR          GIF4          LL_BDMA_IsActiveFlag_GI4
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI4(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF4) == (BDMA_ISR_GIF4));
}

/**
  * @brief  Get Channel 5 global interrupt flag.
  * @rmtoll ISR          GIF5          LL_BDMA_IsActiveFlag_GI5
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI5(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF5) == (BDMA_ISR_GIF5));
}

/**
  * @brief  Get Channel 6 global interrupt flag.
  * @rmtoll ISR          GIF6          LL_BDMA_IsActiveFlag_GI6
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI6(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF6) == (BDMA_ISR_GIF6));
}

/**
  * @brief  Get Channel 7 global interrupt flag.
  * @rmtoll ISR          GIF7          LL_BDMA_IsActiveFlag_GI7
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_GI7(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_GIF7) == (BDMA_ISR_GIF7));
}

/**
  * @brief  Get Channel 0 transfer complete flag.
  * @rmtoll ISR          TCIF0         LL_BDMA_IsActiveFlag_TC0
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC0(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF0) == (BDMA_ISR_TCIF0));
}
/**
  * @brief  Get Channel 1 transfer complete flag.
  * @rmtoll ISR          TCIF1         LL_BDMA_IsActiveFlag_TC1
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC1(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF1) == (BDMA_ISR_TCIF1));
}

/**
  * @brief  Get Channel 2 transfer complete flag.
  * @rmtoll ISR          TCIF2         LL_BDMA_IsActiveFlag_TC2
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC2(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF2) == (BDMA_ISR_TCIF2));
}

/**
  * @brief  Get Channel 3 transfer complete flag.
  * @rmtoll ISR          TCIF3         LL_BDMA_IsActiveFlag_TC3
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC3(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF3) == (BDMA_ISR_TCIF3));
}

/**
  * @brief  Get Channel 4 transfer complete flag.
  * @rmtoll ISR          TCIF4         LL_BDMA_IsActiveFlag_TC4
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC4(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF4) == (BDMA_ISR_TCIF4));
}

/**
  * @brief  Get Channel 5 transfer complete flag.
  * @rmtoll ISR          TCIF5         LL_BDMA_IsActiveFlag_TC5
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC5(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF5) == (BDMA_ISR_TCIF5));
}

/**
  * @brief  Get Channel 6 transfer complete flag.
  * @rmtoll ISR          TCIF6         LL_BDMA_IsActiveFlag_TC6
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC6(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF6) == (BDMA_ISR_TCIF6));
}

/**
  * @brief  Get Channel 7 transfer complete flag.
  * @rmtoll ISR          TCIF7         LL_BDMA_IsActiveFlag_TC7
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TC7(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TCIF7) == (BDMA_ISR_TCIF7));
}

/**
  * @brief  Get Channel 0 half transfer flag.
  * @rmtoll ISR          HTIF0         LL_BDMA_IsActiveFlag_HT0
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT0(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF0) == (BDMA_ISR_HTIF0));
}
/**
  * @brief  Get Channel 1 half transfer flag.
  * @rmtoll ISR          HTIF1         LL_BDMA_IsActiveFlag_HT1
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT1(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF1) == (BDMA_ISR_HTIF1));
}

/**
  * @brief  Get Channel 2 half transfer flag.
  * @rmtoll ISR          HTIF2         LL_BDMA_IsActiveFlag_HT2
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT2(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF2) == (BDMA_ISR_HTIF2));
}

/**
  * @brief  Get Channel 3 half transfer flag.
  * @rmtoll ISR          HTIF3         LL_BDMA_IsActiveFlag_HT3
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT3(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF3) == (BDMA_ISR_HTIF3));
}

/**
  * @brief  Get Channel 4 half transfer flag.
  * @rmtoll ISR          HTIF4         LL_BDMA_IsActiveFlag_HT4
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT4(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF4) == (BDMA_ISR_HTIF4));
}

/**
  * @brief  Get Channel 5 half transfer flag.
  * @rmtoll ISR          HTIF5         LL_BDMA_IsActiveFlag_HT5
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT5(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF5) == (BDMA_ISR_HTIF5));
}

/**
  * @brief  Get Channel 6 half transfer flag.
  * @rmtoll ISR          HTIF6         LL_BDMA_IsActiveFlag_HT6
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT6(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF6) == (BDMA_ISR_HTIF6));
}

/**
  * @brief  Get Channel 7 half transfer flag.
  * @rmtoll ISR          HTIF7         LL_BDMA_IsActiveFlag_HT7
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_HT7(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_HTIF7) == (BDMA_ISR_HTIF7));
}

/**
  * @brief  Get Channel 1 transfer error flag.
  * @rmtoll ISR          TEIF1         LL_BDMA_IsActiveFlag_TE1
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE1(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF1) == (BDMA_ISR_TEIF1));
}

/**
  * @brief  Get Channel 2 transfer error flag.
  * @rmtoll ISR          TEIF2         LL_BDMA_IsActiveFlag_TE2
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE2(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF2) == (BDMA_ISR_TEIF2));
}

/**
  * @brief  Get Channel 3 transfer error flag.
  * @rmtoll ISR          TEIF3         LL_BDMA_IsActiveFlag_TE3
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE3(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF3) == (BDMA_ISR_TEIF3));
}

/**
  * @brief  Get Channel 4 transfer error flag.
  * @rmtoll ISR          TEIF4         LL_BDMA_IsActiveFlag_TE4
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE4(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF4) == (BDMA_ISR_TEIF4));
}

/**
  * @brief  Get Channel 5 transfer error flag.
  * @rmtoll ISR          TEIF5         LL_BDMA_IsActiveFlag_TE5
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE5(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF5) == (BDMA_ISR_TEIF5));
}

/**
  * @brief  Get Channel 6 transfer error flag.
  * @rmtoll ISR          TEIF6         LL_BDMA_IsActiveFlag_TE6
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE6(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF6) == (BDMA_ISR_TEIF6));
}

/**
  * @brief  Get Channel 7 transfer error flag.
  * @rmtoll ISR          TEIF7         LL_BDMA_IsActiveFlag_TE7
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsActiveFlag_TE7(BDMA_TypeDef *BDMAx)
{
  return (uint32_t)(READ_BIT(BDMAx->ISR, BDMA_ISR_TEIF7) == (BDMA_ISR_TEIF7));
}

/**
  * @brief  Clear Channel 0 global interrupt flag.
  * @rmtoll IFCR         CGIF0         LL_BDMA_ClearFlag_GI0
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI0(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF0);
}
/**
  * @brief  Clear Channel 1 global interrupt flag.
  * @rmtoll IFCR         CGIF1         LL_BDMA_ClearFlag_GI1
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI1(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF1);
}

/**
  * @brief  Clear Channel 2 global interrupt flag.
  * @rmtoll IFCR         CGIF2         LL_BDMA_ClearFlag_GI2
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI2(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF2);
}

/**
  * @brief  Clear Channel 3 global interrupt flag.
  * @rmtoll IFCR         CGIF3         LL_BDMA_ClearFlag_GI3
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI3(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF3);
}

/**
  * @brief  Clear Channel 4 global interrupt flag.
  * @rmtoll IFCR         CGIF4         LL_BDMA_ClearFlag_GI4
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI4(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF4);
}

/**
  * @brief  Clear Channel 5 global interrupt flag.
  * @rmtoll IFCR         CGIF5         LL_BDMA_ClearFlag_GI5
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI5(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF5);
}

/**
  * @brief  Clear Channel 6 global interrupt flag.
  * @rmtoll IFCR         CGIF6         LL_BDMA_ClearFlag_GI6
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI6(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF6);
}

/**
  * @brief  Clear Channel 7 global interrupt flag.
  * @rmtoll IFCR         CGIF7         LL_BDMA_ClearFlag_GI7
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_GI7(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CGIF7);
}

/**
  * @brief  Clear Channel 0  transfer complete flag.
  * @rmtoll IFCR         CTCIF0        LL_BDMA_ClearFlag_TC0
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC0(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF0);
}
/**
  * @brief  Clear Channel 1  transfer complete flag.
  * @rmtoll IFCR         CTCIF1        LL_BDMA_ClearFlag_TC1
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC1(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF1);
}

/**
  * @brief  Clear Channel 2  transfer complete flag.
  * @rmtoll IFCR         CTCIF2        LL_BDMA_ClearFlag_TC2
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC2(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF2);
}

/**
  * @brief  Clear Channel 3  transfer complete flag.
  * @rmtoll IFCR         CTCIF3        LL_BDMA_ClearFlag_TC3
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC3(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF3);
}

/**
  * @brief  Clear Channel 4  transfer complete flag.
  * @rmtoll IFCR         CTCIF4        LL_BDMA_ClearFlag_TC4
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC4(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF4);
}

/**
  * @brief  Clear Channel 5  transfer complete flag.
  * @rmtoll IFCR         CTCIF5        LL_BDMA_ClearFlag_TC5
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC5(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF5);
}

/**
  * @brief  Clear Channel 6  transfer complete flag.
  * @rmtoll IFCR         CTCIF6        LL_BDMA_ClearFlag_TC6
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC6(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF6);
}

/**
  * @brief  Clear Channel 7  transfer complete flag.
  * @rmtoll IFCR         CTCIF7        LL_BDMA_ClearFlag_TC7
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TC7(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTCIF7);
}

/**
  * @brief  Clear Channel 0  half transfer flag.
  * @rmtoll IFCR         CHTIF0        LL_BDMA_ClearFlag_HT0
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT0(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF0);
}
/**
  * @brief  Clear Channel 1  half transfer flag.
  * @rmtoll IFCR         CHTIF1        LL_BDMA_ClearFlag_HT1
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT1(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF1);
}

/**
  * @brief  Clear Channel 2  half transfer flag.
  * @rmtoll IFCR         CHTIF2        LL_BDMA_ClearFlag_HT2
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT2(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF2);
}

/**
  * @brief  Clear Channel 3  half transfer flag.
  * @rmtoll IFCR         CHTIF3        LL_BDMA_ClearFlag_HT3
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT3(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF3);
}

/**
  * @brief  Clear Channel 4  half transfer flag.
  * @rmtoll IFCR         CHTIF4        LL_BDMA_ClearFlag_HT4
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT4(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF4);
}

/**
  * @brief  Clear Channel 5  half transfer flag.
  * @rmtoll IFCR         CHTIF5        LL_BDMA_ClearFlag_HT5
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT5(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF5);
}

/**
  * @brief  Clear Channel 6  half transfer flag.
  * @rmtoll IFCR         CHTIF6        LL_BDMA_ClearFlag_HT6
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT6(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF6);
}

/**
  * @brief  Clear Channel 7  half transfer flag.
  * @rmtoll IFCR         CHTIF7        LL_BDMA_ClearFlag_HT7
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_HT7(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CHTIF7);
}

/**
  * @brief  Clear Channel 1 transfer error flag.
  * @rmtoll IFCR         CTEIF1        LL_BDMA_ClearFlag_TE1
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE1(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF1);
}

/**
  * @brief  Clear Channel 2 transfer error flag.
  * @rmtoll IFCR         CTEIF2        LL_BDMA_ClearFlag_TE2
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE2(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF2);
}

/**
  * @brief  Clear Channel 3 transfer error flag.
  * @rmtoll IFCR         CTEIF3        LL_BDMA_ClearFlag_TE3
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE3(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF3);
}

/**
  * @brief  Clear Channel 4 transfer error flag.
  * @rmtoll IFCR         CTEIF4        LL_BDMA_ClearFlag_TE4
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE4(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF4);
}

/**
  * @brief  Clear Channel 5 transfer error flag.
  * @rmtoll IFCR         CTEIF5        LL_BDMA_ClearFlag_TE5
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE5(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF5);
}

/**
  * @brief  Clear Channel 6 transfer error flag.
  * @rmtoll IFCR         CTEIF6        LL_BDMA_ClearFlag_TE6
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE6(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF6);
}

/**
  * @brief  Clear Channel 7 transfer error flag.
  * @rmtoll IFCR         CTEIF7        LL_BDMA_ClearFlag_TE7
  * @param  BDMAx BDMA Instance
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_ClearFlag_TE7(BDMA_TypeDef *BDMAx)
{
  WRITE_REG(BDMAx->IFCR, BDMA_IFCR_CTEIF7);
}

/**
  * @}
  */

/** @defgroup BDMA_LL_EF_IT_Management IT_Management
  * @{
  */
/**
  * @brief  Enable Transfer complete interrupt.
  * @rmtoll CCR          TCIE          LL_BDMA_EnableIT_TC
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_EnableIT_TC(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  SET_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_TCIE);
}

/**
  * @brief  Enable Half transfer interrupt.
  * @rmtoll CCR          HTIE          LL_BDMA_EnableIT_HT
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_EnableIT_HT(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  SET_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_HTIE);
}

/**
  * @brief  Enable Transfer error interrupt.
  * @rmtoll CCR          TEIE          LL_BDMA_EnableIT_TE
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_EnableIT_TE(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  SET_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_TEIE);
}

/**
  * @brief  Disable Transfer complete interrupt.
  * @rmtoll CCR          TCIE          LL_BDMA_DisableIT_TC
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_DisableIT_TC(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  CLEAR_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_TCIE);
}

/**
  * @brief  Disable Half transfer interrupt.
  * @rmtoll CCR          HTIE          LL_BDMA_DisableIT_HT
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_DisableIT_HT(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  CLEAR_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_HTIE);
}

/**
  * @brief  Disable Transfer error interrupt.
  * @rmtoll CCR          TEIE          LL_BDMA_DisableIT_TE
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_BDMA_DisableIT_TE(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  CLEAR_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR, BDMA_CCR_TEIE);
}

/**
  * @brief  Check if Transfer complete Interrupt is enabled.
  * @rmtoll CCR          TCIE          LL_BDMA_IsEnabledIT_TC
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsEnabledIT_TC(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                             BDMA_CCR_TCIE) == (BDMA_CCR_TCIE));
}

/**
  * @brief  Check if Half transfer Interrupt is enabled.
  * @rmtoll CCR          HTIE          LL_BDMA_IsEnabledIT_HT
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsEnabledIT_HT(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                             BDMA_CCR_HTIE) == (BDMA_CCR_HTIE));
}

/**
  * @brief  Check if Transfer error Interrupt is enabled.
  * @rmtoll CCR          TEIE          LL_BDMA_IsEnabledIT_TE
  * @param  BDMAx BDMA Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_BDMA_CHANNEL_0
  *         @arg @ref LL_BDMA_CHANNEL_1
  *         @arg @ref LL_BDMA_CHANNEL_2
  *         @arg @ref LL_BDMA_CHANNEL_3
  *         @arg @ref LL_BDMA_CHANNEL_4
  *         @arg @ref LL_BDMA_CHANNEL_5
  *         @arg @ref LL_BDMA_CHANNEL_6
  *         @arg @ref LL_BDMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BDMA_IsEnabledIT_TE(BDMA_TypeDef *BDMAx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((BDMA_Channel_TypeDef *)((uint32_t)((uint32_t)BDMAx + CHANNEL_OFFSET_TAB[Channel])))->CCR,
                             BDMA_CCR_TEIE) == (BDMA_CCR_TEIE));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup BDMA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

uint32_t LL_BDMA_Init(BDMA_TypeDef *BDMAx, uint32_t Channel, LL_BDMA_InitTypeDef *BDMA_InitStruct);
uint32_t LL_BDMA_DeInit(BDMA_TypeDef *BDMAx, uint32_t Channel);
void LL_BDMA_StructInit(LL_BDMA_InitTypeDef *BDMA_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* BDMA */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_LL_BDMA_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
