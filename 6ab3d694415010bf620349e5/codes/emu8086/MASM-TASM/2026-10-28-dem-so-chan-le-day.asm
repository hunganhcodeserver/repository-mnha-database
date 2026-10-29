; Emu8086 - Hello
.model small
.stack 100h
.data
    ms1 db 'Nhap day so: $'
    ms2 db 10, 13, 'Day so vua nhap: $'
    ms3 db 10, 13, 'So chu so chan: $'
    ms4 db 10, 13, 'So chu so le: $'
    s db 21 dup(?)
    dem_chan db 0          ; so chu so chan
    dem_le   db 0          ; so chu so le
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
    mov ah, 1        ; AH = 01h (chọn hàm đọc 1 ký tự)
    int 21h          ; gõ '1' -> AL = 49 (31h)
    cmp al, 13       ; so 49 với 13 -> 49 ≠ 13 -> ZF = 0
    je xong          ; ZF = 0 -> KHÔNG nhảy, chạy tiếp xuống dưới
    sub al, 48       ; AL = 49 - 48 = 1
    mov [si], al     ; s[0] = 1 (ghi vào ô mà SI = 0 đang trỏ)
    inc si           ; SI = 0 + 1 = 1
    inc bx           ; BX = 0 + 1 = 1
    loop nhap        ; CX = 20 - 1 = 19, khác 0 -> quay lại nhap
    ; Trạng thái sau lần lặp 1: AL = 1, SI = 1, BX = 1, CX = 19, s = [1, ?, ?, ...]
    
xong:   
    ;thong bao xuat
    lea dx, ms2
    mov ah, 9
    int 21h
    
    ;xuat s[i]
    cmp bx, 0        ; không nhập gì thì khỏi in
    je thoat
    mov cx, bx       ; CX = số phần tử cần in
    lea si, s        ; SI quay lại đầu mảng s
    
xuat:
    mov dl, [si]     ; DL = s[SI]
    add dl, 48       ; số -> ký tự ASCII
    mov ah, 2        ; in ký tự trong DL
    int 21h
    inc si           ; SI++
    loop xuat        ; CX--, khác 0 thì in tiếp

thoat:
    mov ah, 4ch
    int 21h
main endp
end main



; ----------------------------------------------------------------------------------------------------------
; Thanh ghi | Đang giữ gì                                         | Dùng kiểm tra "có nhập gì không"?
; ----------------------------------------------------------------------------------------------------------
; SI        | Địa chỉ ô nhớ đang trỏ tới (ô ghi tiếp / ô '$')     | KHÔNG, SI là địa chỉ, không phải số lượng
; CX        | Bộ đếm của loop, đếm ngược từ 20                    | KHÔNG, không cho biết đã nhập bao nhiêu
; AL        | Ký tự vừa gõ (Enter = 13) / ký tự đang xét          | CÓ khi duyệt, AL = '$' ngay lần đầu là
;           | trong s / thương của DIV                            | chưa nhập gì
; AH        | Chọn hàm (01h, 09h, 02h); sau DIV là số dư          | KHÔNG, AH chỉ là số hiệu hàm hoặc số dư
; BL        | Số chữ số CHẴN đã đếm (inc bl)                      | KHÔNG, BL chỉ đếm chẵn, không đếm ký tự
; BH        | Số chữ số LẺ đã đếm (inc bh)                        | KHÔNG, BH chỉ đếm lẻ, không đếm ký tự
; DH        | Hàng đơn vị cất tạm khi in số                       | KHÔNG, DH chỉ là 1 chữ số cất tạm
; DL        | Ký tự cần in ra (hàm 02h, add dl, 30h)              | KHÔNG, DL chỉ là 1 ký tự đang in
; DX        | Địa chỉ chuỗi cần in (hàm 09h, lea dx, ...)         | KHÔNG, DX là địa chỉ chuỗi
; ----------------------------------------------------------------------------------------------------------
