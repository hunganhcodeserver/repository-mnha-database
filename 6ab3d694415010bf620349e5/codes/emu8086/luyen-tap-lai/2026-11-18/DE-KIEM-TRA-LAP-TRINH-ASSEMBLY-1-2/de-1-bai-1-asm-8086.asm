.model small
.stack 100h
.data
   ms1 db 'Ho ten ban la: $' 
   ht  db 30 dup('$') ; khai bao mang chua 30 ky tu
   ;ht[0] -> ht[29] la 30 ky tu
   ms2 db 10, 13, 'Chao ban $'
   ms3 db ', chuc ban thanh cong!$'

.code
main proc

    mov ax, @data
    mov ds, ax

    mov ah, 9
    lea dx, ms1
    int 21h
    
    ; nhap ho ten tu ban phim
    lea bx, ht

nhap:
    mov ah, 1
    int 21h
    cmp al, 13 ; kiem tra phim Enter
    je xong
    mov [bx], al
    inc bx
    jmp nhap

xong:
    ;in ms2
    mov ah, 9
    lea dx, ms2
    int 21h

    ; in ho ten vua nhap
    mov ah, 9
    lea dx, ht
    int 21h

    ; in ms3
    mov ah, 9
    lea dx, ms3
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main