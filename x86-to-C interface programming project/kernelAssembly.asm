; kernel x86-64 assembly language version

section .data
ans dq 0.0

section .text
bits 64
default rel

global callAssembly

callAssembly:
    movsd xmm3, [ans]
L1:
    movsd xmm1, [rdx]
    movsd xmm2, [r8]
    
    mulsd xmm1, xmm2
    addsd xmm3, xmm1
    
    add rdx, 8
    add r8, 8
    loop L1
    
    movsd [r9], xmm3
    ret 