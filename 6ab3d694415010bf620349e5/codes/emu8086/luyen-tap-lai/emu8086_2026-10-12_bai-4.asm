.model small
.stack 100h
.data
    ms1 db 'nhap so: $'
    ms2 db 10, 13, 'so vua nhap: $'

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov ah, 9
        lea dx, ms1
        int 21h

        mov bx, 0
    
    nhap:
        mov ah, 1 ;
        int 21h
        cmp al, 13
        je in_so
        sub al, 48 ;
        mov ah, 0
        mov cx, ax
        mov ax, bx
        mov bx, 10
        mul bx
        add ax, cx
        mov bx, ax
        jmp nhap

    in_so:
        mov ah, 9
        lea dx, ms2
        int 21h
        mov ax, bx
        mov cx, 0
        mov bx, 10

    chia:
        mov dx, 0           ; dx = 0 truoc khi chia
        div bx              ; ax = thuong, dx = du
        push dx             ; luu du vao stack
        inc cx              ; tang so chu so
        cmp ax, 0
        jne chia            ; lap lai neu ax != 0

    in_ra:
        pop dx              
        add dl, 48          ; chuyen so thanh ky tu
        mov ah, 2
        int 21h             ; in mot chu so
        loop in_ra          ; lap lai cho den khi cx = 0

        mov ah, 4ch
        int 21h
        main endp
    end main
