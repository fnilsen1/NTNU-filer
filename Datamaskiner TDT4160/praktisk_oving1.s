    add x5, a0, a1
    add x6, a2, a3
    add x7, a4, a5

    bge x5, x6, firstComparison
    add a0, x0, x6
    bge x7, x6, thirdComparison
    jal, x0, Ferdig
    
firstComparison:
    add a0, x0, x5
    bge x7, x5, secondComparison
    jal, x0, Ferdig

secondComparison:
    add a0, x0, x7
    jal, x0, Ferdig
    
thirdComparison:
    add a0, x0, x7
    jal, x0, Ferdig

Ferdig:
    nop