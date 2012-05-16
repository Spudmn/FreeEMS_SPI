/*      FreeEMS - Unit Test SPI

        Copyright 2012 Aaron Keith

        This file is part of the FreeEMS project.

        FreeEMS software is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        FreeEMS software is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/


 */

#include "SPI.h"


/** @brief Transmit and Receive bytes over the SPI Bus and wait till complete
*
* This will Send and receive a number of bytes over the SPI Bus
* It will use the data in pSettings to configure the bus.
*
*
* @author
*
* @warning
*
*
* @param pSettings pointer to setup information for the SPI Bus.
* @param pTxBuffer pointer to a buffer holding the the bytes to transmit.
* @param pRxBuffer pointer to a buffer were the received bytes will be stored.
* @param TxCount The number of bytes to send from the TxBuffer
* @param RxCount The number of bytes to receive and store in RxBuffer
*
*
* @return An error code. Zero means success, anything else is a failure.
*/
uint8_t SPI_Read_Write_Blocking(SPI_Settings_t * pSettings,uint8_t  *pTxBuffe, uint8_t  *pRxBuffer, uint16_t BytesToSend, uint16_t BytesToGet)
{
   uint8_t Result;

   Result = SPI_Read_Write(pSettings,*pTxBuffer,pRxBuffer,TxCount, RxCount);
   if (Result)
   {
      return (Result);
   }

   while (SPI_Complete(pSettings->SPI_Bus) == 0);  // Wait for transfer to complete

   return (SPI_Complete(pSettings->SPI_Bus));

}


