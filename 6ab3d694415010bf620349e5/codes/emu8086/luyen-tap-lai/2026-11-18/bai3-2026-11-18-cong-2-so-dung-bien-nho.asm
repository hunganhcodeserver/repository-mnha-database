.model small
.stack 100h
.data
  ms1 db 'nhap so thu nhat: $'
  ms2 db 10, 13, 'nhap so thu hai: $'
  ms3 db 10, 13, 'tong hai so: $'

  a  db 0     ; số thứ nhất, rồi số dư
  b  db 0     ; khai báo, không dùng
.code
main proc
  mov ax, @data
  mov ds, ax  ; nạp DS
  mov ah, 9
  lea dx, ms1
  int 21h     ; in lời nhắc 1
  mov ah, 1
  int 21h     ; AL = ký tự hàng chục
  sub al, 48
  mov bl, 10
  mul bl      ; AX = chục x 10
  mov bx, ax  ; BL = chục x 10
  mov ah, 1
  int 21h     ; AL = ký tự hàng đơn vị
  sub al, 48
  add bl, al  ; BL = số thứ nhất
  mov a, bl   ; cất vào biến a
  mov ah, 9
  lea dx, ms2
  int 21h     ; in lời nhắc 2
  mov ah, 1
  int 21h     ; AL = ký tự hàng chục
  sub al, 48
  mov bl, 10
  mul bl      ; AX = chục x 10
  mov bl, al  ; BL = chục x 10
  mov ah, 1
  int 21h     ; AL = ký tự hàng đơn vị
  sub al, 48
  add bl, al  ; BL = số thứ hai

  add bl, a   ; BL = tổng
  mov ah, 9

  lea dx, ms3
  int 21h     ; in lời nhắc kết quả
  mov ah, 0
  mov al, bl  ; AX = tổng
  mov bl, 10
  div bl      ; AL = chục, AH = đơn vị
  mov a, ah   ; cất số đơn vị vào a

  mov ah, 2
  mov dl, al
  add dl, 48
  int 21h     ; in hàng chục
  mov dl, a   ; đọc số dư từ biến a
  add dl, 48
  int 21h     ; in hàng đơn vị

  mov ah, 4ch
  int 21h     ; thoát về DOS

main endp
end main
