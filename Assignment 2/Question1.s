.data
    array:      .word   11, 10, 8, 7, 5, 4, 2, 0, 1, 33
    array_size: .word   10
    info:  .asciiz "\nReuben Devanesan, 19110059 \nQuestion 1 (MIPS) \n"
    array_highest:  .asciiz "\nHighest Value: " 
    array_lowest:  .asciiz "\nLowest Value: "
    average:  .asciiz "\nAverage: "

.text
.globl main

main:   
    la $a0, array
    lw $a1, array_size
    lw $t2, ($a0)           # Highest Value
    lw $t3, ($a0)           # Lowest Value
    li $t4, 0               # sum

loop:
    beq $a1, $zero, end
    lw $t0, ($a0)
    add $t4, $t4, $t0
    bge $t0, $t3, not_lowest 
    move $t3, $t0
    not_lowest:
    ble $t0, $t2, not_highest 
    move $t2, $t0
    not_highest:
    addi $a1, $a1, -1
    addi $a0, $a0, 4
    j loop

end:
    li $v0, 4
    la $a0, info
    syscall

    li $v0, 4
    la $a0, array_highest
    syscall
    li $v0, 1
    move $a0, $t2
    syscall 

    li $v0, 4
    la $a0, array_lowest
    syscall
    li $v0, 1
    move $a0, $t3
    syscall 

    div $t4, $t4, 10
    li $v0, 4
    la $a0, average
    syscall
    li $v0, 1
    move $a0, $t4
    syscall 