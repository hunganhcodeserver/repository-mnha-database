; Emu8086 - Hello
.model small
.stack 100h
.data
    ms1 db 'Nhap day so: $'
    ms2 db 10, 13, 'Day so vua nhap: $'
    ms3 db 10, 13, 'So chu so chan: $'
    ms4 db 10, 13 'So chu so le: $'
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
    ; Trạng thái trước lần lặp 1: SI = 0, BX = 0, CX = 20, s = [?, ?, ?, ...]
    mov ah, 1        ; đọc 1 ký tự, kết quả trong AL
        ; AH = 01h (chọn hàm đọc 1 ký tự)
    int 21h
        ; gõ '1' -> AL = 49 (31h)
    cmp al, 13       ; Enter thì dừng
        ; so 49 với 13 -> 49 ≠ 13 -> ZF = 0
        ;INT 21H ===> AH = 01H => trả mã ASCII ký tự đó vào AL
    je xong          ; Jump if Equal - Nhảy nếu bằng (điều kiện: cmp al, 13)
        ; ZF = 0 -> KHÔNG nhảy, chạy tiếp xuống dưới
    sub al, 48       ; ký tự -> giá trị số
        ; AL = 49 - 48 = 1
    mov [si], al     ; lưu vào mảng
        ; s[0] = 1 (ghi vào ô mà SI = 0 đang trỏ)
    inc si           ; si++
        ; SI = 0 + 1 = 1
    inc bx           ; bx++
        ; BX = 0 + 1 = 1
    loop nhap
        ; CX = 20 - 1 = 19, khác 0 -> quay lại nhap
    ; Trạng thái sau lần lặp 1: AL = 1, SI = 1, BX = 1, CX = 19, s = [1, ?, ?, ...]
    
xong:    
    mov ah, 4ch
    int 21h
main endp
end main
