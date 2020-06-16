ldr R0, =n
ldr R1,[R0]
sub R2, R1, #1
ldr R3, =arr

mov R5,#0

outerLoop:
mov R6,#0
mov R4, R3
sub R7, R1, R5
sub R7, R7 ,#1

innerLoop:
cmp R6,R7
beq end
add R6, R6, #1
ldr R8, [R4]
ldr R9, [R4, #4]
add R4, R4, #4
cmp R8,R9 
blt innerLoop
sub R4, R4, #4
str R9, [R4]
str R8, [R4,#4]
add R4, R4, #4
cmp R6,R7
bne innerLoop

end:
add R5, R5, #1
cmp R5, R2
blt outerLoop

mov R2, #0

mem:
ldr R8, [R3]
add R2, R2, #1
add R3, R3, #4
cmp R2, R1
blt mem



.data
n: .word 100
arr: .word 33,2,26,30,54,4,81,56,23,47,43,39,95,31,28,80,94,70,98,93,14,92,63,89,74,44,85,27,52,40,3,58,91,79,64,19,66,68,48,88,61,16,97,65,87,99,9,69,84,86,42,34,5,53,10,82,36,1,25,22,59,32,17,29,37,12,51,55,50,11,75,41,77,0,67,76,46,62,71,83,20,96,7,78,24,45,6,90,38,49,60,13,15,73,57,72,8,18,21,35 
.end
