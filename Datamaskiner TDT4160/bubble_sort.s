#li a0, 4
#li a1, 15
#li a2, 6
#li a3, 10
#li a4, 20
#li a5, 9

li a6, 0
li a7, 5
#a6: nåværende iterasjon
#a7: antall iterasjoner 
#Vi swapper s0 og s1
#
#
#
j Loop

swap_check:
    blt s0, s1, No_swap
    mv s2, s0
    mv s0, s1
    mv s1, s2
    
No_swap:
    ret
    
Loop:
    mv s0, a0
    mv s1, a1
    call swap_check
    mv a0, s0
    mv a1, s1 
    
    mv s0, a1
    mv s1, a2
    call swap_check
    mv a1, s0
    mv a2, s1     
    
    mv s0, a2
    mv s1, a3
    call swap_check
    mv a2, s0
    mv a3, s1
    
    mv s0, a3
    mv s1, a4
    call swap_check
    mv a3, s0
    mv a4, s1
    
    mv s0, a4
    mv s1, a5
    call swap_check
    mv a4, s0
    mv a5, s1    
    
    addi a6, a6, 1
    blt a6, a7, Loop

Finished:
    nop