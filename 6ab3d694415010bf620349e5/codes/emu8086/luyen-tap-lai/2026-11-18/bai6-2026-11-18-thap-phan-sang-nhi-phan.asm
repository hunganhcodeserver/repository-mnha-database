.model small
.stack 100h
.data
  ms1 db 'nhap so thap phan: $'
  ms2 db 'so nhi phan: $'
.code
main proc
  mov ax, @data
  mov ds, ax  ; nạp DS

  mov ah, 9
  lea dx, ms1
  int 21h     ; in lời nhắc nhập
  xor bx, bx  ; BX = 0
nhap:
  mov ah, 1
  int 21h     ; AL = ký tự
  cmp al, 13    ; là Enter?
  je xong_nhap  ; đúng thì dừng nhập
  sub al, 48    ; '0'..'9' thành 0..9
  mov ah, 0     ; xoá AH
  mov cx, ax    ; CX = chữ số mới
  mov ax, 10    ; AX = 10
  mul bx        ; DX:AX = AX x BX
  add ax, cx    ; cộng chữ số mới
  mov bx, ax    ; lưu lại vào BX
  jmp nhap      ; đọc ký tự kế tiếp
xong_nhap:
  call xuong_dong
  mov ah, 9
  lea dx, ms2
  int 21h       ; in 'so nhi phan: '
  mov ax, bx    ; AX = số cần đổi
  mov bx, 2     ; BX = số chia
  xor cx, cx    ; CX = 0 (đếm bit)
chia_2:
  xor dx, dx   ; DX = 0 trước khi chia
  div bx       ; AX = thương, DX = dư
  push dx      ; cất số dư (0 hoặc 1)
  inc cx       ; đếm thêm 1 bit
  cmp ax, 0    ; thương còn khác 0?
  jne chia_2   ; còn thì chia tiếp

in_bit:
  pop dx       ; lấy bit ra
  add dl, 48   ; 0/1 thành '0'/'1'
  mov ah, 2    ; hàm 2: in DL
  int 21h
  loop in_bit  ; CX-1, khác 0 thì lặp
  call xuong_dong
  mov ah, 4ch
  int 21h      ; thoát về DOS
main endp
xuong_dong proc
  push ax
  push dx
  mov ah, 2
  mov dl, 13  ; về đầu dòng
  int 21h
  mov dl, 10  ; xuống dòng
  int 21h
  pop dx
  pop ax
  ret
xuong_dong endp
end main
