section .data
    a       dq      2.5
    b       dq      5.3
    c       dq      21.0
    
    fmt     db      "Input: %f, Result: %f", 10, 0

section .text
    global main
    extern printf

calculate_quadratic:
    push    rbp
    mov     rbp, rsp

    movsd   xmm1, [rel a] 
    mulsd   xmm1, xmm0
    mulsd   xmm1, xmm0

    movsd   xmm2, [rel b]
    mulsd   xmm2, xmm0

    addsd   xmm1, xmm2

    movsd   xmm2, [rel c]
    subsd   xmm1, xmm2

    movsd   xmm0, xmm1

    mov     rsp, rbp
    pop     rbp
    ret

main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16

    movsd   xmm0, [rel test_input]
    movsd   [rbp-8], xmm0

    call    calculate_quadratic
    
    movsd   [rbp-16], xmm0
    
    lea     rdi, [rel fmt]
    mov     rax, 2
    movsd   xmm0, [rbp-8]
    movsd   xmm1, [rbp-16]
    call    printf

    mov     rax, 0
    leave
    ret

section .data
    test_input  dq  4.0