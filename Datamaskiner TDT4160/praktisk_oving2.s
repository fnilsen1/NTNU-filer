#a0: største divisor < A
#a1:1 hvis A er et kvadrattall, 0 ellers
#a2: input int A
#a3: heltall vi sjekker om er divisor
#a4: rest
#a5: største divisor^2
#a6: heltall vi sjekker om passer inn i n^2
#Plan: dele på minste faktor for å få største faktor

#Kommenter ut linje
    #li a0, 676
    mv a2, a0
    li a0, 1
    li a3, 1
    li a6, 1
    
forLokke:
    addi a3, a3, 1
    rem a4, a2, a3
    beq a4, x0, hvisFaktor
    blt a3, a2, forLokke
    
#Litt random at dette funker lmao cuz A/A = 1
hvisFaktor:
    div a0, a2, a3

#jal x0, Ferdig
    
whileLokke:
    addi a6, a6, 1
    mul a5, a6, a6
    beq a5, a2, erKvadrattall
    bgt a5, a2, Ferdig
    blt a6, a2, whileLokke

erKvadrattall:
    li a1, 1

Ferdig:
    nop


    



    