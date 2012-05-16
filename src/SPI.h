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

#ifndef SPI_H_
#define SPI_H_

typedef struct
{
  uint16_t CS_Port_Bit;         // Some sort of Port pin mapping for the Chip Select.  Copy how Fred has mapped this.
  uint8_t SPI_Bus;            // Which of the 2 SPI buses do we want to use.
  uint16_t Bus_Speed;
  uint16_t  Bus_Mode;          // There may be other settings and these will be defined when I get into the code.
} SPI_Settings_t;



/** @brief Transmit and Receive bytes over the SPI Bus
*
* This will Send and receive a number of bytes over the SPI Bus
* It will use the data in pSettings to configure the bus.
* This function will use interrupts to complete the transfer
* and will return immediately. Use SPI_Complete() to check
* if the transfer is complete.
*
*
* @author
*
* @warning Do not call this function if a transfer is in progress.
* Use SPI_Complete() to check if the transfer is complete.
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

uint8_t SPI_Read_Write(SPI_Settings_t *pSettings,uint8_t  *pTxBuffer, uint8_t  *pRxBuffer, uint16_t TxCount, uint16_t RxCount);


/** @brief Check on the status of the SPI transfer
*
* Calling this function will return the status of the
* interrupt transfer.
*
*
* @author
*
* @warning
*
* @param SPI_Bus Which SPI Bus to check.
*
* @return Zero means Busy. One means complete no error. anything else is a failure.
*/
uint8_t  SPI_Complete(uint8_t SPI_Bus);



#endif /* SPI_H_ */
