.model small
.stack 100h
.data
  x    db 5             ; 1 byte, x = 5
  y    dw 1234h         ; 2 byte (word)
  z    db ?             ; chưa có giá trị
  ms   db 'ket qua: $'  ; chuỗi, kết thúc $
  arr  db 1, 2, 3       ; mảng 3 byte
  buf  db 10 dup(?)     ; 10 byte chưa gán
  muoi equ 10           ; hằng số, không tốn RAM
.code
main proc
  mov ax, @data
  mov ds, ax
  mov al, x   ; AL = 5
  mov bl, 3
  add al, bl  ; AL = 8
  sub al, 3   ; AL = 5
  inc al      ; AL = 6
  mov z, al   ; z = 6
  mov bl, muoi
  mul bl      ; AX = 60
  mov bh, 7
  div bh      ; AL = 8, AH = 4
  mov bl, ah  ; BL = 4 (số dư)
  mov bh, al  ; BH = 8 (thương)
  mov ah, 9
  lea dx, ms
  int 21h  ; in 'ket qua: '
  mov ah, 2
  mov dl, bh
  add dl, 48
  int 21h  ; in 8
  mov dl, bl
  add dl, 48
  int 21h  ; in 4

  mov ah, 4ch
  int 21h
main endp
end main
