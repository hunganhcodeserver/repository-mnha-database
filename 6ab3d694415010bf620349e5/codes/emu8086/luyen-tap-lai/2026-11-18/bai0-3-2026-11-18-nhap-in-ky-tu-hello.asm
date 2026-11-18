.model small
.stack 100h
.data
  ms1 db 'Hello$'
.code
main proc
  mov ax, @data
  mov ds, ax

  mov ah, 1
  int 21h     ; AL = phím vừa gõ
  mov bl, al  ; cất sang BL
  mov ah, 2
  mov dl, 'A'
  int 21h  ; in ký tự A

  mov ah, 9
  lea dx, ms1
  int 21h  ; in chuỗi Hello

  mov ah, 2
  mov dl, bl
  int 21h  ; in lại phím đã gõ

  mov ah, 4ch
  int 21h  ; thoát về DOS
main endp
end main
