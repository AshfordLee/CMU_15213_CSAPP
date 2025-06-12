1    movl   8(%ebp), %ecx       # ECX ← a      （从栈帧读取第一个参数 a）
2    movl  12(%ebp), %esi       # ESI ← b      （第二个参数 b）
3    cmpl   %esi, %ecx          # 比较 a − b，更新 EFLAGS
4    setl   %al                 # t1 = (a < b)?1:0  （signed less → AL）
5    cmpl   %ecx, %esi          # 比较 b − a，更新 EFLAGS
6    setb  -1(%ebp)             # t2 = (b < a)?1:0  （unsigned below → 存到 [EBP−1]）

7    cmpw   %cx,16(%ebp)        # 比较 c (stack@16) − (a mod 2^16)，更新 EFLAGS
8    setge -2(%ebp)             # t3 = (c ≥ a)?1:0  （signed ≥ → 存到 [EBP−2]）

9    movb   %cl, %dl            # 把 a 的低 8 位(CL) 复制到 DL
10   cmpb  16(%ebp), %dl        # 比较 c (low8) − DL(a low8)，更新 EFLAGS
11   setne  %bl                 # t4 = (a≠c)?1:0  （not equal → BL）

12   cmpl   %esi,16(%ebp)       # 比较 c − b，更新 EFLAGS
13   setg  -3(%ebp)             # t5 = (c > b)?1:0  （signed greater → 存到 [EBP−3]）

14   testl  %ecx, %ecx          # 测试 a 本身：设置 ZF 和 SF
15   setg   %dl                 # t6 = (a > 0)?1:0  （signed greater than zero → DL）

16   addb  -1(%ebp), %al    # AL += t2
17   addb  -2(%ebp), %al    # AL += t3
18   addb   %bl,     %al    # AL += t4
19   addb  -3(%ebp), %al    # AL += t5
20   addb   %dl,     %al    # AL += t6
21   movsbl %al, %eax       # 把 AL (signed byte) 符号扩展到 EAX
