.model small
.stack 100h
.data
  ms1 db 'nhap so: $'
  ms2 db 10, 13, 'so vua nhap $'
.code
main proc
  mov ax, @data
  mov ds, ax  ; nạp DS
  mov ah, 9
  lea dx, ms1
  int 21h     ; in lời nhắc nhập
  mov bx, 0   ; BX = số đang lưu

nhap:
  mov ah, 1
  int 21h     ; AL = ký tự vừa gõ
  cmp al, 13  ; có phải Enter?
  je in_so    ; đúng thì thôi nhập
  sub al, 48  ; ký tự thành số
  mov ah, 0   ; AX = chữ số
  mov cx, ax  ; cất chữ số vào CX
  mov ax, bx  ; AX = số đang lưu
  mov bx, 10
  mul bx      ; AX = số x 10
  add ax, cx  ; cộng chữ số mới
  mov bx, ax  ; BX = số mới
  jmp nhap    ; quay lại nhập
in_so:
  mov ah, 9
  lea dx, ms2
  int 21h     ; in lời nhắc kết quả
  mov ax, bx  ; AX = số cần in
  mov cx, 0   ; CX = số chữ số
  mov bx, 10  ; BX = số chia
chia:
  mov dx, 0   ; DX = 0 trước khi chia
  div bx      ; AX = thương, DX = dư
  push dx     ; đẩy số dư
  inc cx      ; đếm thêm một chữ số
  cmp ax, 0   ; thương bằng 0 chưa?
  jne chia    ; chưa thì chia tiếp

in_ra:
  pop dx      ; lấy chữ số ở đỉnh
  add dl, 48  ; chữ số thành ký tự
  mov ah, 2
  int 21h     ; in một chữ số
  loop in_ra  ; lặp CX lần

  mov ah, 4ch
  int 21h     ; thoát về DOS
main endp
end main
