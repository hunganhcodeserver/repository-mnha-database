.model small
.stack 100h
.data
    s db 21 dup(?)
    s1 db 21 dup(?)
    s2 db 21 dup(?)
    s3 db 21 dup(?)
    ms1 db 'nhap day ki tu : $'
    ms2 db 10, 13, 'day ki tu vua nhap la : $'
    ms3 db 10, 13, 'day chu hoa la : $'
    ms4 db 10, 13, 'day chu hoa la : khong co$'
    ms5 db 10, 13, 'day chu thuong la : $'
    ms6 db 10, 13, 'day chu thuong la : khong co$'
    ms7 db 10, 13, 'day chu so la : $'
    ms8 db 10, 13, 'day chu so la : khong co$'
    ms9 db 10, 13, 'so chu hoa la : $'
    ms10 db 10, 13, 'so chu thuong la : $'
    ms11 db 10, 13, 'so chu so la : $'

.code
    main proc

        mov ax, @data
        mov ds, ax

        mov ah, 9
        lea dx, ms1
        int 21h
        xor si, si

    nhap1:
        mov ah, 1
        int 21h
        cmp al, 13
        je stop1
        mov s[si], al
        inc si
        cmp si, 20
        je stop1
        jmp nhap1

    stop1:
        mov s[si], '$'
        mov cx, si
        mov ah, 9
        lea dx, ms2
        int 21h
        lea dx, s
        int 21h

    locchuhoa:
        xor si, si  ;doc s
        xor di, di  ;ghi s2
    
    lochoa:
        cmp si, cx
        jae stop2
        mov al, s[si]
        cmp al, 'A'
        jb boquahoa
        cmp al, 'Z'
        ja boquahoa
        mov s2[di], al
        inc di

    boquahoa:
        inc si
        jmp lochoa

    stop2:
        mov s2[di], '$'
        cmp di, 0
        je khongcochuhoa
        mov ah, 9
        lea dx, ms3
        int 21h
        lea dx, s2
        int 21h
        jmp sochuhoa

    khongcochuhoa:
        mov ah, 9
        lea dx, ms4
        int 21h

    sochuhoa:
        mov ah, 9
        lea dx, ms9
        int 21h
        mov ax, di
        call in_so

    locchuthuong:
        xor si, si  ;doc s
        xor di, di  ;ghi s1
    
    locthuong:
        cmp si, cx
        jae stop3
        mov al, s[si]
        cmp al, 'a'
        jb boquathuong
        cmp al, 'z'
        ja boquathuong
        mov s1[di], al
        inc di

    boquathuong:
        inc si
        jmp locthuong

    stop3:
        mov s1[di], '$'
        cmp di, 0
        je khongcochuthuong
        mov ah, 9
        lea dx, ms5
        int 21h
        lea dx, s1
        int 21h
        jmp sochuthuong

    khongcochuthuong:
        mov ah, 9
        lea dx, ms6
        int 21h

    sochuthuong:
        mov ah, 9
        lea dx, ms10
        int 21h
        mov ax, di
        call in_so

    locchuso:
        xor si, si  ;doc s
        xor di, di  ;ghi s3

    locso:
        cmp si, cx
        jae stop4
        mov al, s[si]
        cmp al, '0'
        jb boquaso
        cmp al, '9'
        ja boquaso
        mov s3[di], al
        inc di

    boquaso:
        inc si
        jmp locso

    stop4:
        mov s3[di], '$'
        cmp di, 0
        je khongcochuso
        mov ah, 9
        lea dx, ms7
        int 21h
        lea dx, s3
        int 21h
        jmp sochuso

    khongcochuso:
        mov ah, 9
        lea dx, ms8
        int 21h

    sochuso:
        mov ah, 9
        lea dx, ms11
        int 21h
        mov ax, di
        call in_so

        mov ah, 4ch
        int 21h

    main endp

    in_so proc
        push ax
        push bx
        push cx
        mov ah, 0
        mov bl, 10
        div bl
        mov bh, ah
        cmp al, 0
        je donvi
        mov dl, al
        add dl, 30h
        mov ah, 2
        int 21h

    donvi:
        mov dl, bh
        add dl, 30h
        mov ah, 2
        int 21h
        pop cx
        pop bx
        pop ax
        ret
    in_so endp

end main