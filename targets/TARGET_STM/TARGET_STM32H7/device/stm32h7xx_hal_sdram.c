/**
  ******************************************************************************
  * @file    stm32h7xx_hal_sdram.c
  * @author  MCD Application Team
  * @brief   SDRAM HAL module driver.
  *          This file provides a generic firmware to drive SDRAM memories mounted
  *          as external device.
  *
  @verbatim
  ==============================================================================
                       ##### How to use this driver #####
  ==============================================================================
  [..]
    This driver is a generic layered driver which contains a set of APIs used to
    control SDRAM memories. It uses the FMC layer functions to interface
    with SDRAM devices.
    The following sequence should be followed to configure the FMC to interface
    with SDRAM memories:

   (#) Declare a SDRAM_HandleTypeDef handle structure, for example:
          SDRAM_HandleTypeDef  hdsram

       (++) Fill the SDRAM_HandleTypeDef handle "Init" field with the allowed
            values of the structure member.

       (++) Fill the SDRAM_HandleTypeDef handle "Instance" field with a predefined
            base register instance for NOR or SDRAM device

   (#) Declare a FMC_SDRAM_TimingTypeDef structure; for example:
          FMC_SDRAM_TimingTypeDef  Timing;
      and fill its fields with the allowed values of the structure member.

   (#) Initialize the SDRAM Controller by calling the function HAL_SDRAM_Init(). This function
       performs the following sequence:

       (##) MSP hardware layer configuration using the function HAL_SDRAM_MspInit()
       (##) Control register configuration using the FMC SDRAM interface function
            FMC_SDRAM_Init()
       (##) Timing register configuration using the FMC SDRAM interface function
            FMC_SDRAM_Timing_Init()
       (##) Program the SDRAM external device by applying its initialization sequence
            according to the device plugged in your hardware. This step is mandatory
            for accessing the SDRAM device.

   (#) At this stage you can perform read/write accesses from/to the memory connected
       to the SDRAM Bank. You can perform either polling or DMA transfer using the
       following APIs:
       (++) HAL_SDRAM_Read()/HAL_SDRAM_Write() for polling read/write access
       (++) HAL_SDRAM_Read_DMA()/HAL_SDRAM_Write_DMA() for DMA read/write transfer

   (#) You can also control the SDRAM device by calling the control APIs HAL_SDRAM_WriteOperation_Enable()/
       HAL_SDRAM_WriteOperation_Disable() to respectively enable/disable the SDRAM write operation or
       the function HAL_SDRAM_SendCommand() to send a specified command to the SDRAM
       device. The command to be sent must be configured with the FMC_SDRAM_CommandTypeDef
       structure.

   (#) You can continuously monitor the SDRAM device HAL state by calling the function
       HAL_SDRAM_GetState()

   *** Callback registration ***
    =============================================
    [..]
      The compilation define  USE_HAL_SDRAM_REGISTER_CALLBACKS when set to 1
      allows the user to configure dynamically the driver callbacks.

      Use Functions @ref HAL_SDRAM_RegisterCallback() to register a user callback,
      it allows to register following callbacks:
        (+) MspInitCallback    : SDRAM MspInit.
        (+) MspDeInitCallback  : SDRAM MspDeInit.
      This function takes as parameters the HAL peripheral handle, the Callback ID
      and a pointer to the user callback function.

      Use function @ref HAL_SDRAM_UnRegisterCallback() to reset a callback to the default
      weak (surcharged) function. It allows to reset following callbacks:
        (+) MspInitCallback    : SDRAM MspInit.
        (+) MspDeInitCallback  : SDRAM MspDeInit.
      This function) takes as parameters the HAL peripheral handle and the Callback ID.

      By default, after the @ref HAL_SDRAM_Init and if the state is HAL_SDRAM_STATE_RESET
      all callbacks are reset to the corresponding legacy weak (surcharged) functions.
      Exception done for MspInit and MspDeInit callbacks that are respectively
      reset to the legacy weak (surcharged) functions in the @ref HAL_SDRAM_Init
      and @ref  HAL_SDRAM_DeInit only when these callbacks are null (not registered beforehand).
      If not, MspInit or MspDeInit are not null, the @ref HAL_SDRAM_Init and @ref HAL_SDRAM_DeInit
      keep and use the user MspInit/MspDeInit callbacks (registered beforehand)

      Callbacks can be registered/unregistered in READY state only.
      Exception done for MspInit/MspDeInit callbacks that can be registered/unregistered
      in READY or RESET state, thus registered (user) MspInit/DeInit callbacks can be used
      during the Init/DeInit.
      In that case first register the MspInit/MspDeInit user callbacks
      using @ref HAL_SDRAM_RegisterCallback before calling @ref HAL_SDRAM_DeInit
      or @ref HAL_SDRAM_Init function.

      When The compilation define USE_HAL_SDRAM_REGISTER_CALLBACKS is set to 0 or
      not defined, the callback registering feature is not available
      and weak (surcharged) callbacks are used.

  @endverbatim
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

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/** @addtogroup STM32H7xx_HAL_Driver
  * @{
  */

/** @defgroup SDRAM SDRAM
  * @brief SDRAM driver modules
  * @{
  */
#ifdef HAL_SDRAM_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @defgroup SDRAM_Exported_Functions SDRAM Exported Functions
  * @{
  */

/** @defgroup SDRAM_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief    Initialization and Configuration functions
  *
  @verbatim
  ==============================================================================
           ##### SDRAM Initialization and de_initialization functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to initialize/de-initialize
    the SDRAM memory

@endverbatim
  * @{
  */

/**
  * @brief  Performs the SDRAM device initialization sequence.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  Timing: Pointer to SDRAM control timing structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Init(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_TimingTypeDef *Timing)
{
  /* Check the SDRAM handle parameter */
  if(hsdram == NULL)
  {
    return HAL_ERROR;
  }

#if (USE_HAL_SDRAM_REGISTER_CALLBACKS == 1)
  if(hsdram->State == HAL_SDRAM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hsdram->Lock = HAL_UNLOCKED;

    if(hsdram->MspInitCallback == NULL)
    {
      hsdram->MspInitCallback = HAL_SDRAM_MspInit;
    }
    /* Init the low level hardware */
    hsdram->MspInitCallback(hsdram);
  }
#else
  if(hsdram->State == HAL_SDRAM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hsdram->Lock = HAL_UNLOCKED;

    /* Initialize the low level hardware (MSP) */
    HAL_SDRAM_MspInit(hsdram);
  }
#endif

  /* Initialize the SDRAM controller state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Initialize SDRAM control Interface */
  (void) FMC_SDRAM_Init(hsdram->Instance, &(hsdram->Init));  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Initialize SDRAM timing Interface */
  (void) FMC_SDRAM_Timing_Init(hsdram->Instance, Timing, hsdram->Init.SDBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Enable FMC IP */
  __FMC_ENABLE();

  /* Update the SDRAM controller state */
  hsdram->State = HAL_SDRAM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Perform the SDRAM device initialization sequence.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_DeInit(SDRAM_HandleTypeDef *hsdram)
{
#if (USE_HAL_SDRAM_REGISTER_CALLBACKS == 1)
  if(hsdram->MspDeInitCallback == NULL)
  {
    hsdram->MspDeInitCallback = HAL_SDRAM_MspDeInit;
  }

  /* DeInit the low level hardware */
  hsdram->MspDeInitCallback(hsdram);
#else
  /* Initialize the low level hardware (MSP) */
  HAL_SDRAM_MspDeInit(hsdram);
#endif
  /* Configure the SDRAM registers with their reset values */
  (void) FMC_SDRAM_DeInit(hsdram->Instance, hsdram->Init.SDBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Reset the SDRAM controller state */
  hsdram->State = HAL_SDRAM_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}

/**
  * @brief  SDRAM MSP Init.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval None
  */
__weak void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef *hsdram)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsdram);

  /* NOTE: This function Should not be modified, when the callback is needed,
            the HAL_SDRAM_MspInit could be implemented in the user file
   */
}

/**
  * @brief  SDRAM MSP DeInit.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval None
  */
__weak void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef *hsdram)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsdram);

  /* NOTE: This function Should not be modified, when the callback is needed,
            the HAL_SDRAM_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  This function handles SDRAM refresh error interrupt request.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval HAL status
*/
void HAL_SDRAM_IRQHandler(SDRAM_HandleTypeDef *hsdram)
{
  /* Check SDRAM interrupt Rising edge flag */
  if(__FMC_SDRAM_GET_FLAG(hsdram->Instance, FMC_SDRAM_FLAG_REFRESH_IT))
  {
    /* SDRAM refresh error interrupt callback */
    HAL_SDRAM_RefreshErrorCallback(hsdram);

    /* Clear SDRAM refresh error interrupt pending bit */
    __FMC_SDRAM_CLEAR_FLAG(hsdram->Instance, FMC_SDRAM_FLAG_REFRESH_ERROR);
  }
}

/**
  * @brief  SDRAM Refresh error callback.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval None
  */
__weak void HAL_SDRAM_RefreshErrorCallback(SDRAM_HandleTypeDef *hsdram)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsdram);

  /* NOTE: This function Should not be modified, when the callback is needed,
            the HAL_SDRAM_RefreshErrorCallback could be implemented in the user file
   */
}

/**
  * @brief  DMA transfer complete callback.
  * @param  hmdma: pointer to a MDMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
__weak void HAL_SDRAM_DMA_XferCpltCallback(MDMA_HandleTypeDef *hmdma)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hmdma);

  /* NOTE: This function Should not be modified, when the callback is needed,
            the HAL_SDRAM_DMA_XferCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  DMA transfer complete error callback.
  * @param  hmdma: DMA handle
  * @retval None
  */
__weak void HAL_SDRAM_DMA_XferErrorCallback(MDMA_HandleTypeDef *hmdma)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hmdma);

  /* NOTE: This function Should not be modified, when the callback is needed,
            the HAL_SDRAM_DMA_XferErrorCallback could be implemented in the user file
   */
}

#if (USE_HAL_SDRAM_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User SDRAM Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param hsdram : SDRAM handle
  * @param CallbackID : ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_SDRAM_MSP_INIT_CB_ID       SDRAM MspInit callback ID
  *          @arg @ref HAL_SDRAM_MSP_DEINIT_CB_ID     SDRAM MspDeInit callback ID
  * @param pCallback : pointer to the Callback function
  * @retval status
  */
HAL_StatusTypeDef HAL_SDRAM_RegisterCallback (SDRAM_HandleTypeDef *hsdram, HAL_SDRAM_CallbackIDTypeDef CallbackId, pSDRAM_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(pCallback == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hsdram);

  if((hsdram->State == HAL_SDRAM_STATE_READY) || (hsdram->State == HAL_SDRAM_STATE_RESET))
  {
    switch (CallbackId)
    {
    case HAL_SDRAM_MSP_INIT_CB_ID :
      hsdram->MspInitCallback = pCallback;
      break;
    case HAL_SDRAM_MSP_DEINIT_CB_ID :
      hsdram->MspDeInitCallback = pCallback;
      break;
    default :

      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsdram);
  return status;
}

/**
  * @brief  Unregister a User SDRAM Callback
  *         SDRAM Callback is redirected to the weak (surcharged) predefined callback
  * @param hsdram : SDRAM handle
  * @param CallbackID : ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_SDRAM_MSP_INIT_CB_ID       SDRAM MspInit callback ID
  *          @arg @ref HAL_SDRAM_MSP_DEINIT_CB_ID     SDRAM MspDeInit callback ID
  * @retval status
  */
HAL_StatusTypeDef HAL_SDRAM_UnRegisterCallback (SDRAM_HandleTypeDef *hsdram, HAL_SDRAM_CallbackIDTypeDef CallbackId)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hsdram);

  if((hsdram->State == HAL_SDRAM_STATE_READY) || (hsdram->State == HAL_SDRAM_STATE_RESET))
  {
    switch (CallbackId)
    {
    case HAL_SDRAM_MSP_INIT_CB_ID :
      hsdram->MspInitCallback = HAL_SDRAM_MspInit;
      break;
    case HAL_SDRAM_MSP_DEINIT_CB_ID :
      hsdram->MspDeInitCallback = HAL_SDRAM_MspDeInit;
      break;
    default :

      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsdram);
  return status;
}
#endif

/**
  * @}
  */

/** @defgroup SDRAM_Exported_Functions_Group2 Input and Output functions
  * @brief    Input Output and memory control functions
  *
  @verbatim
  ==============================================================================
                    ##### SDRAM Input and Output functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to use and control the SDRAM memory

@endverbatim
  * @{
  */

/**
  * @brief  Reads 8-bit data buffer from the SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Read_8b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint8_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint8_t* pdstbuffer = pDstBuffer;
  __IO uint8_t *pSdramAddress = (uint8_t *)pAddress;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if(hsdram->State == HAL_SDRAM_STATE_PRECHARGED)
  {
    return  HAL_ERROR;
  }

  /* Read data from source */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint8_t *)pSdramAddress;
    pdstbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}


/**
  * @brief  Writes 8-bit data buffer to SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Write_8b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint8_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize ;
  uint8_t* psrcbuffer = pSrcBuffer ;
  __IO uint8_t *pSdramAddress = (uint8_t *)pAddress;
  HAL_SDRAM_StateTypeDef tmp;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  tmp = hsdram->State;

  if(tmp == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if((tmp == HAL_SDRAM_STATE_PRECHARGED) || (tmp == HAL_SDRAM_STATE_WRITE_PROTECTED))
  {
    return  HAL_ERROR;
  }

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint8_t *)pSdramAddress = *psrcbuffer;
    psrcbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}


/**
  * @brief  Reads 16-bit data buffer from the SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Read_16b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint16_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t  buffersize = BufferSize ;
  uint16_t* pdstbuffer = pDstBuffer ;
  __IO uint16_t *pSdramAddress = (uint16_t *)pAddress;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if(hsdram->State == HAL_SDRAM_STATE_PRECHARGED)
  {
    return  HAL_ERROR;
  }

  /* Read data from source */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint16_t *)pSdramAddress;
    pdstbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}

/**
  * @brief  Writes 16-bit data buffer to SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Write_16b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint16_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t  buffersize = BufferSize ;
  uint16_t* psrcbuffer = pSrcBuffer ;
  __IO uint16_t *pSdramAddress = (uint16_t *)pAddress;
  HAL_SDRAM_StateTypeDef tmp;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  tmp = hsdram->State;

  if(tmp == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if((tmp == HAL_SDRAM_STATE_PRECHARGED) || (tmp == HAL_SDRAM_STATE_WRITE_PROTECTED))
  {
    return  HAL_ERROR;
  }

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint16_t *)pSdramAddress = *psrcbuffer;
    psrcbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}

/**
  * @brief  Reads 32-bit data buffer from the SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Read_32b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t  buffersize = BufferSize;
  uint32_t* pdstbuffer = pDstBuffer;
  __IO uint32_t *pSdramAddress = (uint32_t *)pAddress;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if(hsdram->State == HAL_SDRAM_STATE_PRECHARGED)
  {
    return  HAL_ERROR;
  }

  /* Read data from source */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint32_t *)pSdramAddress;
    pdstbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}

/**
  * @brief  Writes 32-bit data buffer to SDRAM memory.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Write_32b(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t  buffersize = BufferSize;
  uint32_t* psrcbuffer = pSrcBuffer;
  __IO uint32_t *pSdramAddress = (uint32_t *)pAddress;
  HAL_SDRAM_StateTypeDef tmp;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  tmp = hsdram->State;

  if(tmp == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if((tmp == HAL_SDRAM_STATE_PRECHARGED) || (tmp == HAL_SDRAM_STATE_WRITE_PROTECTED))
  {
    return  HAL_ERROR;
  }

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint32_t *)pSdramAddress = *psrcbuffer;
    psrcbuffer++;
    pSdramAddress++;
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return HAL_OK;
}

/**
  * @brief  Reads a Words data from the SDRAM memory using DMA transfer.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Read_DMA(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize)
{
  HAL_SDRAM_StateTypeDef tmp;
  HAL_StatusTypeDef status;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  tmp = hsdram->State;

  if(tmp == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if(tmp == HAL_SDRAM_STATE_PRECHARGED)
  {
    return  HAL_ERROR;
  }

  /* Configure DMA user callbacks */
  hsdram->hmdma->XferCpltCallback  = HAL_SDRAM_DMA_XferCpltCallback;
  hsdram->hmdma->XferErrorCallback = HAL_SDRAM_DMA_XferErrorCallback;

  /* Enable the DMA Stream */
  status = HAL_MDMA_Start_IT(hsdram->hmdma, (uint32_t)pAddress, (uint32_t)pDstBuffer, (uint32_t)(BufferSize * 4U), 1);

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return status;
}

/**
  * @brief  Writes a Words data buffer to SDRAM memory using DMA transfer.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_Write_DMA(SDRAM_HandleTypeDef *hsdram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize)
{
  HAL_SDRAM_StateTypeDef tmp;
  HAL_StatusTypeDef status;

  /* Process Locked */
  __HAL_LOCK(hsdram);

  /* Check the SDRAM controller state */
  tmp = hsdram->State;

  if(tmp == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }
  if((tmp == HAL_SDRAM_STATE_PRECHARGED) || (tmp == HAL_SDRAM_STATE_WRITE_PROTECTED))
  {
    return  HAL_ERROR;
  }

  /* Configure DMA user callbacks */
  hsdram->hmdma->XferCpltCallback  = HAL_SDRAM_DMA_XferCpltCallback;
  hsdram->hmdma->XferErrorCallback = HAL_SDRAM_DMA_XferErrorCallback;

  /* Enable the DMA Stream */
  status = HAL_MDMA_Start_IT(hsdram->hmdma, (uint32_t)pSrcBuffer, (uint32_t)pAddress, (uint32_t)(BufferSize * 4U), 1);

  /* Process Unlocked */
  __HAL_UNLOCK(hsdram);

  return status;
}

/**
  * @}
  */

/** @defgroup SDRAM_Exported_Functions_Group3 Control functions
 *  @brief   management functions
 *
@verbatim
  ==============================================================================
                         ##### SDRAM Control functions #####
  ==============================================================================
  [..]
    This subsection provides a set of functions allowing to control dynamically
    the SDRAM interface.

@endverbatim
  * @{
  */

/**
  * @brief  Enables dynamically SDRAM write protection.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_WriteProtection_Enable(SDRAM_HandleTypeDef *hsdram)
{
  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Enable write protection */
  (void) FMC_SDRAM_WriteProtection_Enable(hsdram->Instance, hsdram->Init.SDBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_WRITE_PROTECTED;

  return HAL_OK;
}

/**
  * @brief  Disables dynamically SDRAM write protection.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_WriteProtection_Disable(SDRAM_HandleTypeDef *hsdram)
{
  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Disable write protection */
  (void) FMC_SDRAM_WriteProtection_Disable(hsdram->Instance, hsdram->Init.SDBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Sends Command to the SDRAM bank.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  Command: SDRAM command structure
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_SendCommand(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command, uint32_t Timeout)
{
  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Send SDRAM command */
  (void) FMC_SDRAM_SendCommand(hsdram->Instance, Command, Timeout);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SDRAM controller state state */
  if(Command->CommandMode == FMC_SDRAM_CMD_PALL)
  {
    hsdram->State = HAL_SDRAM_STATE_PRECHARGED;
  }
  else
  {
    hsdram->State = HAL_SDRAM_STATE_READY;
  }

  return HAL_OK;
}

/**
  * @brief  Programs the SDRAM Memory Refresh rate.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  RefreshRate: The SDRAM refresh rate value
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_ProgramRefreshRate(SDRAM_HandleTypeDef *hsdram, uint32_t RefreshRate)
{
  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Program the refresh rate */
  (void) FMC_SDRAM_ProgramRefreshRate(hsdram->Instance ,RefreshRate);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Sets the Number of consecutive SDRAM Memory auto Refresh commands.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @param  AutoRefreshNumber: The SDRAM auto Refresh number
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SDRAM_SetAutoRefreshNumber(SDRAM_HandleTypeDef *hsdram, uint32_t AutoRefreshNumber)
{
  /* Check the SDRAM controller state */
  if(hsdram->State == HAL_SDRAM_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_BUSY;

  /* Set the Auto-Refresh number */
  (void) FMC_SDRAM_SetAutoRefreshNumber(hsdram->Instance ,AutoRefreshNumber);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SDRAM state */
  hsdram->State = HAL_SDRAM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Returns the SDRAM memory current mode.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval The SDRAM memory mode.
  */
uint32_t HAL_SDRAM_GetModeStatus(SDRAM_HandleTypeDef *hsdram)
{
  /* Return the SDRAM memory current mode */
  return(FMC_SDRAM_GetModeStatus(hsdram->Instance, hsdram->Init.SDBank));
}

/**
  * @}
  */

/** @defgroup SDRAM_Exported_Functions_Group4 State functions
 *  @brief   Peripheral State functions
 *
@verbatim
  ==============================================================================
                      ##### SDRAM State functions #####
  ==============================================================================
  [..]
    This subsection permits to get in run-time the status of the SDRAM controller
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Returns the SDRAM state.
  * @param  hsdram: pointer to a SDRAM_HandleTypeDef structure that contains
  *                the configuration information for SDRAM module.
  * @retval HAL state
  */
HAL_SDRAM_StateTypeDef HAL_SDRAM_GetState(SDRAM_HandleTypeDef *hsdram)
{
  return hsdram->State;
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* HAL_SDRAM_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
