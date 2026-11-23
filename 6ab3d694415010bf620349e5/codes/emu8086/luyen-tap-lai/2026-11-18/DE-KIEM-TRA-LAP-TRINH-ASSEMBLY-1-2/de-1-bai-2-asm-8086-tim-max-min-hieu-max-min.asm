.model small
.stack 100h
.data
    ms1 db 'Nhap n so nguyen n (3<=n<=5): $'
    n   db 3 dup('$')
    ms2 db 'Nhap cac so nguyen n (goi la s_n voi 1<=s_n<=9): $'
    ms3 db 'Max = $'
    ms4 db 'Min = $'
    ms5 db 'Max - Min = $'

.code
main proc
    mov ax, @data
    mov ds, ax 

nhap_lai:
    mov ah, 9
    lea dx, ms1
    int 21h

    lea bx, n

nhap_n:
    mov ah, 1
    int 21h
    cmp al, 13
    je xong_n
    mov [bx], al 
    jmp nhap_n

xong_n:
    call xuong_dong
    mov al, n
    sub al, 48
    cmp al, 3
    jb nhap_lai
    cmp al, 5 
    ja nhap_lai
    mov cl, al 
    mov ch, 0 

    mov ah, 9 
    lea dx, ms2
    int 21h 
    call xuong_dong

    mov bl, 0
    mov bh, 9

nhap_s:
    mov ah, 1 
    int 21h
    sub al, 48
    cmp al, 1 
    jb nhap_s
    cmp al, 9 
    ja nhap_s

    cmp al, bl  
    jbe khong_max
    mov bl, al 

khong_max:
    cmp al, bh 
    jae khong_min 
    mov bh, al  

khong_min:
    call xuong_dong
    loop nhap_s

    ; in max
    mov ah, 9
    lea dx, ms3
    int 21h
    mov dl, bl
    add dl, 48
    mov ah, 2
    int 21h
    call xuong_dong

    ; in min
    mov ah, 9
    lea dx, ms4
    int 21h
    mov dl, bh
    add dl, 48
    mov ah, 2
    int 21h
    call xuong_dong

    ; in max - min
    mov ah, 9
    lea dx, ms5
    int 21h

    mov dl, bl 
    sub dl, bh 
    add dl, 48

    mov ah, 2
    int 21h
    call xuong_dong

    mov ah, 4ch
    int 21h
main endp

xuong_dong proc 
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    ret
xuong_dong endp

end main