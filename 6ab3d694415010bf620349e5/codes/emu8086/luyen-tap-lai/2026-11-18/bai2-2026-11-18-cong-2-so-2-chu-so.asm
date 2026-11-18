.model small
.stack 100h
.data
  ms1 db 'nhap so thu nhat: $'
  ms2 db 10, 13, 'nhap so thu hai: $'
  ms3 db 10, 13, 'tong hai so: $'
.code
main proc
  mov ax, @data
  mov ds, ax  ; nạp DS
  mov ah, 9
  lea dx, ms1
  int 21h     ; in lời nhắc 1
  mov ah, 1
  int 21h     ; AL = ký tự hàng chục
  sub al, 48  ; ký tự thành số
  mov bl, 10
  mul bl      ; AX = chục x 10
  mov bx, ax  ; BL = chục x 10
  mov ah, 1
  int 21h     ; AL = ký tự hàng đơn vị
  sub al, 48
  add bl, al  ; BL = số thứ nhất
  mov ah, 9
  lea dx, ms2
  int 21h     ; in lời nhắc 2
  mov ah, 1
  int 21h     ; AL = ký tự hàng chục
  sub al, 48
  mov bh, 10
  mul bh      ; AX = chục x 10
  mov bh, al  ; BH = chục x 10
  mov ah, 1
  int 21h     ; AL = ký tự hàng đơn vị
  sub al, 48
  add bh, al  ; BH = số thứ hai
  add bl, bh  ; BL = tổng (< 100)
  mov ah, 9

  lea dx, ms3
  int 21h     ; in lời nhắc kết quả
  mov ah, 0   ; xoá AH trước khi chia
  mov al, bl  ; AX = tổng
  mov bh, 10
  div bh      ; AL = chục, AH = đơn vị
  mov bh, ah  ; cất số đơn vị sang BH

  mov ah, 2
  mov dl, al
  add dl, 48
  int 21h     ; in hàng chục
  mov dl, bh
  add dl, 48
  int 21h     ; in hàng đơn vị

  mov ah, 4ch
  int 21h     ; thoát về DOS

main endp
end main
