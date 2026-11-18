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
  int 21h     ; AL = ký tự vừa gõ
  sub al, 48  ; ký tự thành số
  mov bl, al  ; cất số thứ nhất vào BL
  mov ah, 9
  lea dx, ms2
  int 21h     ; in lời nhắc 2
  mov ah, 1
  int 21h     ; AL = số thứ hai (ký tự)
  sub al, 48  ; ký tự thành số
  add bl, al  ; BL = tổng hai số

  mov ah, 9
  lea dx, ms3
  int 21h     ; in lời nhắc kết quả
  mov ah, 0   ; xoá AH trước khi chia
  mov al, bl  ; AX = tổng
  mov bh, 10
  div bh      ; AL = chục, AH = đơn vị
  mov bh, ah  ; cất số đơn vị sang BH
  mov ah, 2   ; hàm in một ký tự
  mov dl, al
  add dl, 48  ; chữ số chục thành ký tự
  int 21h     ; in hàng chục
  mov dl, bh
  add dl, 48  ; chữ số đơn vị thành ký tự
  int 21h     ; in hàng đơn vị

  mov ah, 4ch
  int 21h     ; thoát về DOS

main endp
end main
