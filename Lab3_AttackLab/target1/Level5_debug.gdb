   file rtarget
   set args -i Level5_raw.txt
   
   # 设置关键断点
   break getbuf
   break *getbuf+17   # getbuf的ret指令前
   break *0x401a19    # 第一个gadget
   break *0x4019cc    # 第二个gadget
   break *0x4019a2    # 第三个gadget
   break touch3
   
   # 运行程序
   run
   
   # getbuf断点处
   info registers rsp
   x/40gx $rsp
   x/40bx $rsp       # 以字节形式查看
   
   # 继续执行到ret指令前
   continue
   info registers rsp
   x/40gx $rsp
   
   # 继续执行到第一个gadget
   stepi
   info registers rsp rip rax
   x/10gx $rsp
   
   # 执行mov %rsp,%rax
   stepi
   info registers rsp rax
   
   # 执行第一个gadget的ret
   stepi
   info registers rsp rip
   x/10gx $rsp
   
   # 继续执行pop %rax
   continue
   info registers rsp rax
   
   # 执行pop
   stepi
   info registers rsp rax
   
   # 执行ret
   stepi
   info registers rsp rip
   
   # 继续到第三个gadget
   continue
   info registers rsp rax rdi
   
   # 执行mov %rax,%rdi
   stepi
   info registers rdi
   
   # 执行ret
   stepi
   info registers rip
   
   # 继续到touch3
   continue
   info registers rdi
   x/s $rdi
   
   quit