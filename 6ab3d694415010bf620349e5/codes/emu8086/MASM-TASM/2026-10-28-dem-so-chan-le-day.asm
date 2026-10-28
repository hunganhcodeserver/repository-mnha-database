; Emu8086 - Hello
.model small
.stack 100h
.data
    ms1 db 'Nhap day so: $'
    ms2 db 10, 13, 'Day so vua nhap: $'
    ms3 db 10, 13, 'Tong chu so chan: $'
    ms4 db 10, 13 'Tong chu so le: $'
    s db 21 dup(?)
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ;thong bao nhap
    lea dx, ms1
    mov ah, 9
    int 21h
    
    ;tao s[i]
    lea si, s        ; si trỏ đầu mảng s
    mov cx, 20       ; tối đa 20 ký tự
    xor bx, bx       ; bx = số ký tự đã nhập
    
nhap:
    mov ah, 1        ; đọc 1 ký tự, kết quả trong AL
    int 21h
    cmp al, 13       ; Enter thì dừng
    ;INT 21H ===> AH = 01H => trả mã ASCII ký tự đó vào AL
    je xong          ;Jump if Equal - Nhảy nếu bằng (điều kiện: cmp al, 13)
    
xong:    
    mov ah, 4ch
    int 21h
main endp
end main
