.model small
.stack 100h
.data
ms1 db 'Nhap so thu nhat: $'
ms2 db 10, 13, 'Nhap so thu hai: $'
ms3 db 10, 13, 'Tong hai so la: $'
a   db 0
b   db 0

.code
main proc
    mov ax, @data
    mov ds, ax

    ; nhap so thu nhat

    mov ah, 09
    lea dx, ms1
    int 21h

    mov ah, 01
    int 21h
    sub al, 48
    mov bl, 10
    mul bl
    mov bx, ax

    mov ah, 01
    int 21h
    sub al, 48
    add bl, al
    mov a, bl

    ;nhap so thu hai

    mov ah, 09
    lea dx, ms2
    int 21h

    mov ah, 01
    int 21h
    sub al, 48
    mov bl, 10
    mul bl
    mov bl, al

    mov ah, 01
    int 21h
    sub al, 48
    add bl, al

    add bl, a

    ; tinh tong hai so

    mov ah, 09
    lea dx, ms3
    int 21h

    mov ah, 0
    mov al, bl
    mov bl, 10
    div bl
    mov a, ah

    mov ah, 2
    mov dl, al
    add dl, 48
    int 21h

    mov dl, a
    add dl, 48
    int 21h

    mov ah, 4ch
    int 21h

    main endp
end main