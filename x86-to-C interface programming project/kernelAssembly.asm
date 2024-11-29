; kernel x86-64 assembly language version

section .text
bits 64
default rel

global assemblyKernel

assemblyKernel:
	xorps xmm2, xmm2	; set value to 0.0 -> sdot

; xmm0 -> first fp argument -> contains answer
; xmm1 -> second fp argument
; xmm2 -> third fp argument
; xmm3 -> fourth fp argument

; n -> rcx
; A -> address of rdx -> xmm0
; B -> address of r8 -> xmm1
; sdot -> address of r9 -> xmm2

dot_product:
	movsd xmm0, [rdx]	; A
	movsd xmm1, [r8]	; B
	mulsd xmm0, xmm1	; A <- A * B
	addsd xmm2, xmm0	; sdot += (A*B)

	add rdx, 8			; double is 8 bytes
	add r8, 8

	loop dot_product


	movsd [r9], xmm2	; place sdot value into address

	ret



	
