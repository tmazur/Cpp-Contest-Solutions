#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // for malloc

/**
 * @brief Results for sum_filtered()
 */
enum sum_filtered_result {
    SUCCESS = 0, /**< Sum calculation was successful */
    OVERFLOW,    /**< Sum overflowed */
};

/**
* @brief prints the sum of @p nums that meet the criteria
* 
* Criteria:
* 1. Number in binary representation has more than threshold 'ones'
* 2. Sum fits in signed 16bit type
* @param[in] nums      array of numbers
* @param[in] length    @p nums array length
* @param[in] threshold number of 'ones' in binary representation to meet criteria
* @return error code or 0 if OK @see sum_filtered_result
*/
int16_t sum_filtered(int16_t* nums, int16_t length, int16_t threshold) {
    int16_t number = 0; /**< stores currently proccessed number */ 
    int16_t sum = 0;
    int16_t ones_count = 0; /**< 'ones' count for currently proccessed number */
    int16_t i;
    
    for(i=0; i<length; ++i) {
        ones_count = 0;
        number = nums[i];
        
        while(0 != number) { /**< stop processing when all bits equal 0 */
            if(number & 1) { /**< check LS bit */
                if(++ones_count > threshold) { /**< number mets threshold */
                    if (sum > 0 && nums[i] > INT16_MAX - sum ||
                        sum < 0 && nums[i] < INT16_MIN - sum) { /**< overflow */
                        return OVERFLOW;
                    }
                    sum += nums[i];
                    break; /**< process next number */
                }
            }
            number = number >> 1; /**< discard LS bit */
        }
    }
    printf("%d\n", sum);
    return SUCCESS;
}

int main(void) {
    int n;
    int* numbers;
    int ret;
    
    scanf("%d", &n);
    if(n > 0) {
        numbers = malloc(n);
        if(numbers) {
            int i;
            for(i=0; i<n; i++) {
                scanf("%d", &numbers[i]);
                // printf("element %d=%d\n", i, numbers[i]);
            }
            
        }
    }
    
    ret = sum_filtered(numbers, n, 4);
    printf("return value = %d\n", ret);
    return 0;
}


int main(void) {
    int n;
    int* numbers;
    int ret;
    
    scanf("%d", &n);
    if(n > 0) {
        numbers = malloc(n);
        if(numbers) {
            int i;
            for(i=0; i<n; i++) {
                scanf("%d", &numbers[i]);
                // printf("element %d=%d\n", i, numbers[i]);
            }
            
        }
    }
    
    ret = sum_filtered(numbers, n, 4);
    printf("return value = %d\n", ret);
    return 0;
}
