Requirements:

1. Function shall sum members of given one-dimensional array. However, it should sum only members whose number of ones in the binary representation is higher than defined threshold (e.g. if the threshold is 4, number 255 will be counted and 15 will not)
2. The function shall utilize as little memory as possible
3. The function shall return 0 on success and error code on error
4. The array elements are of a type 16-bit signed integer and an overflow during calculation shall be regarded as a failure
5. Use data types that ensure portability between different CPUs (so the calculations will be the same 
on 8/16/32-bit MCU)