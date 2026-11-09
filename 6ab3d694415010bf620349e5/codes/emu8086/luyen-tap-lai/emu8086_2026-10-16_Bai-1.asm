.model small
.stack 100h
.data
    s db 20 dup(?)
    s1 db 20 dup(?)
    s2 db 20 dup(?)
    ms1 db 'nhap day ki tu : $'
    ms2 db 10, 13, 'day ki tu vua nhap la : $'
    ms3 db 10, 13, 'day chu hoa la : $'
    ms4 db 10, 13, 'day chu thuong la : $'

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov ah, 9
        lea dx, ms1
        int 21h
        lea si, s

    nhap:
        mov ah, 1
        int 21h
        cmp al, 13
        je xong_nhap
        mov [si], al
        inc si
        jmp nhap

    xong_nhap:
        mov byte ptr [si], '$'
        mov ah, 9
        lea dx, ms2
        int 21h
        lea dx, s
        int 21h

        lea si, s
        lea di, s2
        lea bx, s1

    duyet:
        mov al, [si]
        cmp al, '$'
        je xong_tach
        cmp al, 'a'
        jb hoa
        mov [bx], al
        inc bx
        jmp tiep

    hoa:
        mov [di], al
        inc di
    
    tiep:
        inc si
        jmp duyet

    xong_tach:
        mov byte ptr [di], '$'
        mov byte ptr [bx], '$'
        mov ah, 9
        lea dx, ms3
        int 21h
        lea dx, s2
        int 21h
        mov ah, 9
        lea dx, ms4
        int 21h
        lea dx, s1
        int 21h

        mov ah, 4ch
        int 21h

    main endp
end main