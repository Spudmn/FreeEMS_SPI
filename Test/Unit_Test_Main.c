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

#include "unity//unity_fixture.h"


TEST_GROUP_RUNNER(SPI)
{
   RUN_TEST_CASE(SPI,Init);
}


void RunAllTests(void)
{
   RUN_TEST_GROUP(SPI);
}

int main (int argc,char * argv[])
{
return UnityMain(argc,argv,RunAllTests);
}
