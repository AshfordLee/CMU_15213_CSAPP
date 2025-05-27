/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~(x & ~y) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int y=x+1;
  return !(y^~x) & !!y;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mapcode=0xAA;
  mapcode=(mapcode<<8) | mapcode;
  mapcode=(mapcode<<16) | mapcode;

  return !((x&mapcode)^mapcode);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int upperbound=0x39;
  int lowerbound=0x30;

  int sign1=x+~lowerbound+1;
  int sign2=upperbound+~x+1;

  int bound1=sign1>>31;
  int bound2=sign2>>31;

  return !bound1&!bound2;

  
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask=!x;
  mask=~mask+1;

  return (~mask & y) | (mask & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

  int sx=(x>>31)&1;
  int sy=(y>>31)&1;

  int diff_sign=sx^sy;
  
  int sd=((y+(~x+1))>>31)&1;

  return (diff_sign&sx)|((!diff_sign)&!sd);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int minusx=~x+1;
  int signx=x>>31;
  int signminusx=minusx>>31;
  return ~((signx|signminusx)) & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    // 1. 把 x 统一为“正数”：若 x<0，则 mask = ~x，否则 mask = x
    int sign = x >> 31;
    int mask = x ^ sign;
    int nz_mask;
    int z_mask;
    int nonzero;
    int zero;

    // 2. 二分法累加 floor(log2(mask))
    int bits = 0, shiftAmt;

    shiftAmt = (!!(mask >> 16)) << 4; bits += shiftAmt; mask >>= shiftAmt;
    shiftAmt = (!!(mask >> 8))  << 3; bits += shiftAmt; mask >>= shiftAmt;
    shiftAmt = (!!(mask >> 4))  << 2; bits += shiftAmt; mask >>= shiftAmt;
    shiftAmt = (!!(mask >> 2))  << 1; bits += shiftAmt; mask >>= shiftAmt;
    shiftAmt = (!!(mask >> 1));       bits += shiftAmt; mask >>= shiftAmt;

    // 3. 构造全 1 或全 0 的掩码，替代之前的乘法
    nonzero = !!mask;           // mask != 0 ? 1 : 0
    nz_mask = ~nonzero + 1;     // nonzero=1 -> 0xFFFFFFFF；nonzero=0 -> 0x0
    zero = !mask;               // mask == 0 ? 1 : 0
    z_mask = ~zero + 1;         // zero=1 -> 0xFFFFFFFF；zero=0 -> 0x0

    // mask != 0 时返回 bits+2；mask == 0 时返回 1
    return (nz_mask & (bits + 2)) | (z_mask & 1);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {

  unsigned sign=uf & 0x80000000;
  unsigned exp=(uf>>23) & 0xFF;
  unsigned frac=uf & 0x7FFFFF;

  if (exp==0xFF)
  {
    return uf;
  }

  if (exp==0)
  {
    frac=frac<<1;
    return sign | frac;
  }
 
  exp=exp+1;

  if (exp==0xFF)
  {
    return sign | 0x7F800000;
  }

  return sign | (exp<<23) | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    // 提取符号位、指数位和尾数位
    int sign = (uf >> 31) & 1;
    int exp = ((uf >> 23) & 0xFF) - 127;  // 减去偏置值
    int frac = uf & 0x7FFFFF;
    int result;
    
    // 处理特殊情况
    if (exp == 128) {  // NaN 或无穷大
        return 0x80000000u;
    }
    
    if (exp < 0) {  // 小于1的数
        return 0;
    }
    
    if (exp > 30) {  // 超出整数范围
        return 0x80000000u;
    }
    
    // 构造整数
    result = (1 << 23) | frac;  // 添加隐含的1
    
    // 根据指数调整
    if (exp < 23) {
        result >>= (23 - exp);  // 右移
    } else {
        result <<= (exp - 23);  // 左移
    }
    
    // 处理符号
    return sign ? -result : result;
}
/* 
 *   floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    // 处理特殊情况
    int exp;
    if (x > 127) {  // 超出规格化数范围
        return 0x7F800000;  // 返回正无穷
    }
    
    if (x < -149) {  // 超出非规格化数范围
        return 0;  // 返回0
    }
    
    // 处理非规格化数
    if (x < -126) {  // 在非规格化数范围内
        int shift = 23 + (x + 126);  // 计算需要左移的位数
        return 1 << shift;
    }
    
    // 处理规格化数
    exp = x + 127;  // 加上偏置值
    return exp << 23;  // 构造浮点数表示
}
