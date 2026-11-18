.model small
.stack 100h
.data
ms1 db 'Nhap so thu nhat: $'
ms2 db 10, 13, 'Nhap so thu hai: $'
ms3 db 10, 13, 'Tong hai so la: $'

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
    mov bl, al

    mov ah, 01
    int 21h
    sub al, 48
    add bl, al

    ;nhap so thu hai

    mov ah, 09
    lea dx, ms2
    int 21h

    mov ah, 01
    int 21h
    sub al, 48
    mov bh, 10
    mul bh
    mov bh, al

    mov ah, 01
    int 21h
    sub al, 48
    add bh, al

    add bl, bh

    ; tinh tong hai so

    mov ah, 09
    lea dx, ms3
    int 21h

    mov ah, 0
    mov al, bl
    mov bh, 10
    div bh
    mov bh, ah

    mov ah, 2
    mov dl, al
    add dl, 48
    int 21h

    mov dl, bh
    add dl, 48
    int 21h

    mov ah, 4ch
    int 21h

    main endp
end main