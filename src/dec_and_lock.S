ffffffff801f6c58 <_atomic_dec_and_lock>:
ffffffff801f6c58:	55               push   %rbp
ffffffff801f6c59:	48 89 f5         mov    %rsi,%rbp
ffffffff801f6c5c:	53               push   %rbx
ffffffff801f6c5d:	48 89 fb         mov    %rdi,%rbx
ffffffff801f6c60:	48 83 ec 08      sub    $0x8,%rsp
ffffffff801f6c64:	8b 37            mov    (%rdi),%esi
ffffffff801f6c66:	83 fe 01         cmp    $0x1,%esi
ffffffff801f6c69:	74 18            je     ffffffff801f6c83 <_atomic_dec_and_lock+0x2b>
ffffffff801f6c6b:	8d 46 ff         lea    -0x1(%rsi),%eax
ffffffff801f6c6e:	48 63 ce         movslq %esi,%rcx
ffffffff801f6c71:	48 63 f8         movslq %eax,%rdi
ffffffff801f6c74:	48 89 c8         mov    %rcx,%rax
ffffffff801f6c77:	f0 0f b1 3b      lock cmpxchg %edi,(%rbx)
ffffffff801f6c7b:	39 c6            cmp    %eax,%esi
ffffffff801f6c7d:	74 22            je     ffffffff801f6ca1 <_atomic_dec_and_lock+0x49>
ffffffff801f6c7f:	89 c6            mov    %eax,%esi
ffffffff801f6c81:	eb e3            jmp    ffffffff801f6c66 <_atomic_dec_and_lock+0xe>
ffffffff801f6c83:	48 89 ef         mov    %rbp,%rdi
ffffffff801f6c86:	e8 30 4f 0f 00   callq  ffffffff802ebbbb <_spin_lock>
			...
