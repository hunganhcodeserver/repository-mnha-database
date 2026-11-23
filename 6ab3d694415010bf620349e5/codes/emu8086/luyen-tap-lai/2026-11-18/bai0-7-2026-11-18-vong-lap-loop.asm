; cach 2: loop
.model small
.stack 100h
.code
main proc
  mov cx, 26   ; số lần lặp
  mov dl, 'A'
intiep:
  mov ah, 2
  int 21h      ; in DL
  add dl, 1    ; ký tự kế
  loop intiep  ; CX-1, khác 0 thì lặp
  mov ah, 4ch
  int 21h
main endp
end main
