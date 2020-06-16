ldr r0, =n
ldr r1, [r0]
ldr r2, =arr
sub r4, r1, #1

mov r13, #4
mov r3, #0

outerLoop:
mov r5, r3
add r6, r3, #1

innerLoop:
cmp r6, r1
beq end
mul r9, r6, r13
ldr r7, [r2, r9]
mul r9, r5, r13
ldr r8, [r2, r9]
add r6, r6, #1
cmp r8,r7
blt innerLoop
sub r6, r6, #1
mov r5, r6
add r6, r6, #1
cmp r6, r1
bne innerLoop

end:
mul r9, r5, r13
ldr r7, [r2, r9]
mul r10, r3, r13
ldr r8, [r2, r10]
str r7, [r2,r10]
str r8, [r2,r9]
add r3, r3, #1
cmp r3, r4
blt outerLoop

mem:
ldr r9, [r2]
sub r1, r1, #1
add r2, r2, #4
cmp r1, #0
bne mem

.data
n: .word 100
arr: .word 33,2,26,30,54,4,81,56,23,47,43,39,95,31,28,80,94,70,98,93,14,92,63,89,74,44,85,27,52,40,3,58,91,79,64,19,66,68,48,88,61,16,97,65,87,99,9,69,84,86,42,34,5,53,10,82,36,1,25,22,59,32,17,29,37,12,51,55,50,11,75,41,77,0,67,76,46,62,71,83,20,96,7,78,24,45,6,90,38,49,60,13,15,73,57,72,8,18,21,35
.end
