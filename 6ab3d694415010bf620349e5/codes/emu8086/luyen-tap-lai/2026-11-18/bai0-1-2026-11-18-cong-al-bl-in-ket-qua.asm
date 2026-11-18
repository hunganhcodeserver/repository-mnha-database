.model small
.stack 100h
.data
  ms db 'AL = $'
.code
main proc
  mov ax, @data
  mov ds, ax  ; nạp DS

  mov al, 5
  mov bl, 3
  add al, bl  ; AL = 8
  mov bh, al  ; cất kết quả sang BH
  mov ah, 9
  lea dx, ms
  int 21h     ; in 'AL = '
  mov dl, bh
  add dl, 48  ; số thành ký tự
  mov ah, 2
  int 21h     ; in '8'

  mov ah, 4ch
  int 21h     ; thoát về DOS
main endp
end main
