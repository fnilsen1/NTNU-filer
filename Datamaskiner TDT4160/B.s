start:
    li a0, 5
    li a1, 7
    li a2, 40
    li a3, 60
    
    addi a1, a1, 3    # a1 = 7 + 3 = 10

    nop               # Sett inn en NOP for � unng� hazard
    nop               # Ekstra NOP for � gi tid til at addi fullf�rer

    add a0, a1, a2    # a0 = a1 + a2 = 10 + 40 = 50

    nop               # Sett inn en NOP for � unng� hazard
    nop               # Ekstra NOP for � gi tid til at add fullf�rer

    sub a0, a3, a0    # a0 = a3 - a0 = 60 - 50 = 10