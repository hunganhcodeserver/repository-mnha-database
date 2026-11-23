.model small
.stack 100h
.data
    ms1 db 'Nhap so nguyen n (3<=n<=5): $'
    n   db 3 dup(?)
    ms2 db 'Nhap cac so nguyen n (goi la s_n voi 1<=s_n<=9): $'
    sl  db 10 dup(?)
    sc  db 10 dup(?)
    ms3 db 10, 13, 'Tong so le: $'
    ms4 db 10, 13, 'Tong so chan: $'
    ms5 db 10, 13, 'Hieu SL-SC = $'

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

    lea si, sl
    lea di, sc
    xor bx, bx

nhap_s:
    mov ah, 1
    int 21h
    sub al, 48
    cmp al, 1
    jb nhap_s
    cmp al, 9
    ja nhap_s

    mov dh, al
    mov ah, 0
    mov dl, 2
    div dl          ; AX / DL: thuong o AL, so du o AH
    cmp ah, 0
    jne so_le       ; du khac 0 thi la so le

    mov [di], dh    ; so chan: cat vao mang sc
    inc di
    add bh, dh      ; cong vao tong chan
    jmp tiep        ; nhay qua nhanh le

so_le:
    mov [si], dh    ; so le: cat vao mang sl
    inc si
    add bl, dh      ; cong vao tong le

tiep:
    loop nhap_s

    ; in tong so le
    mov ah, 9
    lea dx, ms3
    int 21h
    mov al, bl
    call in_so

    ; in tong so chan
    mov ah, 9
    lea dx, ms4
    int 21h
    mov al, bh
    call in_so

    ; in hieu SL - SC
    mov ah, 9
    lea dx, ms5
    int 21h
    cmp bl, bh
    jae duong           ; SL >= SC: hieu khong am

    mov ah, 2
    mov dl, '-'
    int 21h
    mov al, bh
    sub al, bl
    jmp in_hieu

duong:
    mov al, bl
    sub al, bh

in_hieu:
    call in_so

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

; In so trong AL (0..99) ra man hinh
in_so proc
    push ax
    push bx
    push dx             ; cat AX, BX, DX
    mov ah, 0           ; xoa AH truoc div
    mov bl, 10          ; so chia
    div bl              ; AL = chuc, AH = don vi
    mov bh, ah          ; cat don vi sang BH
    cmp al, 0           ; chuc = 0?
    je donvi            ; bo so 0 dau
    mov dl, al
    add dl, 30h         ; so thanh ky tu
    mov ah, 2
    int 21h             ; in chu so chuc
donvi:
    mov dl, bh
    add dl, 30h
    mov ah, 2
    int 21h             ; in chu so don vi
    pop dx              ; pop nguoc thu tu push
    pop bx
    pop ax
    ret
in_so endp

end main