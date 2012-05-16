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
  unsigned char    Reg1;
  unsigned char    Reg2;
  unsigned char    Reg3;
}SPI_Regs;

typedef struct
{
  unsigned short * CS_Port;         // Some sort of Port pin mapping for the Chip Select.  Copy how Fred has mapped this.
  unsigned char    CS_Bit_Mask;
  SPI_Regs      * SPI_Reg_Bank;     // Which of the 2 SPI buses do we want to use.
  unsigned short Bus_Speed;
  unsigned short  Bus_Mode;          // There may be other settings and these will be defined when I get into the code.
} SPI_Settings;


unsigned char SPI_Read_Write(SPI_Settings *Settings,unsigned char *TxBuffer, unsigned char *RxBuffer, unsigned short TxCount, unsigned short RxCount);
unsigned char  SPI_Complete(SPI_Settings *Settings);
unsigned char SPI_Read_Write_Blocking(SPI_Settings *Settings,unsigned char  *TxBuffer, unsigned char  *RxBuffer, unsigned short TxCount, unsigned short RxCount);



#endif /* SPI_H_ */
